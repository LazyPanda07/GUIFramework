#pragma once

#include "core.h"

#include "BaseComposites/BaseComposite.h"

namespace gui_framework
{
	/// @brief Used for recreation windowed application from JSON
	class GUI_FRAMEWORK_API Recreator
	{
	private:
		json::JSONParser windowedApplicationStructure;

	public:
		Recreator(const std::filesystem::path& pathToJSON);

		Recreator(const std::string& json);

		std::unique_ptr<BaseComposite> deserialize() const;

		~Recreator() = default;
	};
}
