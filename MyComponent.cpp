#include "MyComponent.h"
#include <iostream>
#include "Monobehavior.h"
MyComponent::MyComponent()
{
	m_name = "MyComponent";
}
MyComponent::MyComponent(std::string name) :m_name(name)
{
}
MyComponent::~MyComponent()
{
}
std::string MyComponent::GetName()
{
	return m_name;
}

void MyComponent::Start()
{
	std::cout << m_name << " - Start ȣ��!" << std::endl;	
}

void MyComponent::Update()
{
	//���� �����ؼ� �ּ�
	//std::cout << m_name << " - Update ȣ��!" << std::endl;
}

void MyComponent::FixedUpdate()
{
	std::cout << m_name << " - FixedUpdate ȣ��!" << std::endl;
}
