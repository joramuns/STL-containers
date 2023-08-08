#include "../tests.h"

TEST(s21_array, constructors) {
  s21::array<int, 3> first{1, 2, 3};
  s21::array<int, 3> two = first;
  s21::array<int, 3> three;
  three = two;
  std::array<int, 3> stdarr = {1, 2, 3};
  for (size_t i = 0; i != first.size(); ++i) {
    ASSERT_EQ(first[i], two[i]);
    ASSERT_EQ(two[i], three[i]);
    ASSERT_EQ(three[i], stdarr[i]);
  }
}

TEST(s21_array, move_constructor) {
  s21::array<double, 3> arr1{1.5, 15.623, 744.23551};
  s21::array<double, 3> arr2(std::move(arr1));
  std::array<double, 3> stdarr1{1.5, 15.623, 744.23551};
  std::array<double, 3> stdarr2(std::move(stdarr1));
  for (size_t i = 0; i != arr2.size(); ++i) {
    ASSERT_EQ(stdarr2[i], arr2[i]);
  }
}

TEST(s21_array, element_acess) {
  s21::array<int, 5> arr{4, 7, 12, 38, 190};
  int *arr2 = arr.data();
  std::array<int, 5> stdarr{4, 7, 12, 38, 190};
  int *stdarr2 = stdarr.data();
  ASSERT_EQ(arr.at(4), stdarr.at(4));
  ASSERT_EQ(arr[3], stdarr[3]);
  ASSERT_EQ(arr.front(), stdarr.front());
  ASSERT_EQ(arr.back(), stdarr.back());
  for (size_t i = 0; i != arr.size(); ++i) {
    ASSERT_EQ(arr2[i], stdarr2[i]);
  }
}

TEST(s21_array, fill) {
  s21::array<int, 5> arr;
  s21::array<int, 5> stdarr;
  arr.fill(7);
  stdarr.fill(7);
  for (size_t i = 0; i != arr.size(); ++i) {
    ASSERT_EQ(arr[i], stdarr[i]);
  }
}

TEST(s21_array, swap) {
  s21::array<int, 4> arr1{1, 2, 3, 4};
  s21::array<int, 4> arr2{5, 6, 7, 8};
  std::array<int, 4> stdarr1{1, 2, 3, 4};
  std::array<int, 4> stdarr2{5, 6, 7, 8};
  arr1.swap(arr2);
  stdarr1.swap(stdarr2);
  for (size_t i = 0; i != arr1.size(); ++i) {
    ASSERT_EQ(arr1[i], stdarr1[i]);
    ASSERT_EQ(arr2[i], stdarr2[i]);
  }
}
