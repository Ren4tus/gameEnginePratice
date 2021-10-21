#include "GameObject.h"
#include "MyComponent.h"
#include "MyComponent2.h"
int main()
{
	GameObject* obj1 = new GameObject();
	obj1->AddComponent(new MyComponent());
	obj1->AddComponent(new MyComponent2());

	obj1->Loop();

	delete obj1;

	return 0;
}