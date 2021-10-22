#pragma once
#include <string>

//순수 가상 함수이고, interface처럼 동작
class IComponent
{
public:
	//test
	IComponent(){}
	virtual ~IComponent(){}
	virtual std::string GetName() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
};
