#pragma once

#include "Winuser.h"

namespace gui_framework
{
	namespace hotkeys
	{
		enum keys : uint32_t
		{
			leftMouseButton = VK_LBUTTON,
			rightMouseButton,
			cancel,
			middleMouseButton,
			x1MouseButton,
			x2MouseButton,
			backspace = VK_BACK,
			tab,
			clear = VK_CLEAR,
			enter,
			shift = VK_SHIFT,
			ctrl,
			alt,
			pause,
			capsLock,
			escape = VK_ESCAPE,
			spacebar = VK_SPACE,
			pageUp,
			pageDown,
			end,
			home,
			leftArrow,
			upArrow,
			rightArrow,
			donwArrow,
			select,
			print,
			execute,
			printScreen,
			ins,
			del,
			help,
			zero,
			one,
			two,
			three,
			four,
			five,
			six,
			seven,
			eight,
			nine,
			A = 0x41,
			B,
			C,
			D,
			E,
			F,
			G,
			H,
			I,
			J,
			K,
			L,
			M,
			N,
			O,
			P,
			Q,
			R,
			S,
			T,
			U,
			V,
			W,
			X,
			Y,
			Z,
			sleep = VK_SLEEP,
			zeroKeypad,
			oneKeypad,
			twoKeypad,
			threeKeypad,
			fourKeypad,
			fiveKeypad,
			sixKeypad,
			sevenKeypad,
			eightKeypad,
			nineKeypad,
			multiply,
			add,
			separator,
			subtract,
			decimal,
			divide,
			F1,
			F2,
			F3,
			F4,
			F5,
			F6,
			F7,
			F8,
			F9,
			F10,
			F11,
			F12,
			F13,
			F14,
			F15,
			F16,
			F17,
			F18,
			F19,
			F20,
			F21,
			F22,
			F23,
			F24,
			numLock = VK_NUMLOCK,
			scrollLock,
			leftShift = VK_LSHIFT,
			rightShift,
			leftCtrl,
			rightCtrl,
			leftAlt,
			rightAlt,
			volumeMute = VK_VOLUME_MUTE,
			volumeDown,
			volumeUp,
			nextTrack,
			previousTrack,
			stopMedia,
			zoom = VK_ZOOM
		};

		enum class additionalKeys : uint32_t
		{
			shift = keys::shift,
			control,
			alt,
			leftShift = keys::leftShift,
			rightShift,
			leftCtrl,
			rightCtrl,
			leftAlt,
			rightAlt,
		};
	}
}
