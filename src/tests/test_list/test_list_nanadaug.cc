#include "../tests.h"

template <typename T>
struct ListBackTest : public testing::Test {
  using List = s21::list<T>;
};

using ListBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListBackTest, ListBackTypes);

TYPED_TEST(ListBackTest, one_item) {
  using List = typename TestFixture::List;
  TypeParam value{110};
  EXPECT_DOUBLE_EQ(List({value}).back(), value);
}

TYPED_TEST(ListBackTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value{91};
  EXPECT_DOUBLE_EQ(List({TypeParam(), TypeParam(), value}).back(), value);
}

template <typename T>
struct ListClearTest : public testing::Test {
  using List = s21::list<T>;
};

using ListClearTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListClearTest, ListClearTypes);

TYPED_TEST(ListClearTest, empty_list) {
  using List = typename TestFixture::List;
  List a{};
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());
}

TYPED_TEST(ListClearTest, size_n_list) {
  using List = typename TestFixture::List;
  List a(0U);
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());

  a = List(4U);
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());

  a = List(16U);
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());
}

template <typename T>
struct ListConstructorTest : public testing::Test {
  using List = s21::list<T>;
};

using ListConstructTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListConstructorTest, ListConstructTypes);

TYPED_TEST(ListConstructorTest, empty) {
  using List = typename TestFixture::List;
  ASSERT_NO_THROW(List());
}

TYPED_TEST(ListConstructorTest, size_n) {
  using List = typename TestFixture::List;
  ASSERT_NO_THROW(List(0U));
  ASSERT_NO_THROW(List(1U));
  ASSERT_NO_THROW(List(8U));
}

TYPED_TEST(ListConstructorTest, initializer_list) {
  using List = typename TestFixture::List;
  ASSERT_NO_THROW(List({}));
  ASSERT_NO_THROW(List({TypeParam()}));
  ASSERT_NO_THROW(List({TypeParam(), TypeParam(), TypeParam()}));
}

TYPED_TEST(ListConstructorTest, other_constructor) {
  using List = typename TestFixture::List;

  ASSERT_NO_THROW({
    List tmp_1{{TypeParam(1)}};
    List tmp_2(tmp_1);
    List tmp_3(std::move(tmp_2));
    List tmp_4{{TypeParam(4)}};
    tmp_4 = std::move(tmp_3);
  });
}

template <typename T>
struct ListEmptyTest : public testing::Test {
  using List = s21::list<T>;
};

using ListEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListEmptyTest, ListEmptyTypes);

TYPED_TEST(ListEmptyTest, empty_list) {
  using List = typename TestFixture::List;
  EXPECT_TRUE(List().empty());
}

TYPED_TEST(ListEmptyTest, not_empty_list) {
  using List = typename TestFixture::List;
  EXPECT_TRUE(List(0).empty());
  EXPECT_TRUE(List({}).empty());
  EXPECT_FALSE(List(4).empty());
  EXPECT_FALSE(List({TypeParam()}).empty());
}

TYPED_TEST(ListEmptyTest, cleared_list) {
  using List = typename TestFixture::List;
  List a = List(0U);
  a.clear();
  ASSERT_TRUE(a.empty());

  a = List({});
  a.clear();
  ASSERT_TRUE(a.empty());

  a = List(4U);
  a.clear();
  ASSERT_TRUE(a.empty());

  a = List({TypeParam(), TypeParam(), TypeParam()});
  a.clear();
  ASSERT_TRUE(a.empty());
}

template <typename T>
struct ListEraseTest : public testing::Test {
  using List = s21::list<T>;
};

using ListEraseTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListEraseTest, ListEraseTypes);

TYPED_TEST(ListEraseTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  /* EXPECT_NO_THROW(a.erase(a.begin())); */
  /* EXPECT_NO_THROW(a.erase(a.end())); */
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ListEraseTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});

  EXPECT_NO_THROW(a.erase(a.begin()));
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ListEraseTest, many_item_1) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});

  EXPECT_NO_THROW(a.erase(a.begin()));
  EXPECT_EQ(a.size(), 2);
}

TYPED_TEST(ListEraseTest, many_item_2) {
  using List = typename TestFixture::List;
  TypeParam value(7);
  List a({TypeParam(), TypeParam(), value});
  auto iter = --a.end();
  auto iter_2 = iter;
  --iter_2;

  EXPECT_NO_THROW(a.erase(iter_2));
  EXPECT_EQ(*iter, value);
  EXPECT_EQ(a.size(), 2);
}

template <typename T>
struct ListFrontTest : public testing::Test {
  using List = s21::list<T>;
};

using ListFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListFrontTest, ListFrontTypes);

TYPED_TEST(ListFrontTest, empty_list) {
  using List = typename TestFixture::List;
  EXPECT_NO_THROW((void)List().front());
}

TYPED_TEST(ListFrontTest, one_item) {
  using List = typename TestFixture::List;
  TypeParam value{110};
  EXPECT_DOUBLE_EQ(List({value}).front(), value);
}

TYPED_TEST(ListFrontTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value{33};
  EXPECT_DOUBLE_EQ(List({value, TypeParam(), TypeParam()}).front(), value);
}

template <typename T>
struct ListInsertTest : public testing::Test {
  using List = s21::list<T>;
};

using ListInsertTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListInsertTest, ListInsertTypes);

TYPED_TEST(ListInsertTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  typename List::iterator iter;
  const TypeParam kValue(16);

  EXPECT_NO_THROW(iter = a.insert(a.begin(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*a.begin(), kValue);
  EXPECT_EQ(a.size(), 1);
}

TYPED_TEST(ListInsertTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(13);

  EXPECT_NO_THROW(iter = a.insert(a.begin(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*a.begin(), kValue);
  EXPECT_EQ(a.size(), 2);
}

TYPED_TEST(ListInsertTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(13);

  EXPECT_NO_THROW(iter = a.insert(a.begin(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*a.begin(), kValue);
  EXPECT_EQ(a.size(), 4);
}

TYPED_TEST(ListInsertTest, empty_insert_end) {
  using List = typename TestFixture::List;
  List a{};
  typename List::iterator iter;
  const TypeParam kValue(16);

  EXPECT_NO_THROW(iter = a.insert(a.end(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*(--a.end()), kValue);
  EXPECT_EQ(a.size(), 1);
}

TYPED_TEST(ListInsertTest, one_item_insert_end) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(78);

  EXPECT_NO_THROW(iter = a.insert(a.end(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*(--a.end()), kValue);
  EXPECT_EQ(a.size(), 2);
}

TYPED_TEST(ListInsertTest, many_item_insert_end) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(99);

  EXPECT_NO_THROW(iter = a.insert(a.end(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*(--a.end()), kValue);
  EXPECT_EQ(a.size(), 4);
}

TYPED_TEST(ListInsertTest, many_item_insert_middle) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  typename List::iterator iter = a.begin();
  typename List::iterator iter_2;
  ++iter;
  ++iter;
  const TypeParam kValue(69);

  EXPECT_NO_THROW(iter_2 = a.insert(iter, kValue));
  EXPECT_DOUBLE_EQ(*(--iter), kValue);
  EXPECT_DOUBLE_EQ(*iter_2, kValue);
  EXPECT_EQ(a.size(), 4);
}

template <typename T>
struct ListMergeTest : public testing::Test {
  using List = s21::list<T>;
};

using ListConstructTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListMergeTest, ListConstructTypes);

TYPED_TEST(ListMergeTest, empty) {
  using List = typename TestFixture::List;

  List a{};
  List b{};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListMergeTest, size_0_1) {
  using List = typename TestFixture::List;
  TypeParam value(1);

  List a{};
  List b{{value}};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListMergeTest, size_1_0) {
  using List = typename TestFixture::List;
  TypeParam value(1);

  List a{{value}};
  List b{};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListMergeTest, size_1_1) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);

  List a{{value_1}};
  List b{{value_2}};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_DOUBLE_EQ(*(++a.begin()), value_2);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListMergeTest, size_0_3) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a{};
  List b{{value_1, value_2, value_3}};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  auto iter = a.begin();
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_2);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_3);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListMergeTest, size_3_0) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a{{value_1, value_2, value_3}};
  List b{};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  auto iter = a.begin();
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_2);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_3);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListMergeTest, size_3_3) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);
  TypeParam value_4(4);
  TypeParam value_5(5);
  TypeParam value_6(6);

  List a{{value_1, value_3, value_5}};
  List b{{value_2, value_4, value_6}};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 6);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  auto iter = a.begin();
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_2);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_3);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_4);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_5);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_6);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListMergeTest, size_3_2) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);
  TypeParam value_4(4);
  TypeParam value_5(5);

  List a{{value_1, value_3, value_5}};
  List b{{value_2, value_4}};

  EXPECT_NO_THROW(a.merge(b));
  EXPECT_EQ(a.size(), 5);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  auto iter = a.begin();
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_2);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_3);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_4);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_5);

  EXPECT_EQ(b.size(), 0);
}

template <class T>
struct ListPopBackTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPopBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPopBackTest, ListPopBackTypes);

TYPED_TEST(ListPopBackTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  /* EXPECT_NO_THROW(a.pop_back()); */
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopBackTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});

  EXPECT_NO_THROW(a.pop_back());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopBackTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value(121);
  List a({TypeParam(), value, TypeParam()});

  EXPECT_NO_THROW(a.pop_back());
  EXPECT_DOUBLE_EQ(*(--a.end()), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}

template <class T>
struct ListPopFrontTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPopFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPopFrontTest, ListPopFrontTypes);

TYPED_TEST(ListPopFrontTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  /* EXPECT_NO_THROW(a.pop_front()); */
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopFrontTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});

  EXPECT_NO_THROW(a.pop_front());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopFrontTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value(51);
  List a({TypeParam(), value, TypeParam()});

  EXPECT_NO_THROW(a.pop_front());
  EXPECT_DOUBLE_EQ(*a.begin(), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}

template <class T>
struct ListPushBackTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPushBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPushBackTest, ListPushBackTypes);

TYPED_TEST(ListPushBackTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  TypeParam value(81);

  EXPECT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);
  EXPECT_DOUBLE_EQ(a.size(), 1);
}

TYPED_TEST(ListPushBackTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  TypeParam value(11);

  EXPECT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);
  EXPECT_DOUBLE_EQ(*(++a.begin()), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}

TYPED_TEST(ListPushBackTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  TypeParam value(39);

  EXPECT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);
  EXPECT_DOUBLE_EQ(a.size(), 4);
}

template <class T>
struct ListPushFrontTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPushFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPushFrontTest, ListPushFrontTypes);

TYPED_TEST(ListPushFrontTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  TypeParam value(81);

  EXPECT_NO_THROW(a.push_front(value));
  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_DOUBLE_EQ(a.size(), 1);
}

TYPED_TEST(ListPushFrontTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  TypeParam value(11);

  EXPECT_NO_THROW(a.push_front(value));
  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_DOUBLE_EQ(*a.begin(), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}

TYPED_TEST(ListPushFrontTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  TypeParam value(39);

  EXPECT_NO_THROW(a.push_front(value));
  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_DOUBLE_EQ(a.size(), 4);
}

template <class T>
struct ListReverseTest : public testing::Test {
  using List = s21::list<T>;
};

using ListReverseTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListReverseTest, ListReverseTypes);

TYPED_TEST(ListReverseTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  EXPECT_NO_THROW(a.reverse());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListReverseTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(1)});

  EXPECT_NO_THROW(a.reverse());
  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(*a.begin(), TypeParam(1));
  EXPECT_DOUBLE_EQ(*(--a.end()), TypeParam(1));
}

TYPED_TEST(ListReverseTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(2), TypeParam(3), TypeParam(4)});

  EXPECT_NO_THROW(a.reverse());
  EXPECT_DOUBLE_EQ(a.size(), 4);

  EXPECT_DOUBLE_EQ(a.front(), 4);
  EXPECT_DOUBLE_EQ(a.back(), 1);
  EXPECT_DOUBLE_EQ(*(a.begin()), 4);
  EXPECT_DOUBLE_EQ(*(--a.end()), 1);

  int k = 4;
  for (auto iter = a.begin(); iter != a.end(); ++iter, --k) {
    EXPECT_DOUBLE_EQ(*iter, TypeParam(k));
  }
}

template <typename T>
struct ListSizeTest : public testing::Test {
  using List = s21::list<T>;
};

using ListSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSizeTest, ListSizeTypes);

TYPED_TEST(ListSizeTest, empty) {
  using List = typename TestFixture::List;
  EXPECT_EQ(List().size(), 0);
}

TYPED_TEST(ListSizeTest, size_n) {
  using List = typename TestFixture::List;
  EXPECT_EQ(List(0).size(), 0);
  EXPECT_EQ(List(1).size(), 1);
  EXPECT_EQ(List(8).size(), 8);
}

TYPED_TEST(ListSizeTest, initializer_list) {
  using List = typename TestFixture::List;
  EXPECT_EQ(List({}).size(), 0);
  EXPECT_EQ(List({TypeParam()}).size(), 1);
  EXPECT_EQ(List({TypeParam(), TypeParam(), TypeParam()}).size(), 3);
}

template <typename T>
struct ListSpliceTest : public testing::Test {
  using List = s21::list<T>;
};

using ListConstructTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSpliceTest, ListConstructTypes);

TYPED_TEST(ListSpliceTest, empty) {
  using List = typename TestFixture::List;

  List a{};
  List b{};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);

  EXPECT_NO_THROW(a.splice(a.end(), b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_0_1) {
  using List = typename TestFixture::List;
  TypeParam value(1);

  List a{};
  List b{{value}};

  EXPECT_NO_THROW(a.splice(a.end(), b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_1_0) {
  using List = typename TestFixture::List;
  TypeParam value(1);

  List a{{value}};
  List b{};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);

  EXPECT_NO_THROW(a.splice(a.end(), b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_1_1) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);

  List a{{value_1}};
  List b{{value_2}};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.front(), value_2);
  EXPECT_DOUBLE_EQ(*(++a.begin()), value_1);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_0_3) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a{};
  List b{{value_1, value_2, value_3}};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  auto iter = a.begin();
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_2);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_3);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_3_3) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);
  TypeParam value_4(4);
  TypeParam value_5(5);
  TypeParam value_6(6);

  List a{{value_1, value_3, value_5}};
  List b{{value_2, value_4, value_6}};

  auto iter = a.begin();
  ++iter;
  ++iter;
  EXPECT_NO_THROW(a.splice(iter, b));
  EXPECT_EQ(a.size(), 6);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  iter = a.begin();
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_3);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_2);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_4);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_6);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_5);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_3_2) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);
  TypeParam value_4(4);
  TypeParam value_5(5);

  List a{{value_1, value_3, value_5}};
  List b{{value_2, value_4}};

  EXPECT_NO_THROW(a.splice(++a.begin(), b));
  EXPECT_EQ(a.size(), 5);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  auto iter = a.begin();
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_2);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_4);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_3);
  ++iter;
  EXPECT_DOUBLE_EQ(*(iter), value_5);

  EXPECT_EQ(b.size(), 0);
}

template <typename T>
struct ListSwapTest : public testing::Test {
  using List = s21::list<T>;
};

using ListSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSwapTest, ListSwapTypes);

TYPED_TEST(ListSwapTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  List b{};

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
  EXPECT_EQ(b.begin(), b.end());
}

TYPED_TEST(ListSwapTest, one_item) {
  using List = typename TestFixture::List;
  List a(1U);
  List b(1U);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 1U);
  EXPECT_EQ(b.size(), 1U);
  EXPECT_NE(a.begin(), a.end());
  EXPECT_NE(b.begin(), b.end());
}

TYPED_TEST(ListSwapTest, many_item) {
  using List = typename TestFixture::List;
  List a(8U);
  List b(16U);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 16U);
  EXPECT_EQ(b.size(), 8U);
  EXPECT_NE(a.begin(), a.end());
  EXPECT_NE(b.begin(), b.end());
}

template <class T>
struct ListUniqueTest : public testing::Test {
  using List = s21::list<T>;
};

using ListUniqueTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListUniqueTest, ListUniqueTypes);

TYPED_TEST(ListUniqueTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListUniqueTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(1)});

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), TypeParam(1));
}

TYPED_TEST(ListUniqueTest, many_item_1) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(1), TypeParam(1)});

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), TypeParam(1));
}

TYPED_TEST(ListUniqueTest, many_item_2) {
  using List = typename TestFixture::List;
  List a(
      {TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(1), TypeParam(1)});
  TypeParam b[] = {1, 2, 1};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_3) {
  using List = typename TestFixture::List;
  List a(
      {TypeParam(1), TypeParam(2), TypeParam(3), TypeParam(3), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_4) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(3),
          TypeParam(3), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_5) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(2),
          TypeParam(2), TypeParam(3), TypeParam(3), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_6) {
  using List = typename TestFixture::List;
  List a(
      {TypeParam(1), TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_7) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(2), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

template <typename T>
struct ListSortTest : public testing::Test {
  using List = s21::list<T>;
};

using ListSortTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSortTest, ListSortTypes);

TYPED_TEST(ListSortTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  a.sort();
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ListSortTest, size_1) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);

  List a({value_1});
  a.sort();

  EXPECT_DOUBLE_EQ(*(a.begin()), value_1);
  EXPECT_EQ(a.size(), 1);
}

TYPED_TEST(ListSortTest, size_2) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);

  List a({value_2, value_1});
  a.sort();

  auto it = a.begin();
  EXPECT_DOUBLE_EQ(*it, value_1);
  ++it;
  EXPECT_DOUBLE_EQ(*it, value_2);
  EXPECT_EQ(a.size(), 2);
}

/* TYPED_TEST(ListSortTest, size_10) { */
/*   using List = typename TestFixture::List; */

/*   List a{}; */
/*   for (size_t i = 0U; i < 10U; ++i) { */
/*     if (i % 2U == 0U) { */
/*       if (i % 3U == 0U) { */
/*         a.emplace_front(TypeParam(i)); */
/*       } else { */
/*         a.emplace_back(TypeParam(i)); */
/*       } */
/*     } else { */
/*       if (i % 3U == 0U) { */
/*         a.emplace_back(TypeParam(i)); */
/*       } else { */
/*         a.emplace_front(TypeParam(i)); */
/*       } */
/*     } */
/*   } */
/*   a.sort(); */

/*   size_t i = 0U; */
/*   for (auto iterator = a.begin(); iterator != a.end(); ++iterator) { */
/*     EXPECT_DOUBLE_EQ(iterator.head->value, TypeParam(i++)); */
/*   } */
/* } */

/* TYPED_TEST(ListSortTest, size_100) { */
/*   using List = typename TestFixture::List; */

/*   List a{}; */
/*   for (size_t i = 0U; i < 100U; ++i) { */
/*     if (i % 2U == 0U) { */
/*       if (i % 3U == 0U) { */
/*         a.emplace_front(TypeParam(i)); */
/*       } else { */
/*         a.emplace_back(TypeParam(i)); */
/*       } */
/*     } else { */
/*       if (i % 3U == 0U) { */
/*         a.emplace_back(TypeParam(i)); */
/*       } else { */
/*         a.emplace_front(TypeParam(i)); */
/*       } */
/*     } */
/*   } */
/*   a.sort(); */

/*   size_t i = 0U; */
/*   for (auto iterator = a.begin(); iterator != a.end(); ++iterator) { */
/*     EXPECT_DOUBLE_EQ(iterator.head->value, TypeParam(i++)); */
/*   } */
/* } */
