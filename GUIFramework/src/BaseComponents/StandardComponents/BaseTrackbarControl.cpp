#include "BaseTrackbarControl.h"

#include "Styles/DefaultStyles.h"
#include "Exceptions/NotImplemented.h"

using namespace std;

namespace gui_framework
{
	BaseTrackbarControl::BaseTrackbarControl(const wstring& trackbarName, const utility::ComponentSettings& settings, const styles::TrackbarControlStyles& styles, BaseComposite* parent) :
		BaseComponent
		(
			standard_classes::trackbarControl,
			trackbarName,
			settings,
			styles,
			parent
		)
	{

	}

	void BaseTrackbarControl::clearSelection()
	{
		SendMessageW(handle, TBM_CLEARSEL, true, NULL);
	}

	LRESULT BaseTrackbarControl::size() const
	{
		return SendMessageW(handle, TBM_GETLINESIZE, NULL, NULL);
	}

	void BaseTrackbarControl::setMinRange(int min)
	{
		SendMessageW(handle, TBM_SETRANGEMIN, true, min);
	}

	void BaseTrackbarControl::setMaxRange(int max)
	{
		SendMessageW(handle, TBM_SETRANGEMAX, true, max);
	}

	void BaseTrackbarControl::setSelectionStart(int startPosition)
	{
		SendMessageW(handle, TBM_SETSELSTART, true, startPosition);
	}

	void BaseTrackbarControl::setSelectionEnd(int endPosition)
	{
		SendMessageW(handle, TBM_SETSELEND, true, endPosition);
	}

	LRESULT BaseTrackbarControl::getPosition() const
	{
		return SendMessageW(handle, TBM_GETPOS, NULL, NULL);
	}

	LRESULT BaseTrackbarControl::getMinRange() const
	{
		return SendMessageW(handle, TBM_GETRANGEMIN, NULL, NULL);
	}

	LRESULT BaseTrackbarControl::getMaxRange() const
	{
		return SendMessageW(handle, TBM_GETRANGEMAX, NULL, NULL);
	}

	LRESULT BaseTrackbarControl::getSelectionStart() const
	{
		return SendMessageW(handle, TBM_GETSELSTART, NULL, NULL);
	}

	LRESULT BaseTrackbarControl::getSelectionEnd() const
	{
		return SendMessageW(handle, TBM_GETSELEND, NULL, NULL);
	}

	void BaseTrackbarControl::setTextColor(uint8_t red, uint8_t green, uint8_t blue)
	{
		__utility::throwNotImplementedException(__FUNCTION__, "BaseTrackbarControl"sv);
	}

	json::JSONBuilder BaseTrackbarControl::getStructure() const
	{
		using json::utility::jsonObject;

		json::JSONBuilder builder = BaseComponent::getStructure();

		jsonObject& current = get<jsonObject>(builder[utility::to_string(windowName, ISerializable::getCodepage())]);

		current.data.push_back({ "minRange"s, static_cast<int64_t>(this->getMinRange()) });
		current.data.push_back({ "maxRange"s, static_cast<int64_t>(this->getMaxRange()) });

		current.data.push_back({ "selectionStart"s, static_cast<int64_t>(this->getSelectionStart()) });
		current.data.push_back({ "selectionEnd"s, static_cast<int64_t>(this->getSelectionEnd()) });

		return builder;
	}
}
