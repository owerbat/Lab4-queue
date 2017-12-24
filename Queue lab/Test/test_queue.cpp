#include "..\Queue lab\TQueue.h"

#include "gtest.h"

TEST(TQueue, can_create_a_queue_with_positive_length) {
	ASSERT_NO_THROW(TQueue<int> q(3));
}

TEST(TQueue, throws_when_create_a_queue_with_negative_length) {
	ASSERT_ANY_THROW(TQueue<int> q(-3));
}

TEST(TQueue, can_push_element_in_not_empty_queue) {
	TQueue<int> q(3);

	ASSERT_NO_THROW(q.push(1));
}

TEST(TQueue, throws_when_push_element_in_full_queue) {
	TQueue<int> q(3);

	for (int i = 0; i < 3; i++) {
		q.push(i);
	}

	ASSERT_ANY_THROW(q.push(1));
}

TEST(TQueue, can_pop_from_not_empty_queue) {
	TQueue<int> q(3);

	for (int i = 0; i < 2; i++) {
		q.push(i);
	}

	ASSERT_NO_THROW(q.pop());
}

TEST(TQueue, throws_when_pop_from_empty_queue) {
	TQueue<int> q(3);

	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, empty_check_return_true_when_queue_is_empty) {
	TQueue<int> q(3);

	EXPECT_EQ(1, q.isempty());
}

TEST(TQueue, full_check_return_true_when_queue_is_full) {
	TQueue<int> q(3);

	for (int i = 0; i < 3; i++) {
		q.push(i);
	}

	EXPECT_EQ(1, q.isfull());
}

TEST(TQueue, empty_check_return_false_when_queue_is_not_empty) {
	TQueue<int> q(3);

	q.push(1);

	EXPECT_EQ(0, q.isempty());
}

TEST(TQueue, full_check_return_false_when_queue_is_not_full) {
	TQueue<int> q(3);

	for (int i = 0; i < 2; i++) {
		q.push(i);
	}

	EXPECT_EQ(0, q.isfull());
}

TEST(TQueue, can_get_last_element) {
	TQueue<int> q(3);

	for (int i = 0; i < 3; i++) {
		q.push(i);
	}

	EXPECT_EQ(2, q.getLastElem());
}

TEST(TQueue, can_get_first) {
	TQueue<int> q(3);

	for (int i = 0; i < 3; i++) {
		q.push(i);
	}
	q.pop();

	EXPECT_EQ(1, q.getFirst());
}

TEST(TQueue, can_get_size) {
	TQueue<int> q(3);

	for (int i = 0; i < 2; i++) {
		q.push(i);
	}

	EXPECT_EQ(2, q.getSize());
}

TEST(TQueue, can_get_maxsize) {
	TQueue<int> q(5);

	EXPECT_EQ(5, q.getMaxsize());
}

TEST(TQueue, can_get_top) {
	TQueue<int> q(3);

	for (int i = 0; i < 3; i++) {
		q.push(i);
	}
	q.pop();

	EXPECT_EQ(1,q.top());
}

TEST(TQueue, throws_when_get_top_from_empty_queue) {
	TQueue<int> q(3);

	ASSERT_ANY_THROW(q.top());
}

TEST(TQueue, can_get_last) {
	TQueue<int> q(3);

	for (int i = 0; i < 3; i++) {
		q.push(i);
	}

	EXPECT_EQ(2, q.getLast());
}

TEST(TQueue, equal_queues_are_equal) {
	TQueue<int> q(3), p(3);

	for (int i = 0; i < 2; i++) {
		q.push(i);
		p.push(i);
	}

	EXPECT_EQ(q, p);
}

TEST(TQueue, different_queues_are_not_equal) {
	TQueue<int> q(3), p(3);

	for (int i = 0; i < 2; i++) {
		q.push(i);
		p.push(i+1);
	}

	EXPECT_NE(q, p);
}

TEST(TQueue, copied_queue_is_equal_to_source_one) {
	TQueue<int> q(3);
	
	for (int i = 0; i < 2; i++) {
		q.push(i);
	}
	TQueue<int> p(q);

	EXPECT_EQ(q, p);
}