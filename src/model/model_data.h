#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_DATA_H
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_DATA_H
#include <iostream>
#include <vector>

namespace s21 {

struct ModelData {
  int count_p;
  int count_v;
  double max_x;
  double max_y;
  double max_z;
  double min_x;
  double min_y;
  double min_z;
  double max_coord;
  std::vector<int> facets;
  std::vector<double> vertexes;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_DATA_H
