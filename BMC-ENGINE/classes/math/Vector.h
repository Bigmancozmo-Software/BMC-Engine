#ifndef VECTOR_H
#define VECTOR_H

class Vector2 {
public:
	int x;
	int y;
	
	Vector2(int x, int y);
	Vector2(int xy);
	Vector2();

	Vector2 operator+(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	};
};

class Vector3 {
public:
	int x;
	int y;
	int z;

	Vector3(int x, int y, int z);
	Vector3(int xyz);
	Vector3();

	Vector3 operator+(const Vector3& other) const {
		return Vector3(x + other.x, y + other.y, z + other.z);
	};
};

#endif // VECTOR_H