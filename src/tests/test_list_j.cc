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
  s21::list<int> aboba;
  aboba.push_back(1);
  aboba.push_back(3);
  aboba.push_back(3);
  aboba.push_back(5);
  aboba.push_back(9);
  s21::list<int> keka;
  keka.push_back(2);
  keka.push_back(3);
  keka.push_back(4);
  keka.push_back(4);
  keka.push_back(7);
  keka.push_back(8);
  for (const auto& item : aboba) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  for (const auto& item : keka) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  aboba.merge(keka);
  for (const auto& item : aboba) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

TEST(List, Unique_1) {
  s21::list<int> aboba;
  aboba.push_back(1);
  aboba.push_back(2);
  aboba.push_back(2);
  aboba.push_back(3);
  aboba.push_back(3);
  aboba.push_back(2);
  aboba.push_back(1);
  aboba.push_back(1);
  aboba.push_back(2);
  for (const auto& item : aboba) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  aboba.unique();
  for (const auto& item : aboba) { 
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

/* TEST(List, Exception_1) { */
/*   s21::list<int> aboba; */
/*   EXPECT_THROW(aboba.pop_back(), std::invalid_argument); */
/*   EXPECT_THROW(aboba.pop_front(), std::invalid_argument); */
/*   EXPECT_THROW(aboba.erase(aboba.begin()), std::invalid_argument); */
/* } */
