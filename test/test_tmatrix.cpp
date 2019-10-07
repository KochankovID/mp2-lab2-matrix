#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(2));
  TMatrix<int> m(2);
  for (int i = 0; i < 2; i++) {
	  for (int j = i; j < 2; j++) {
		  EXPECT_EQ(m[i][j], 0);
	  }
  }
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(2);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
  TMatrix<int> m1(m);
  for (int i = 0; i < 2; i++) {
	  for (int j = i; j < 2; j++) {
		  EXPECT_EQ(m1[i][j], 0);
	  }
  }
}

TEST(TMatrix, constructor_by_default)
{
	ASSERT_NO_THROW(TMatrix<int> a);
	TMatrix<int> m1;
	for (int i = 0; i < m1.GetSize(); i++) {
		for (int j = i; j < m1.GetSize(); j++) {
			EXPECT_EQ(m1[i][j], 0);
		}
	}
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<double> t1(13);
	t1[0][0] = 10;
	t1[5][6] = 101;
	TMatrix<double> t2(t1);
	EXPECT_EQ(t1, t2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<double> t1(13);
	TMatrix<double> t2(t1);
	t2[0][0] = 1003;
	EXPECT_EQ(t1[0][0], 0);
	EXPECT_EQ(t2[0][0], 1003);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<double> t1(13);
	EXPECT_EQ(t1.GetSize(), 13);
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<double> t1(2);
	t1[0][0] = 10;
	EXPECT_EQ(t1[0][0], 10);
	EXPECT_EQ(t1[0][1], 0);
	EXPECT_EQ(t1[1][1], 0);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<double> t1(13);
	ASSERT_ANY_THROW(t1[-1][9] = 10);
}

TEST(TMatrix, throws_when_set_element_below_the_diagonal)
{
	TMatrix<double> t1(13);
	ASSERT_ANY_THROW(t1[4][0] = 10);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<double> t1(13);
	ASSERT_ANY_THROW(t1[5][13] = 10);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<double> t1(13);
	ASSERT_NO_THROW(t1 = t1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<double> t1(13), t2(13);
	t1[0][4] = 1;
	t1[7][8] = 1;
	t2 = t1;
	EXPECT_EQ(t2[0][4], 1);
	EXPECT_EQ(t2[7][8], 1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<double> t1(13), t2(20);
	t1[1][1] = 1;
	t1[4][9] = 1;
	t2 = t1;
	EXPECT_EQ(t2.GetSize(), 13);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<double> t1(13), t2(20);
	t1[1][1] = 1;
	t1[4][9] = 1;
	t2 = t1;
	EXPECT_EQ(t2[1][1], 1);
	EXPECT_EQ(t2[4][9], 1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<double> t1(13), t2(20);
	t1[1][1] = 1;
	t1[4][9] = 1;
	t2 = t1;
	EXPECT_TRUE(t2 == t1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<double> t1(13);
	t1[9][10] = 1;
	EXPECT_TRUE(t1 == t1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<double> t1(13), t2(45);
	EXPECT_FALSE(t1 == t2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<double> t1(2), t2(2);
	t1[0][0] = 1;
	t2[0][1] = 3;
	t2[0][0] = 2;
	EXPECT_NO_THROW(t1 + t2);
	TMatrix<double> t3(t1 + t2);
	EXPECT_EQ(t3[0][0], 3);
	EXPECT_EQ(t3[0][1], 3);
	EXPECT_EQ(t3[1][1], 0);

}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<double> t1(13), t2(43);
	t1[0][5] = 1;
	t2[0][5] = 3;
	EXPECT_ANY_THROW(t1 + t2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<double> t1(13), t2(13);
	t1[0][5] = 1;
	t2[0][5] = 3;
	EXPECT_NO_THROW(t1 - t2);
	TMatrix<double> t3(t1 - t2);
	EXPECT_EQ(t3[0][5], -2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<double> t1(13), t2(43);
	t1[0][5] = 1;
	t2[0][5] = 3;
	EXPECT_ANY_THROW(t1 - t2);
}

