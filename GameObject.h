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

	//�׳� while�� ������ ���� �ӽ� ����
	bool m_tempIsGameEnd;
	std::string m_name;
};
