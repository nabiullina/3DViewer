#ifndef CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_MODEL_CONTROLLER_OBJECT_CONTROLLER_H
#define CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_MODEL_CONTROLLER_OBJECT_CONTROLLER_H

#include "../../model/object_facade/object_facade.h"

namespace s21 {

class ObjectController {
 public:
  static ObjectController *GetInstance(ObjectFacade *object_facade);

  ModelData GetModelData();

  void ParseDataFromFile(std::string file_path);
  void Rotate(double value, int coordinate);
  void Move(double value, int coordinate);
  void Scale(double value);
  void ClearData();
  int GetCountV();
  int GetCountP();

 private:
  static ObjectController *object_controller_;
  ObjectFacade *object_facade_{};

  ObjectController() = default;
  explicit ObjectController(ObjectFacade *object_facade_);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_CONTROLLER_MODEL_CONTROLLER_OBJECT_CONTROLLER_H
