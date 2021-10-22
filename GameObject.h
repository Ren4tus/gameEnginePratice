#pragma once
#include <vector>
#include <string>
#include "Component.h"
#include "Monobehavior.h"
class GameObject : public Monobehavior
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
	void Start() override;
	void Update() override;
	void MainLoop() override;
	std::string GetName() override;
private:
	std::vector<Monobehavior*> m_components;

	//�׳� while�� ������ ���� �ӽ� ����
	bool m_tempIsGameEnd;
	std::string m_name;
};
