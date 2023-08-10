#include "../tests.h"

template <typename T>
struct VectorInsManyTest : public testing::Test {
  using Vector = s21::vector<T>;
  using StdVector = std::vector<T>;
};

using VectorIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorInsManyTest, VectorIterTypes);

TYPED_TEST(VectorInsManyTest, MiddleInsert) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdVector std_test(
      {1, 3, 99, 1, 2, 3, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});

  auto iter = test.begin();
  std::advance(iter, 3);

  test.insert_many(iter, 1, 2, 3);
}

TYPED_TEST(VectorInsManyTest, BeginInsert) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdVector std_test(
      {1, 2, 3, 1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});

  auto iter = test.begin();

  test.insert_many(iter, 1, 2, 3);
}

TYPED_TEST(VectorInsManyTest, EndTest) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdVector std_test(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3, 1, 2, 3});

  auto iter = test.end();

  test.insert_many(iter, 1, 2, 3);
}

TYPED_TEST(VectorInsManyTest, Back) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdVector std_test(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3, 1, 2, 3});

  test.insert_many_back(1, 2, 3);
}

TYPED_TEST(VectorInsManyTest, BackEmpty) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test({});
  StdVector std_test(
      {1, 2, 3});

  test.insert_many_back(1, 2, 3);
}

TYPED_TEST(VectorInsManyTest, EndEmpty) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test({});
  StdVector std_test(
      {1, 2, 3});

  test.insert_many(test.end(), 1, 2, 3);
}

TYPED_TEST(VectorInsManyTest, BeginEmpty) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test({});
  StdVector std_test(
      {1, 2, 3});

  test.insert_many(test.begin(), 1, 2, 3);
}

template <typename T>
struct ListInsManyTest : public testing::Test {
  using List = s21::list<T>;
  using StdList = std::list<T>;
};

using ListIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListInsManyTest, ListIterTypes);

TYPED_TEST(ListInsManyTest, MiddleInsert) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdList std_test(
      {1, 3, 99, 1, 2, 3, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});

  auto iter = test.begin();
  std::advance(iter, 3);

  test.insert_many(iter, 1, 2, 3);
}

TYPED_TEST(ListInsManyTest, BeginInsert) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdList std_test(
      {1, 2, 3, 1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});

  auto iter = test.begin();

  test.insert_many(iter, 1, 2, 3);
}

TYPED_TEST(ListInsManyTest, EndTest) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdList std_test(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3, 1, 2, 3});

  auto iter = test.end();

  test.insert_many(iter, 1, 2, 3);
}

TYPED_TEST(ListInsManyTest, Back) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdList std_test(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3, 1, 2, 3});

  test.insert_many_back(1, 2, 3);
}

TYPED_TEST(ListInsManyTest, BackEmpty) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({});
  StdList std_test(
      {1, 2, 3});

  test.insert_many_back(1, 2, 3);
}

TYPED_TEST(ListInsManyTest, EndEmpty) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({});
  StdList std_test(
      {1, 2, 3});

  test.insert_many(test.end(), 1, 2, 3);
}

TYPED_TEST(ListInsManyTest, BeginEmpty) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({});
  StdList std_test(
      {1, 2, 3});

  test.insert_many(test.begin(), 1, 2, 3);
}

template <typename T>
struct QueueInsManyTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueInsManyTest, QueueIterTypes);

TYPED_TEST(QueueInsManyTest, FullQueue) {
  using Queue = typename TestFixture::Queue;

  Queue test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});

  test.insert_many_back(1, 2, 3);
  EXPECT_EQ(test.back(), 3);
  EXPECT_EQ(test.front(), 1);
}

TYPED_TEST(QueueInsManyTest, EmptyQueue) {
  using Queue = typename TestFixture::Queue;

  Queue test({});

  test.insert_many_back(9, 2, 3);
  EXPECT_EQ(test.back(), 3);
  EXPECT_EQ(test.front(), 9);
}

template <typename T>
struct StackInsManyTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackInsManyTest, StackIterTypes);

TYPED_TEST(StackInsManyTest, FullStack) {
  using Stack = typename TestFixture::Stack;

  Stack test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});

  test.insert_many_front(1, 2, 3);
  EXPECT_EQ(test.top(), 3);
}

TYPED_TEST(StackInsManyTest, EmptyStack) {
  using Stack = typename TestFixture::Stack;

  Stack test({});

  test.insert_many_front(9, 2, 7);
  EXPECT_EQ(test.top(), 7);
}

TEST(InsManyTree, Map_0) {
  s21::map<int, int> test{std::make_pair(1, 2), std::make_pair(2, 4), std::make_pair(99, 0)};
  auto result = test.insert_many(std::make_pair(4, 3), std::make_pair(101, 21));
}
