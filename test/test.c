/*
 * This file is part of libcmmk.
 *
 * libcmmk is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * libcmmk is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with libcmmk.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <libcmmk/libcmmk.h>

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h> /* usleep() */
#include <signal.h>
#include <time.h> /* do we need this? */
#endif

#include <string.h> /* memset() */
#include <stdio.h>
#include <stdlib.h>

int g_stop = 0;

#ifdef WIN32
BOOL WINAPI ctrl_handler(DWORD ctrlType)
{
	/* We only care about ctrl+c events. */
	if (ctrlType == CTRL_C_EVENT) {
		g_stop = 1;
		return TRUE;
	}
	return FALSE;
}
#else
static void interrupted(int sig)
{
	(void)sig;

	g_stop = 1;
}
#endif

void sleep_ms(int ms) {
#ifdef WIN32
	Sleep(ms);
#elif _POSIX_C_SOURCE >= 199309L
	struct timespec t;
	t.tv_sec = ms / 1000;
	t.tv_nsec = (ms % 1000) * 1000000;
	nanosleep(&t, NULL);
#else
	usleep(ms * 1000);
#endif
}

int test_multilayer(struct cmmk *dev)
{
        fprintf(stderr, "test_multilayer\n");
	/* Simple multilayer demo.
	 *
	 * This will set the ESC and arrow keys to a rainbow pattern, the main block to raindrop and
	 * everything else to a set color (#404040, greyish).
	 */
	struct cmmk_effect_matrix map = {0};

	struct cmmk_effect_fully_lit f = {
		.color = MKRGB(0x404040)
	};

	struct cmmk_effect_wave w = {
		.speed = 0x20,
		.direction = CMMK_LEFT_TO_RIGHT,
		.start = MKRGB(0xffffff)
	};

	struct cmmk_effect_raindrops r = {
		.speed = 0x20,
		.interval = 0x30,
		.active = MKRGB(0xffffff),
		.rest = MKRGB(0x000000)
	};

	map.data[0][0] = CMMK_EFFECT_WAVE;
	map.data[4][16] = CMMK_EFFECT_WAVE;
	map.data[5][15] = CMMK_EFFECT_WAVE;
	map.data[5][16] = CMMK_EFFECT_WAVE;
	map.data[5][17] = CMMK_EFFECT_WAVE;

	memset(&map.data[1], CMMK_EFFECT_RAINDROPS, 15);
	memset(&map.data[2], CMMK_EFFECT_RAINDROPS, 15);
	memset(&map.data[3], CMMK_EFFECT_RAINDROPS, 15);
	memset(&map.data[4], CMMK_EFFECT_RAINDROPS, 15);
	memset(&map.data[5], CMMK_EFFECT_RAINDROPS, 15);

	cmmk_set_control_mode(dev, CMMK_EFFECT);

	cmmk_switch_multilayer(dev, 1);
		cmmk_set_effect_fully_lit(dev, &f);
		cmmk_set_effect_wave(dev, &w);
		cmmk_set_effect_raindrops(dev, &r);
	cmmk_switch_multilayer(dev, 0);

	cmmk_set_multilayer_map(dev, &map);
        /*fprintf(stderr, "CMMK_EFFECT_FULLY_LIT\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_FULLY_LIT);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_BREATHE\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_BREATHE);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_CYCLE\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_CYCLE);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_SINGLE\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_SINGLE);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_WAVE\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_WAVE);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_RIPPLE\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_RIPPLE);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_CROSS\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_CROSS);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_RAINDROPS\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_RAINDROPS);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_STARS\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_STARS);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_SNAKE\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_SNAKE);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_REC\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_REC);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_INDICATOR\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_INDICATOR);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_MULTILAYER_1\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_MULTILAYER_1);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_MULTILAYER_2\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_MULTILAYER_2);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_MULTILAYER_3\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_MULTILAYER_3);*/
	/*sleep_ms(3000);*/
        /*fprintf(stderr, "CMMK_EFFECT_MULTILAYER_4\n");*/
	/*cmmk_set_active_effect(dev, CMMK_EFFECT_MULTILAYER_4);*/
	/*sleep_ms(3000);*/

	return 0;
}

int test_seq(struct cmmk *dev)
{
        fprintf(stderr, "test_seq\n");
	/* Sequential demo.
	 *
	 * Lights up every key once, starting on the left and moving horizontally, row by row.
	 */
	struct rgb offcolor = MKRGB(0x000000);
	struct rgb oncolor = MKRGB(0x0055a4);
	struct rgb oncolor2 = MKRGB(0xffffff);
	struct rgb oncolor3 = MKRGB(0xef4135);
	cmmk_set_control_mode(dev, CMMK_MANUAL);
	/*cmmk_set_all_single(dev, &oncolor);*/
	/*sleep_ms(1000);*/
	/*cmmk_set_all_single(dev, &oncolor2);*/
	/*sleep_ms(1000);*/
	/*cmmk_set_all_single(dev, &oncolor3);*/
	/*sleep_ms(1000);*/
	for (int row = 0; row < 7; ++row) {
		for (int col = 0; col < 22; ++col) {
			if (g_stop) { return 1; }
			cmmk_set_single_key(dev, row, col, &oncolor);
			sleep_ms(100);
			cmmk_set_single_key(dev, row, col, &offcolor);
		}
	}
	return 0;
}

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	struct cmmk state;
	state.cxt = NULL;

	int product;


	if (cmmk_find_device(&product) != 0) {
		return 1;
	}
	fprintf(stderr, "ok%d", product);
	if (cmmk_attach(&state, product, CMMK_LAYOUT_FR_CK530) != 0) {
		return 1;
	}

#ifdef WIN32
	SetConsoleCtrlHandler(ctrl_handler, TRUE);
#else
	signal(SIGINT, interrupted);
#endif

	test_multilayer(&state);

	while (!g_stop) {
		sleep_ms(1000);
	}

	g_stop = 0;

	while (!g_stop) {
		test_seq(&state);
	}

	cmmk_set_control_mode(&state, CMMK_FIRMWARE);
	cmmk_detach(&state);

	return 0;
}
