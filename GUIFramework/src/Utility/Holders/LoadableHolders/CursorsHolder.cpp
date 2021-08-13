#include "pch.h"
#include "CursorsHolder.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		CursorsHolder::CursorsHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count) :
			BaseLoadableHolder
			(
				imagesWidth,
				imagesHeight,
				count
			)
		{

		}

		HCURSOR CursorsHolder::getCursor(const filesystem::path& pathToCursor) const
		{
			return any_cast<HCURSOR>(images.at(pathToCursor).data);
		}

		HCURSOR CursorsHolder::getCursor(uint16_t cursorIndex) const
		{
			return any_cast<HCURSOR>(ranges::find_if(images, [cursorIndex](const pair<wstring, imageData>& data) { return data.second.index == cursorIndex; })->second.data);
		}

		uint16_t CursorsHolder::addImage(const filesystem::path& pathToCursor)
		{
			return BaseLoadableHolder::insertImage(pathToCursor, imageType::cursor);
		}
	}
}
