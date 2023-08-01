#include "../tests.h"

TEST(Array, NullPointer) {
  std::array<int, 0> std_keka;
  s21::array<int, 0> keka;

  EXPECT_EQ(std_keka.data(), keka.data());
}
