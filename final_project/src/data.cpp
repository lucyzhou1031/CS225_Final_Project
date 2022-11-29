#include <data.h>
#include <utils.h>
#include <ctype.h>

#include <iomanip>
#include <sstream>

DataParsing::DataParsing(std::string filename, int height) {
    height_ = height;
    std::string file = file_to_string(filename);
    std::string line;
    std::vector<int> nodes(height_, 0);
    std::vector<std::vector<int>> graph(height_, nodes);
    std::vector<std::string> lines;
    int size = SplitString(file, '\n', lines);
    for (int i = 0; i < size; i++) {
        if(!isdigit(lines.at(i).at(0))) {
            continue;
        }
        lines.at(i) = Trim(lines.at(i));
        std::vector<std::string> each_line;
        int j = SplitString(lines.at(i), ' ', each_line);
        if (each_line.size() != 2) {
            continue;
        }
        for (int k = 0; k < j; k++) {
            each_line.at(k) = Trim(each_line.at(k));
        }
        int row = std::stoi(each_line.at(1));
        int col = std::stoi(each_line.at(0));
        std::cout << row << " " << col << std::endl;
        graph.at(row).at(col) = 1;
        if (row >= 0 && row <= height_ && col >= 0 && col <= height_) {
            
        }
    }

    // adjacency_matrix = graph;
    // transit_matrix = adjacency_matrix;
    for (unsigned i = 0; i < adjacency_matrix.size(); i++) {
        std::vector<double> result;
        std::vector<int> uu;
        for (unsigned j = 0; j < adjacency_matrix.at(i).size(); j++) {
            result.push_back((double)graph.at(i).at(j));
            uu.push_back(graph.at(i).at(j));
        }
        adjacency_matrix.push_back(uu);
        transit_matrix.push_back(result);
    }
    for (unsigned j = 0; j < graph.at(0).size(); j++) {
        int sum = 0;
        for (unsigned i = 0; i < graph.size(); i++) {
            sum += graph.at(i).at(j);
        }
        
        for (unsigned i = 0; i < graph.size(); i++) {
            if (sum == 0) {
                transit_matrix.at(i).at(j) = toPrecise(((double) 1.0 / (double) height_), 3); 
            } else {
                transit_matrix.at(i).at(j) = toPrecise(((double) graph.at(i).at(j) / (double) height_), 3);
            }
        }
    }
}

double DataParsing::toPrecise(double input, int precision) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << input;
    std::string s = stream.str();
    return std::stod(s);
}
std::vector<std::vector<int>> DataParsing::getAdjacencyMatrix() {
    return adjacency_matrix;
}
std::vector<std::vector<double>> DataParsing::getTransitMatrix() {
    return transit_matrix;
}