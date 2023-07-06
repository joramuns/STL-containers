#include "../tests.h"

class SetTest {
 public:
  s21::set<int> empty_set;
  s21::set<int> set_int{3, 5, 7, 2, 1, 1, 4, 6};
  s21::set<std::string> set_string{"baka", "obon", "kokoro"};
  s21::set<double> set_double{1.2, 2.0, 3.345, -1.233};

  std::set<int> empty_set_orig;
  std::set<int> set_int_orig{3, 5, 7, 2, 1, 1, 4, 6};
  std::set<std::string> set_string_orig{"baka", "obon", "kokoro"};
  std::set<double> set_double_orig{1.2, 2.0, 3.345, -1.233};

  s21::set<int> swapped{100, 101, 102};
  std::set<int> swapped_orig{100, 101, 102};

  s21::set<int> merged{1, 50, 60};
  std::set<int> merged_orig{1, 50, 60};
};

TEST(SetKosmosman, Constructor) {
  SetTest tmp;
  EXPECT_EQ(*(tmp.empty_set.begin()) == *(tmp.empty_set_orig.begin()), true);
  EXPECT_EQ(*(tmp.empty_set.end()) == *(tmp.empty_set_orig.end()), true);
}

TEST(SetKosmosman, ConstructorList) {
  SetTest tmp;
  int eq[7]{1, 2, 3, 4, 5, 6, 7};
  int* pos = eq;
  for (auto it : tmp.set_int) {
    EXPECT_EQ(it == *(pos++), true);
  }
}

TEST(SetKosmosman, ConstructorCopy) {
  SetTest tmp;
  s21::set<double> two{tmp.set_double};
  double eq[4]{-1.233, 1.2, 2.0, 3.345};
  double* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  tmp.set_double.clear();
  EXPECT_TRUE(tmp.set_double.empty());
  EXPECT_TRUE(!two.empty());
}

TEST(SetKosmosman, ConstructorMove) {
  SetTest tmp;
  s21::set<double> two{std::move(tmp.set_double)};
  double eq[4]{-1.233, 1.2, 2.0, 3.345};
  double* pos = eq;
  for (auto it : two) {
    EXPECT_EQ(it == *(pos++), true);
  }
  EXPECT_TRUE(tmp.set_double.empty());
  EXPECT_TRUE(!two.empty());
}

TEST(SetKosmosman, OperatorsPlusTest) {
  SetTest tmp;
  s21::set<int>::iterator it(tmp.set_int.begin());
  EXPECT_TRUE(*(it++) == 1);
  EXPECT_TRUE(*(it) == 2);
  EXPECT_TRUE(*(++it) == 3);
}

TEST(SetKosmosman, OperatorsMinusTest) {
  SetTest tmp;
  s21::set<int>::iterator it(tmp.set_int.find(7));
  EXPECT_TRUE(*(it--) == 7);
  EXPECT_TRUE(*(it) == 6);
  EXPECT_TRUE(*(--it) == 5);
}

TEST(SetKosmosman, EmptyTest) {
  SetTest tmp;
  EXPECT_TRUE(tmp.set_int.empty() == tmp.set_int_orig.empty());
  EXPECT_TRUE(tmp.empty_set.empty() == tmp.empty_set_orig.empty());
  EXPECT_TRUE(tmp.set_string.empty() == tmp.set_string_orig.empty());
  EXPECT_TRUE(tmp.set_double.empty() == tmp.set_double_orig.empty());
}

TEST(SetKosmosman, SizeTest) {
  SetTest tmp;
  EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
  EXPECT_TRUE(tmp.empty_set.size() == tmp.empty_set_orig.size());
  EXPECT_TRUE(tmp.set_string.size() == tmp.set_string_orig.size());
  EXPECT_TRUE(tmp.set_double.size() == tmp.set_double_orig.size());
}

/* TEST(SetKosmosman, MaxSizeTest) { */
/*   SetTest tmp; */
/*   EXPECT_TRUE(tmp.set_int.max_size() == tmp.set_int_orig.max_size()); */
/*   EXPECT_TRUE(tmp.empty_set.max_size() == tmp.empty_set_orig.max_size()); */
/* } */

TEST(SetKosmosman, ClearTest) {
  SetTest tmp;
  tmp.set_int.clear();
  tmp.set_int_orig.clear();
  EXPECT_TRUE(tmp.set_int.empty() == tmp.set_int_orig.empty());
}

TEST(SetKosmosman, InsertTest) {
  SetTest tmp;
  tmp.empty_set.insert(1);
  tmp.empty_set.insert(1);
  EXPECT_TRUE(tmp.set_int.empty() == tmp.set_int_orig.empty());
  EXPECT_TRUE(*(tmp.set_int.find(1)) == *(tmp.set_int_orig.find(1)));
  EXPECT_EQ(tmp.set_int.find(2) == tmp.set_int.end(),
            tmp.set_int_orig.find(2) == tmp.set_int_orig.end());
}

TEST(SetKosmosman, EraseTest) {
  SetTest tmp;
  tmp.set_int.erase(tmp.set_int.find(5));
  tmp.set_int_orig.erase(5);
  EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
  EXPECT_EQ(tmp.set_int.find(5) == tmp.set_int.end(),
            tmp.set_int_orig.find(5) == tmp.set_int_orig.end());
}

TEST(SetKosmosman, SwapTest) {
  SetTest tmp;
  tmp.set_int.swap(tmp.swapped);
  tmp.set_int_orig.swap(tmp.swapped_orig);
  EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
  auto it_orig = tmp.set_int_orig.begin();
  for (auto it = tmp.set_int.begin(); it != tmp.set_int.end(); ++it) {
    EXPECT_TRUE(*it == *(it_orig++));
  }
}

TEST(SetKosmosman, FindTest) {
  SetTest tmp;
  for (int i = 1; i < 8; ++i) {
    EXPECT_TRUE(tmp.set_int.find(i) != tmp.set_int.end());
    EXPECT_TRUE(tmp.set_int.find(i + 10) == tmp.set_int.end());
  }
}

TEST(SetKosmosman, ContainsTest) {
  SetTest tmp;
  for (int i = 1; i < 8; ++i) {
    EXPECT_TRUE(tmp.set_int.contains(i));
    EXPECT_FALSE(tmp.set_int.contains(i + 10));
  }
}

TEST(SetKosmosman, MergeTest) {
  SetTest tmp;
  tmp.set_int.merge(tmp.merged);
  tmp.set_int_orig.merge(tmp.merged_orig);
  EXPECT_TRUE(tmp.set_int.size() == tmp.set_int_orig.size());
  EXPECT_TRUE(tmp.merged.size() == tmp.merged_orig.size());
  auto it_orig = tmp.set_int_orig.begin();
  for (auto it = tmp.set_int.begin(); it != tmp.set_int.end(); ++it) {
    EXPECT_TRUE(*it == *(it_orig++));
  }
}
