#include "../tests.h"

template <typename T>
void test_eq(s21::vector<T> &a, std::vector<T> &std_a) {
  EXPECT_EQ(a.size(), std_a.size());
  auto iter_std = std_a.begin();
  auto iter = a.begin();
  while (iter_std != std_a.end() && iter != a.end()) {
    EXPECT_EQ(*iter, *iter_std);
    ++iter;
    ++iter_std;
  }
}

TEST(s21_vector, constructor_test_1) {
  s21::vector<char> test_vector;
  std::vector<char> test_vector_B;
  ASSERT_EQ(test_vector.size(), test_vector_B.size());
}

TEST(s21_vector, constructor_test_2) {
  s21::vector<char> test_vector;
  std::vector<char> test_vector_B;
  ASSERT_EQ(test_vector.capacity(), test_vector_B.capacity());
}

TEST(s21_vector, constructor_test_5) {
  std::initializer_list<int> values{1, 2, 77, 4, 5, 6};
  s21::vector<int> test_vector(values);
  std::vector<int> std_test_vector(values);
  ASSERT_EQ(test_vector.size(), std_test_vector.size());
  test_eq<int>(test_vector, std_test_vector);
}

TEST(s21_vector, constructor_test_4) {
  std::initializer_list<int> values{1, 2, 77, 4, 5, 6};
  s21::vector<int> test_vector(values);
  s21::vector<int> copy_vector(test_vector);
  std::vector<int> std_test_vector(values);
  std::vector<int> std_copy_vector(std_test_vector);
  ASSERT_EQ(std_copy_vector.size(), copy_vector.size());
  test_eq<int>(copy_vector, std_copy_vector);
}

TEST(s21_vector, constructor_test_6) {
  s21::vector<char> test_vector(5);
  std::vector<char> test_vector_B(5);
  ASSERT_EQ(test_vector.size(), test_vector_B.size());
}

TEST(s21_vector, operator_test_1) {
  s21::vector<int> test_vector{1, 2, 77, 4, 5, 6};
  s21::vector<int> test_operator;

  std::vector<int> std_test_vector{1, 2, 77, 4, 5, 6};
  std::vector<int> std_test_operator;
  test_operator = test_vector;
  std_test_operator = std_test_vector;
  test_eq<int>(test_operator, std_test_operator);
}

TEST(s21_vector, operator_test_2) {
  s21::vector<int> myvector{1, 2, 77, 4, 5, 6};
  s21::vector<int> move_vector(std::move(myvector));
  std::vector<int> test_vector{1, 2, 77, 4, 5, 6};
  std::vector<int> std_move_vector(std::move(test_vector));
  test_eq<int>(move_vector, std_move_vector);
}

TEST(s21_vector, operator_test_3) {
  s21::vector<int> myvector{1, 2, 77, 4, 5, 6};
  s21::vector<int> move_vector = std::move(myvector);
  std::vector<int> test_vector{1, 2, 77, 4, 5, 6};
  std::vector<int> std_move_vector;
  std_move_vector = std::move(test_vector);
  test_eq<int>(move_vector, std_move_vector);
}

TEST(vector_tests, operator_equal) {
  std::initializer_list<int> values{1, 2, 77, 4, 5};
  s21::vector<int> A(values);
  std::vector<int> B(values);
  EXPECT_EQ(A.size(), B.size());
  A = std::move(A);
  EXPECT_EQ(A.size(), B.size());
  for (size_t i = 0; i < A.size(); i++) {
    EXPECT_EQ(A[i], B[i]);
  }
  // // ===
  s21::vector<int> C(values);
  std::vector<int> D(values);
  s21::vector<int> E;
  std::vector<int> F;
  E = C;
  F = D;
  EXPECT_EQ(E.size(), F.size());
  for (size_t i = 0; i < C.size(); i++) {
    EXPECT_EQ(E[i], F[i]);
  }
  // // ===
  s21::vector<int> K(values);
  s21::vector<int> L(values);
  K = K;
  L = L;
  EXPECT_EQ(K.size(), K.size());
  for (size_t i = 0; i < K.size(); i++) {
    EXPECT_EQ(K[i], L[i]);
  }
}

TEST(s21_vector, at_test_1) {
  s21::vector<char> test_vector{'a', 'b', 'c', 'd'};
  s21::vector<char> myvector{'a', 'b', 'c', 'd'};
  for (size_t i = 0; i < test_vector.size(); i++) {
    EXPECT_EQ(test_vector.at(i), myvector.at(i));
  }
  test_vector.at(0) = 'b';
  myvector.at(0) = 'b';
  EXPECT_EQ(test_vector.at(0), myvector.at(0));
}

TEST(s21_vector, create_2) {
  s21::vector<char> test_vector;
  ASSERT_EQ(test_vector.empty(), 1);
  test_vector.push_back('a');
  ASSERT_EQ(test_vector.empty(), 0);
}

TEST(s21_vector, max_size_test) {
  s21::vector<char> myvector;
  std::vector<char> test_vector;
  ASSERT_EQ(myvector.max_size(), test_vector.max_size());
}

TEST(s21_vector, reserve_test) {
  s21::vector<char> myvector;
  std::vector<char> test_vector;
  myvector.reserve(100);
  test_vector.reserve(100);
  ASSERT_EQ(myvector.size(), test_vector.size());
}

TEST(s21_vector, shrink_to_fit_test) {
  s21::vector<int> myvector{1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> test_vector{1, 2, 3, 4, 5, 6, 7, 8};

  myvector.push_back(2);
  test_vector.push_back(2);
  myvector.shrink_to_fit();
  test_vector.shrink_to_fit();
  ASSERT_EQ(myvector.size(), test_vector.size());
}

TEST(s21_vector, insert_test) {
  s21::vector<int> myvector{1, 2, 3, 4, 5, 6, 7, 8};
  s21::vector<int>::iterator myit;
  myit = myvector.begin();
  myit = myvector.insert(myit + 3, 200);
  std::vector<int> test_vector{1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int>::iterator it;
  it = test_vector.begin();
  it = test_vector.insert(it + 3, 200);
  test_eq<int>(myvector, test_vector);
}

TEST(s21_vector, erase_test_1) {
  s21::vector<int> myvector{1, 2, 77, 3, 4, 5};
  std::vector<int> test_vector{1, 2, 77, 3, 4, 5};
  myvector.erase(myvector.begin() + 2);
  test_vector.erase(test_vector.begin() + 2);
  test_eq<int>(myvector, test_vector);
}

TEST(s21_vector, pop_back_test_1) {
  s21::vector<int> myvector{1, 2, 77, 3, 4, 5};
  std::vector<int> test_vector{1, 2, 77, 3, 4, 5};
  myvector.pop_back();
  test_vector.pop_back();
  test_eq<int>(myvector, test_vector);
}

TEST(s21_vector, push_back_test_1) {
  s21::vector<int> myvector{1, 2, 77, 3, 4, 5};
  std::vector<int> test_vector{1, 2, 77, 3, 4, 5};
  myvector.push_back(7);
  test_vector.push_back(7);
  test_eq<int>(myvector, test_vector);
}

TEST(s21_vector, data_test_1) {
  std::vector<int> test_vector(5);
  int *p = test_vector.data();
  *p = 10;
  ++p;
  *p = 20;
  s21::vector<int> myvector(5);
  auto it = myvector.data();
  *it = 10;
  ++it;
  *it = 20;
  test_eq<int>(myvector, test_vector);
}

TEST(s21_vector, front_back_test_1) {
  s21::vector<int> myvector{78, 16};
  std::vector<int> test_vector{78, 16};
  ASSERT_EQ(myvector.front(), test_vector.front());
  ASSERT_EQ(myvector.back(), test_vector.back());
}

TEST(vector_modifiers, bounus_emplace_iterator_Test1) {
  s21::vector<int> myvector;
  auto itC = (myvector.end());
  myvector.insert_many(itC, 9,8,7,6,5);
  std::vector<int> result{9, 8, 7, 6, 5};
  test_eq<int>(myvector, result);
}

TEST(vector_modifiers, bounus_emplace_back_Test1) {
  s21::vector<int> myvector;
  myvector.insert_many_back(1, 2, 3);
  ASSERT_EQ(myvector.size(), 3);
  ASSERT_EQ(myvector.front(), 1);
  ASSERT_EQ(myvector.back(), 3);
}

TEST(vector_modifiers, bounus_emplace_back_Test2) {
  s21::vector<int> myvector{9, 8, 7};
  myvector.insert_many_back(1, 2, 3);
  ASSERT_EQ(myvector.size(), 6);
  ASSERT_EQ(myvector.front(), 9);
  ASSERT_EQ(myvector.back(), 3);
}
