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

		uint16_t CursorsHolder::addImage(const filesystem::path& pathToCursor)
		{
			return BaseLoadableHolder::insertImage(pathToCursor, imageType::cursor);
		}
	}
}
