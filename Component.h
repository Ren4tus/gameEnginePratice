#pragma once
#include <string>

//���� ���� �Լ��̰�, interfaceó�� ����
class IComponent
{ 
public:
	IComponent(){}
	virtual ~IComponent(){}
	virtual std::string GetName() = 0;
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
};
