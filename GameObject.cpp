#include "GameObject.h"
#include <iostream>
GameObject::~GameObject()
{
	for (std::vector<Monobehavior*>::iterator iter = m_components.begin();
		iter != m_components.end();
		iter++)
	{
		delete (*iter);
	}
}
void GameObject::AddComponent(Monobehavior* newComponent)
{
	m_components.push_back(newComponent);
}

void GameObject::Start()
{
}

void GameObject::Update()
{

}
std::string GameObject::GetName() {
	return m_name;
}

void GameObject::MainLoop()
{
	//awake

	//start
	for (std::vector<Monobehavior*>::iterator iter = m_components.begin();
		iter != m_components.end();
		iter++)
	{
		(*iter)->Init();
	}
	
	//update, fixedupdate loop
	while (!m_tempIsGameEnd) {
		for (std::vector<Monobehavior*>::iterator iter = m_components.begin();
			iter != m_components.end();
			iter++)
		{
			(*iter)->MainLoop();
		}
	}
}
