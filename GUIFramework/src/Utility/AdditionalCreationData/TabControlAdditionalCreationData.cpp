#include "core.h"
#include "TabControlAdditionalCreationData.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		AdditionalCreationData<TabControl>::AdditionalCreationData(const vector<TabControl::tabData>& data, uint16_t imagesWidth, uint16_t imagesHeight) :
			data(data),
			imagesWidth(imagesWidth),
			imagesHeight(imagesHeight)
		{

		}

		any AdditionalCreationData<TabControl>::getData() const
		{
			return make_any<tuple<vector<TabControl::tabData>, uint16_t, uint16_t>>(data, imagesWidth, imagesHeight);
		}
	}
}
