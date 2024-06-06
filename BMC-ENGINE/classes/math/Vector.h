#ifndef VECTOR_H
#define VECTOR_H

class Vector2 {
public:
	int x;
	int y;
	
	Vector2(int x, int y);
	Vector2(int xy);
	Vector2();
};

class Vector3 {
public:
	int x;
	int y;
	int z;

	Vector3(int x, int y, int z);
	Vector3(int xyz);
	Vector3();
};

#endif // VECTOR_H