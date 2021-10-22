#pragma once
#include <vector>
#include "Component.h"
#include "Monobehavior.h"
class GameObject
{
public:
	GameObject()
	{
		m_tempIsGameEnd = false;
	}

	~GameObject();

	void AddComponent(Monobehavior* newComponent);
	void Loop();
private:
	std::vector<Monobehavior*> m_components;

	//그냥 while문 돌리기 위한 임시 변수
	bool m_tempIsGameEnd;
};
