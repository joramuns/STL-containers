#include "../tests.h"

template <class T>
struct ArrayAtTest : public testing::Test {};

using ArrayAtTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayAtTest, ArrayAtTypes);

TYPED_TEST(ArrayAtTest, empty) {
  s21::array<TypeParam, 0U> a{};

  EXPECT_ANY_THROW((void)a.at(0));
  EXPECT_ANY_THROW((void)a.at(1));
  EXPECT_ANY_THROW((void)a.at(100));
}

TYPED_TEST(ArrayAtTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};

  EXPECT_DOUBLE_EQ(a.at(0), value);
  EXPECT_ANY_THROW((void)a.at(1));
  EXPECT_ANY_THROW((void)a.at(100));
}

TYPED_TEST(ArrayAtTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(a.at(0), value_1);
  EXPECT_DOUBLE_EQ(a.at(1), value_2);
  EXPECT_DOUBLE_EQ(a.at(2), value_3);
  EXPECT_ANY_THROW((void)a.at(3));
  EXPECT_ANY_THROW((void)a.at(4));
  EXPECT_ANY_THROW((void)a.at(10));
}

template <class T>
struct ArrayBackTest : public testing::Test {};

using ArrayBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayBackTest, ArrayBackTypes);

TYPED_TEST(ArrayBackTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};

  EXPECT_DOUBLE_EQ(a.back(), value);
}

TYPED_TEST(ArrayBackTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(a.back(), value_3);
}

template <class T>
struct ArrayConstructorTest : public testing::Test {};

using ArrayConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayConstructorTest, ArrayConstructorTypes);

TYPED_TEST(ArrayConstructorTest, empty) { s21::array<TypeParam, 0U>(); }

TYPED_TEST(ArrayConstructorTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1({});
  s21::array<TypeParam, 1U> tmp_2({TypeParam(1)});
  s21::array<TypeParam, 3U> tmp_3({TypeParam(1), TypeParam(2), TypeParam(3)});

  ASSERT_ANY_THROW((s21::array<TypeParam, 0U>{{TypeParam(1)}}));
}

TYPED_TEST(ArrayConstructorTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1({TypeParam(1)});
  s21::array<TypeParam, 1U> tmp_2{tmp_1};
  s21::array<TypeParam, 1U> tmp_3{std::move(tmp_2)};
  s21::array<TypeParam, 1U> tmp_4{{TypeParam(3)}};
  tmp_4 = std::move(tmp_3);
}

template <class T>
struct ArrayDataTest : public testing::Test {};

using ArrayDataTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayDataTest, ArrayDataTypes);

TYPED_TEST(ArrayDataTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};

  EXPECT_DOUBLE_EQ(*(a.data()), value);
}

TYPED_TEST(ArrayDataTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(*(a.data()), value_1);
}

template <class T>
struct ArrayEmptyTest : public testing::Test {};

using ArrayEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayEmptyTest, ArrayEmptyTypes);

TYPED_TEST(ArrayEmptyTest, empty) {
  s21::array<TypeParam, 0U> a{};
  EXPECT_TRUE(a.empty());
}

TYPED_TEST(ArrayEmptyTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1({});
  EXPECT_TRUE(tmp_1.empty());
  s21::array<TypeParam, 1U> tmp_2({TypeParam(1)});
  EXPECT_FALSE(tmp_2.empty());
  s21::array<TypeParam, 3U> tmp_3({TypeParam(1), TypeParam(2), TypeParam(3)});
  EXPECT_FALSE(tmp_3.empty());
}

TYPED_TEST(ArrayEmptyTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1({TypeParam(1)});
  EXPECT_FALSE(tmp_1.empty());
  s21::array<TypeParam, 1U> tmp_2{tmp_1};
  EXPECT_FALSE(tmp_2.empty());
  s21::array<TypeParam, 1U> tmp_3{std::move(tmp_2)};
  EXPECT_FALSE(tmp_3.empty());
  s21::array<TypeParam, 1U> tmp_4{{TypeParam(3)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_FALSE(tmp_4.empty());
}

template <class T>
struct ArrayFillTest : public testing::Test {};

using ArrayFillTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayFillTest, ArrayFillTypes);

TYPED_TEST(ArrayFillTest, empty) {
  s21::array<TypeParam, 0U> a{};

  EXPECT_NO_THROW(a.fill(TypeParam(3)));
}

TYPED_TEST(ArrayFillTest, size_1) {
  s21::array<TypeParam, 1U> a{};

  TypeParam value{1};
  a.fill(value);

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(ArrayFillTest, size_3) {
  s21::array<TypeParam, 3U> a{};

  TypeParam value{3};
  a.fill(value);

  EXPECT_DOUBLE_EQ(a[0], value);
  EXPECT_DOUBLE_EQ(a[1], value);
  EXPECT_DOUBLE_EQ(a[2], value);
}

template <class T>
struct ArrayFrontTest : public testing::Test {};

using ArrayFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayFrontTest, ArrayFrontTypes);

TYPED_TEST(ArrayFrontTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(ArrayFrontTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(a.front(), value_1);
}

template <class T>
struct ArrayMaxSizeTest : public testing::Test {};

using ArrayMaxSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayMaxSizeTest, ArrayMaxSizeTypes);

TYPED_TEST(ArrayMaxSizeTest, empty) {
  s21::array<TypeParam, 0U> a{};
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ArrayMaxSizeTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1({});
  EXPECT_EQ(tmp_1.size(), 0);
  s21::array<TypeParam, 1U> tmp_2({TypeParam(1)});
  EXPECT_EQ(tmp_2.size(), 1);
  s21::array<TypeParam, 3U> tmp_3({TypeParam(1), TypeParam(2), TypeParam(3)});
  EXPECT_EQ(tmp_3.size(), 3);
}

TYPED_TEST(ArrayMaxSizeTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1({TypeParam(1)});
  EXPECT_EQ(tmp_1.size(), 1);
  s21::array<TypeParam, 1U> tmp_2{tmp_1};
  EXPECT_EQ(tmp_2.size(), 1);
  s21::array<TypeParam, 1U> tmp_3{std::move(tmp_2)};
  EXPECT_EQ(tmp_3.size(), 1);
  s21::array<TypeParam, 1U> tmp_4{{TypeParam(3)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_EQ(tmp_4.size(), 1);
}

template <class T>
struct ArrayOperatorGetTest : public testing::Test {};

using ArrayOperatorGetTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayOperatorGetTest, ArrayOperatorGetTypes);

TYPED_TEST(ArrayOperatorGetTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};
  const s21::array<TypeParam, 1U> const_a{{value}};

  EXPECT_DOUBLE_EQ(a[0], value);
  EXPECT_DOUBLE_EQ(const_a[0], value);
}

TYPED_TEST(ArrayOperatorGetTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};
  const s21::array<TypeParam, 3U> const_a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(a[0], value_1);
  EXPECT_DOUBLE_EQ(a[1], value_2);
  EXPECT_DOUBLE_EQ(a[2], value_3);

  EXPECT_DOUBLE_EQ(const_a[0], value_1);
  EXPECT_DOUBLE_EQ(const_a[1], value_2);
  EXPECT_DOUBLE_EQ(const_a[2], value_3);
}

template <class T>
struct ArraySizeTest : public testing::Test {};

using ArraySizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArraySizeTest, ArraySizeTypes);

TYPED_TEST(ArraySizeTest, empty) {
  s21::array<TypeParam, 0U> a{};
  std::array<TypeParam, 0U> b{};
  EXPECT_EQ(a.max_size(), b.max_size());
}

TYPED_TEST(ArraySizeTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1_a({});
  std::array<TypeParam, 0U> tmp_1_b({});
  EXPECT_EQ(tmp_1_a.max_size(), tmp_1_b.max_size());

  s21::array<TypeParam, 1U> tmp_2_a({TypeParam(1)});
  std::array<TypeParam, 1U> tmp_2_b({TypeParam(1)});
  EXPECT_EQ(tmp_2_a.max_size(), tmp_2_b.max_size());

  s21::array<TypeParam, 3U> tmp_3_a({TypeParam(1), TypeParam(2), TypeParam(3)});
  std::array<TypeParam, 3U> tmp_3_b({TypeParam(1), TypeParam(2), TypeParam(3)});
  EXPECT_EQ(tmp_3_a.max_size(), tmp_3_b.max_size());
}

TYPED_TEST(ArraySizeTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1_a({TypeParam(1)});
  std::array<TypeParam, 1U> tmp_1_b({TypeParam(1)});
  EXPECT_EQ(tmp_1_a.max_size(), tmp_1_b.max_size());

  s21::array<TypeParam, 1U> tmp_2_a{tmp_1_a};
  std::array<TypeParam, 1U> tmp_2_b{tmp_1_b};
  EXPECT_EQ(tmp_2_a.max_size(), tmp_2_b.max_size());

  s21::array<TypeParam, 1U> tmp_3_a{std::move(tmp_2_a)};
  std::array<TypeParam, 1U> tmp_3_b{std::move(tmp_2_b)};
  EXPECT_EQ(tmp_3_a.max_size(), tmp_3_b.max_size());

  s21::array<TypeParam, 1U> tmp_4_a{{TypeParam(3)}};
  tmp_4_a = std::move(tmp_3_a);
  std::array<TypeParam, 1U> tmp_4_b{{TypeParam(3)}};
  tmp_4_b = std::move(tmp_3_b);
  EXPECT_EQ(tmp_4_a.max_size(), tmp_4_b.max_size());
}

template <class T>
struct ArraySwapTest : public testing::Test {};

using ArraySwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArraySwapTest, ArraySwapTypes);

TYPED_TEST(ArraySwapTest, empty) {
  s21::array<TypeParam, 0U> a{};
  s21::array<TypeParam, 0U> b{};

  a.swap(b);

  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ArraySwapTest, size_1) {
  TypeParam value_1{1};
  TypeParam value_2{2};

  s21::array<TypeParam, 1U> a({value_1});
  s21::array<TypeParam, 1U> b({value_2});

  a.swap(b);

  EXPECT_DOUBLE_EQ(a.front(), value_2);
  EXPECT_DOUBLE_EQ(b.front(), value_1);
}

TYPED_TEST(ArraySwapTest, size_3) {
  TypeParam value_1_1{1};
  TypeParam value_1_2{3};
  TypeParam value_1_3{5};

  TypeParam value_2_1{2};
  TypeParam value_2_2{4};
  TypeParam value_2_3{6};

  s21::array<TypeParam, 3U> a({value_1_1, value_1_2, value_1_3});
  s21::array<TypeParam, 3U> b({value_2_1, value_2_2, value_2_3});

  a.swap(b);

  EXPECT_DOUBLE_EQ(a[0], value_2_1);
  EXPECT_DOUBLE_EQ(a[1], value_2_2);
  EXPECT_DOUBLE_EQ(a[2], value_2_3);

  EXPECT_DOUBLE_EQ(b[0], value_1_1);
  EXPECT_DOUBLE_EQ(b[1], value_1_2);
  EXPECT_DOUBLE_EQ(b[2], value_1_3);
}
