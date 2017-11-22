#include "..\Queue lab\TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_a_queue_with_positive_length) {
	ASSERT_NO_THROW(TQueue<int> q(3));
}