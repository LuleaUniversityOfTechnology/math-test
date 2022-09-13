#pragma once
#include "vec3.h"
#include "vec4.h"
#include "mat4.h"
#include <cmath>

inline vec3 max(vec3 a, vec3 b)
{
    return vec3(fmax(a[0], b[0]), fmax(a[1], b[1]), fmax(a[2], b[2]));
}

inline vec4 max(vec4 a, vec4 b)
{
    return vec4(fmax(a[0], b[0]), fmax(a[1], b[1]), fmax(a[2], b[2]), fmax(a[3], b[3]));
}

inline bool cmple(vec3 a, vec3 b)
{
    return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2];
}

inline bool cmple(vec4 a, vec4 b)
{
    return a[0] <= b[0] && a[1] <= b[1] && a[2] <= b[2] && a[3] <= b[3];
}

inline bool n_fequal(float f0, float f1, float tol)
{
    float f = f0 - f1;
    return ((f > (-tol)) && (f < tol));
}

inline bool nearequal(vec3 v0, vec3 v1, vec3 epsilon)
{
	vec3 delta = v0 - v1;
	vec3 temp = vec3(0,0,0);
	temp = temp - delta;
	temp = max(temp, delta);
	return cmple(temp, epsilon);
}

inline bool nearequal(vec4 v0, vec4 v1, vec4 epsilon)
{
	vec4 delta = v0 - v1;
	vec4 temp = vec4(0,0,0,0);
	temp = temp - delta;
	temp = max(temp, delta);
	return cmple(temp, epsilon);
}

inline bool matnearequal(mat4 lhs, mat4 rhs)
{
	const float E = 0.00001f;
    const vec4 E4(E, E, E, E);
	return nearequal(lhs[0], rhs[0], E4) && nearequal(lhs[1], rhs[1], E4) && nearequal(lhs[2], rhs[2], E4) && nearequal(lhs[3], rhs[3], E4);
}
