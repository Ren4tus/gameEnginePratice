#include "GameObject.h"
#include "MyComponent.h"
#include "MyComponent2.h"
#include "Scene.h"
int main()
{
	Monobehavior* triangle = new MyComponent();
	Monobehavior* collision = new MyComponent2();
	GameObject* body = new GameObject("body");
	body->SetPosition(0.0f, 0.0f, 0.0f);
	body->AddComponent(triangle);
	body->AddComponent(collision);

	Monobehavior* box = new MyComponent();
	GameObject* turret = new GameObject("turret");
	body->AddChild(turret);
	turret->SetPosition(0.0f, 0.0f, 2.0f);
	turret->SetScale(0.5f, 0.5f, 2.0f);
	turret->AddComponent(box);

	Scene* scene = new Scene("scene name");
	scene->AddGameObejct(body);
	scene->AddGameObejct(turret);

	scene->Loop();
	return 0;
}