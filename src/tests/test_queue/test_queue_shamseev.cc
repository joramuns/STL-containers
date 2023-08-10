#include "../tests.h"

TEST(s21_queue, test1) {
  s21::queue<int> my_queue;
  std::queue<int> lib_queue;
  my_queue.push(3);
  my_queue.push(5);
  lib_queue.push(3);
  lib_queue.push(5);
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  ASSERT_EQ(lib_queue.size(), my_queue.size());
}

TEST(s21_queue, test2) {
  s21::queue<int> my_queue({1, 2, 3, 4});
  std::queue<int> lib_queue({1, 2, 3, 4});
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  lib_queue.pop();
  my_queue.pop();
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  lib_queue.pop();
  my_queue.pop();
  ASSERT_EQ(3, my_queue.front());
  ASSERT_EQ(3, lib_queue.front());
  ASSERT_EQ(4, my_queue.back());
  ASSERT_EQ(4, lib_queue.back());
}

TEST(s21_queue, test3) {
  s21::queue<int> test_queue;
  test_queue.push(500);
  test_queue.push(1000);
  std::queue<int> test_queue1;
  test_queue1.push(500);
  test_queue1.push(1000);
  s21::queue<int> my_queue(test_queue);
  std::queue<int> lib_queue(test_queue1);
  ASSERT_EQ(lib_queue.size(), my_queue.size());
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
}

TEST(s21_queue, test4) {
  s21::queue<int> test_queue;
  test_queue.push(500);
  test_queue.push(1000);
  std::queue<int> test_queue1;
  test_queue1.push(500);
  test_queue1.push(1000);
  s21::queue<int> my_queue = std::move(test_queue);
  std::queue<int> lib_queue = std::move(test_queue1);
  ASSERT_EQ(lib_queue.size(), my_queue.size());
  ASSERT_EQ(lib_queue.front(), my_queue.front());
  ASSERT_EQ(lib_queue.back(), my_queue.back());
  ASSERT_EQ(0, test_queue.size());
  ASSERT_EQ(0, test_queue1.size());
}

TEST(s21_queue, test5) {
  s21::queue<int> my_queue({1, 2, 3, 4});
  std::queue<int> lib_queue({1, 2, 3, 4});
  s21::queue<int> to_swap({15, 125, 20});
  std::queue<int> to_swap1({15, 125, 20});
  my_queue.swap(to_swap);
  lib_queue.swap(to_swap1);
  ASSERT_EQ(3, my_queue.size());
  ASSERT_EQ(3, lib_queue.size());
  ASSERT_EQ(15, my_queue.front());
  ASSERT_EQ(15, lib_queue.front());
  ASSERT_EQ(4, to_swap.size());
  ASSERT_EQ(4, to_swap1.size());
  ASSERT_EQ(4, to_swap.back());
  ASSERT_EQ(4, to_swap1.back());
}

TEST(s21_queue, emplace_back) {
  s21::queue<int> my_queue{6, 7, 9};
  s21::queue<int> res_queue{6, 7, 9, 1, 2, 8};
  my_queue.insert_many_back(1, 2, 8);
  for (size_t i = 0; i <= res_queue.size(); i++) {
    ASSERT_EQ(my_queue.back(), res_queue.back());
    my_queue.pop();
    res_queue.pop();
  }
}
