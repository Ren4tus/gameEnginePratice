#pragma once
#include <vector>
#include <string>
#include <stack>
#include "Vector3.h"
#include "Component.h"
#include "Monobehavior.h"
class Transform;
class GameObject
{
public:
	GameObject();
	GameObject(std::string name);
	~GameObject();

	void AddComponent(Monobehavior* newComponent);
	void AddChild(GameObject* childGameobject);
	void SetPosition(double x, double y, double z);
	void AddPosition(Vector3 vec3);
	void SetScale(double x, double y, double z);
	Transform* GetTransform();
	void FixedUpdate();
	void Update();
	void Start();
	void DebugNowPosition();
private:
	std::vector<Monobehavior*> m_components;
	std::vector<GameObject*> m_childGameobjects;
	Vector3 m_reservationPosition;
	std::stack<Vector3*> m_reservationScale;
	std::string m_name;
};

