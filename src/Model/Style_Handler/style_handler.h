#ifndef CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_H_
#define CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_H_

#include "map"
#include "string"

namespace s21 {
class StyleHandler {
 public:
 private:
  int type_of_point_;
  bool projection_;
  bool dotted_line_;
  float line_width_;
  float point_size_;

  std::map<std::string, int> colors_ {
      std::pair<std::string, int>("color_of_line_r", 0),
      std::pair<std::string, int>("color_of_line_g", 0),
      std::pair<std::string, int>("color_of_line_b", 0),
      std::pair<std::string, int>("color_of_back_r", 0),
      std::pair<std::string, int>("color_of_back_g", 0),
      std::pair<std::string, int>("color_of_back_b", 0),
      std::pair<std::string, int>("color_of_point_r", 0),
      std::pair<std::string, int>("color_of_point_g", 0),
      std::pair<std::string, int>("color_of_point_b", 0)};
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_STYLE_HANDLER_H_
