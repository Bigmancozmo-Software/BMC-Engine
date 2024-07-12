#include <gtest/gtest.h>
#include "../BMC-ENGINE/classes/math/Vector.h"

TEST(Vector2Tests, Add) {
	Vector2 added = Vector2(8, 5) + Vector2(3, 4);
	Vector2 expected = Vector2(11, 9);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}

TEST(Vector3Tests, Add) {
	Vector3 added = Vector3(5, 6, 3) + Vector3(8, 3, 7);
	Vector3 expected = Vector3(13, 9, 10);

	EXPECT_EQ(added.x, expected.x);
	EXPECT_EQ(added.y, expected.y);
}