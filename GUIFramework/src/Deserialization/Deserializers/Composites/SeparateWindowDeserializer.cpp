#include "headers.h"
#include "SeparateWindowDeserializer.h"

using namespace std;

namespace gui_framework
{
	namespace deserializers
	{
		BaseComponent* SeparateWindowDeserializer::deserialize(const string& className, const json::utility::objectSmartPointer<json::utility::jsonObject>& description, BaseComposite* parent) const
		{
			SeparateWindow* result = nullptr;
			uint64_t codepage = interfaces::ISerializable::getCodepage();
			//utility::AdditionalCreationData<SeparateWindow> creationData(utility::to_wstring(className, codepage), );

			return result;
		}
	}
}
