#include "Recreator.h"

#include "Deserializers/Composites/SeparateWindowDeserializer.h"

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
		const auto& [componentName, description] = **windowedApplicationStructure.begin();

		return unique_ptr<BaseComposite>
			(
				static_cast<BaseComposite*>
				(
					deserializers::SeparateWindowDeserializer().deserialize(componentName, get<json::utility::jsonObject>(description))
					)
				);
	}
}
