#include <Graph.h>
#include <iostream>
#include <vector>
#include <GraphNode.h>


class DataParsing {
    public:
        DataParsing(std::string filename, int height);
        std::vector<std::vector<int>> getAdjacencyMatrix();
        std::vector<std::vector<double>> getTransitMatrix();


    private:
        int height_;
        std::vector<std::vector<int>> adjacency_matrix;
        std::vector<std::vector<double>> transit_matrix;
};