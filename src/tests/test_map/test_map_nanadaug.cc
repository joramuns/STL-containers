#include "../tests.h"

TEST(test, mapConstructorsList) {
  s21::map<int, std::string> new_map;

  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();

  while (my_iter != my_map.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(std_iter == std_map.end());

  s21::map<int, std::string> my_map2(my_map);
  std::map<int, std::string> std_map2(std_map);

  my_iter = my_map2.begin();
  std_iter = std_map2.begin();

  while (std_iter != std_map2.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map2.end());

  s21::map<int, std::string> my_map3 = std::move(my_map2);
  std::map<int, std::string> std_map3 = std::move(std_map2);

  my_iter = my_map3.begin();
  std_iter = std_map3.begin();

  while (std_iter != std_map3.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map3.end());

  s21::map<int, std::string> my_map4 = std::move(my_map2);
  std::map<int, std::string> std_map4 = std::move(std_map2);
}

TEST(test, mapAt) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  auto my_ans = my_map.at(33);
  auto std_ans = std_map.at(33);
  ASSERT_TRUE(my_ans == std_ans);

  my_ans = my_map.at(3);
  std_ans = std_map.at(3);
  ASSERT_TRUE(my_ans == std_ans);
}

TEST(test, mapSquareBrackets) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  auto my_ans = my_map[33];
  auto std_ans = std_map[33];
  ASSERT_TRUE(my_ans == std_ans);

  my_ans = my_map[3];
  std_ans = std_map[3];
  ASSERT_TRUE(my_ans == std_ans);
}

TEST(test, mapEmpty) {
  s21::map<int, std::string> new_map;
  ASSERT_TRUE(new_map.empty() == true);

  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  ASSERT_TRUE(my_map.empty() == false);
}

TEST(test, mapSize) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  ASSERT_EQ(my_map.size(), std_map.size());
}

TEST(test, mapClear) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  ASSERT_EQ(my_map.size(), std_map.size());
}

TEST(test, mapInsert1) {
  s21::map<int, std::string> my_map;
  std::map<int, std::string> std_map;

  my_map.insert(1, "one");
  std_map.insert({1, "one"});
  my_map.insert(2, "two");
  std_map.insert({2, "two"});
  my_map.insert(22, "twotwo");
  std_map.insert({22, "twotwo"});
  my_map.insert(-22, "-twotwo");
  std_map.insert({-22, "-twotwo"});
  my_map.insert(22, "three");
  std_map.insert({22, "three"});
  my_map.insert(22234, "two3two");
  std_map.insert({22234, "two3two"});
  my_map.insert(12, "onetwo");
  std_map.insert({12, "onetwo"});
  my_map.insert(-12, "-onetwo");
  std_map.insert({-12, "-onetwo"});
  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();
  while (std_iter != std_map.end()) {
    ASSERT_EQ(my_iter.GetKey(), (*std_iter).first);
    ASSERT_EQ(*my_iter, (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, mapInsert2) {
  s21::map<int, std::string> my_map;
  std::map<int, std::string> std_map;

  my_map.insert({1, "one"});
  std_map.insert({1, "one"});
  my_map.insert({2, "two"});
  std_map.insert({2, "two"});
  my_map.insert({22, "twotwo"});
  std_map.insert({22, "twotwo"});
  my_map.insert({-22, "-twotwo"});
  std_map.insert({-22, "-twotwo"});
  my_map.insert({22, "three"});
  std_map.insert({22, "three"});
  my_map.insert({22234, "two3two"});
  std_map.insert({22234, "two3two"});
  my_map.insert({12, "onetwo"});
  std_map.insert({12, "onetwo"});
  my_map.insert({-12, "-onetwo"});
  std_map.insert({-12, "-onetwo"});
  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();
  while (std_iter != std_map.end()) {
    ASSERT_EQ(my_iter.GetKey(), (*std_iter).first);
    ASSERT_EQ(*my_iter, (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, mapErace1) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();

  my_map.erase(my_iter);
  std_map.erase(std_iter);

  my_iter = my_map.begin();
  std_iter = std_map.begin();

  while (std_iter != std_map.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map.end());
}

TEST(test, mapErace2) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();
  ++my_iter;
  ++std_iter;

  my_map.erase(my_iter);
  std_map.erase(std_iter);

  my_iter = my_map.begin();
  std_iter = std_map.begin();

  while (std_iter != std_map.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map.end());
}

TEST(test, mapErace3) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();
  ++my_iter;
  ++std_iter;
  ++my_iter;
  ++std_iter;

  my_map.erase(my_iter);
  std_map.erase(std_iter);

  my_iter = my_map.begin();
  std_iter = std_map.begin();

  while (std_iter != std_map.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map.end());
}

TEST(test, mapSwap) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  s21::map<int, std::string> my_map2{
      std::make_pair(-42, "fodasfo"), std::make_pair(323, "basdar"),
      std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba")};
  std::map<int, std::string> std_map2{
      std::make_pair(-42, "fodasfo"), std::make_pair(323, "basdar"),
      std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba")};

  my_map.swap(my_map2);
  std_map.swap(std_map2);

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();

  while (std_iter != std_map.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map.end());

  my_iter = my_map2.begin();
  std_iter = std_map2.begin();

  while (std_iter != std_map2.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map2.end());
}

TEST(test, mapMerge) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  s21::map<int, std::string> my_map2{
      std::make_pair(42, "foo"), std::make_pair(323, "basdar"),
      std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba")};
  std::map<int, std::string> std_map2{
      std::make_pair(42, "foo"), std::make_pair(323, "basdar"),
      std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba")};

  my_map.merge(my_map2);
  std_map.merge(std_map2);

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();

  while (std_iter != std_map.end()) {
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map.end());
}

TEST(test, mapInsertAsign) {
  s21::map<int, std::string> my_map;
  std::map<int, std::string> std_map;

  my_map.insert_or_assign(1, "one");
  std_map.insert_or_assign(1, "one");
  my_map.insert_or_assign(2, "two");
  std_map.insert_or_assign(2, "two");
  my_map.insert_or_assign(22, "twotwo");
  std_map.insert_or_assign(22, "twotwo");
  my_map.insert_or_assign(-22, "-twotwo");
  std_map.insert_or_assign(-22, "-twotwo");
  my_map.insert_or_assign(22, "three");
  std_map.insert_or_assign(22, "three");
  my_map.insert_or_assign(22234, "two3two");
  std_map.insert_or_assign(22234, "two3two");
  my_map.insert_or_assign(12, "onetwo");
  std_map.insert_or_assign(12, "onetwo");
  my_map.insert_or_assign(-12, "-onetwo");
  std_map.insert_or_assign(-12, "-onetwo");

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();
  while (std_iter != std_map.end()) {
    ASSERT_EQ(my_iter.GetKey(), (*std_iter).first);
    ASSERT_EQ(*my_iter, (*std_iter).second);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, mapContains) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  ASSERT_EQ(my_map.contains(42), true);
  ASSERT_EQ(my_map.contains(42342), false);
  ASSERT_EQ(my_map.contains(33), true);
  ASSERT_EQ(my_map.contains(0), false);
}

TEST(test, mapEmplace) {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  std::map<int, std::string> std_map2{
      std::make_pair(42, "foo"), std::make_pair(323, "basdar"),
      std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba")};

  std_map.merge(std_map2);
  my_map.insert_many(std::make_pair(42, "foo"), std::make_pair(323, "basdar"),
                 std::make_pair(343, "abobaaWD"), std::make_pair(-3, "ba"));

  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();

  while (std_iter != std_map.end()) {
    ASSERT_TRUE(*my_iter == (*std_iter).second);
    ASSERT_TRUE(my_iter.GetKey() == (*std_iter).first);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(my_iter == my_map.end());
}
