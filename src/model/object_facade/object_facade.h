#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_OBJECT_FACADE_OBJECT_FACADE_H
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_OBJECT_FACADE_OBJECT_FACADE_H

#include "../parser/parser_strategy.h"
#include "../parser/simple_parser.h"
#include "../transformer/transformer.h"

namespace s21 {

class ObjectFacade {
 public:
  ModelData GetModelData() { return model_data_; }

  void ParseDataFromFile(std::string filename) {
    ParserStrategy<SimpleParser>::ParseDataFromFile(filename, &model_data_);
  }

  void Rotate(double value, int coordinate) {
    Transformer::Rotate(&model_data_, value, coordinate);
  }

  void Move(double value, int coordinate) {
    Transformer::Move(&model_data_, value, coordinate);
  }

  void Scale(double value) { Transformer::Scale(&model_data_, value); }

  void ClearData() { model_data_ = {}; }

 private:
  ModelData model_data_ = {};
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_OBJECT_FACADE_OBJECT_FACADE_H
