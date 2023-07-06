#ifndef CPP4_3DVIEWER_V2_0_1_AFFINE_TRANSFORMATION_H_
#define CPP4_3DVIEWER_V2_0_1_AFFINE_TRANSFORMATION_H_

#include <cmath>

#include "../common.h"

namespace s21 {
class AffineTransformation {
  static void RotationOnAxisX(std::vector<Vertex> &vertices, float angle,
                              int increment);
  static void RotationOnAxisY(std::vector<Vertex> &vertices, float angle,
                              int increment);
  static void RotationOnAxisZ(std::vector<Vertex> &vertices, float angle,
                              int increment);

  static void Transform(std::vector<Vertex> &source_vertices,
                        std::vector<Vertex> &vertices, int x, int y, int z,
                        float angle_x, float angle_y, float angle_z,
                        float scale, float max_z);
};

}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_AFFINE_TRANSFORMATION_H_
