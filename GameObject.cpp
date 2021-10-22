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

void GameObject::AddChild(GameObject* childGameobject)
{
	m_childGameobjects.push_back(childGameobject);
}

void GameObject::Loop()
{
	//awake

	//start
	for (std::vector<GameObject*>::iterator iter = m_childGameobjects.begin();
		iter != m_childGameobjects.end();
		iter++)
	{
		for (std::vector<Monobehavior*>::iterator compIter = (*iter)->m_components.begin();
			compIter != (*iter)->m_components.end();
			compIter++)
		{
			(*compIter)->Init();
		}
	}
	for (std::vector<Monobehavior*>::iterator iter = m_components.begin();
		iter != m_components.end();
		iter++)
	{
		(*iter)->Init();
	}
	
	//update, fixedupdate loop

	while (!m_tempIsGameEnd) {
		for (std::vector<GameObject*>::iterator iter = m_childGameobjects.begin();
			iter != m_childGameobjects.end();
			iter++)
		{
			for (std::vector<Monobehavior*>::iterator compIter = (*iter)->m_components.begin();
				compIter != (*iter)->m_components.end();
				compIter++)
			{
				(*compIter)->MainLoop();
			}
		}
		for (std::vector<Monobehavior*>::iterator mCompiter = m_components.begin();
			mCompiter != m_components.end();
			mCompiter++)
		{
			(*mCompiter)->MainLoop();
		}
	}
}
