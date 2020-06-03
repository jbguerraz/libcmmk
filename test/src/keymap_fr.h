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

/* XXX = unassigned */
static keyboard_layout layout_fr_s = {
	/*
	 ESC   F1    F2    F3    F4    XXX   F5    F6    F7    F8    XXX   F9    F10   F11   F12   PRN   SCL   PAU   XXX   XXX   XXX   XXX */
	{96,   97,   98,   99,   104,  -1,   105,  106,  112,  113,  -1,   114,  67,   68,   69,   102,  103,  107,  -1,   -1,   -1,   -1},

	/*
	 ²     &     é     "     '     (     -     è     _     ç     à     )     =     XXX   BCK   INS   HOM   PUP   XXX   XXX   XXX   XXX */
	{0,    1,    8,    9,    16,   17,   24,   25,   32,   33,   40,   41,   48,   -1,   49,   56,   57,   64,   -1,   -1,   -1,   -1},

	/*
	 TAB   A     Z     E     R     T     Y     U     I     O     P     ^     $     XXX   xxx     DEL   END   PDN   XXX   XXX   XXX   XXX */
	{2,    3,    10,   11,   18,   19,   26,   27,   34,   35,   42,   43,   50,   -1,   -1,   58,   59,   66,   -1,   -1,   -1,   -1},

	/*
	 CAP   Q     S     D     F     G     H     J     K     L     M     ù     *     XXX   ENT   XXX   XXX   XXX   XXX   XXX   XXX   XXX */
	{4,    5,    12,   13,   20,   21,   28,   29,   36,   37,   44,   45,   -1,   -1,   52,   -1,   -1,   -1,   -1,   -1,   -1,   -1},

	/*
	 LSHFT <     W     X     C     V     B     N     ,     ;     :     !     XXX   XXX   RSHFT XXX   UP    XXX   XXX   XXX   XXX   XXX */
	{6,    -1,   7,    14,   15,   22,   23,   30,   31,   38,   39,   46,   -1,   -1,   47,   -1,   61,   -1,   -1,   -1,   -1,   -1},

	/*
	 LCTRL LWIN  LALT  XXX   XXX   XXX   SPACE XXX   XXX   XXX   RALT  RWIN  FN    XXX   RCTRL LEFT  DOWN  RIGHT XXX   XXX   XXX   XXX */
	{91,   90,   92,   -1,   -1,   -1,   93,   -1,   -1,   -1,   94,   60,   95,   -1,   54,   63,   62,   70,   -1,   -1,   -1,   -1},

	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
};

static keyboard_layout layout_fr_ck530 = {
	/*
	 ESC   F1    F2    F3    F4    XXX   F5    F6    F7    F8    XXX   F9    F10   F11   F12   PRN   SCL   PAU   XXX   XXX   XXX   XXX */
	{7,    28,   35,   42,   49,   -1,   63,   70,   77,   84,   -1,   91,   98,   105,  112,  119,  126,  133,  -1,   -1,   -1,   -1},

	/*
	 ²     &     é     "     '     (     -     è     _     ç     à     )     =     XXX   BCK   INS   HOM   PUP   XXX   XXX   XXX   XXX */
	{8,    22,   29,   36,   43,   50,   57,   64,   71,   78,   85,   92,   99,   -1,   113,  120,  127,  134,   -1,   -1,   -1,   -1},

	/*
	 TAB   A     Z     E     R     T     Y     U     I     O     P     ^     $     XXX   xxx   DEL   END   PDN   XXX   XXX   XXX   XXX */
	{9,    23,   30,   37,   44,   51,   58,   65,   72,   79,   86,   93,   100,   -1,   -1,   121,  128,  135,   -1,   -1,   -1,   -1},

	/*
	 CAP   Q     S     D     F     G     H     J     K     L     M     ù     *     XXX   ENT   XXX   XXX   XXX   XXX   XXX   XXX   XXX */
	{10,   24,   31,   38,   45,   52,   59,   66,   73,   80,   87,   94,   108,   -1,  115,   -1,   -1,   -1,   -1,   -1,   -1,   -1},

	/*
	 LSHFT  <    W     X     C     V     B     N     ,     ;     :     !     XXX   XXX   RSHFT XXX   UP    XXX   XXX   XXX   XXX   XXX */
	{11,    18,  25,   32,   39,   46,   53,   60,   67,   74,   81,   88,   -1,   -1,   116,   -1,  130,   -1,   -1,   -1,   -1,   -1},

	/*
	 LCTRL LWIN  LALT  XXX   XXX   XXX   SPACE XXX   XXX   XXX   RALT  RWIN  FN    XXX   RCTRL LEFT  DOWN  RIGHT XXX   XXX   XXX   XXX */
	{12,   19,   26,   -1,   -1,   -1,   54,   -1,   -1,   -1,   82,   89,   96,   -1,   117,  124,  131,  138,   -1,   -1,   -1,   -1},

	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
};

static keyboard_layout layout_fr_l = {
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
};

static keyboard_layout layout_fr_mk750 = {
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
	{-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1},
};
