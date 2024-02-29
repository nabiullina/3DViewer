#include "view_controller.h"

s21::ViewController::ViewController(s21::StyleView* style_view) {
  this->style_view_ = style_view;
}

void s21::ViewController::SaveSettings() { style_view_->SaveSettings(); }

void s21::ViewController::SetColors(std::map<std::string, float> colors) {
  style_view_->SetColors(colors);
}

void s21::ViewController::SetType(std::map<std::string, int> type) {
  style_view_->SetType(type);
}

void s21::ViewController::SetSize(std::map<std::string, int> size) {
  style_view_->SetSize(size);
}

std::map<std::string, float> s21::ViewController::GetColors() {
  return style_view_->GetColors();
}

std::map<std::string, int> s21::ViewController::GetSize() {
  return style_view_->GetSize();
}

std::map<std::string, int> s21::ViewController::GetType() {
  return style_view_->GetType();
}
