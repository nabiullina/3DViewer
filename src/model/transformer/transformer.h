#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_TRANSFORMER_TRANSFORMER_H
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_TRANSFORMER_TRANSFORMER_H

#include <cmath>

#include "../model_data.h"

namespace s21 {

class Transformer {
 public:
  static void Rotate(ModelData *model_data, double value, int coordinate);

  static void Scale(ModelData *model_data, double value);

  static void Move(ModelData *model_data, double value, int coordinate);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_TRANSFORMER_TRANSFORMER_H
