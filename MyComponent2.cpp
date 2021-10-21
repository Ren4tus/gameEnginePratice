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
	std::cout << m_name << " - Start 호출!" << std::endl;
}

void MyComponent2::Update()
{
	//보기 불편해서 주석
	//std::cout << m_name << " - Update 호출!" << std::endl;
}

void MyComponent2::FixedUpdate()
{
	std::cout << m_name << " - FixedUpdate 호출!" << std::endl;
}
