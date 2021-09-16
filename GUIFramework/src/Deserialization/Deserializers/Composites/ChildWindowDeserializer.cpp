#include "headers.h"
#include "ChildWindowDeserializer.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* ChildWindowDeserializer::deserialize(const string& componentName, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			return nullptr;
		}
	}
}
