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
	std::cout << m_name << " - Start 호출!" << std::endl;	
}

void MyComponent::Update()
{
	//보기 불편해서 주석
	//std::cout << m_name << " - Update 호출!" << std::endl;
}

void MyComponent::FixedUpdate()
{
	std::cout << m_name << " - FixedUpdate 호출!" << std::endl;
}
