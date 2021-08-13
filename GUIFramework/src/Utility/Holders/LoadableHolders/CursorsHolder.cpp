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
			const any* result = nullptr;

			for (const auto& [path, data] : images)
			{
				if (data.index == cursorIndex)
				{
					result = &data.data;
				}
			}
			
			if (!result)
			{
				throw out_of_range("Wrong index");
			}

			return any_cast<HCURSOR>(*result);
		}

		uint16_t CursorsHolder::addImage(const filesystem::path& pathToCursor)
		{
			return BaseLoadableHolder::insertImage(pathToCursor, imageType::cursor);
		}
	}
}
