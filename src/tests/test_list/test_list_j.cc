#include "../tests.h"

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

TEST(List, Reverse_5) {
  s21::list<int> aboba{1, 2, 3};
  std::list<int> std_aboba{1, 2, 3};
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

TEST(List, Splice_1) {
  s21::list<int> aboba{1, 2, 3};
  s21::list<int> keka{4, 5, 6};
  std::list<int> std_aboba{1, 2, 3};
  std::list<int> std_keka{4, 5, 6};
  aboba.splice(aboba.begin(), keka);
  std_aboba.splice(std_aboba.begin(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_2) {
  s21::list<int> aboba{1, 2, 3};
  s21::list<int> keka{4, 5, 6};
  std::list<int> std_aboba{1, 2, 3};
  std::list<int> std_keka{4, 5, 6};
  aboba.splice(aboba.end(), keka);
  std_aboba.splice(std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_3) {
  s21::list<int> aboba{1, 2, 3};
  s21::list<int> keka{4, 5, 6};
  std::list<int> std_aboba{1, 2, 3};
  std::list<int> std_keka{4, 5, 6};
  aboba.splice(--aboba.end(), keka);
  std_aboba.splice(--std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_4) {
  s21::list<int> aboba{1};
  s21::list<int> keka{4, 5, 6};
  std::list<int> std_aboba{1};
  std::list<int> std_keka{4, 5, 6};
  aboba.splice(aboba.begin(), keka);
  std_aboba.splice(std_aboba.begin(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_5) {
  s21::list<int> aboba{1};
  s21::list<int> keka{4, 5, 6};
  std::list<int> std_aboba{1};
  std::list<int> std_keka{4, 5, 6};
  aboba.splice(aboba.end(), keka);
  std_aboba.splice(std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_6) {
  s21::list<int> aboba{1};
  s21::list<int> keka{4, 5, 6};
  std::list<int> std_aboba{1};
  std::list<int> std_keka{4, 5, 6};
  aboba.splice(--aboba.end(), keka);
  std_aboba.splice(--std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_7) {
  s21::list<int> aboba{1, 2, 3};
  s21::list<int> keka{4};
  std::list<int> std_aboba{1, 2, 3};
  std::list<int> std_keka{4};
  aboba.splice(aboba.begin(), keka);
  std_aboba.splice(std_aboba.begin(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_8) {
  s21::list<int> aboba{1, 2, 3};
  s21::list<int> keka{4};
  std::list<int> std_aboba{1, 2, 3};
  std::list<int> std_keka{4};
  aboba.splice(aboba.end(), keka);
  std_aboba.splice(std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_9) {
  s21::list<int> aboba{1, 2, 3};
  s21::list<int> keka{4};
  std::list<int> std_aboba{1, 2, 3};
  std::list<int> std_keka{4};
  aboba.splice(--aboba.end(), keka);
  std_aboba.splice(--std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_10) {
  s21::list<int> aboba{1};
  s21::list<int> keka{4};
  std::list<int> std_aboba{1};
  std::list<int> std_keka{4};
  aboba.splice(aboba.begin(), keka);
  std_aboba.splice(std_aboba.begin(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_11) {
  s21::list<int> aboba{1};
  s21::list<int> keka{4};
  std::list<int> std_aboba{1};
  std::list<int> std_keka{4};
  aboba.splice(aboba.end(), keka);
  std_aboba.splice(std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_12) {
  s21::list<int> aboba{1};
  s21::list<int> keka{4};
  std::list<int> std_aboba{1};
  std::list<int> std_keka{4};
  aboba.splice(--aboba.end(), keka);
  std_aboba.splice(--std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_13) {
  s21::list<int> aboba;
  s21::list<int> keka{4};
  std::list<int> std_aboba;
  std::list<int> std_keka{4};
  aboba.splice(aboba.begin(), keka);
  std_aboba.splice(std_aboba.begin(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_14) {
  s21::list<int> aboba;
  s21::list<int> keka{4};
  std::list<int> std_aboba;
  std::list<int> std_keka{4};
  aboba.splice(aboba.end(), keka);
  std_aboba.splice(std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_15) {
  s21::list<int> aboba;
  s21::list<int> keka{4};
  std::list<int> std_aboba;
  std::list<int> std_keka{4};
  aboba.splice(--aboba.end(), keka);
  std_aboba.splice(--std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_16) {
  s21::list<int> aboba{1};
  s21::list<int> keka;
  std::list<int> std_aboba{1};
  std::list<int> std_keka;
  aboba.splice(aboba.begin(), keka);
  std_aboba.splice(std_aboba.begin(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_17) {
  s21::list<int> aboba{1};
  s21::list<int> keka;
  std::list<int> std_aboba{1};
  std::list<int> std_keka;
  aboba.splice(aboba.end(), keka);
  std_aboba.splice(std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

TEST(List, Splice_18) {
  s21::list<int> aboba{1};
  s21::list<int> keka;
  std::list<int> std_aboba{1};
  std::list<int> std_keka;
  aboba.splice(--aboba.end(), keka);
  std_aboba.splice(--std_aboba.end(), std_keka);
  auto s21_it = aboba.begin();
  auto std_it = std_aboba.begin();
  auto s21_it_end = aboba.end();
  auto std_it_end = std_aboba.end();
  ASSERT_EQ(aboba.size(), std_aboba.size());
  do {
    ASSERT_EQ(*s21_it, *std_it);
  } while (++s21_it != s21_it_end && ++std_it != std_it_end);
}

// TEST(List, Sort_1) {
//   std::list<int> std_keka{3, 2, 1};
//   s21::list<int> keka{3, 2, 1};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_2) {
//   std::list<int> std_keka{1, 2, 3};
//   s21::list<int> keka{1, 2, 3};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_3) {
//   std::list<int> std_keka{3, 1, 2};
//   s21::list<int> keka{3, 1, 2};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_4) {
//   std::list<int> std_keka{3, 3, 1};
//   s21::list<int> keka{3, 3, 1};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_5) {
//   std::list<int> std_keka{3, 2};
//   s21::list<int> keka{3, 2};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_6) {
//   std::list<int> std_keka{2, 3};
//   s21::list<int> keka{2, 3};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_7) {
//   std::list<int> std_keka{1, 4, 3, 2};
//   s21::list<int> keka{1, 4, 3, 2};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_8) {
//   std::list<int> std_keka{1, 3, 4, 2};
//   s21::list<int> keka{1, 3, 4, 2};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_9) {
//   std::list<int> std_keka{4, 3, 1, 2};
//   s21::list<int> keka{4, 3, 1, 2};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_10) {
//   std::list<int> std_keka{4};
//   s21::list<int> keka{4};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

// TEST(List, Sort_11) {
//   std::list<int> std_keka{};
//   s21::list<int> keka{};
//   std_keka.sort();
//   keka.sort();
//   auto s21_it = keka.begin();
//   auto std_it = std_keka.begin();
//   auto s21_it_end = keka.end();
//   auto std_it_end = std_keka.end();
//   ASSERT_EQ(keka.size(), std_keka.size());
//   do {
//     ASSERT_EQ(*s21_it, *std_it);
//   } while (++s21_it != s21_it_end && ++std_it != std_it_end);
// }

TEST(List, Max_Size) {
  s21::list<int> intlist{};
  s21::list<char> charlist{};
  s21::list<size_t> sztlist{};
  s21::list<float> fltlist{};
  s21::list<double> dbllist{};
  s21::list<std::vector<int>> vecintlist{};
  s21::list<std::vector<char>> veccharlist{};
  s21::list<std::vector<size_t>> vecsztlist{};
  s21::list<std::list<int>> listintlist{};
  s21::list<std::set<int>> setintlist{};

  std::list<int> std_intlist{};
  std::list<char> std_charlist{};
  std::list<size_t> std_sztlist{};
  std::list<float> std_fltlist{};
  std::list<double> std_dbllist{};
  std::list<std::vector<int>> std_vecintlist{};
  std::list<std::vector<char>> std_veccharlist{};
  std::list<std::vector<size_t>> std_vecsztlist{};
  std::list<std::list<int>> std_listintlist{};
  std::list<std::set<int>> std_setintlist{};

  ASSERT_EQ(intlist.max_size(), std_intlist.max_size());
  ASSERT_EQ(charlist.max_size(), std_charlist.max_size());
  ASSERT_EQ(sztlist.max_size(), std_sztlist.max_size());
  ASSERT_EQ(dbllist.max_size(), std_dbllist.max_size());
  ASSERT_EQ(vecintlist.max_size(), std_vecintlist.max_size());
  ASSERT_EQ(veccharlist.max_size(), std_veccharlist.max_size());
  ASSERT_EQ(vecsztlist.max_size(), std_vecsztlist.max_size());
  ASSERT_EQ(listintlist.max_size(), std_listintlist.max_size());
  ASSERT_EQ(setintlist.max_size(), std_setintlist.max_size());
}
/* TEST(List, Exception_1) { */
/*   s21::list<int> aboba; */
/*   EXPECT_THROW(aboba.pop_back(), std::invalid_argument); */
/*   EXPECT_THROW(aboba.pop_front(), std::invalid_argument); */
/*   EXPECT_THROW(aboba.erase(aboba.begin()), std::invalid_argument); */
/* } */
