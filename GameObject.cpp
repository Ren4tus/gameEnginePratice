#include "GameObject.h"
#include <iostream>
void GameObject::AddComponent(Monobehavior* newComponent)
{
	m_components.push_back(newComponent);
}

void GameObject::Loop()
{
	//awake

	//start
	for (std::vector<Monobehavior*>::iterator iter = m_components.begin();
		iter != m_components.end();
		iter++)
	{
		(*iter)->Init();
	}
	
	//update, fixedupdate ∑Á«¡
	while (!m_tempIsGameEnd) {
		for (std::vector<Monobehavior*>::iterator iter = m_components.begin();
			iter != m_components.end();
			iter++)
		{
			(*iter)->MainLoop();
		}
	}
}
