#ifndef CPP4_3DVIEWER_V2_0_1_COMMON_H_
#define CPP4_3DVIEWER_V2_0_1_COMMON_H_

#include <vector>

namespace s21 {

struct Vertex {
  float x, y, z;
};

struct ObjectData {
  std::vector<unsigned int> facets;
  std::vector<Vertex> vertices;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_COMMON_H_
