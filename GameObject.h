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

	//�׳� while�� ������ ���� �ӽ� ����
	bool m_tempIsGameEnd;
};
