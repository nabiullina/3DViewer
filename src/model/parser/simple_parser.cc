#include "simple_parser.h"

#include <sstream>
#include <utility>

void s21::SimpleParser::ParseDataFromFile(std::string file_path,
                                          s21::ModelData *model_data) {
  std::vector<int> count_blocks = CountBlocks(file_path, model_data);
  std::ifstream file_stream;
  file_stream.open(file_path);

  int f_block_count = 0;
  int count_all_blocks = 0;
  int count_verticies = 0;

  std::string str;
  while (getline(file_stream, str)) {
    std::istringstream ss(str);
    std::string token;
    ss >> token;
    if (token == "v" && f_block_count == 0) {
      model_data->vertexes[count_verticies++] /= model_data->max_coord;
      model_data->vertexes[count_verticies++] /= model_data->max_coord;
      model_data->vertexes[count_verticies++] /= model_data->max_coord;
    } else if (token == "v" && f_block_count == 1) {
      count_all_blocks += 1;
      model_data->vertexes[count_verticies++] /= model_data->max_coord;
      model_data->vertexes[count_verticies++] /= model_data->max_coord;
      model_data->vertexes[count_verticies++] /= model_data->max_coord;
      f_block_count = 0;
    }
    if (token == "f") {
      ParseFacets(ss, model_data, count_all_blocks, count_blocks);
      f_block_count = 1;
    }
  }
  if (model_data->max_coord < 1) {
    model_data->max_coord = 2;
  }
  file_stream.close();
}

std::vector<int> s21::SimpleParser::CountBlocks(std::string file_path,
                                                s21::ModelData *model_data) {
  std::ifstream file_stream;
  file_stream.open(file_path);
  //  if (!file_stream.is_open()) {
  //    throw std::invalid_argument("File opening error");
  //  }
  std::vector<int> result;
  std::string str;
  int count_v_block = 0;
  int count_f_block = 0;

  while (getline(file_stream, str)) {
    std::istringstream input_stream(str);
    std::string token;
    input_stream >> token;
    if ((count_v_block == 1 && count_f_block == 1) && token == "v") {
      result.push_back(model_data->count_v);
      count_f_block = 0;
      count_v_block = 0;
    }
    if (token == "v") {
      ParseVertexes(input_stream, model_data);
      model_data->count_v++;
      count_v_block = 1;
    } else if (token == "f") {
      model_data->count_p++;
      count_f_block = 1;
    }
  }
  result.push_back(model_data->count_v);
  file_stream.close();

  model_data->max_coord =
      model_data->max_x > model_data->max_y   ? model_data->max_x
      : model_data->max_y > model_data->max_z ? model_data->max_y
                                              : model_data->max_z;
  return result;
}
void s21::SimpleParser::ParseFacets(std::istringstream &string_stream,
                                    s21::ModelData *model_data,
                                    int count_all_blocks,
                                    std::vector<int> count_blocks) {
  std::vector<int> tmp_res;
  std::string token;
  while (string_stream >> token) {
    std::istringstream input_string_stream(token);
    std::string vert;
    getline(input_string_stream, vert, '/');
    int dbl = std::stoi(vert);
    if (dbl < 0) {
      dbl = count_blocks.at(count_all_blocks) + dbl + 1;
    }
    tmp_res.push_back(dbl);
  }
  model_data->facets.push_back(tmp_res.at(0) - 1);
  for (unsigned long i = 1; i < tmp_res.size(); i++) {
    model_data->facets.push_back(tmp_res.at(i) - 1);
    model_data->facets.push_back(tmp_res.at(i) - 1);
  }
  model_data->facets.push_back(tmp_res.at(0) - 1);
}
void s21::SimpleParser::ParseVertexes(std::istringstream &string_stream,
                                      s21::ModelData *model_data) {
  double tmp_res;
  // std::vector<double> vertexes;
  for (int i = 0; i < 3; i++) {
    string_stream >> tmp_res;
    model_data->vertexes.push_back(tmp_res);
    if (i == 0) {
      if (model_data->vertexes.size() > 3) {
        model_data->max_x =
            fabs(model_data->vertexes.back()) > fabs(model_data->max_x)
                ? fabs(model_data->vertexes.back())
                : fabs(model_data->max_x);
        model_data->min_x =
            fabs(model_data->vertexes.back()) < fabs(model_data->min_x)
                ? fabs(model_data->vertexes.back())
                : fabs(model_data->min_x);
      } else {
        model_data->max_x = fabs(model_data->vertexes.back());
        model_data->min_x = fabs(model_data->vertexes.back());
      }
    } else if (i == 1) {
      if (model_data->vertexes.size() > 3) {
        model_data->max_y =
            fabs(model_data->vertexes.back()) > fabs(model_data->max_y)
                ? fabs(model_data->vertexes.back())
                : fabs(model_data->max_y);
        model_data->min_y =
            fabs(model_data->vertexes.back()) < fabs(model_data->min_y)
                ? fabs(model_data->vertexes.back())
                : fabs(model_data->min_y);
      } else {
        model_data->max_y = fabs(model_data->vertexes.back());
        model_data->min_y = fabs(model_data->vertexes.back());
      }
    } else {
      if (model_data->vertexes.size() > 3) {
        model_data->max_z =
            fabs(model_data->vertexes.back()) > fabs(model_data->max_z)
                ? fabs(model_data->vertexes.back())
                : fabs(model_data->max_z);
        model_data->min_z =
            fabs(model_data->vertexes.back()) < fabs(model_data->min_z)
                ? fabs(model_data->vertexes.back())
                : fabs(model_data->min_z);
      } else {
        model_data->max_z = fabs(model_data->vertexes.back());
        model_data->min_z = fabs(model_data->vertexes.back());
      }
    }
  }
  // for (auto vertex : vertexes) {
  //   model_data->vertexes_.push_back(vertex);
  // }
}
