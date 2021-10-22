#pragma once
#include <vector>
#include <string>
#include "Component.h"
#include "Monobehavior.h"
class GameObject
{
public:
	GameObject()
	{
		m_tempIsGameEnd = false;
	}
	GameObject(std::string name)
	{
		m_tempIsGameEnd = false;
		m_name = name;
	}
	~GameObject();

	void AddComponent(Monobehavior* newComponent);
	void AddChild(GameObject* childGameobject);
	void Loop();
private:
	std::vector<Monobehavior*> m_components;
	std::vector<GameObject*> m_childGameobjects;

	//그냥 while문 돌리기 위한 임시 변수
	bool m_tempIsGameEnd;
	std::string m_name;
};
