#include "transformer.h"

void s21::Transformer::Rotate(s21::ModelData *model_data, double value,
                              int coordinate) {
  double rad = M_PI * value / 180;
  if (coordinate == 0) {
    for (unsigned long i = 0; i < model_data->vertexes.size(); i += 3) {
      double temp_y = model_data->vertexes[i + 1];
      double temp_z = model_data->vertexes[i + 2];
      model_data->vertexes[i + 1] = cos(rad) * temp_y + sin(rad) * temp_z;
      model_data->vertexes[i + 2] = sin(rad) * (-temp_y) + cos(rad) * temp_z;
    }
  } else if (coordinate == 1) {
    for (unsigned long i = 1; i < model_data->vertexes.size(); i += 3) {
      double temp_x = model_data->vertexes[i - 1];
      double temp_z = model_data->vertexes[i + 1];
      model_data->vertexes[i - 1] = cos(rad) * temp_x + sin(rad) * temp_z;
      model_data->vertexes[i + 1] = sin(rad) * (-temp_x) + cos(rad) * temp_z;
    }
  } else if (coordinate == 2) {
    for (unsigned long i = 2; i < model_data->vertexes.size(); i += 3) {
      double temp_x = model_data->vertexes[i - 2];
      double temp_y = model_data->vertexes[i - 1];
      model_data->vertexes[i - 2] = cos(rad) * temp_x - sin(rad) * temp_y;
      model_data->vertexes[i - 1] = sin(rad) * temp_x + cos(rad) * temp_y;
    }
  }
}
void s21::Transformer::Scale(s21::ModelData *model_data, double value) {
  for (auto &vertex : model_data->vertexes) {
    vertex *= value;
  }
}
void s21::Transformer::Move(s21::ModelData *model_data, double value,
                            int coordinate) {
  for (unsigned long i = 0; i < model_data->vertexes.size() / 3; i++) {
    model_data->vertexes[i * 3 + coordinate] += value;
  }
}
