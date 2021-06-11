#include "pch.h"
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
				BaseComposite* composite = dynamic_cast<BaseComposite*>(currentComponent);

				if (composite)
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
						BaseComposite* composite = dynamic_cast<BaseComposite*>(parents.top());
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
				}
				else
				{
					if (parents.size())
					{
						BaseComposite* composite = dynamic_cast<BaseComposite*>(parents.top());
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
							currentComponent = nullptr;
						}
					}
				}
			}

			void getPreviousComponent(BaseComponent*& currentComponent, stack<BaseComponent*>& parents, stack<size_t>& indices)
			{
				BaseComposite* composite = nullptr;

				if (currentComponent)
				{
					composite = dynamic_cast<BaseComposite*>(currentComponent);
				}
				else
				{
					const vector<unique_ptr<BaseComponent>>& components = dynamic_cast<BaseComposite*>(parents.top())->getChildren();

					if (components.size())
					{
						currentComponent = components.back().get();
					}
				}

				if (composite)
				{
					const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

					if (components.size())
					{
						indices.push(components.size() - 1);

						parents.push(composite);

						currentComponent = components.back().get();
					}
					else if (parents.size())
					{
						BaseComposite* composite = dynamic_cast<BaseComposite*>(parents.top());
						int64_t previousIndex = indices.top();
						const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

						parents.pop();
						indices.pop();

						if (previousIndex > -1)
						{
							parents.push(composite);
							indices.push(previousIndex - 1);

							currentComponent = components[previousIndex].get();
						}
						else
						{
							currentComponent = nullptr;
						}
					}
				}
				else
				{
					if (parents.size())
					{
						BaseComposite* composite = dynamic_cast<BaseComposite*>(parents.top());
						int64_t previousIndex = indices.top();
						const vector<unique_ptr<BaseComponent>>& components = composite->getChildren();

						parents.pop();
						indices.pop();

						if (previousIndex > -1)
						{
							parents.push(composite);
							indices.push(previousIndex - 1);

							currentComponent = components[previousIndex].get();
						}
						else
						{
							getNextComponent(currentComponent, parents, indices);
						}
					}
				}
			}
		}
	}
}
