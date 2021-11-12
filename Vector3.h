#pragma once
using namespace std;

class Vector3
{
public:
    double x, y, z;

public:
    Vector3() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }
    Vector3(double _x, double _y, double _z)
        : x(_x), y(_y), z(_z)
    {

    }
    void inverse()
    {
        x = -x;
        y = -y;
        z = -z;
    }


};