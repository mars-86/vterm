#ifndef _VTERM_INTERNAL_SEQUENCES_INCLUDED_H_
#define _VTERM_INTERNAL_SEQUENCES_INCLUDED_H_
#pragma once

#include <string>

#define VTERM_ESCAPE "\x1B"
#define VTERM_BELL "\x07"
#define VTERM_CURSOR_BLINKING VTERM_ESCAPE "[?12h"
#define VTERM_CURSOR_NOT_BLINKING VTERM_ESCAPE "[?12l"
#define VTERM_CURSOR_SHOW VTERM_ESCAPE "[?25h"
#define VTERM_CURSOR_HIDE VTERM_ESCAPE "[?25l"
#define VTERM_ALTERNATE_SCREEN_BUFFER VTERM_ESCAPE "[?1049h"
#define VTERM_MAIN_SCREEN_BUFFER VTERM_ESCAPE "[?1049l"
#define VTERM_DEC_CHARSET VTERM_ESCAPE "(0"
#define VTERM_ASCII_CHARSET VTERM_ESCAPE "(B"

// change to constexpr because macro param stringify don't work with escape characters
template<typename T = short>
constexpr auto VTERM_CURSOR_POSITION_UP(T n) { return VTERM_ESCAPE "[" + std::to_string(n) + "A"; }
template<typename T = short>
constexpr auto VTERM_CURSOR_POSITION_DOWN(T n) { return VTERM_ESCAPE "[" + std::to_string( n ) + "B"; }
template<typename T = short>
constexpr auto VTERM_CURSOR_POSITION_FWARD(T n) { return VTERM_ESCAPE "[" + std::to_string(n) + "C"; }
template<typename T = short>
constexpr auto VTERM_CURSOR_POSITION_BWARD(T n) { return VTERM_ESCAPE "[" + std::to_string(n) + "D"; }
// FIX: this command can handle from 0 to 16 colors
// const std::string VTERM_SET_GRAPHIC_RENDITION(std::string s) { return VTERM_ESCAPE "[" + s + "m"; }

#endif // !_VTERM_INTERNAL_SEQUENCES_INCLUDED_H_
