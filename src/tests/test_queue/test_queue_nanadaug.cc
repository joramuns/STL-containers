#include "../tests.h"

template <typename T>
struct QueueBackTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueBackTest, QueueBackTypes);

TYPED_TEST(QueueBackTest, size_1) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value}};

  EXPECT_DOUBLE_EQ(a.back(), value);
}

TYPED_TEST(QueueBackTest, size_2) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{TypeParam(1), value}};

  EXPECT_DOUBLE_EQ(a.back(), value);
}

TYPED_TEST(QueueBackTest, size_3) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{TypeParam(1), TypeParam(2), value}};

  EXPECT_DOUBLE_EQ(a.back(), value);
}

template <typename T>
struct QueueConstructorTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueConstructorTest, QueueConstructorTypes);

TYPED_TEST(QueueConstructorTest, empty) {
  using Queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(Queue());
}

TYPED_TEST(QueueConstructorTest, initializer_list) {
  using Queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(Queue({}));
  ASSERT_NO_THROW(Queue({TypeParam()}));
  ASSERT_NO_THROW(Queue({TypeParam(), TypeParam(), TypeParam()}));
}

TYPED_TEST(QueueConstructorTest, other_constructor) {
  using Queue = typename TestFixture::Queue;

  ASSERT_NO_THROW({
    Queue tmp_1{{TypeParam(1)}};
    Queue tmp_2(tmp_1);
    Queue tmp_3(std::move(tmp_2));
    Queue tmp_4{{TypeParam(4)}};
    tmp_4 = std::move(tmp_3);
  });
}

template <typename T>
struct QueueEmptyTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueEmptyTest, QueueEmptyTypes);

TYPED_TEST(QueueEmptyTest, empty) {
  using Queue = typename TestFixture::Queue;
  EXPECT_TRUE(Queue().empty());
}

TYPED_TEST(QueueEmptyTest, initializer_list) {
  using Queue = typename TestFixture::Queue;
  EXPECT_TRUE(Queue({}).empty());
  EXPECT_FALSE(Queue({TypeParam()}).empty());
  EXPECT_FALSE(Queue({TypeParam(), TypeParam(), TypeParam()}).empty());
}

TYPED_TEST(QueueEmptyTest, other_constructor) {
  using Queue = typename TestFixture::Queue;

  Queue tmp_1{{TypeParam(1)}};
  EXPECT_FALSE(tmp_1.empty());
  Queue tmp_2(tmp_1);
  EXPECT_FALSE(tmp_1.empty());
  EXPECT_FALSE(tmp_2.empty());
  Queue tmp_3(std::move(tmp_2));
  EXPECT_FALSE(tmp_3.empty());
  Queue tmp_4{{TypeParam(4)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_FALSE(tmp_4.empty());
}

template <typename T>
struct QueueFrontTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueFrontTest, QueueFrontTypes);

TYPED_TEST(QueueFrontTest, size_1) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(QueueFrontTest, size_2) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value, TypeParam(1)}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(QueueFrontTest, size_3) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value, TypeParam(1), TypeParam(2)}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}

template <class T>
struct QueuePopTest : public testing::Test {
  using Queue = s21::queue<T>;
  using StdQueue = std::queue<T>;
};

using QueuePopTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueuePopTest, QueuePopTypes);

TYPED_TEST(QueuePopTest, empty) {
  using Queue = typename TestFixture::Queue;
  using StdQueue = typename TestFixture::StdQueue;

  Queue a{};
  StdQueue b{};
  EXPECT_NO_THROW(a.pop());
  EXPECT_NO_THROW(b.pop());
}

TYPED_TEST(QueuePopTest, one_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);

  Queue a{{value_1}};
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(QueuePopTest, many_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{{value_1, value_2, value_3}};
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.front(), value_1);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.front(), value_2);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_3);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}

template <class T>
struct QueuePushTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueuePushTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueuePushTest, QueuePushTypes);

TYPED_TEST(QueuePushTest, empty) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{};
  EXPECT_EQ(a.size(), 0);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.back(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
}

TYPED_TEST(QueuePushTest, one_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{{TypeParam()}};
  EXPECT_EQ(a.size(), 1);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.back(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.back(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
}

TYPED_TEST(QueuePushTest, many_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{{TypeParam(), TypeParam(), TypeParam()}};
  EXPECT_EQ(a.size(), 3);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.back(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 5);
  EXPECT_DOUBLE_EQ(a.back(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 6);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
}

template <typename T>
struct QueueSizeTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueSizeTest, QueueSizeTypes);

TYPED_TEST(QueueSizeTest, empty) {
  using Queue = typename TestFixture::Queue;
  EXPECT_EQ(Queue().size(), 0);
}

TYPED_TEST(QueueSizeTest, initializer_list) {
  using Queue = typename TestFixture::Queue;
  EXPECT_EQ(Queue({}).size(), 0);
  EXPECT_EQ(Queue({TypeParam()}).size(), 1);
  EXPECT_EQ(Queue({TypeParam(), TypeParam(), TypeParam()}).size(), 3);
}

TYPED_TEST(QueueSizeTest, other_constructor) {
  using Queue = typename TestFixture::Queue;

  Queue tmp_1{{TypeParam(1)}};
  EXPECT_EQ(tmp_1.size(), 1);
  Queue tmp_2(tmp_1);
  EXPECT_EQ(tmp_1.size(), 1);
  EXPECT_EQ(tmp_2.size(), 1);
  Queue tmp_3(std::move(tmp_2));
  EXPECT_EQ(tmp_3.size(), 1);
  Queue tmp_4{{TypeParam(4)}};
  EXPECT_EQ(tmp_4.size(), 1);
  tmp_4 = std::move(tmp_3);
  EXPECT_EQ(tmp_4.size(), 1);
}

template <typename T>
struct QueueSwapTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueSwapTest, QueueSwapTypes);

TYPED_TEST(QueueSwapTest, empty) {
  using Queue = typename TestFixture::Queue;
  Queue a{};
  Queue b{};

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}
