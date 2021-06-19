#include "pch.h"
#include "FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		FileDoesNotExist::FileDoesNotExist(const filesystem::path& filePath) :
			BaseGUIFrameworkException(format("File {} does not exist", filePath.string()))
		{

		}
	}
}
