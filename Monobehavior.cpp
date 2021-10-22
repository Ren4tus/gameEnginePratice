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

	//todo: 시간을 재는 기능은 scene에 있어야 될 것 같음. 지금은 컴포넌트 갯수만큼 여러번 호출
	time->StartTimer();

	//Update 함수 호출
	if (time->m_tick > UPDATE_EXECUTE_TIME) {
		//나중에 deltatime 디버그할때 쓸거같아서 일단 남겨둠
		//std::cout.setf(std::ios::fixed, std::ios::floatfield);
		Update();
		time->m_tick = 0.0f;
		m_fixedUpdateCounter++;
	}

	//FixedUpdtae 함수 호출
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

