#include <data.h>

DataParsing::DataParsing(std::string filename, int height) {
    height_ = height;
    std::ifstream myfile(filename);
    std::string line;
    std::vector<int> nodes(height, 0);
    std::vector<std::vector<int> graph(height, nodes);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if (line.substr(0, 1) != "#") {
                std::string s = ""
                int row = 0;
                int col = 0;
                for (unsigned i = 0; i < line.length(); i++) {
                    if (s != "" && line.substr(i, 1) == " ") {
                        col = std::stoi(s);
                        s = "";
                    }
                    s += line.substr(i, 1);
                    if (i == line.length() - 1) {
                        row == std::stoi(s);
                        s = "";
                    }
                }
                graph.at(row).at(col) = 1;
            }
        }
        myfile.close();
    }
    adjacency_matrix = graph;
    transit_matrix = adjacency_matrix;
    for (unsigned j = 0; j < graph.at(0).size(); j++) {
        int sum = 0;
        for (unsigned i = 0; i < graph.size(); i++) {
            sum += graph.at(i).at(j);
        }
        
        for (unsigned i = 0; i < graph.size(); i++) {
            if (sum == 0) {
                transit_matrix.at(i).at(j) = ((double) 1.0 / (double) height);
            } else {
                transit_matrix.at(i).at(j) = ((double) graph.at(i).at(j) / (double) height);
            }
        }
    }
}


std::vector<std::vector<GraphNode>> DataParsing::getAdjacencyMatrix() {
    return adjacency_matrix;
}
std::vector<std::vector<GraphNode>> DataParsing::getTransitMatrix() {
    return transit_matrix;
}