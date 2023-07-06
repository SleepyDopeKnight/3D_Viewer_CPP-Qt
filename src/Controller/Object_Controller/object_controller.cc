#include "object_controller.h"

namespace s21 {
  bool ObjectHandlerController::RecordDataFromFile(std::string file_path) {
    return object_model_->RecordData(file_path);
  }
}  // namespace s21