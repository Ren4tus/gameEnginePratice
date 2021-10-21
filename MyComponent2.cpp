#include "MyComponent2.h"
#include <iostream>
MyComponent2::MyComponent2()
{
	m_name = "MyComponent2";
}
MyComponent2::MyComponent2(std::string name) :m_name(name)
{
}
MyComponent2::~MyComponent2()
{
}
std::string MyComponent2::GetName()
{
	return m_name;
}

void MyComponent2::Start()
{
	std::cout << m_name << " - Start ȣ��!" << std::endl;
}

void MyComponent2::Update()
{
	//���� �����ؼ� �ּ�
	//std::cout << m_name << " - Update ȣ��!" << std::endl;
}

void MyComponent2::FixedUpdate()
{
	std::cout << m_name << " - FixedUpdate ȣ��!" << std::endl;
}
