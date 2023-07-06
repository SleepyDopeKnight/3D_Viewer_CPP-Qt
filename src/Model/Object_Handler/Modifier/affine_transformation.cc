#include "affine_transformation.h"

namespace s21 {
void AffineTransformation::RotationOnAxisX(std::vector<Vertex>& vertices,
                                           float angle, int increment) {
  angle = 6.28 * angle / 360;
  float y = vertices[increment].y;
  float z = vertices[increment].z;
  vertices[increment].y = y * std::cosf(angle) + z * std::sinf(angle);
  vertices[increment].z = -y * std::sinf(angle) + z * std::cosf(angle);
}

void AffineTransformation::RotationOnAxisY(std::vector<Vertex>& vertices,
                                           float angle, int increment) {
  angle = 6.28 * angle / 360;
  float x = vertices[increment].x;
  float z = vertices[increment].z;
  vertices[increment].x = x * cosf(angle) + z * sinf(angle);
  vertices[increment].z = -x * sinf(angle) + z * cosf(angle);
}

void AffineTransformation::RotationOnAxisZ(std::vector<Vertex>& vertices,
                                           float angle, int increment) {
  angle = 3.14 * angle / 180;
  float x = vertices[increment].x;
  float y = vertices[increment].y;
  vertices[increment].x = x * cosf(angle) + y * sinf(angle);
  vertices[increment].y = -x * sinf(angle) + y * cosf(angle);
}

void AffineTransformation::Transform(std::vector<Vertex>& source_vertices,
                                     std::vector<Vertex>& vertices, int x,
                                     int y, int z, float angle_x, float angle_y,
                                     float angle_z, float scale, float max_z) {
  for (int i = 0; i < source_vertices.size() * 3; i += 3) {
    vertices[i].x = source_vertices[i].x;
    vertices[i].y = source_vertices[i].y;
    vertices[i].z = source_vertices[i].z;
    RotationOnAxisX(vertices, angle_x, i);
    RotationOnAxisY(vertices, angle_y, i);
    RotationOnAxisZ(vertices, angle_z, i);
    vertices[i].x = (vertices[i].x + (float)x / (float)25.0 * max_z) * scale;
    vertices[i].y = (vertices[i].y + (float)y / (float)25.0 * max_z) * scale;
    vertices[i].z = (vertices[i].z + (float)z / (float)25.0 * max_z) * scale;
  }
}

}  // namespace s21