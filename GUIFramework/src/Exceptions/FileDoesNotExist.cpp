#include "headers.h"
#include "FileDoesNotExist.h"

using namespace std;

namespace gui_framework
{
	namespace exceptions
	{
		FileDoesNotExist::FileDoesNotExist(const filesystem::path& filePath, string_view fileName, string_view methodName, int line) :
			BaseGUIFrameworkException(format(R"(File "{}" does not exist)"sv, filePath.string()), fileName, methodName, line)
		{

		}
	}
}
