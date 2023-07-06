#include "v_f_parser.h"

// int main() {
//   s21::ObjectData object_data;
//   std::string file_path = "/Users/chamomiv/Downloads/ring.obj";
//   s21::Parser::RecordDataFromFile(file_path, object_data);
//   for (const auto &vertex : object_data.vertices) {
//     std::cout << "v " << vertex.x << " " << vertex.y << " " << vertex.z
//               << std::endl;
//   }
//   for (const auto &facet : object_data.facets) {
//     std::cout << facet << " ";
//     // << std::endl;
//   }
//   // for (const auto& facet : object_data.facets) {
//   //   std::cout << "f";
//   //   for (int index : facet) {
//   //     std::cout << " " << index;
//   //   }
//   //   std::cout << std::endl;
//   // }
//   // const s21::Facet& last_facet = object_data.facets.back();
//   // int first_index = last_facet.front();
//   // int last_index = last_facet.back();
//   // std::cout << first_index << " " << last_index << std::endl;
//   return 0;
// }

bool s21::VFParser::RecordDataFromFile(const std::string &file_path,
                                     s21::ObjectData &object_data) {
    std::ifstream input_file(file_path);
    if (!input_file.is_open()) {
        return false;
    }

    std::ios::sync_with_stdio(false);
    object_data.facets.clear();
    object_data.vertices.clear();
    std::string line;
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        std::string data_type;
        iss >> data_type;
        if (data_type == "v") {
            RecordVertex(iss, object_data);
        } else if (data_type == "f" && !object_data.vertices.empty()) {
            RecordFacet(iss, object_data);
        }
    }
    input_file.close();
    return true;
}

void s21::VFParser::RecordVertex(std::istringstream &iss,
                               s21::ObjectData &object_data) {
    s21::Vertex vertex{};
    iss >> vertex.x >> vertex.y >> vertex.z;
    object_data.vertices.push_back(vertex);
}

void s21::VFParser::RecordFacet(std::istringstream &iss,
                              s21::ObjectData &object_data) {
    int facet_value;
    std::string facet_string;
    std::vector<unsigned int> source_facets;
    while (iss >> facet_string) {
        std::istringstream facet_iss(facet_string);
        std::string facet_data;
        std::getline(facet_iss, facet_data, '/');
        facet_value = std::stoi(facet_data) - 1;
        if (facet_value < 0) {
            facet_value = (int) object_data.vertices.size() + facet_value + 1;
        }
        source_facets.push_back(facet_value);
    }

    object_data.facets.push_back(source_facets[0]);
    for (size_t i = 1; i < source_facets.size(); ++i) {
        object_data.facets.push_back(source_facets[i]);
        object_data.facets.push_back(source_facets[i]);
    }
    object_data.facets.push_back(source_facets[0]);
}
