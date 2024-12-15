#pragma once
#include "../../common.hpp"

#define M_PI 3.14159265358979323846f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))

class Vector2 {
public:
	float x, y;

	Vector2() {
		x = y = 0.f;
	}
	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}
	Vector2 zero() {
		return Vector2(0.f, 0.f);
	}

	Vector2 operator+(const Vector2& input) const {
		return Vector2(x + input.x, y + input.y);
	}
	Vector2 operator-(const Vector2& input) const {
		return Vector2(x - input.x, y - input.y);
	}
	Vector2 operator/(float input) const {
		return Vector2(x / input, y / input);
	}
	Vector2 operator*(float input) const {
		return Vector2(x * input, y * input);
	}
	Vector2& operator+=(const Vector2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	Vector2& operator-=(const Vector2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}
	Vector2& operator/=(float input) {
		x /= input;
		y /= input;
		return *this;
	}
	Vector2& operator*=(float input) {
		x *= input;
		y *= input;
		return *this;
	}
	bool operator==(const Vector2& input) const {
		return x == input.x && y == input.y;
	}

	ImVec2 toImVec2() const {
		return ImVec2(x, y);
	}
	std::string toString() const {
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}

	bool valid() {
		return !(x == 0.f && y == 0.f) || (x == -1.f && y == -1.f);
	}
	float length() const {
		return sqrt((x * x) + (y * y));
	}
	float distance(Vector2 b) {
		return (*this - b).length();
		//return sqrt(pow(b.x - x, 2) + pow(b.y - y, 2));
	}
	void normalize() {
		if (x < -89)
			x = -89;
		else if (x > 89)
			x = 89;

		if (y < -360)
			y += 360;
		else if (y > 360)
			y -= 360;
	}
	std::string toString() {
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
	}
};
class Vector3 {
public:
	float x, y, z;

	Vector3() {
		x = y = z = 0.f;
	}
	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3 zero() {
		return Vector3(0.f, 0.f, 0.f);
	}

	Vector3 operator+(const Vector3& input) const {
		return Vector3(x + input.x, y + input.y, z + input.z);
	}
	Vector3 operator-(const Vector3& input) const {
		return Vector3(x - input.x, y - input.y, z - input.z);
	}
	Vector3 operator/(float input) const {
		return Vector3(x / input, y / input, z / input);
	}
	Vector3 operator*(float input) const {
		return Vector3(x * input, y * input, z * input);
	}
	Vector3& operator+=(const Vector3& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}
	Vector3& operator-=(const Vector3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}
	Vector3& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		return *this;
	}
	Vector3& operator*=(float input) {
		x *= input;
		y *= input;
		z *= input;
		return *this;
	}
	bool operator==(const Vector3& input) const {
		return x == input.x && y == input.y && z == input.z;
	}

	std::string toString() const {
		return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
	}

	bool valid() {
		return !(x == 0.f && y == 0.f && z == 0.f) || (x == -1.f && y == -1.f && z == -1.f);
	}
	float length() const {
		return (float)sqrt((x * x) + (y * y) + (z * z));
	}
	float length_2d() const {
		return (float)sqrt((x * x) + (y * y));
	}
	float dot(Vector3 input) {
		return (x * input.x) + (y * input.y) + (z * input.z);
	}
	float distance(Vector3 b) {
		return (*this - b).length();
	}
	float distance_2d(Vector3 b) const {
		return (*this - b).length_2d();
	}
};
class Vector4 {
public:
	float x, y, z, w;

	Vector4() {
		x = y = z = w = 0.f;
	}
	Vector4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4 operator+(const Vector4& input) const {
		return Vector4(x + input.x, y + input.y, z + input.z, w + input.w);
	}
	Vector4 operator-(const Vector4& input) const {
		return Vector4(x - input.x, y - input.y, z - input.z, w - input.w);
	}
	Vector4 operator/(float input) const {
		return Vector4(x / input, y / input, z / input, w / input);
	}
	Vector4 operator*(float input) const {
		return Vector4(x * input, y * input, z * input, w * input);
	}
	Vector4& operator+=(const Vector4& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}
	Vector4& operator-=(const Vector4& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}
	Vector4& operator/=(float input) {
		x /= input;
		y /= input;
		z /= input;
		w /= input;
		return *this;
	}
	Vector4& operator*=(float input) {
		x *= input;
		y *= input;
		z *= input;
		w *= input;
		return *this;
	}
	bool operator==(const Vector4& input) const {
		return x == input.x && y == input.y && z == input.z  && w == input.w;
	}

	bool valid() {
		return !(x == 0.f && y == 0.f && z == 0.f && w == 0.f) || (x == -1.f && y == -1.f && z == -1.f && w == -1.f);
	}
	float length() const {
		return (float)sqrt((x * x) + (y * y) + (z * z) + (w * w));
	}
	float length_2d() const {
		return (float)sqrt((x * x) + (y * y));
	}
	float dot(Vector4 input) {
		return (x * input.x) + (y * input.y) + (z * input.z);
	}
	float distance(Vector4 b) {
		return (*this - b).length();
	}
	float distance_2d(Vector4 b) const {
		return (*this - b).length_2d();
	}
};

inline double to_rad(double degree) {
	return (degree * (M_PI / 180));
}
inline Vector2 calculateAngle(Vector3 src, Vector3 dst) {
	Vector3 dir = src - dst;
	return Vector2{ RAD2DEG(asin(dir.y / dir.length())), RAD2DEG(-atan2(dir.x, -dir.z)) };
}
inline float calculateBulletDrop(float height, float distance, float velocity, float gravity) {
	float pitch = atan2(height, distance);
	float bullet_velocity = velocity * cos(pitch);
	float _time = distance / bullet_velocity;

	return (gravity * _time * _time * 0.5f) * 10;
}