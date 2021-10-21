#pragma once
#include <string>
#include "Monobehavior.h"
class MyComponent : public Monobehavior
{
public:
	MyComponent();
	~MyComponent();
	MyComponent(std::string name);

	std::string GetName() override;
	void Start() override;
	void Update() override;
	void FixedUpdate() override;
private:
	std::string m_name;
};
