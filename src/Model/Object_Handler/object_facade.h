#ifndef CPP4_3DVIEWER_V2_0_1_OBJECT_FACADE_H_
#define CPP4_3DVIEWER_V2_0_1_OBJECT_FACADE_H_

#include "Recorder/V_F_Recorder/v_f_parser.h"
#include "Recorder/strategy_recorder.h"
#include "common.h"

namespace s21 {
class ObjectFacade {
 public:
  // main logic
  bool RecordData(const std::string& file_path);

  // getters and setters
  s21::ObjectData GetObjectData() { return object_data_; };

 private:
  s21::ObjectData object_data_;
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_OBJECT_FACADE_H_
