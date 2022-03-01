#include "headers.h"
#include "ProgressBar.h"

using namespace std;

namespace gui_framework
{
	ProgressBar::ProgressBar(const wstring& progressBarName, const utility::ComponentSettings& settings, BaseComponent* parent, int minRange, int maxRange, int updateStep) :
		BaseProgressBar
		(
			progressBarName,
			settings,
			parent,
			minRange,
			maxRange,
			updateStep
		),
		IResizableComponent
		(
			handle,
			parent->getHandle()
		)
	{

	}

	size_t ProgressBar::getHash() const
	{
		return typeid(ProgressBar).hash_code();
	}

	json::JSONBuilder ProgressBar::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseProgressBar::getStructure();
		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		return builder;
	}
}
