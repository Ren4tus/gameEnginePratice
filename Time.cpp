#include "Time.h"

Time& Time::getIncetance()
{
	static Time instance;
	return instance;
}

Time::Time() : m_deltaTime(0.0f), m_tick(0.0f){ }

Time::~Time()
{
}

void Time::EndTimer()
{
	QueryPerformanceCounter(&end);
	m_deltaTime = (end.QuadPart - start.QuadPart) / (float)timer.QuadPart;
	//deltaTime�� �ʹ� �۾����� �ּҰ� 0.00001������ ����
	(m_deltaTime < 0.001f) ? m_deltaTime = 0.00001 : m_deltaTime = m_deltaTime;

	m_tick += m_deltaTime;
}

void Time::StartTimer()
{
	QueryPerformanceFrequency(&timer);
	QueryPerformanceCounter(&start);
}
