#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_VIEW_MODEL_VIEW_H
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_VIEW_MODEL_VIEW_H

#include <QDir>
#include <QSettings>
#include <QStandardPaths>
#include <iostream>
#include <map>
#include <string>

namespace s21 {

class StyleView {
 public:
  StyleView();
  void SaveSettings();
  std::map<std::string, float> GetColors();
  std::map<std::string, int> GetType();
  std::map<std::string, int> GetSize();

  void SetColors(std::map<std::string, float> colors);
  void SetType(std::map<std::string, int> type);
  void SetSize(std::map<std::string, int> size);

 private:
  void InitSettings();
  std::map<std::string, float> colors_;
  std::map<std::string, int> type_;
  std::map<std::string, int> size_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_VIEW_MODEL_VIEW_H