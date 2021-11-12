#pragma once
#include <vector>
#include "Component.h"
class Time;

class Monobehavior : public IComponent {
private:

public:
	Monobehavior();
	~Monobehavior();

	std::string GetName() override;
	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	void Init();

};