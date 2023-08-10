#include "../tests.h"

template <typename T>
struct ConstArrayIterTest : public testing::Test {
  using Array = const s21::array<T, 7>;
  using StdArray = const std::array<T, 7>;
};

using ArrayIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ConstArrayIterTest, ArrayIterTypes);

TYPED_TEST(ConstArrayIterTest, PrevNextAdvance) {
  using Array = typename TestFixture::Array;
  using StdArray = typename TestFixture::StdArray;

  Array arr_test({1, 3, 99, 17, 100, 127, 0});
  StdArray std_arr_test({1, 3, 99, 17, 100, 127, 0});

  auto iter = arr_test.begin();
  auto std_iter = std_arr_test.begin();
  EXPECT_EQ(*std::next(iter), *std::next(std_iter));
  EXPECT_EQ(*std::prev(arr_test.end()), *std::prev(std_arr_test.end()));
  std::advance(iter, 3);
  std::advance(std_iter, 3);
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(*(iter--), *(std_iter--));
  EXPECT_EQ(*(iter++), *(std_iter++));
}

template <typename T>
struct ConstListIterTest : public testing::Test {
  using List = const s21::list<T>;
  using StdList = const std::list<T>;
};

using ListIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ConstListIterTest, ListIterTypes);

TYPED_TEST(ConstListIterTest, PrevNextAdvance) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test({1, 3, 99, 17, 100, 127, 0});
  StdList std_test({1, 3, 99, 17, 100, 127, 0});

  auto iter = test.begin();
  auto std_iter = std_test.begin();
  EXPECT_EQ(*std::next(iter), *std::next(std_iter));
  EXPECT_EQ(*std::prev(test.end()), *std::prev(std_test.end()));
  std::advance(iter, 3);
  std::advance(std_iter, 3);
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(*(iter--), *(std_iter--));
  EXPECT_EQ(*(iter++), *(std_iter++));
}

template <typename T>
struct ConstMapIterTest : public testing::Test {
  using Map = const s21::map<T, T>;
  using StdMap = const std::map<T, T>;
};

using MapIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ConstMapIterTest, MapIterTypes);

TYPED_TEST(ConstMapIterTest, PrevNextAdvance) {
  using Map = typename TestFixture::Map;
  using StdMap = typename TestFixture::StdMap;

  Map test({{1, 3}, {3, 9}, {99, 1}, {17, 21}, {100, 2}, {127, 99}, {0, 18}});
  StdMap std_test(
      {{1, 3}, {3, 9}, {99, 1}, {17, 21}, {100, 2}, {127, 99}, {0, 18}});

  auto iter = test.begin();
  auto std_iter = std_test.begin();
  EXPECT_EQ(*std::next(iter), std::next(std_iter)->second);
  EXPECT_EQ(*std::prev(test.end()), std::prev(std_test.end())->second);
  EXPECT_EQ(std::next(iter).GetKey(), std::next(std_iter)->first);
  EXPECT_EQ(std::prev(test.end()).GetKey(), std::prev(std_test.end())->first);
  std::advance(iter, 5);
  std::advance(std_iter, 5);
  EXPECT_EQ(*iter, std_iter->second);
  EXPECT_EQ(iter.GetKey(), std_iter->first);
  EXPECT_EQ(*(iter--), (std_iter--)->second);
  EXPECT_EQ(*(iter++), (std_iter++)->second);
  EXPECT_EQ((iter--).GetKey(), (std_iter--)->first);
  EXPECT_EQ((iter++).GetKey(), (std_iter++)->first);
}

template <typename T>
struct ConstSetIterTest : public testing::Test {
  using Set = const s21::set<T>;
  using StdSet = const std::set<T>;
};

using SetIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ConstSetIterTest, SetIterTypes);

TYPED_TEST(ConstSetIterTest, PrevNextAdvance) {
  using Set = typename TestFixture::Set;
  using StdSet = typename TestFixture::StdSet;

  Set test({1, 3, 99, 17, 100, 127, 0});
  StdSet std_test({1, 3, 99, 17, 100, 127, 0});

  auto iter = test.begin();
  auto std_iter = std_test.begin();
  EXPECT_EQ(*std::next(iter), *std::next(std_iter));
  EXPECT_EQ(*std::prev(test.end()), *std::prev(std_test.end()));
  std::advance(iter, 3);
  std::advance(std_iter, 3);
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(*(iter--), *(std_iter--));
  EXPECT_EQ(*(iter++), *(std_iter++));
}

template <typename T>
struct ConstMultiSetIterTest : public testing::Test {
  using MultiSet = const s21::set<T>;
  using StdMultiSet = const std::set<T>;
};

using MultiSetIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ConstMultiSetIterTest, MultiSetIterTypes);

TYPED_TEST(ConstMultiSetIterTest, PrevNextAdvance) {
  using MultiSet = typename TestFixture::MultiSet;
  using StdMultiSet = typename TestFixture::StdMultiSet;

  MultiSet test({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdMultiSet std_test(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});

  auto iter = test.begin();
  auto std_iter = std_test.begin();
  EXPECT_EQ(*std::next(iter), *std::next(std_iter));
  EXPECT_EQ(*std::prev(test.end()), *std::prev(std_test.end()));
  std::advance(iter, 3);
  std::advance(std_iter, 3);
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(*(iter--), *(std_iter--));
  EXPECT_EQ(*(iter++), *(std_iter++));
}

template <typename T>
struct ConstVectorIterTest : public testing::Test {
  using Vector = const s21::vector<T>;
  using StdVector = const std::vector<T>;
};

using VectorIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ConstVectorIterTest, VectorIterTypes);

TYPED_TEST(ConstVectorIterTest, PrevNextAdvance) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test0({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  Vector test1(test0);
  Vector test(std::move(test1));
  StdVector std_test0(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdVector std_test1(std_test0);
  StdVector std_test(std::move(std_test1));

  auto iter = test.begin();
  auto std_iter = std_test.begin();
  EXPECT_EQ(*std::next(iter), *std::next(std_iter));
  EXPECT_EQ(*std::prev(test.end()), *std::prev(std_test.end()));
  std::advance(iter, 3);
  std::advance(std_iter, 3);
  EXPECT_EQ(*iter, *std_iter);
  EXPECT_EQ(*(iter--), *(std_iter--));
  EXPECT_EQ(*(iter++), *(std_iter++));
}
