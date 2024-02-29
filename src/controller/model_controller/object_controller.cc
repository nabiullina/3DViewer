#include "object_controller.h"

s21::ObjectController *s21::ObjectController::object_controller_ = nullptr;

void s21::ObjectController::ParseDataFromFile(std::string file_path) {
  object_facade_->ParseDataFromFile(file_path);
}
void s21::ObjectController::Rotate(double value, int coordinate) {
  object_facade_->Rotate(value, coordinate);
}
void s21::ObjectController::Move(double value, int coordinate) {
  object_facade_->Move(value, coordinate);
}
void s21::ObjectController::Scale(double value) {
  object_facade_->Scale(value);
}

s21::ObjectController::ObjectController(s21::ObjectFacade *object_facade) {
  object_facade_ = object_facade;
}

s21::ObjectController *s21::ObjectController::GetInstance(
    s21::ObjectFacade *object_facade) {
  if (object_controller_ == nullptr) {
    object_controller_ = new ObjectController(object_facade);
  }
  return object_controller_;
}

s21::ModelData s21::ObjectController::GetModelData() {
  return object_facade_->GetModelData();
}

void s21::ObjectController::ClearData() { object_facade_->ClearData(); }

int s21::ObjectController::GetCountV() {
  return object_facade_->GetModelData().count_v;
}

int s21::ObjectController::GetCountP() {
  return object_facade_->GetModelData().count_p;
}
