#include <gtest/gtest.h>

#include <cmath>
#include <vector>

#include "../model/object_facade/object_facade.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(parse_test, test_one_block) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/cube.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  EXPECT_EQ(model_data.count_p, 6);
  EXPECT_EQ(model_data.count_v, 8);
  EXPECT_EQ(model_data.facets.at(0), 0);
  EXPECT_EQ(model_data.facets.at(1), 4);
  EXPECT_EQ(model_data.facets.at(3), 6);
  EXPECT_EQ(model_data.facets.at(5), 2);
}

TEST(parse_test, test_many_blocks) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/skull.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  EXPECT_EQ(model_data.count_v, 6122);
  EXPECT_EQ(model_data.count_p, 9537);
}

TEST(parse_test, test_clear_data) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/skull.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  EXPECT_EQ(model_data.count_v, 6122);
  EXPECT_EQ(model_data.count_p, 9537);
  obj_fac.ClearData();
  model_data = obj_fac.GetModelData();
  EXPECT_EQ(model_data.count_v, 0);
  EXPECT_EQ(model_data.count_p, 0);
}

TEST(move_test, test1) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/cube.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  s21::Transformer::Move(&model_data, 1, 0);
  EXPECT_EQ(model_data.vertexes.at(0), 2);
  EXPECT_EQ(model_data.vertexes.at(3), 2);
  EXPECT_EQ(model_data.vertexes.at(6), 2);
  EXPECT_EQ(model_data.vertexes.at(9), 2);
  EXPECT_EQ(model_data.vertexes.at(12), 0);
  EXPECT_EQ(model_data.vertexes.at(15), 0);
  EXPECT_EQ(model_data.vertexes.at(18), 0);
  EXPECT_EQ(model_data.vertexes.at(21), 0);
}

TEST(affine_test, test_x) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/cube.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  s21::Transformer::Rotate(&model_data, 15, 0);
  double res1 = cos(M_PI * 15 / 180) * 1 + sin(M_PI * 15 / 180) * (-1);
  double res2 = sin(M_PI * 15 / 180) * (-1) + cos(M_PI * 15 / 180) * (-1);
  EXPECT_EQ(model_data.vertexes.at(1), res1);
  EXPECT_EQ(model_data.vertexes.at(2), res2);
  EXPECT_EQ(model_data.vertexes.at(22), -res1);
  EXPECT_EQ(model_data.vertexes.at(23), -res2);
}

TEST(affine_test, test_y) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/cube.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  s21::Transformer::Rotate(&model_data, 15, 1);
  double res1 = cos(M_PI * 15 / 180) * 1 + sin(M_PI * 15 / 180) * (-1);
  double res2 = sin(M_PI * 15 / 180) * (-1) + cos(M_PI * 15 / 180) * (-1);
  EXPECT_EQ(model_data.vertexes.at(0), res1);
  EXPECT_EQ(model_data.vertexes.at(2), res2);
  EXPECT_EQ(model_data.vertexes.at(21), -res1);
  EXPECT_EQ(model_data.vertexes.at(23), -res2);
}

TEST(affine_test, test_z) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/cube.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  s21::Transformer::Rotate(&model_data, 15, 2);
  double res1 = cos(M_PI * 15 / 180) * 1 + sin(M_PI * 15 / 180) * (-1);
  double res2 = sin(M_PI * 15 / 180) * (-1) + cos(M_PI * 15 / 180) * (-1);
  EXPECT_EQ(model_data.vertexes.at(0), res1);
  EXPECT_EQ(model_data.vertexes.at(1), -res2);
  EXPECT_EQ(model_data.vertexes.at(21), -res1);
  EXPECT_EQ(model_data.vertexes.at(22), res2);
}

TEST(scale_test, test1) {
  s21::ObjectFacade obj_fac;
  obj_fac.ParseDataFromFile("./tests/cube.obj");
  s21::ModelData model_data = obj_fac.GetModelData();
  s21::Transformer::Scale(&model_data, 2);
  EXPECT_EQ(model_data.vertexes.at(0), 2);
  EXPECT_EQ(model_data.vertexes.at(1), 2);
  EXPECT_EQ(model_data.vertexes.at(2), -2);
  EXPECT_EQ(model_data.vertexes.at(3), 2);
  EXPECT_EQ(model_data.vertexes.at(4), -2);
  EXPECT_EQ(model_data.vertexes.at(5), -2);
  EXPECT_EQ(model_data.vertexes.at(6), 2);
  EXPECT_EQ(model_data.vertexes.at(7), 2);
  EXPECT_EQ(model_data.vertexes.at(7), 2);
}
