#ifndef VECTOR_H
#define VECTOR_H

/// 
/// Two-component vector (X/Y)
/// 
class Vector2 {
public:
	/// 
	/// The X coordinate of the Vector2.
	/// 
	int x;

	/// 
	/// The Y coordinate of the Vector2.
	/// 
	int y;
	
	/// 
	/// Create the Vector2
	/// @param x The X coordinate to assign to the Vector2.
	/// @param y The Y coordinate to assign to the Vector2.
	/// 
	Vector2(int x, int y);

	/// 
	/// Create the Vector2
	/// @param xy The value to assign to the X and Y coordinates of the Vector2.
	/// 
	Vector2(int xy);

	/// 
	/// Create a blank Vector2, with X/Y = 0.
	/// 
	Vector2();

	Vector2 operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); };
	Vector2 operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); };
	Vector2 operator*(const Vector2& other) const { return Vector2(x * other.x, y * other.y); };
	Vector2 operator/(const Vector2& other) const { return Vector2(x / other.x, y / other.y); };
};

/// 
/// Three-component vector (X/Y/Z)
/// 
class Vector3 {
public:
	/// 
	/// The X coordinate of the Vector3
	/// 
	int x;

	/// 
	/// The Y coordinate of the Vector3
	/// 
	int y;

	/// 
	/// The Z coordinate of the Vector3
	/// 
	int z;

	/// 
	/// Create the Vector2
	/// @param x The X coordinate to assign to the Vector3.
	/// @param y The Y coordinate to assign to the Vector3.
	/// @param z The Z coordinate to assign to the Vector3.
	/// 
	Vector3(int x, int y, int z);

	/// 
	/// Create the Vector3
	/// @param xyz The value to assign to the X/Y/Z coordinates of the Vector2.
	///
	Vector3(int xyz);

	/// 
	/// Create a blank Vector3, with X/Y/Z = 0.
	/// 
	Vector3();

	Vector3 operator+(const Vector3& other) const { return Vector3(x + other.x, y + other.y, z + other.z); };
	Vector3 operator-(const Vector3& other) const { return Vector3(x - other.x, y - other.y, z - other.z); };
	Vector3 operator*(const Vector3& other) const { return Vector3(x * other.x, y * other.y, z * other.z); };
	Vector3 operator/(const Vector3& other) const { return Vector3(x / other.x, y / other.y, z / other.z); };
};

#endif // VECTOR_H