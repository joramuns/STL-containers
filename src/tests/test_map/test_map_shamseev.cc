#include "../tests.h"

using namespace s21;
template <typename Key, typename T>
void test_eq(map<Key, T> &a, std::map<Key, T> &std_a) {
  EXPECT_EQ(a.size(), std_a.size());
  auto it_std = std_a.begin();
  auto it = a.begin();
  while (it_std != std_a.end() && it != a.end()) {
    EXPECT_EQ(it.GetKey(), it_std->first);
    EXPECT_EQ(*it, it_std->second);
    ++it;
    ++it_std;
  }
}

TEST(s21_map, create1) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}, {2, 9}};
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}, {2, 9}};
  test_eq(a, std_a);
}

TEST(s21_map, create2) {
  map<char, int> a;
  a.insert('a', 15);
  a.insert('c', 25);
  // a.print_tree_map();
}

TEST(s21_map, create3) {
  map<char, int> a{{'[', 3}, {'-', 24}, {'q', 0}, {'x', 23}};
  map<char, int> b(a);
  std::map<char, int> std_a{{'[', 3}, {'-', 24}, {'q', 0}, {'x', 23}};
  std::map<char, int> std_b(std_a);
  test_eq(b, std_b);
  test_eq(a, std_a);
}

TEST(s21_map, create4) {
  map<char, int> a{{'[', 3}, {'-', 24}, {'q', 0}, {'x', 23}};
  map<char, int> b(std::move(a));
  std::map<char, int> std_a{{'[', 3}, {'-', 24}, {'q', 0}, {'x', 23}};
  std::map<char, int> std_b(std::move(std_a));
  test_eq(b, std_b);
  test_eq(a, std_a);
}

TEST(s21_map, insert) {
  map<char, int> a;
  std::map<char, int> std_a;
  a.insert({'z', 423});
  a.insert({'k', 123});
  a.insert({'*', 1});
  std_a.insert({'z', 423});
  std_a.insert({'k', 123});
  std_a.insert({'*', 1});
  test_eq(a, std_a);
}

TEST(s21_map, insert1) {
  map<char, int> a;
  std::map<char, int> std_a;
  a.insert('z', 423);
  a.insert('k', 123);
  a.insert('*', 1);
  std_a.insert({'z', 423});
  std_a.insert({'k', 123});
  std_a.insert({'*', 1});
  test_eq(a, std_a);
}

TEST(s21_map, insert2) {
  map<char, int> a;
  std::map<char, int> std_a;
  a.insert('z', 423);
  a.insert('k', 123);
  a.insert('*', 1);
  a.insert_or_assign('z', 124);
  a.insert_or_assign('c', -123);
  std_a.insert({'z', 423});
  std_a.insert({'k', 123});
  std_a.insert({'*', 1});
  std_a.insert_or_assign('z', 124);
  std_a.insert_or_assign('c', -123);
  test_eq(a, std_a);
}

TEST(s21_map, create_copy) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}, {2, 9}};
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}, {2, 9}};
  map<int, int> b(a);
  std::map<int, int> std_b(std_a);
  test_eq(b, std_b);
}

TEST(s21_map, move_create) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}, {2, 9}};
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}, {2, 9}};
  map<int, int> b(std::move(a));
  std::map<int, int> std_b(std::move(std_a));
  test_eq(b, std_b);
}

TEST(s21_map, test_it) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}};
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}};
  auto it = a.begin();
  auto std_it = std_a.begin();
  EXPECT_EQ(it.GetKey(), std_it->first);
  EXPECT_EQ(*it, std_it->second);
}

TEST(s21_map, test_it2) {
  map<int, int> a{{3, 7},    {8, 3},   {1, 9},   {1, 7},   {-8, 3},   {41, 9},
                  {-403, 7}, {538, 3}, {164, 9}, {123, 7}, {-648, 3}, {12, 9}};
  std::map<int, int> std_a{{3, 7},   {8, 3},   {1, 9},    {1, 7},
                           {-8, 3},  {41, 9},  {-403, 7}, {538, 3},
                           {164, 9}, {123, 7}, {-648, 3}, {12, 9}};
  auto std_it = std_a.begin();
  for (auto it = a.begin(); it != a.end(); ++it) {
    EXPECT_EQ(it.GetKey(), std_it->first);
    EXPECT_EQ(*it, std_it->second);
    ++std_it;
  }
}

TEST(s21_map, test_op_eq) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}};
  map<int, int> b;
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}};
  std::map<int, int> std_b;
  std_b = std_a;
  b = a;
  test_eq(b, std_b);
}

TEST(s21_map, test_op_eq2) {
  map<int, int> a;
  map<int, int> b;
  std::map<int, int> std_a;
  std::map<int, int> std_b;
  std_b = std_a;
  b = a;
  test_eq(b, std_b);
}

TEST(s21_map, contains) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}};
  EXPECT_EQ(a.contains(8), true);
  EXPECT_EQ(a.contains(5), false);
}

TEST(s21_map, ins_or_assign) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}, {4, 9}, {5, 9}};
  a.insert_or_assign(7, 5);
  a.insert_or_assign(3, -1000);
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}, {4, 9}, {5, 9}};
  std_a.insert_or_assign(7, 5);
  std_a.insert_or_assign(3, -1000);
  test_eq(a, std_a);
}

TEST(s21_map, erase) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}, {4, 9}, {5, 9}};
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}, {4, 9}, {5, 9}};
  auto it = a.begin();
  auto std_it = std_a.begin();
  ++it;
  ++std_it;
  a.erase(it);
  std_a.erase(std_it);
  test_eq(a, std_a);
}

TEST(s21_map, erase2) {
  map<int, int> a{{3, 7}};
  std::map<int, int> std_a{{3, 7}};
  auto it = a.begin();
  auto std_it = std_a.begin();
  a.erase(it);
  std_a.erase(std_it);
  test_eq(a, std_a);
}

TEST(s21_map, erase3) {
  map<int, int> a{{3, 7}, {8, 3}};
  std::map<int, int> std_a{{3, 7}, {8, 3}};
  auto it = a.begin();
  auto std_it = std_a.begin();
  a.erase(it);
  std_a.erase(std_it);
  test_eq(a, std_a);
}

/* TEST(s21_map, emplace_bonus_test) { */
/*   map<double, int> a{{2.34534534, 1}}; */
/*   a.emplace(std::pair{2.34, 3}, std::pair{1.43, 4}, std::pair{1.0, 6}, */
/*             std::pair{14.54, 21}, std::pair{75.34, 5}); */
/*   std::map<double, int> std_a{{2.34534534, 1}}; */
/*   std_a.emplace(std::pair{2.34, 3}); */
/*   std_a.emplace(std::pair{1.43, 4}); */
/*   std_a.emplace(std::pair{1.0, 6}); */
/*   std_a.emplace(std::pair{14.54, 21}); */
/*   std_a.emplace(std::pair{75.34, 5}); */
/*   test_eq(a, std_a); */
/* } */

TEST(s21_map, merge) {
  map<int, int> a{{3, 7}, {8, 3}, {1, 9}, {4, 9}, {5, 9}};
  std::map<int, int> std_a{{3, 7}, {8, 3}, {1, 9}, {4, 9}, {5, 9}};
  map<int, int> b{{4, 7}, {5, 3}, {6, 9}, {7, 9}, {8, 9}};
  std::map<int, int> std_b{{4, 7}, {5, 3}, {6, 9}, {7, 9}, {8, 9}};
  a.merge(b);
  std_a.merge(std_b);
  test_eq(a, std_a);
}
