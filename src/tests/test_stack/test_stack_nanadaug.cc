#include "../tests.h"

template <typename T>
struct StackConstructorTest : public testing::Test {
  using Stack = s21::stack<T>;
  using StdStack = std::stack<T>;
};

using StackConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackConstructorTest, StackConstructorTypes);

TYPED_TEST(StackConstructorTest, empty) {
  using Stack = typename TestFixture::Stack;
  ASSERT_NO_THROW(Stack());
}

TYPED_TEST(StackConstructorTest, initializer_list) {
  using Stack = typename TestFixture::Stack;
  ASSERT_NO_THROW(Stack({}));
  ASSERT_NO_THROW(Stack({TypeParam()}));
  ASSERT_NO_THROW(Stack({TypeParam(), TypeParam(), TypeParam()}));
}

TYPED_TEST(StackConstructorTest, other_constructor) {
  using Stack = typename TestFixture::Stack;

  ASSERT_NO_THROW({
    Stack tmp_1{{TypeParam(1)}};
    Stack tmp_2(tmp_1);
    Stack tmp_3(std::move(tmp_2));
    Stack tmp_4{{TypeParam(4)}};
    tmp_4 = std::move(tmp_3);
  });
}

template <typename T>
struct StackEmptyTest : public testing::Test {
  using Stack = s21::stack<T>;
  using StdStack = std::stack<T>;
};

using StackEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackEmptyTest, StackEmptyTypes);

TYPED_TEST(StackEmptyTest, empty) {
  using Stack = typename TestFixture::Stack;
  EXPECT_TRUE(Stack().empty());
}

TYPED_TEST(StackEmptyTest, initializer_list) {
  using Stack = typename TestFixture::Stack;
  EXPECT_TRUE(Stack({}).empty());
  EXPECT_FALSE(Stack({TypeParam()}).empty());
  EXPECT_FALSE(Stack({TypeParam(), TypeParam(), TypeParam()}).empty());
}

TYPED_TEST(StackEmptyTest, other_constructor) {
  using Stack = typename TestFixture::Stack;

  Stack tmp_1{{TypeParam(1)}};
  EXPECT_FALSE(tmp_1.empty());
  Stack tmp_2(tmp_1);
  EXPECT_FALSE(tmp_1.empty());
  EXPECT_FALSE(tmp_2.empty());
  Stack tmp_3(std::move(tmp_2));
  EXPECT_FALSE(tmp_3.empty());
  Stack tmp_4{{TypeParam(4)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_FALSE(tmp_4.empty());
}

template <class T>
struct StackPopTest : public testing::Test {
  using Stack = s21::stack<T>;
  using StdStack = std::stack<T>;
};

using StackPopTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackPopTest, StackPopTypes);

TYPED_TEST(StackPopTest, empty) {
  using Stack = typename TestFixture::Stack;

  Stack a{};
  EXPECT_NO_THROW(a.pop());
}

TYPED_TEST(StackPopTest, one_item) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);

  Stack a{{value_1}};
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), value_1);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(StackPopTest, many_item) {
  using Stack = typename TestFixture::Stack;
  using StdStack = typename TestFixture::StdStack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{{value_1, value_2, value_3}};
  StdStack b{{value_1, value_2, value_3}};
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.top(), b.top());

  EXPECT_NO_THROW(a.pop());
  b.pop();
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), b.top());

  EXPECT_NO_THROW(a.pop());
  b.pop();
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), b.top());

  EXPECT_NO_THROW(a.pop());
  b.pop();
  EXPECT_EQ(a.size(), 0);
}

template <class T>
struct StackPushTest : public testing::Test {
  using Stack = s21::stack<T>;
  using StdStack = std::stack<T>;
};

using StackPushTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackPushTest, StackPushTypes);

TYPED_TEST(StackPushTest, empty) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{};
  EXPECT_EQ(a.size(), 0);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
}

TYPED_TEST(StackPushTest, one_item) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{{TypeParam()}};
  EXPECT_EQ(a.size(), 1);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.top(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
}

TYPED_TEST(StackPushTest, many_item) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{{TypeParam(), TypeParam(), TypeParam()}};
  EXPECT_EQ(a.size(), 3);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.top(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 5);
  EXPECT_DOUBLE_EQ(a.top(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 6);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
}

template <typename T>
struct StackSizeTest : public testing::Test {
  using Stack = s21::stack<T>;
  using StdStack = std::stack<T>;
};

using StackSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackSizeTest, StackSizeTypes);

TYPED_TEST(StackSizeTest, empty) {
  using Stack = typename TestFixture::Stack;
  EXPECT_EQ(Stack().size(), 0);
}

TYPED_TEST(StackSizeTest, initializer_list) {
  using Stack = typename TestFixture::Stack;
  EXPECT_EQ(Stack({}).size(), 0);
  EXPECT_EQ(Stack({TypeParam()}).size(), 1);
  EXPECT_EQ(Stack({TypeParam(), TypeParam(), TypeParam()}).size(), 3);
}

TYPED_TEST(StackSizeTest, other_constructor) {
  using Stack = typename TestFixture::Stack;

  Stack tmp_1{{TypeParam(1)}};
  EXPECT_EQ(tmp_1.size(), 1);
  Stack tmp_2(tmp_1);
  EXPECT_EQ(tmp_1.size(), 1);
  EXPECT_EQ(tmp_2.size(), 1);
  Stack tmp_3(std::move(tmp_2));
  EXPECT_EQ(tmp_3.size(), 1);
  Stack tmp_4{{TypeParam(4)}};
  EXPECT_EQ(tmp_4.size(), 1);
  tmp_4 = std::move(tmp_3);
  EXPECT_EQ(tmp_4.size(), 1);
}

template <typename T>
struct StackSwapTest : public testing::Test {
  using Stack = s21::stack<T>;
  using StdStack = std::stack<T>;
};

using StackSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackSwapTest, StackSwapTypes);

TYPED_TEST(StackSwapTest, empty) {
  using Stack = typename TestFixture::Stack;
  Stack a{};
  Stack b{};

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

template <typename T>
struct StackTopTest : public testing::Test {
  using Stack = s21::stack<T>;
  using StdStack = std::stack<T>;
};

using StackTopTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackTopTest, StackTopTypes);

TYPED_TEST(StackTopTest, size_1) {
  using Stack = typename TestFixture::Stack;
  TypeParam value(88);
  Stack a{{value}};

  EXPECT_DOUBLE_EQ(a.top(), value);
}


TYPED_TEST(StackTopTest, size_3) {
  using Stack = typename TestFixture::Stack;
  using StdStack = typename TestFixture::StdStack;
  TypeParam value(88);
  Stack a{{value, TypeParam(1), TypeParam(2)}};
  StdStack b{{value, TypeParam(1), TypeParam(2)}};

  EXPECT_DOUBLE_EQ(a.top(), b.top());
}
