#include "../tests.h"

TEST(MultisetJ, UpperBound_1) {
  s21::multiset<int> keka{1, 1, 2, 3, 3, 3, 4, 8, 99, 100, 99, 102, 243};
  std::multiset<int> std_keka{1, 1, 2, 3, 3, 3, 4, 8, 99, 100, 99, 102, 243};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_2) {
  s21::multiset<int> keka{1, 1};
  std::multiset<int> std_keka{1, 1};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_3) {
  s21::multiset<int> keka{};
  std::multiset<int> std_keka{};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_4) {
  s21::multiset<int> keka{1, 2, 2, 2, 2, 3};
  std::multiset<int> std_keka{1, 2, 2, 2, 2, 3};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_5) {
  s21::multiset<int> keka{1, 2, 3, 3, 3, 3, 3};
  std::multiset<int> std_keka{1, 2, 3, 3, 3, 3, 3};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_6) {
  s21::multiset<int> keka{1, 6, 6, 6, 6, 27};
  std::multiset<int> std_keka{1, 6, 6, 6, 6, 27};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_7) {
  s21::multiset<int> keka{3, 3, 3, 3, 3, 9, 11};
  std::multiset<int> std_keka{3, 3, 3, 3, 3, 9, 11};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_8) {
  s21::multiset<int> keka{9, 19, 23, 23, 23, 23, 23};
  std::multiset<int> std_keka{9, 19, 23, 23, 23, 23, 23};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, UpperBound_9) {
  s21::multiset<int> keka{13};
  std::multiset<int> std_keka{13};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.upper_bound(key);
    auto std_iter = std_keka.upper_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_1) {
  s21::multiset<int> keka{1, 1, 2, 3, 3, 3, 4, 8, 99, 100, 99, 102, 243};
  std::multiset<int> std_keka{1, 1, 2, 3, 3, 3, 4, 8, 99, 100, 99, 102, 243};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_2) {
  s21::multiset<int> keka{1, 1};
  std::multiset<int> std_keka{1, 1};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_3) {
  s21::multiset<int> keka{};
  std::multiset<int> std_keka{};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_4) {
  s21::multiset<int> keka{1, 2, 2, 2, 2, 3};
  std::multiset<int> std_keka{1, 2, 2, 2, 2, 3};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_5) {
  s21::multiset<int> keka{1, 2, 3, 3, 3, 3, 3};
  std::multiset<int> std_keka{1, 2, 3, 3, 3, 3, 3};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_6) {
  s21::multiset<int> keka{1, 6, 6, 6, 6, 27};
  std::multiset<int> std_keka{1, 6, 6, 6, 6, 27};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_7) {
  s21::multiset<int> keka{3, 3, 3, 3, 3, 9, 11};
  std::multiset<int> std_keka{3, 3, 3, 3, 3, 9, 11};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_8) {
  s21::multiset<int> keka{9, 19, 23, 23, 23, 23, 23};
  std::multiset<int> std_keka{9, 19, 23, 23, 23, 23, 23};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, LowerBound_9) {
  s21::multiset<int> keka{13};
  std::multiset<int> std_keka{13};
  auto end_iter = keka.end();
  auto std_end_iter = std_keka.end();

  for (const auto &key : keka) {
    auto iter = keka.lower_bound(key);
    auto std_iter = std_keka.lower_bound(key);
    if (iter == end_iter) {
      ASSERT_EQ(std_end_iter, std_iter);
    } else {
      ASSERT_EQ(*iter, *std_iter);
    }
  }
}

TEST(MultisetJ, Merge_1) {
  s21::multiset<int> keka{1, 2, 3};
  s21::multiset<int> mergoka{};
  std::multiset<int> std_keka{1, 2, 3};
  std::multiset<int> std_mergoka{};

  keka.merge(mergoka);
  std_keka.merge(std_mergoka);

  auto std_iter = std_keka.begin();

  for (const auto &key : keka) {
    ASSERT_EQ(key, *std_iter);
    ++std_iter;
  }

  ASSERT_EQ(mergoka.empty(), true);
}

TEST(MultisetJ, Merge_2) {
  s21::multiset<int> keka{1, 2, 3};
  s21::multiset<int> mergoka{1, 2, 3};
  std::multiset<int> std_keka{1, 2, 3};
  std::multiset<int> std_mergoka{1, 2, 3};

  keka.merge(mergoka);
  std_keka.merge(std_mergoka);

  auto std_iter = std_keka.begin();

  for (const auto &key : keka) {
    ASSERT_EQ(key, *std_iter);
    ++std_iter;
  }

  ASSERT_EQ(mergoka.empty(), true);
}

TEST(MultisetJ, Merge_3) {
  s21::multiset<int> keka{1, 1, 1};
  s21::multiset<int> mergoka{1, 2, 3};
  std::multiset<int> std_keka{1, 1, 1};
  std::multiset<int> std_mergoka{1, 2, 3};

  keka.merge(mergoka);
  std_keka.merge(std_mergoka);

  auto std_iter = std_keka.begin();

  for (const auto &key : keka) {
    ASSERT_EQ(key, *std_iter);
    ++std_iter;
  }

  ASSERT_EQ(mergoka.empty(), true);
}

TEST(MultisetJ, Merge_4) {
  s21::multiset<int> keka{1, 1, 1};
  s21::multiset<int> mergoka{1, 1, 1};
  std::multiset<int> std_keka{1, 1, 1};
  std::multiset<int> std_mergoka{1, 1, 1};

  keka.merge(mergoka);
  std_keka.merge(std_mergoka);

  auto std_iter = std_keka.begin();

  for (const auto &key : keka) {
    ASSERT_EQ(key, *std_iter);
    ++std_iter;
  }

  ASSERT_EQ(mergoka.empty(), true);
}

TEST(MultisetJ, Merge_5) {
  s21::multiset<int> keka{2, 2, 2};
  s21::multiset<int> mergoka{1, 1, 1};
  std::multiset<int> std_keka{2, 2, 2};
  std::multiset<int> std_mergoka{1, 1, 1};

  keka.merge(mergoka);
  std_keka.merge(std_mergoka);

  auto std_iter = std_keka.begin();

  for (const auto &key : keka) {
    ASSERT_EQ(key, *std_iter);
    ++std_iter;
  }

  ASSERT_EQ(mergoka.empty(), true);
}

TEST(MultisetJ, Merge_6) {
  s21::multiset<int> keka{};
  s21::multiset<int> mergoka{1, 1, 1};
  std::multiset<int> std_keka{};
  std::multiset<int> std_mergoka{1, 1, 1};

  keka.merge(mergoka);
  std_keka.merge(std_mergoka);

  auto std_iter = std_keka.begin();

  for (const auto &key : keka) {
    ASSERT_EQ(key, *std_iter);
    ++std_iter;
  }

  ASSERT_EQ(mergoka.empty(), true);
}

TEST(MultisetJ, Merge_7) {
  s21::multiset<int> keka{};
  s21::multiset<int> mergoka{};
  std::multiset<int> std_keka{};
  std::multiset<int> std_mergoka{};

  keka.merge(mergoka);
  std_keka.merge(std_mergoka);

  auto std_iter = std_keka.begin();

  for (const auto &key : keka) {
    ASSERT_EQ(key, *std_iter);
    ++std_iter;
  }

  ASSERT_EQ(mergoka.empty(), true);
}

TEST(MultisetJ, EqualRange_1) {
  std::multiset<int> std_keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};
  s21::multiset<int> keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};

  auto range = keka.equal_range(7);
  auto std_range = std_keka.equal_range(7);
  ASSERT_EQ(*range.first, *std_range.first);
  ASSERT_EQ(*range.second, *std_range.second);
}

TEST(MultisetJ, EqualRange_2) {
  std::multiset<int> std_keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};
  s21::multiset<int> keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};

  auto range = keka.equal_range(3);
  auto std_range = std_keka.equal_range(3);
  ASSERT_EQ(*range.first, *std_range.first);
  ASSERT_EQ(*range.second, *std_range.second);
}

TEST(MultisetJ, EqualRange_3) {
  std::multiset<int> std_keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};
  s21::multiset<int> keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};

  auto range = keka.equal_range(198);
  auto std_range = std_keka.equal_range(198);
  ASSERT_EQ(*range.first, *std_range.first);
  ASSERT_EQ(*range.second, *std_range.second);
}

TEST(MultisetJ, EqualRange_4) {
  std::multiset<int> std_keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};
  s21::multiset<int> keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};

  auto range = keka.equal_range(5);
  auto std_range = std_keka.equal_range(5);
  ASSERT_EQ(*range.first, *std_range.first);
  ASSERT_EQ(*range.second, *std_range.second);
}

TEST(MultisetJ, EqualRange_5) {
  std::multiset<int> std_keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};
  s21::multiset<int> keka{3, 4, 5, 5, 7, 7, 7, 7, 9, 198, 200, 200, 200, 200, 200, 232};

  auto range = keka.equal_range(232);
  auto std_range = std_keka.equal_range(232);
  auto ms_end = keka.end();
  auto std_end = std_keka.end();
  ASSERT_EQ(*range.first, *std_range.first);
  ASSERT_EQ(range.second, ms_end);
  ASSERT_EQ(std_end, std_range.second);
}

TEST(MultisetJ, EqualRange_6) {
  std::multiset<int> std_keka{};
  s21::multiset<int> keka{};

  auto range = keka.equal_range(232);
  auto std_range = std_keka.equal_range(232);
  auto ms_end = keka.end();
  auto std_end = std_keka.end();
  ASSERT_EQ(range.first, ms_end);
  ASSERT_EQ(range.second, ms_end);
  ASSERT_EQ(std_end, std_range.first);
  ASSERT_EQ(std_end, std_range.second);
}

TEST(MultisetJ, EqualRange_7) {
  std::multiset<int> std_keka{3, 3, 3, 3, 3, 3, 3, 3, 3};
  s21::multiset<int> keka{3, 3, 3, 3, 3, 3, 3, 3, 3};

  auto range = keka.equal_range(3);
  auto std_range = std_keka.equal_range(3);
  auto ms_end = keka.end();
  auto std_end = std_keka.end();
  auto ms_begin = keka.begin();
  auto std_begin = std_keka.begin();
  ASSERT_EQ(*range.first, *std_range.first);
  ASSERT_EQ(range.first, ms_begin);
  ASSERT_EQ(std_range.first, std_begin);
  ASSERT_EQ(range.second, ms_end);
  ASSERT_EQ(std_end, std_range.second);
}

TEST(MultisetJ, EqualRange_8) {
  std::multiset<int> std_keka{3, 3, 3, 3, 3, 3, 3, 3, 3};
  s21::multiset<int> keka{3, 3, 3, 3, 3, 3, 3, 3, 3};

  auto range = keka.equal_range(198);
  auto std_range = std_keka.equal_range(198);
  auto ms_end = keka.end();
  auto std_end = std_keka.end();
  ASSERT_EQ(range.first, ms_end);
  ASSERT_EQ(range.second, ms_end);
  ASSERT_EQ(std_range.first, std_end);
  ASSERT_EQ(std_range.second, std_end);
}
