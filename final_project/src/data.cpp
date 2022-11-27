#include <data.h>
#include <utils.h>

DataParsing::DataParsing(std::string filename, int height) {
    // V2D table;
    // std::string file = file_to_string(filename);
    // std::vector<std::string> lines;
    // int size = SplitString(file, '\n', lines);
    // for (int i = 0; i < size; i++) {
    //     lines.at(i) = Trim(lines.at(i));
    //     std::vector<std::string> to_push;
    //     int j = SplitString(lines.at(i), ',', to_push);
    //     for (int k = 0; k < j; k++) {
    //         to_push.at(k) = Trim(to_push.at(k));
    //     }
    //     table.push_back(to_push);
    // }
    // return table;
    height_ = height;
    std::string file = file_to_string(filename);
    std::string line;
    std::vector<int> nodes(height_, 0);
    std::vector<std::vector<int>> graph(height_, nodes);
    std::vector<std::string> lines;
    int size = SplitString(file, '\n', lines);
    for (int i = 0; i < size; i++) {
        lines.at(i) = Trim(lines.at(i));
        std::vector<std::string> each_line;
        int j = SplitString(lines.at(i), ' ', each_line);
        for (int k = 0; k < j; k++) {
            each_line.at(k) = Trim(each_line.at(k));
            
        }
        if (row >= 0 && row <= height_ && col >= 0 && col <= height_) {
            row = std::stoi(each_line.at(1));
            col = std::stoi(each_line.at(0));
            graph.at(row).at(col) = 1;
        }
        
    }
    //     while (getline(myfile, line)) {
    //         if (line.substr(0, 1) != "#") {
    //             std::string s = ""
    //             int row = 0;
    //             int col = 0;
    //             for (unsigned i = 0; i < line.length(); i++) {
    //                 if (s != "" && line.substr(i, 1) == " ") {
    //                     col = std::stoi(s);
    //                     s = "";
    //                 }
    //                 s += line.substr(i, 1);
    //                 if (i == line.length() - 1) {
    //                     row == std::stoi(s);
    //                     s = "";
    //                 }
    //             }
    //             graph.at(row).at(col) = 1;
    //         }
    //     }
    //     myfile.close();

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


std::vector<std::vector<int>> DataParsing::getAdjacencyMatrix() {
    return adjacency_matrix;
}
std::vector<std::vector<double>> DataParsing::getTransitMatrix() {
    return transit_matrix;
}