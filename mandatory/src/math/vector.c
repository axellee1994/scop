

#include "math3d.h"

Vector3 Vector3Add(Vector3 a, Vector3 b)
{
    Vector3 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}

Vector3 Vector3Sub(Vector3 a, Vector3 b)
{
    Vector3 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}

Vector3 Vector3Multiply(Vector3 a, float scalar)
{
    Vector3 result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    result.z = a.z * scalar;
    return result;
}

Vector3 Vector3Divide(Vector3 a, float scalar)
{
    Vector3 result;
    result.x = a.x / scalar;
    result.y = a.y / scalar;
    result.z = a.z / scalar;
    return result;
}

float Vector3Dot(Vector3 a, Vector3 b)
{
    Vector3 result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;

    return result.x + result.y + result.z;
}

Vector3 Vector3CrossProduct(Vector3 a, Vector3 b)
{
    Vector3 result;
    result.x = (a.y * b.z) - (a.z * b.y);
    result.y = (a.z * b.x) - (a.x * b.z);
    result.z = (a.x * b.y) - (a.y * b.x);
    
    return result;
}