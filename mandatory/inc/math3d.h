#ifndef MATH3D_H
# define MATH3D_H

# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef union {
    float v[3];

    struct
    {
        float x;
        float y;
        float z;
    };
} Vector3;

typedef union {
    float m[16];

    struct
    {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    };
} Matrix;

// Vector operations
Vector3 Vector3Add(Vector3 a, Vector3 b);
Vector3 Vector3Sub(Vector3 a, Vector3 b);
Vector3 Vector3Multiply(Vector3 a, float scalar);
Vector3 Vector3Divide(Vector3 a, float scalar);
float Vector3Dot(Vector3 a, Vector3 b);
Vector3 Vector3CrossProduct(Vector3 a, Vector3 b);

// Matrix operations
Matrix MatrixIdentity(void);
Matrix MatrixMultiply(Matrix a, Matrix b);
Matrix MatrixTranslate(float x, float y, float z);
Matrix MatrixRotateY(float angle);
Matrix MatrixPerspective(float fov, float aspect, float nearPlane, float farPlane);
#endif
