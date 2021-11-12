#include "GameObject.h"
#include "Transform.h"
#include <iostream>
GameObject::GameObject()
{
	m_name = "GameObject";
	AddComponent(new Transform());
	m_reservationPosition = Vector3(0.0, 0.0, 0.0);
}
GameObject::GameObject(std::string name)
{
	m_name = name;
	AddComponent(new Transform());
	m_reservationPosition = Vector3(0.0, 0.0, 0.0);
}
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

void GameObject::SetPosition(double x, double y, double z)
{
	m_reservationPosition = Vector3(x, y, z);
}

void GameObject::AddPosition(Vector3 vec3)
{
	m_reservationPosition.x += vec3.x;
	m_reservationPosition.y += vec3.y;
	m_reservationPosition.z += vec3.z;
}

void GameObject::SetScale(double x, double y, double z)
{
	m_reservationScale.push(new Vector3(x, y, z));
}

Transform* GameObject::GetTransform()
{
	return static_cast<Transform*>(m_components[0]);
}

void GameObject::FixedUpdate()
{
	DebugNowPosition();
	for (std::vector<GameObject*>::iterator iter = m_childGameobjects.begin();
		iter != m_childGameobjects.end();
		iter++)
	{
		for (std::vector<Monobehavior*>::iterator compIter = (*iter)->m_components.begin();
			compIter != (*iter)->m_components.end();
			compIter++)
		{
			(*compIter)->FixedUpdate();
		}
	}
	for (std::vector<Monobehavior*>::iterator mCompiter = m_components.begin();
		mCompiter != m_components.end();
		mCompiter++)
	{
		(*mCompiter)->FixedUpdate();
	}
}

void GameObject::Update()
{
	for (std::vector<GameObject*>::iterator iter = m_childGameobjects.begin();
		iter != m_childGameobjects.end();
		iter++)
	{
		for (std::vector<Monobehavior*>::iterator compIter = (*iter)->m_components.begin();
			compIter != (*iter)->m_components.end();
			compIter++)
		{
			(*compIter)->Update();
		}
	}
	for (std::vector<Monobehavior*>::iterator mCompiter = m_components.begin();
		mCompiter != m_components.end();
		mCompiter++)
	{
		(*mCompiter)->Update();
	}
}

void GameObject::Start()
{
	//matrix propagation
	this->GetTransform()->Translate(m_reservationPosition);
	for (std::vector<GameObject*>::iterator iter = m_childGameobjects.begin();
		iter != m_childGameobjects.end();
		iter++) 
	{
		(*iter)->AddPosition((*iter)->GetTransform()->m_position);
	}

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
}

void GameObject::DebugNowPosition()
{
	Vector3 tempPosition = this->GetTransform()->m_position;
	std::cout << m_name + ": (" << tempPosition.x << "," << tempPosition.y << "," << tempPosition.z << ")" << std::endl;
}
