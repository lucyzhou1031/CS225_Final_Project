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
    unsigned count = 0;
    //count the latest col/row num
    for (int i = 0; i < size; i++) {
        // if(!isdigit(lines.at(i).at(0))) {
        //     continue;
        // }
        lines.at(i) = Trim(lines.at(i));
        std::vector<std::string> each_line;
        int j = SplitString(lines.at(i), ' ', each_line);
        for (unsigned k = 0; k < each_line.size(); k++) {
            each_line.at(k) = Trim(each_line.at(k));
        }
        std::vector<int> digits;
        for (std::string i : each_line) {
            if (i != "") {
                digits.push_back(std::stoi(i));
            }
        }
        if (digits.size() != 2) {
            continue;
        }
        int row = digits.at(1);
        int col = digits.at(0);
        if (mapping_idx.find(row) == mapping_idx.end()) {
            mapping_idx[row] = count;
            row = (int) count;
            count++;
        } else {
            row = mapping_idx.at(row);
        }
        if (mapping_idx.find(col) == mapping_idx.end()) {
            mapping_idx[col] = count;
            col = (int) count;
            count++;
        } else {
            col = mapping_idx.at(col);
        }
        graph.at(row).at(col) = 1;
    }
    for (unsigned i = 0; i < graph.size(); i++) {
        std::vector<double> result;
        std::vector<int> uu;
        for (unsigned j = 0; j < graph.at(i).size(); j++) {
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
                transit_matrix.at(i).at(j) = toPrecise(((double) graph.at(i).at(j) / (double) sum), 3);
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

std::map<int, unsigned> DataParsing::getMap() {
    return mapping_idx;
}

Graph DataParsing::getGraph() {

    for (auto it = mapping_idx.begin(); it != mapping_idx.end(); it++) {
        g.addVertex(it -> first);
    }
    
    for (unsigned i = 0; i < transit_matrix.size(); i++) {
        for (unsigned j = 0; j < transit_matrix.at(i).size(); j++) {
            if (transit_matrix.at(i).at(j) == 0.000) continue;
            int fromID = 0;
            int toID = 0;
            int count = 0;
            for (auto it = mapping_idx.begin(); it != mapping_idx.end(); it++) {
                if (it -> second == i) {
                    toID = it -> first;
                    count++;
                }
                if (it -> second == j) {
                    fromID = it -> first;
                    count++;
                }
                if (count == 2) {
                    g.addEdge(fromID, toID, transit_matrix.at(i).at(j));
                    //std::cout << fromID << " " << toID << " " << transit_matrix.at(i).at(j) << std::endl;
                    break;
                }
            }
            
        }
    }
    return g;
}