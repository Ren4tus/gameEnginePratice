#include "GameObject.h"
#include "MyComponent.h"
#include "MyComponent2.h"
int main()
{
	GameObject* parentObject = new GameObject("parentObject");
	GameObject* obj1 = new GameObject("obj1");
	obj1->AddComponent(new MyComponent());
	obj1->AddComponent(new MyComponent2());
	parentObject->AddComponent(obj1);
	parentObject->MainLoop();

	delete obj1;
	delete parentObject;
	return 0;
}