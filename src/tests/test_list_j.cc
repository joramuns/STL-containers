#include "tests.h"

TEST(List, Filling_int_1) {
  s21::list<int> aboba;
  aboba.push_back(1);
  aboba.push_back(2);
  aboba.push_back(3);
  aboba.push_back(4);
  aboba.push_back(2);
  aboba.push_back(9);
  aboba.push_front(7);
  aboba.push_front(5);
  aboba.pop_back();
  aboba.pop_front();
  ASSERT_EQ(aboba.front(), 7);
  ASSERT_EQ(aboba.back(), 2);
}

TEST(List, Filling_char_1) {
  s21::list<char> aboba;
  aboba.push_back('b');
  aboba.push_back('e');
  aboba.push_back('o');
  aboba.pop_back();
  aboba.push_back('x');
  aboba.push_back('s');
  aboba.push_back('m');
  aboba.pop_front();
  aboba.push_front('k');
  aboba.push_front('p');
  aboba.pop_front();
  aboba.push_front('t');
  aboba.push_back(';');
  aboba.push_front('q');
  aboba.push_back('[');
  ASSERT_EQ(aboba.front(), 'q');
  ASSERT_EQ(aboba.back(), '[');
}

TEST(List, Size_1) {
  s21::list<int> aboba(5);
  ASSERT_EQ(aboba.size(), 5);
}

TEST(List, Size_2) {
  s21::list<int> aboba(0);
  ASSERT_EQ(aboba.size(), 0);
}

TEST(List, Size_3) {
  s21::list<int> aboba;
  aboba.push_back(0);
  aboba.pop_back();
  aboba.push_back(1);
  aboba.pop_front();
  aboba.push_back(2);
  aboba.pop_back();
  aboba.push_back(3);
  aboba.pop_front();
  aboba.push_back(4);
  aboba.pop_front();
  aboba.push_front(5);
  aboba.pop_front();
  aboba.push_front(99);
  ASSERT_EQ(aboba.size(), 1);
}

TEST(List, Empty_1) {
  s21::list<int> aboba(9);
  aboba.push_back(13);
  aboba.push_back(99);
  for (int i = 0; i < 11; i++) {
    aboba.pop_back();
  }
  ASSERT_EQ(aboba.empty(), true);
}

TEST(List, Empty_2) {
  s21::list<int> aboba(9);
  aboba.push_back(13);
  aboba.push_back(99);
  for (int i = 0; i < 11; i++) {
    aboba.pop_front();
  }
  ASSERT_EQ(aboba.empty(), true);
}

TEST(List, Empty_3) {
  s21::list<int> aboba(2);
  aboba.pop_back();
  aboba.pop_front();
  ASSERT_EQ(aboba.empty(), true);
}

TEST(List, Empty_4) {
  s21::list<int> aboba;
  aboba.push_back(0);
  aboba.pop_back();
  aboba.push_back(1);
  aboba.pop_front();
  aboba.push_front(2);
  aboba.pop_back();
  aboba.push_front(3);
  aboba.pop_front();
  ASSERT_EQ(aboba.empty(), true);
}

TEST(List, Merge_1) {
  s21::list<int> aboba{1, 3, 3, 5, 9};
  s21::list<int> keka{2, 3, 4, 4, 7, 8};
  std::list<int> std_aboba{1, 3, 3, 5, 9};
  std::list<int> std_keka{2, 3, 4, 4, 7, 8};
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Merge_2) {
  s21::list<int> aboba{1};
  s21::list<int> keka{2};
  std::list<int> std_aboba{1};
  std::list<int> std_keka{2};
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Merge_3) {
  s21::list<int> aboba{1, 2};
  s21::list<int> keka{1, 2};
  std::list<int> std_aboba{1, 2};
  std::list<int> std_keka{1, 2};
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Merge_4) {
  s21::list<int> aboba{2, 1};
  s21::list<int> keka{1, 2};
  std::list<int> std_aboba{2, 1};
  std::list<int> std_keka{1, 2};
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Merge_5) {
  s21::list<int> aboba;
  s21::list<int> keka;
  std::list<int> std_aboba;
  std::list<int> std_keka;
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Merge_6) {
  s21::list<int> aboba{2, 1};
  s21::list<int> keka{2, 1};
  std::list<int> std_aboba{2, 1};
  std::list<int> std_keka{2, 1};
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Merge_7) {
  s21::list<int> aboba{2, 1, 2, 1};
  s21::list<int> keka{2, 1, 2, 1};
  std::list<int> std_aboba{2, 1, 2, 1};
  std::list<int> std_keka{2, 1, 2, 1};
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Merge_8) {
  s21::list<int> aboba{2};
  s21::list<int> keka{2};
  std::list<int> std_aboba{2};
  std::list<int> std_keka{2};
  aboba.merge(keka);
  std_aboba.merge(std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Unique_1) {
  s21::list<int> aboba{1, 2, 2, 3, 3, 2, 1, 1, 2};
  std::list<int> std_aboba{1, 2, 2, 3, 3, 2, 1, 1, 2};
  aboba.unique();
  std_aboba.unique();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Unique_2) {
  s21::list<int> aboba{1};
  std::list<int> std_aboba{1};
  aboba.unique();
  std_aboba.unique();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Unique_3) {
  s21::list<int> aboba{1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 2, 1};
  s21::list<int> std_aboba{1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 2, 2, 1};
  aboba.unique();
  std_aboba.unique();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Unique_4) {
  s21::list<int> aboba;
  s21::list<int> std_aboba;
  aboba.unique();
  std_aboba.unique();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Reverse_1) {
  s21::list<int> aboba{1, 2, 2, 3, 3, 2, 1, 1, 2};
  std::list<int> std_aboba{1, 2, 2, 3, 3, 2, 1, 1, 2};
  aboba.reverse();
  std_aboba.reverse();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Reverse_2) {
  s21::list<int> aboba{1};
  std::list<int> std_aboba{1};
  aboba.reverse();
  std_aboba.reverse();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Reverse_3) {
  s21::list<int> aboba{1, 2};
  std::list<int> std_aboba{1, 2};
  aboba.reverse();
  std_aboba.reverse();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Reverse_4) {
  s21::list<int> aboba;
  std::list<int> std_aboba;
  aboba.reverse();
  std_aboba.reverse();
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}
/* TEST(List, Exception_1) { */
/*   s21::list<int> aboba; */
/*   EXPECT_THROW(aboba.pop_back(), std::invalid_argument); */
/*   EXPECT_THROW(aboba.pop_front(), std::invalid_argument); */
/*   EXPECT_THROW(aboba.erase(aboba.begin()), std::invalid_argument); */
/* } */
