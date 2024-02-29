#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_PARSER_H
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_PARSER_H

#include <iostream>

#include "../model_data.h"

namespace s21 {

class Parser {
 public:
  void ParseDataFromFile(std::string filename, ModelData *model_data){};
  Parser() = default;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_PARSER_H
