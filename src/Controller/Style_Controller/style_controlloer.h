#ifndef CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_CONTROLLOER_H_
#define CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_CONTROLLOER_H_

#include "../../Model/Style_Handler/style_handler.h"

namespace s21 {
class StyleHandlerController {
public:
  StyleHandlerController(s21::StyleHandler *style_model) : style_model_(style_model) {};

private:
  s21::StyleHandler *style_model_;

};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_CONTROLLOER_H_
