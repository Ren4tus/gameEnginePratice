#include <iostream>
#include <iomanip>
#include "Monobehavior.h"
#include "Time.h"
Monobehavior::Monobehavior():m_fixedUpdateCounter(0)
{
	time = new Time();
}
Monobehavior::~Monobehavior()
{
	delete time;
}

std::string Monobehavior::GetName()
{
	return "Monobehavior";
}

void Monobehavior::Start()
{
	std::cout << GetName() << " : Start()" << std::endl;
}

void Monobehavior::Update()
{
	std::cout << GetName() <<" : Update()" << std::endl;
}

void Monobehavior::FixedUpdate()
{
	std::cout << GetName()<< "FixedUpdate()" << std::endl;
}

void Monobehavior::MainLoop()
{

	//todo: �ð��� ��� ����� scene�� �־�� �� �� ����. ������ ������Ʈ ������ŭ ������ ȣ��
	time->StartTimer();

	//Update �Լ� ȣ��
	if (time->m_tick > UPDATE_EXECUTE_TIME) {
		//���߿� deltatime ������Ҷ� ���Ű��Ƽ� �ϴ� ���ܵ�
		//std::cout.setf(std::ios::fixed, std::ios::floatfield);
		Update();
		time->m_tick = 0.0f;
		m_fixedUpdateCounter++;
	}

	//FixedUpdtae �Լ� ȣ��
	if (m_fixedUpdateCounter > FIXED_EXECUTE_TIME) {
		FixedUpdate();
		m_fixedUpdateCounter = 0;
	}

	time->EndTimer();
}

void Monobehavior::Init()
{
	Start();
}

Time* Monobehavior::GetTime()
{
	return time;
}

