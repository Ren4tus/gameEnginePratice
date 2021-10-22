#pragma once
#include <vector>
#include "Component.h"
class Time;

class Monobehavior : public IComponent {
private:
	Time* time;
	const unsigned short FIXED_EXECUTE_TIME = 2;
	const float UPDATE_EXECUTE_TIME = 3.0f;
	unsigned short m_fixedUpdateCounter;
public:
	Monobehavior();
	~Monobehavior();

	std::string GetName() override;
	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	virtual void MainLoop();
	void Init();
	Time* GetTime();

};