#pragma once
#include <string>
#include "Monobehavior.h"
class MyComponent2 : public Monobehavior
{
public:
	MyComponent2();
	~MyComponent2();
	MyComponent2(std::string name);

	std::string GetName() override;
	void Start() override;
	void Update() override;
	void FixedUpdate() override;
private:
	std::string m_name;
};
