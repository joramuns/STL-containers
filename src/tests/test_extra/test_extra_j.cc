#include "../tests.h"

template <typename T>
struct ArrayIterTest : public testing::Test {
  using Array = s21::array<T, 7>;
  using StdArray = std::array<T, 7>;
};

using ArrayIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayIterTest, ArrayIterTypes);

TYPED_TEST(ArrayIterTest, PrevNextAdvance) {
  using Array = typename TestFixture::Array;
  using StdArray = typename TestFixture::StdArray;

  Array arr_test0({1, 3, 99, 17, 100, 127, 0});
  Array arr_test1{arr_test0};
  Array arr_test{std::move(arr_test1)};
  StdArray std_arr_test0({1, 3, 99, 17, 100, 127, 0});
  StdArray std_arr_test1{std_arr_test0};
  StdArray std_arr_test{std::move(std_arr_test1)};

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
struct ListIterTest : public testing::Test {
  using List = s21::list<T>;
  using StdList = std::list<T>;
};

using ListIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListIterTest, ListIterTypes);

TYPED_TEST(ListIterTest, PrevNextAdvance) {
  using List = typename TestFixture::List;
  using StdList = typename TestFixture::StdList;

  List test0({1, 3, 99, 17, 100, 127, 0});
  List test1{test0};
  List test{std::move(test1)};
  StdList std_test0({1, 3, 99, 17, 100, 127, 0});
  StdList std_test1{std_test0};
  StdList std_test{std::move(std_test1)};

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
struct MapIterTest : public testing::Test {
  using Map = s21::map<T, T>;
  using StdMap = std::map<T, T>;
};

using MapIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(MapIterTest, MapIterTypes);

TYPED_TEST(MapIterTest, PrevNextAdvance) {
  using Map = typename TestFixture::Map;
  using StdMap = typename TestFixture::StdMap;

  Map test0({{1, 3}, {3, 9}, {99, 1}, {17, 21}, {100, 2}, {127, 99}, {0, 18}});
  Map test1{test0};
  Map test{std::move(test1)};
  StdMap std_test0(
      {{1, 3}, {3, 9}, {99, 1}, {17, 21}, {100, 2}, {127, 99}, {0, 18}});
  StdMap std_test1{std_test0};
  StdMap std_test{std::move(std_test1)};

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
struct SetIterTest : public testing::Test {
  using Set = s21::set<T>;
  using StdSet = std::set<T>;
};

using SetIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(SetIterTest, SetIterTypes);

TYPED_TEST(SetIterTest, PrevNextAdvance) {
  using Set = typename TestFixture::Set;
  using StdSet = typename TestFixture::StdSet;

  Set test0({1, 3, 99, 17, 100, 127, 0});
  Set test1{test0};
  Set test{std::move(test1)};
  StdSet std_test0({1, 3, 99, 17, 100, 127, 0});
  StdSet std_test1{std_test0};
  StdSet std_test{std::move(std_test1)};

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
struct MultiSetIterTest : public testing::Test {
  using MultiSet = s21::set<T>;
  using StdMultiSet = std::set<T>;
};

using MultiSetIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(MultiSetIterTest, MultiSetIterTypes);

TYPED_TEST(MultiSetIterTest, PrevNextAdvance) {
  using MultiSet = typename TestFixture::MultiSet;
  using StdMultiSet = typename TestFixture::StdMultiSet;

  MultiSet test0({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  MultiSet test1{test0};
  MultiSet test{std::move(test1)};
  StdMultiSet std_test0(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdMultiSet std_test1{std_test0};
  StdMultiSet std_test{std::move(std_test1)};

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
struct VectorIterTest : public testing::Test {
  using Vector = s21::vector<T>;
  using StdVector = std::vector<T>;
};

using VectorIterTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorIterTest, VectorIterTypes);

TYPED_TEST(VectorIterTest, PrevNextAdvance) {
  using Vector = typename TestFixture::Vector;
  using StdVector = typename TestFixture::StdVector;

  Vector test0({1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  Vector test1{test0};
  Vector test{std::move(test1)};
  StdVector std_test0(
      {1, 3, 99, 17, 100, 127, 0, 100, 99, 3, 9, 127, 0, 0, 0, 3});
  StdVector std_test1{std_test0};
  StdVector std_test{std::move(std_test1)};

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
