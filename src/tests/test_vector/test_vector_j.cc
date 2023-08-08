#include "../tests.h"

TEST(Vector, MaxSize) {
  s21::vector<int> intvec{};
  s21::vector<char> charvec{};
  s21::vector<size_t> sztvec{};
  s21::vector<float> fltvec{};
  s21::vector<double> dblvec{};
  s21::vector<std::vector<int>> vecintvec{};
  s21::vector<std::vector<char>> veccharvec{};
  s21::vector<std::vector<size_t>> vecsztvec{};
  s21::vector<std::vector<std::vector<int>>> vecvecintvec{};
  s21::vector<std::list<int>> veclistvec{};
  s21::vector<std::set<int>> vecsetvec{};
  std::vector<int> std_intvec{};
  std::vector<char> std_charvec{};
  std::vector<size_t> std_sztvec{};
  std::vector<float> std_fltvec{};
  std::vector<double> std_dblvec{};
  std::vector<std::vector<int>> std_vecintvec{};
  std::vector<std::vector<char>> std_veccharvec{};
  std::vector<std::vector<size_t>> std_vecsztvec{};
  std::vector<std::vector<std::vector<int>>> std_vecvecintvec{};
  std::vector<std::list<int>> std_veclistvec{};
  std::vector<std::set<int>> std_vecsetvec{};
  
  ASSERT_EQ(intvec.max_size(), std_intvec.max_size());
  ASSERT_EQ(charvec.max_size(), std_charvec.max_size());
  ASSERT_EQ(sztvec.max_size(), std_sztvec.max_size());
  ASSERT_EQ(fltvec.max_size(), std_fltvec.max_size());
  ASSERT_EQ(dblvec.max_size(), std_dblvec.max_size());
  ASSERT_EQ(vecintvec.max_size(), std_vecintvec.max_size());
  ASSERT_EQ(veccharvec.max_size(), std_veccharvec.max_size());
  ASSERT_EQ(vecsztvec.max_size(), std_vecsztvec.max_size());
  ASSERT_EQ(vecvecintvec.max_size(), std_vecvecintvec.max_size());
  ASSERT_EQ(veclistvec.max_size(), std_veclistvec.max_size());
  ASSERT_EQ(vecsetvec.max_size(), std_vecsetvec.max_size());
}
