#include "headers.h"
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

	unique_ptr<BaseComposite> Recreator::deserialize() const
	{
		unique_ptr<BaseComposite> result;

		return result;
	}
}
