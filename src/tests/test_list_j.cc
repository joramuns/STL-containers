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
