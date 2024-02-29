#ifndef CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_MODEL_CONTROLLER_VIEW_CONTROLLER_H
#define CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_MODEL_CONTROLLER_VIEW_CONTROLLER_H

#include "../../model/model_view/model_view.h"

namespace s21 {
class ViewController {
 public:
  ViewController(s21::StyleView* style_view);
  void SaveSettings();
  std::map<std::string, float> GetColors();
  std::map<std::string, int> GetType();
  std::map<std::string, int> GetSize();

  void SetColors(std::map<std::string, float> colors);
  void SetType(std::map<std::string, int> type);
  void SetSize(std::map<std::string, int> size);

 private:
  s21::StyleView* style_view_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_MODEL_CONTROLLER_VIEW_CONTROLLER_H
