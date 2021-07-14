#pragma once

#include "pch.h"

namespace gui_framework
{
	namespace interfaces
	{
		class GUI_FRAMEWORK_API IStyles
		{
		private:
			LONG_PTR styles;
			LONG_PTR extendedStyles;

		protected:
			virtual void appendStyle(LONG_PTR style) final;

			virtual void appendExtendedStyle(LONG_PTR extendedStyle) final;

		public:
			IStyles();

			virtual LONG_PTR getStyles() const final;

			virtual LONG_PTR getExtendedStyles() const final;

			virtual ~IStyles() = default;
		};
	}
}
