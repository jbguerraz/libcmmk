from ctypes import *
from colour import Color

class Keyboard:
    class CMMK_COLOR(Structure):
        _fields_ = [('R', c_ubyte), ('G', c_ubyte), ('B', c_ubyte)]

        def __repr__(self):
            return '({0}, {1}, {2})'.format(self.R, self.G, self.B)

    class CMMK_DEVICE(Structure):
        _fields_ = [('cxt', POINTER(c_void_p)), ('dev', POINTER(c_void_p)), ('product', c_int), ('layout', c_int), ('rowmap', c_int8), ('colmap', c_int8), ('multilayer_mode', c_int)]

        def __repr__(self):
            return '({0}, {1}, {2}, {3}, {4}, {5}, {6})'.format(self.cxt, self.dev, self.product, self.layout, self.rowmap, self.colmap, self.multilayer_mode)

    CONTROL_MODES = {'manual': c_int(0x02), 'firmware': c_int(0x00)}
    LAYOUTS = {'FR_CK530': c_int(9)}
    DEVICE = pointer(CMMK_DEVICE())

    def __init__(self, layout='', libusb='', libcmmk=''):
        CDLL(libusb, mode=RTLD_GLOBAL)
        self.cmmk = CDLL(libcmmk, mode=RTLD_GLOBAL)
        self.cmmk.cmmk_find_device.argtypes = [POINTER(c_int)]
        self.cmmk.cmmk_attach.argtypes = [c_void_p, c_int, c_int]
        self.cmmk.cmmk_detach.argtypes = [c_void_p]
        self.cmmk.cmmk_set_control_mode.argtypes = [c_void_p, c_int]
        self.cmmk.cmmk_set_all_single.argtypes = [c_void_p, c_void_p]
        self.cmmk.cmmk_set_single_key_by_id.argtypes = [c_void_p, c_int, c_void_p]
        self.cmmk.cmmk_set_single_key.argtypes = [c_void_p, c_int, c_int, c_void_p]
        self.product = c_int(0)
        self.layout = self.LAYOUTS[layout]

    def attach(self):
        if self.cmmk.cmmk_find_device(self.product) == 0:
            if self.cmmk.cmmk_attach(self.DEVICE, self.product, self.layout) == 0:
                return self.cmmk.cmmk_set_control_mode(self.DEVICE, self.CONTROL_MODES['manual']) == 0
            else:
                return False
        else:
            return False

    def colorize(self, target, color=None):
        if isinstance(target, dict):
            for target, color in target.items():
                self.colorize(target, color)
        elif isinstance(target, list):
            for item in target:
                self.colorize(item, color)
        else:
            c = self.to_cmmk_color(color)
            if isinstance(target, str):
                if target == 'all':
                    self.cmmk.cmmk_set_all_single(self.DEVICE, pointer(c))
                # elif len(target) == 1:
                    # self.cmmk.cmmk_set_single_key_by_name(self.DEVICE, c_char_p(target), c)
                # else:
                    # for char in target:
                        # self.cmmk.cmmk_set_single_key_by_name(self.DEVICE, c_char_p(char), pointer(c))
            elif isinstance(target, int):
                self.cmmk.cmmk_set_single_key_by_id(self.DEVICE, c_int(target), pointer(c))
            elif isinstance(target, tuple):
                self.cmmk.cmmk_set_single_key(self.DEVICE, c_int(target[0]), c_int(target[1]), pointer(c))

    def detach(self):
        self.cmmk.cmmk_set_control_mode(self.DEVICE, self.CONTROL_MODES['firmware'])
        self.cmmk.cmmk_detach(self.DEVICE)

    def to_cmmk_color(self, color):
        return self.CMMK_COLOR(int(color.red * 255), int(color.green * 255), int(color.blue * 255))

import os
class Backlight:
    GET_CMD = 'xbacklight -ctrl "%s" -get'
    SET_CMD = 'xbacklight -ctrl "%s" -set %s'

    def __init__(self, ctrl):
        self.ctrl = ctrl

    def _exec_cmd(self, cmd):
        os.system(cmd)

    def set(self, percent):
        self._exec_cmd(self.SET_CMD % (self.ctrl, percent))

class Power:
    def get(self):
        f = open("/sys/class/power_supply/BAT0/capacity", "r")
        power = f.read()
        f.close()
        return power

import random
import time
ext_k = Keyboard(layout='FR_CK530', libusb='/lib64/libusb-1.0.so.0.1.0', libcmmk='./build/dist/lib64/libcmmk.so')
k = Backlight('asus::kbd_backlight')
s = Backlight('intel_backlight')
p = Power()
c = Color('red')
while True:
    power = int(p.get())
    if power <= 60:
        ext_k_available = False
        while True:
            if not ext_k_available:
                ext_k_available = ext_k.attach()
            for i in range(100):
                if ext_k_available:
                    c.luminance = 0.01 * (100 - (i*1))
                    ext_k.colorize('all', c)
                s.set(100 - (i*1))
                k.set(100 - (i*1))
                # time.sleep(0.005)
            for i in range(100):
                if ext_k_available:
                    c.luminance = 0.01 * (i*1)
                    ext_k.colorize('all', c)
                s.set(i*1)
                k.set(i*1)
                # time.sleep(0.005)
        if ext_k_available:
            ext_k.detach()
    else:
        time.sleep(10)
