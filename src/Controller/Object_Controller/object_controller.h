#ifndef CPP4_3DVIEWER_V2_0_1_OBJECT_HANDLER_CONTROLLOER_H_
#define CPP4_3DVIEWER_V2_0_1_OBJECT_HANDLER_CONTROLLOER_H_

#include <string>
#include "../../Model/Object_Handler/object_facade.h"

namespace s21 {
  class ObjectHandlerController {
  public:
    ObjectHandlerController(s21::ObjectFacade *object_model_) : object_model_(object_model_) {};

    bool RecordDataFromFile(std::string file_path);

    s21::ObjectData GetData() { return object_model_->GetObjectData(); };

  private:
    s21::ObjectFacade *object_model_;
  };

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_OBJECT_HANDLER_CONTROLLOER_H_
