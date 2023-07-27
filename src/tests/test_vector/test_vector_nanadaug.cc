#include "../tests.h"

template <typename T>
struct VectorMaxSizeTest : public testing::Test {
  using Vector = s21::vector<T>;
  using SVector = std::vector<T>;
};

using VectorMaxSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorMaxSizeTest, VectorMaxSizeTypes);

TYPED_TEST(VectorMaxSizeTest, empty_list) {
  using Vector = typename TestFixture::Vector;
  using SVector = typename TestFixture::SVector;

  EXPECT_EQ(Vector().max_size(), SVector().max_size());
}

TYPED_TEST(VectorMaxSizeTest, size_n_list) {
  using Vector = typename TestFixture::Vector;
  using SVector = typename TestFixture::SVector;

  EXPECT_EQ(Vector(11).max_size(), SVector(11).max_size());
}

template <typename T>
struct VectorAtTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorAtTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorAtTest, VectorAtTypes);

TYPED_TEST(VectorAtTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector vector{};

  EXPECT_ANY_THROW((void)vector.at(0U));
  EXPECT_ANY_THROW((void)vector.at(1U));
}

TYPED_TEST(VectorAtTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(11);
  Vector vector({kValue});

  EXPECT_DOUBLE_EQ(vector.at(0), kValue);
  EXPECT_ANY_THROW((void)vector.at(1U));
}

TYPED_TEST(VectorAtTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(33);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_NO_THROW((void)vector.at(0));
  EXPECT_NO_THROW((void)vector.at(1));
  EXPECT_DOUBLE_EQ(vector.at(2), kValue);
  EXPECT_NO_THROW((void)vector.at(3));

  EXPECT_ANY_THROW((void)vector.at(4));
  EXPECT_ANY_THROW((void)vector.at(1000000));
}

TYPED_TEST(VectorAtTest, many_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(10);
  Vector vector({kValue, TypeParam(), TypeParam(), TypeParam()});

  EXPECT_DOUBLE_EQ(vector.at(0), kValue);
  EXPECT_NO_THROW((void)vector.at(1));
  EXPECT_NO_THROW((void)vector.at(2));
  EXPECT_NO_THROW((void)vector.at(3));

  EXPECT_ANY_THROW((void)vector.at(4));
  EXPECT_ANY_THROW((void)vector.at(1000000));
}

TYPED_TEST(VectorAtTest, many_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(19);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), kValue});

  EXPECT_NO_THROW((void)vector.at(0));
  EXPECT_NO_THROW((void)vector.at(1));
  EXPECT_NO_THROW((void)vector.at(2));
  EXPECT_DOUBLE_EQ(vector.at(3), kValue);

  EXPECT_ANY_THROW((void)vector.at(4));
  EXPECT_ANY_THROW((void)vector.at(1000000));
}

template <typename T>
struct VectorBackTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorBackTest, VectorBackTypes);

TYPED_TEST(VectorBackTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(13);
  Vector vector({value});
  EXPECT_DOUBLE_EQ(vector.back(), value);
}

TYPED_TEST(VectorBackTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(14);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), value});
  EXPECT_DOUBLE_EQ(vector.back(), value);
}

template <typename T>
struct VectorCapacityTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorCapacityTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorCapacityTest, VectorCapacityTypes);

TYPED_TEST(VectorCapacityTest, empty) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector().capacity(), 0);
}

TYPED_TEST(VectorCapacityTest, size_n) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector(0).capacity(), 0);
  EXPECT_DOUBLE_EQ(Vector(1).capacity(), 1);
  EXPECT_DOUBLE_EQ(Vector(8).capacity(), 8);
}

TYPED_TEST(VectorCapacityTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector({}).capacity(), 0);
  EXPECT_DOUBLE_EQ(Vector({TypeParam()}).capacity(), 1);
  EXPECT_DOUBLE_EQ(Vector({TypeParam(), TypeParam(), TypeParam()}).capacity(),
                   3);
}

template <typename T>
struct VectorClearTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorClearTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorClearTest, VectorClearTypes);

TYPED_TEST(VectorClearTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  TypeParam value{13};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
  EXPECT_EQ(iter, a.data());

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
}

TYPED_TEST(VectorClearTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  TypeParam value{26};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 14);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
  EXPECT_EQ(iter, a.data());

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
}

TYPED_TEST(VectorClearTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  TypeParam value{98};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.end(), value));
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.back());

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  EXPECT_NO_THROW(a.clear());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);
}

template <typename T>
struct VectorConstructorTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorConstructorTest, VectorConstructorTypes);

TYPED_TEST(VectorConstructorTest, empty) {
  using Vector = typename TestFixture::Vector;
  ASSERT_NO_THROW(Vector());
}

TYPED_TEST(VectorConstructorTest, size_n) {
  using Vector = typename TestFixture::Vector;
  ASSERT_NO_THROW(Vector(0));
  ASSERT_NO_THROW(Vector(1));
  ASSERT_NO_THROW(Vector(8));
}

TYPED_TEST(VectorConstructorTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  ASSERT_NO_THROW(Vector({}));
  ASSERT_NO_THROW(Vector({TypeParam()}));
  ASSERT_NO_THROW(Vector({TypeParam(), TypeParam(), TypeParam()}));
}

TYPED_TEST(VectorConstructorTest, other_constructor) {
  using Vector = typename TestFixture::Vector;

  ASSERT_NO_THROW({
    Vector tmp_1{{TypeParam(1)}};
    Vector tmp_2(tmp_1);
    Vector tmp_3(std::move(tmp_2));
    Vector tmp_4{{TypeParam(4)}};
    tmp_4 = std::move(tmp_3);
  });
}

template <typename T>
struct VectorDataTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorDataTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorDataTest, VectorDataTypes);

TYPED_TEST(VectorDataTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(11);
  Vector vector({kValue});

  EXPECT_EQ(vector.data(), vector.begin());
  EXPECT_DOUBLE_EQ(*(vector.data()), kValue);
}

TYPED_TEST(VectorDataTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(33);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_EQ(vector.data(), vector.begin());
  EXPECT_DOUBLE_EQ(*(vector.data() + 2), kValue);
}

TYPED_TEST(VectorDataTest, many_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(10);
  Vector vector({kValue, TypeParam(), TypeParam(), TypeParam()});

  EXPECT_EQ(vector.data(), vector.begin());

  EXPECT_DOUBLE_EQ(*(vector.data()), kValue);
  EXPECT_NO_THROW((void)*(vector.data() + 1));
  EXPECT_NO_THROW((void)*(vector.data() + 2));
  EXPECT_NO_THROW((void)*(vector.data() + 3));
}

TYPED_TEST(VectorDataTest, many_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(19);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), kValue});

  EXPECT_EQ(vector.data(), vector.begin());

  EXPECT_NO_THROW((void)*(vector.data()));
  EXPECT_NO_THROW((void)*(vector.data() + 1));
  EXPECT_NO_THROW((void)*(vector.data() + 2));
  EXPECT_DOUBLE_EQ(*(vector.data() + 3), kValue);
}

template <typename T>
struct VectorEmptyTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorEmptyTest, VectorEmptyTypes);

TYPED_TEST(VectorEmptyTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_TRUE(a.empty());
}

TYPED_TEST(VectorEmptyTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U);
  EXPECT_TRUE(a.empty());
  Vector b(1U);
  EXPECT_FALSE(b.empty());
  Vector c(8U);
  EXPECT_FALSE(c.empty());
}

TYPED_TEST(VectorEmptyTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a({});
  EXPECT_TRUE(a.empty());

  Vector b({TypeParam()});
  EXPECT_FALSE(b.empty());

  Vector c({TypeParam(), TypeParam(), TypeParam()});
  EXPECT_FALSE(c.empty());
}

template <typename T>
struct VectorEraseTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorEraseTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorEraseTest, VectorEraseTypes);

TYPED_TEST(VectorEraseTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector vector{};

  EXPECT_EQ(vector.capacity(), 0);
  EXPECT_EQ(vector.size(), 0);

  EXPECT_NO_THROW(vector.erase(vector.begin()));
  EXPECT_NO_THROW(vector.erase(vector.end()));

  EXPECT_EQ(vector.capacity(), 0);
  EXPECT_EQ(vector.size(), 0);
}

TYPED_TEST(VectorEraseTest, one_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(91);
  Vector vector({kValue});

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 1);

  EXPECT_NO_THROW(vector.erase(vector.begin()));

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 0);
}

TYPED_TEST(VectorEraseTest, one_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(91);
  Vector vector({kValue});

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 1);

  EXPECT_NO_THROW(vector.erase(vector.end() - 1));

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 0);
}

TYPED_TEST(VectorEraseTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(82);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_EQ(vector.capacity(), 4);
  EXPECT_EQ(vector.size(), 4);

  EXPECT_NO_THROW(vector.erase(vector.begin()));
  EXPECT_NO_THROW(vector.erase(vector.begin()));

  EXPECT_EQ(vector.capacity(), 4);
  EXPECT_EQ(vector.size(), 2);
  EXPECT_DOUBLE_EQ(*(vector.data()), kValue);
}

template <typename T>
struct VectorFrontTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorFrontTest, VectorFrontTypes);

TYPED_TEST(VectorFrontTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(11);
  Vector vector({value});
  EXPECT_DOUBLE_EQ(vector.front(), value);
}

TYPED_TEST(VectorFrontTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(12);
  Vector vector({value, TypeParam(), TypeParam(), TypeParam()});
  EXPECT_DOUBLE_EQ(vector.front(), value);
}

template <typename T>
struct VectorInsertTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorInsertTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorInsertTest, VectorInsertTypes);

TYPED_TEST(VectorInsertTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  TypeParam value{13};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
  EXPECT_EQ(iter, a.data());
}

TYPED_TEST(VectorInsertTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  TypeParam value{26};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 14);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
  EXPECT_EQ(iter, a.data());
}

TYPED_TEST(VectorInsertTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  TypeParam value{98};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.end(), value));
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.back());

  EXPECT_DOUBLE_EQ(a.size(), 14);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
}

template <typename T>
struct VectorOperatorGetTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorOperatorGetTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorOperatorGetTest, VectorOperatorGetTypes);

TYPED_TEST(VectorOperatorGetTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(11);
  Vector vector({kValue});

  EXPECT_DOUBLE_EQ(vector[0], kValue);
}

TYPED_TEST(VectorOperatorGetTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(33);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_NO_THROW((void)vector[0]);
  EXPECT_NO_THROW((void)vector[1]);
  EXPECT_DOUBLE_EQ(vector[2], kValue);
  EXPECT_NO_THROW((void)vector[3]);
}

TYPED_TEST(VectorOperatorGetTest, many_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(10);
  Vector vector({kValue, TypeParam(), TypeParam(), TypeParam()});

  EXPECT_DOUBLE_EQ(vector[0], kValue);
  EXPECT_NO_THROW((void)vector[1]);
  EXPECT_NO_THROW((void)vector[2]);
  EXPECT_NO_THROW((void)vector[3]);
}

TYPED_TEST(VectorOperatorGetTest, many_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(19);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), kValue});

  EXPECT_NO_THROW((void)vector[0]);
  EXPECT_NO_THROW((void)vector[1]);
  EXPECT_NO_THROW((void)vector[2]);
  EXPECT_DOUBLE_EQ(vector[3], kValue);
}

template <typename T>
struct VectorPopBackTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorPopBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorPopBackTest, VectorPopBackTypes);

TYPED_TEST(VectorPopBackTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  ASSERT_NO_THROW(a.pop_back());

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);
}

TYPED_TEST(VectorPopBackTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(11);

  EXPECT_DOUBLE_EQ(a.size(), 11);
  EXPECT_DOUBLE_EQ(a.capacity(), 11);

  ASSERT_NO_THROW(a.pop_back());

  EXPECT_DOUBLE_EQ(a.size(), 10);
  EXPECT_DOUBLE_EQ(a.capacity(), 11);
}

TYPED_TEST(VectorPopBackTest, size_n_2) {
  using Vector = typename TestFixture::Vector;
  Vector a(1);

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);

  ASSERT_NO_THROW(a.pop_back());

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
}

template <typename T>
struct VectorPushBackTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorPushBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorPushBackTest, VectorPushBackTypes);

TYPED_TEST(VectorPushBackTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  TypeParam value{32};

  ASSERT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
}

TYPED_TEST(VectorPushBackTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(81);

  EXPECT_DOUBLE_EQ(a.size(), 81);
  EXPECT_DOUBLE_EQ(a.capacity(), 81);

  TypeParam value{34};

  ASSERT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);

  EXPECT_DOUBLE_EQ(a.size(), 82);
  EXPECT_DOUBLE_EQ(a.capacity(), 162);
}

TYPED_TEST(VectorPushBackTest, size_n_2) {
  using Vector = typename TestFixture::Vector;
  Vector a(3);

  EXPECT_DOUBLE_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.capacity(), 3);

  TypeParam value{35};

  ASSERT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);

  EXPECT_DOUBLE_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.capacity(), 6);
}

template <typename T>
struct VectorReserveTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorReserveTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorReserveTest, VectorReserveTypes);

TYPED_TEST(VectorReserveTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};
  EXPECT_EQ(a.capacity(), 0);
  a.reserve(100U);
  EXPECT_EQ(a.capacity(), 100);
}

TYPED_TEST(VectorReserveTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U);
  EXPECT_EQ(a.capacity(), 0);
  a.reserve(1U);
  EXPECT_EQ(a.capacity(), 1);

  Vector b(1U);
  EXPECT_EQ(b.capacity(), 1);
  b.reserve(0U);
  EXPECT_EQ(b.capacity(), 1);
  b.reserve(10U);
  EXPECT_EQ(b.capacity(), 10);

  Vector c(8U);
  EXPECT_EQ(c.capacity(), 8);
  c.reserve(2U);
  EXPECT_EQ(c.capacity(), 8);
}

TYPED_TEST(VectorReserveTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a({});
  EXPECT_EQ(a.capacity(), 0);
  a.reserve(0U);
  EXPECT_EQ(a.capacity(), 0);

  Vector b({TypeParam()});
  EXPECT_EQ(b.capacity(), 1);
  b.reserve(1U);
  EXPECT_EQ(b.capacity(), 1);

  Vector c({TypeParam(), TypeParam(), TypeParam()});
  EXPECT_EQ(c.capacity(), 3);
  c.reserve(0U);
  EXPECT_EQ(c.capacity(), 3);
}

template <typename T>
struct VectorShrinkTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorShrinkTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorShrinkTest, VectorShrinkTypes);

TYPED_TEST(VectorShrinkTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};
  EXPECT_NO_THROW(a.shrink_to_fit());

  EXPECT_DOUBLE_EQ(a.capacity(), 0);
}

TYPED_TEST(VectorShrinkTest, size_n) {
  using Vector = typename TestFixture::Vector;

  Vector a(1U);
  a.reserve(100U);
  EXPECT_NO_THROW(a.shrink_to_fit());
  EXPECT_DOUBLE_EQ(a.capacity(), 1);

  Vector b(8U);
  b.reserve(16U);
  EXPECT_NO_THROW(b.shrink_to_fit());
  EXPECT_DOUBLE_EQ(b.capacity(), 8);
}

TYPED_TEST(VectorShrinkTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector({}).capacity(), 0);

  Vector a{{TypeParam()}};
  a.reserve(2U);
  EXPECT_NO_THROW(a.shrink_to_fit());
  EXPECT_DOUBLE_EQ(a.capacity(), 1);

  Vector b{{TypeParam(), TypeParam(), TypeParam()}};
  b.reserve(6U);
  EXPECT_NO_THROW(b.shrink_to_fit());
  EXPECT_DOUBLE_EQ(b.capacity(), 3);
}

template <typename T>
struct VectorSizeTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorSizeTest, VectorSizeTypes);

TYPED_TEST(VectorSizeTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(VectorSizeTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U);
  EXPECT_EQ(a.size(), 0);

  Vector b(1U);
  EXPECT_EQ(b.size(), 1);

  Vector c(8U);
  EXPECT_EQ(c.size(), 8);
}

TYPED_TEST(VectorSizeTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a({});
  EXPECT_EQ(a.size(), 0);

  Vector b({TypeParam()});
  EXPECT_EQ(b.size(), 1);

  Vector c({TypeParam(), TypeParam(), TypeParam()});
  EXPECT_EQ(c.size(), 3);
}

template <typename T>
struct VectorSwapTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorSwapTest, VectorSwapTypes);

TYPED_TEST(VectorSwapTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{}, b{};
  EXPECT_NO_THROW(a.swap(b));
}

TYPED_TEST(VectorSwapTest, size_0) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U), b(0U);
  EXPECT_NO_THROW(a.swap(b));
}

TYPED_TEST(VectorSwapTest, size_1) {
  using Vector = typename TestFixture::Vector;
  Vector a(1), b(1);
  EXPECT_NO_THROW(a.swap(b));
}

TYPED_TEST(VectorSwapTest, size_8) {
  using Vector = typename TestFixture::Vector;
  Vector a(4), b(8);
  EXPECT_NO_THROW(a.swap(b));

  EXPECT_EQ(a.size(), 8);
  EXPECT_EQ(b.size(), 4);
}

TYPED_TEST(VectorSwapTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(14);

  Vector a{}, b{{value}};

  EXPECT_NO_THROW(b.swap(a));

  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(b.size(), 0);

  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_EQ(b.begin(), b.end());
}
