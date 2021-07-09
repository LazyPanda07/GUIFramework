#include "pch.h"
#include "CursorHolder.h"

using namespace std;

namespace gui_framework
{
	namespace utility
	{
		CursorHolder::CursorHolder(uint16_t imagesWidth, uint16_t imagesHeight, size_t count) :
			BaseLoadableHolder
			(
				imagesWidth,
				imagesHeight,
				count
			)
		{

		}

		uint16_t CursorHolder::addImage(const filesystem::path& pathToCursor)
		{
			return BaseLoadableHolder::insertImage(pathToCursor, imageType::cursor);
		}
	}
}
