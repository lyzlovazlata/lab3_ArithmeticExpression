#include <gtest.h>

#include"TQueue.h"

#include <gtest.h>
#include"TStack.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int>s(5));
}
TEST(TStack, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(TQueue<int>s(MAX_QUEUE_SIZE + 1));
}
TEST(TQueue, cant_create_stack_with_length_less_then_zero)
{
	ASSERT_ANY_THROW(TQueue<int>s(-100));
}
TEST(TQueue, can_copy_queue)
{
	TQueue<int> st(10);
	ASSERT_NO_THROW(TQueue<int> s1(st));
}
TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> st(2);
	st.push(3);
	st.push(4);
	TQueue<int> st2(st);
	EXPECT_EQ(st.pop(), st2.pop());
	EXPECT_EQ(st.pop(), st2.pop());
}
TEST(TQueue, copied_queue_has_its_own_memory)
{
	TQueue<int> st(2);
	st.push(3);
	st.push(4);
	TQueue<int> st2(st);
	st.pop();
	st.pop();
	st.push(0);
	st.push(0);
	EXPECT_NE(st.pop(), st2.pop());
	EXPECT_NE(st.pop(), st2.pop());
}

TEST(TQueue, cant_push_when_full)
{
	TQueue<int> s(2);
	s.push(3);
	s.push(4);
	ASSERT_ANY_THROW(s.push(0));
}
TEST(TQueue, cant_pop_when_empty)
{
	TQueue<int> s(2);
	ASSERT_ANY_THROW(s.pop());
}


