#include <gtest.h>

#include"Expression.h"
#include"string"

TEST(Expression, throws_when_lex_error)
{
	string s = "abc"; Expression ax(s);
	EXPECT_ANY_THROW(ax.run());
}
TEST(Expression, throws_when_synt_error)
{
	string s = ")6--)"; Expression ax(s);
	EXPECT_ANY_THROW(ax.run());
}
TEST(Expression, can_create_copy_expression)
{
	string s = "2+3";
	Expression ae(s);
	Expression a(ae);
	ASSERT_NO_THROW(Expression a(ae));
}

TEST(Expression, can_count_unar)
{
	string s = "2-(-3)";
	Expression e(s);
	e.run();
	int a = e.getRes();
	EXPECT_EQ(a, 5);
}