#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_SIMPLE_PARSER_H
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_SIMPLE_PARSER_H

#include <cmath>
#include <fstream>
#include <stdexcept>

#include "../model_data.h"
#include "parser.h"

namespace s21 {
class SimpleParser : Parser {
 public:
  static void ParseDataFromFile(std::string file_path, ModelData *model_data);

 private:
  static std::vector<int> CountBlocks(std::string file_path,
                                      s21::ModelData *model_data);
  static void ParseFacets(std::istringstream &string_stream,
                          s21::ModelData *model_data, int count_all_blocks,
                          std::vector<int> count_blocks);
  static void ParseVertexes(std::istringstream &string_stream,
                            s21::ModelData *model_data);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_SIMPLE_PARSER_H
