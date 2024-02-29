#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_STRATEGY_H
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_STRATEGY_H

#include <iostream>

#include "../model_data.h"

namespace s21 {
template <class Parser>
class ParserStrategy {
 public:
  static void ParseDataFromFile(std::string filename, ModelData *model_data) {
    Parser::ParseDataFromFile(filename, model_data);
  }
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_STRATEGY_H
