#pragma once
#include <string>
#include "Vector3.h"
#include "Monobehavior.h"
class Transform : public Monobehavior
{
public:
	Transform();
	~Transform();

	std::string GetName() override;
	void Start() override;
	void Update() override;
	void FixedUpdate() override;
	void Translate(Vector3 translateVector);

	Vector3 m_position;
	Vector3 m_scale;
private:
	std::string m_name;

};
