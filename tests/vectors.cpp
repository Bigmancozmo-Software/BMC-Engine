#include <gtest/gtest.h>
#include "../BMC-ENGINE/classes/math/Vector.h"

// Vector2 //

TEST(Vector2Tests, Add) {
	Vector2 added = Vector2(8, 5) + Vector2(3, 4);
	Vector2 expected = Vector2(11, 9);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

TEST(Vector2Tests, Subtract) {
	Vector2 added = Vector2(8, 5) - Vector2(3, 4);
	Vector2 expected = Vector2(5, 1);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

TEST(Vector2Tests, Multiply) {
	Vector2 added = Vector2(8, 5) * Vector2(3, 4);
	Vector2 expected = Vector2(24, 20);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

TEST(Vector2Tests, Divide) {
	Vector2 added = Vector2(8, 5) / Vector2(3, 4);
	Vector2 expected = Vector2(8 / 3, 5 / 4);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

// Vector3 //

TEST(Vector3Tests, Add) {
	Vector3 added = Vector3(5, 6, 3) + Vector3(8, 3, 7);
	Vector3 expected = Vector3(13, 9, 10);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

TEST(Vector3Tests, Subtract) {
	Vector3 added = Vector3(5, 6, 3) - Vector3(8, 3, 7);
	Vector3 expected = Vector3(-3, 3, -4);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

TEST(Vector3Tests, Multiply) {
	Vector3 added = Vector3(5, 6, 3) * Vector3(8, 3, 7);
	Vector3 expected = Vector3(40, 18, 21);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

TEST(Vector3Tests, Divide) {
	Vector3 added = Vector3(5, 6, 3) / Vector3(8, 3, 7);
	Vector3 expected = Vector3(5 / 8, 6 / 3, 3 / 7);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}