#pragma once

#include "headers.h"

namespace gui_framework
{
	namespace interfaces
	{
		/// @brief Provides styles for other classes
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

			IStyles(LONG_PTR styles, LONG_PTR extendedStyles);

			IStyles(const IStyles&) = default;

			IStyles(IStyles&&) noexcept = default;

			IStyles& operator = (const IStyles&) = default;

			IStyles& operator = (IStyles&&) noexcept = default;

			virtual LONG_PTR getStyles() const final;

			virtual LONG_PTR getExtendedStyles() const final;

			virtual bool operator == (const IStyles& other) const final;

			virtual std::istream& operator >> (std::istream& stream) final;

			virtual std::ostream& operator << (std::ostream& stream) const final;

			virtual ~IStyles() = default;
		};
	}
}
