#include "Recreator.h"

using namespace std;

namespace gui_framework
{
	Recreator::Recreator(const filesystem::path& pathToJSON) :
		windowedApplicationStructure(ifstream(pathToJSON))
	{

	}

	Recreator::Recreator(const string& json) :
		windowedApplicationStructure(json)
	{

	}
}
