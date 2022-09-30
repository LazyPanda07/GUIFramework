#include "core.h"
#include "IteratorsFunctionality.h"

#include "BaseComposites/BaseComposite.h"

using namespace std;

namespace gui_framework
{
	namespace iterators
	{
		namespace utility
		{
			void getNextComponent(BaseComponent*& currentComponent, stack<BaseComponent*>& parents, stack<size_t>& indices)
			{
				if (BaseComposite* composite = dynamic_cast<BaseComposite*>(currentComponent))
				{
					const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

					if (components.size())
					{
						indices.push(1);

						parents.push(composite);

						currentComponent = components.front().get();
					}
					else if (parents.size())
					{
						BaseComposite* composite = static_cast<BaseComposite*>(parents.top());
						size_t nextIndex = indices.top();
						const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

						parents.pop();
						indices.pop();

						if (nextIndex < components.size())
						{
							parents.push(composite);
							indices.push(nextIndex + 1);

							currentComponent = components[nextIndex].get();
						}
						else
						{
							getNextComponent(currentComponent, parents, indices);
						}
					}
					else
					{
						currentComponent = nullptr;
					}
				}
				else
				{
					if (parents.size())
					{
						BaseComposite* composite = static_cast<BaseComposite*>(parents.top());
						size_t nextIndex = indices.top();
						const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

						parents.pop();
						indices.pop();

						if (nextIndex < components.size())
						{
							parents.push(composite);
							indices.push(nextIndex + 1);

							currentComponent = components[nextIndex].get();
						}
						else
						{
							getNextComponent(currentComponent, parents, indices);
						}
					}
					else
					{
						currentComponent = nullptr;
					}
				}
			}
		}
	}
}
