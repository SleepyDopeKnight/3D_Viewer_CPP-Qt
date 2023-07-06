#include "object_facade.h"

namespace s21 {
bool ObjectFacade::RecordData(const std::string& file_path) {
  return StrategyRecorder<VFParser>::RecordDataFromFile(file_path, object_data_);
}
}  // namespace s21