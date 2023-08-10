#include "../tests.h"

TEST(Set, MaxSize) {
  s21::set<int> aboba;
  struct keka {
    void *left_;
    void *right_;
    void *parent_;
    bool color_;
    bool head_;
    int key_;
    int value_;
  };
  size_t struct_size_max_size =
      std::numeric_limits<size_t>::max() / sizeof(keka) / 2;
  ASSERT_EQ(struct_size_max_size, aboba.max_size());
}
