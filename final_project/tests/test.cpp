
#include "data.h"
#include "Graph.h"
#include "pageRank.h"
#include "dfs.h"
#include "dijkstras.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;         

template <typename T>
string print_matrix(vector<vector<T>> matrix, string test, string type){
    string filename = "test_" + test + "_" + type + "_output.txt";
    ofstream file;
    file.open(filename);
    if(matrix.size() < 0 || matrix[0].size() < 0){
        file << "invalid demension";
        return "invalid demension";
    }
    if(file.is_open()){
        for (unsigned int i = 0; i < matrix.size(); i++){
            for (unsigned int j= 0; j < matrix[0].size(); j++){
                file << to_string(matrix[i][j]);
                file << " ";
            }
            file << "\n";
        }
    }
    file.close();
    return filename;
}

TEST_CASE("test_extreme","[data_parsing, test_extreme_case]"){
    DataParsing test_extreme("/workspaces/cs225/CS225_Final_Project/final_project/test_extreme.txt", 10);
    //output adj/tran matrix into file
    vector<vector<int>> testAdj = test_extreme.getAdjacencyMatrix();
    print_matrix(testAdj, "extreme", "AdjMatrix");
    vector<vector<double>> testTran = test_extreme.getTransitMatrix();
    print_matrix(testTran, "extreme", "TranMatrix");
    //test data_parsing: output & expected
    const vector<vector<int>> expected_adj = {
        {0,1,0,0,1,1,1,0,0,0},\
        {0,0,0,0,0,0,0,0,0,1},\
        {0,1,1,0,0,1,0,0,0,0},\
        {0,1,0,0,0,0,1,0,0,0},\
        {0,0,0,0,0,0,0,0,0,0},\
        {0,0,0,0,0,0,0,0,0,0},\
        {0,0,0,0,0,0,0,0,0,0},\
        {0,0,0,0,0,0,0,0,1,0},\
        {0,0,0,0,0,0,0,0,0,0},\
        {0,0,0,0,0,0,0,0,0,0}
    };
    REQUIRE(testAdj == expected_adj);

    const vector<vector<double>> expected_trans = {
    {0.100,0.333,0.000,0.100,1.000,0.500,0.500,0.100,0.000,0.000},\
    {0.100,0.000,0.000,0.100,0.000,0.000,0.000,0.100,0.000,1.000},\
    {0.100,0.333,1.000,0.100,0.000,0.500,0.000,0.100,0.000,0.000},\
    {0.100,0.333,0.000,0.100,0.000,0.000,0.500,0.100,0.000,0.000},\
    {0.100,0.000,0.000,0.100,0.000,0.000,0.000,0.100,0.000,0.000},\
    {0.100,0.000,0.000,0.100,0.000,0.000,0.000,0.100,0.000,0.000},\
    {0.100,0.000,0.000,0.100,0.000,0.000,0.000,0.100,0.000,0.000},\
    {0.100,0.000,0.000,0.100,0.000,0.000,0.000,0.100,1.000,0.000},\
    {0.100,0.000,0.000,0.100,0.000,0.000,0.000,0.100,0.000,0.000},\
    {0.100,0.000,0.000,0.100,0.000,0.000,0.000,0.100,0.000,0.000}
    };
    REQUIRE(testTran == expected_trans);
}

TEST_CASE("test_small","[data_parsing, test_small_case]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_small.txt", 10);
    vector<vector<int>> testAdj = test_small.getAdjacencyMatrix();
    print_matrix(testAdj, "small", "AdjMatrix");
    vector<vector<double>> testTran = test_small.getTransitMatrix();
    print_matrix(testTran, "small", "TranMatrix");
    const vector<vector<int>> expected_adj = {
        {0,1,0,1,1,1,1,1,1,1},\
        {0,0,0,0,0,0,0,0,0,0},\
        {0,1,1,0,0,1,0,0,0,1},\
        {0,1,0,0,0,1,1,1,0,1},\
        {0,0,0,0,0,0,0,1,1,0},\
        {0,0,1,0,0,1,0,0,1,0},\
        {0,0,0,0,0,1,1,0,1,0},\
        {0,0,0,0,0,0,0,1,0,0},\
        {0,0,1,0,1,0,0,0,0,0},\
        {0,0,0,0,1,0,0,0,0,0}
    };

    REQUIRE(testAdj == expected_adj);

    const vector<vector<double>> expected_tran = {
        {0.100,0.333,0.000,1.000,0.333,0.200,0.333,0.250,0.250,0.333},\
        {0.100,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000},\
        {0.100,0.333,0.333,0.000,0.000,0.200,0.000,0.000,0.000,0.333},\
        {0.100,0.333,0.000,0.000,0.000,0.200,0.333,0.250,0.000,0.333},\
        {0.100,0.000,0.000,0.000,0.000,0.000,0.000,0.250,0.250,0.000},\
        {0.100,0.000,0.333,0.000,0.000,0.200,0.000,0.000,0.250,0.000},\
        {0.100,0.000,0.000,0.000,0.000,0.200,0.333,0.000,0.250,0.000},\
        {0.100,0.000,0.000,0.000,0.000,0.000,0.000,0.250,0.000,0.000},\
        {0.100,0.000,0.333,0.000,0.333,0.000,0.000,0.000,0.000,0.000},\
        {0.100,0.000,0.000,0.000,0.333,0.000,0.000,0.000,0.000,0.000}
    };

    REQUIRE(testTran == expected_tran);
}


TEST_CASE("test_graph_basic","[graph_class, test_small]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_small.txt", 10);
    Graph graph_small = test_small.getGraph();
    //test: findAdjacency
    vector<int> adj_nodeID_one = graph_small.findAdjacency(1);
    REQUIRE(adj_nodeID_one.size() == 10);
    vector<int> adj_nodeID_two = graph_small.findAdjacency(2);
    const vector<int> expected_adj_two = {1,3,9};
    REQUIRE(adj_nodeID_two.size() == 3);
    for (int i: expected_adj_two){
        REQUIRE(find(adj_nodeID_two.begin(), adj_nodeID_two.end(), i) != adj_nodeID_two.end());
    }
    
    //test: getEdgeWeight
    REQUIRE(graph_small.getEdgeWeight(9,0) == -1.000);
    REQUIRE(graph_small.getEdgeWeight(2,2) == -1.000);
    REQUIRE(graph_small.getEdgeWeight(3,1) == -1.000);
    REQUIRE(graph_small.getEdgeWeight(5,4) == -1.000);
    REQUIRE(graph_small.getEdgeWeight(1,6) == 0.100);
    REQUIRE(graph_small.getEdgeWeight(3,5) == 0.333);
    REQUIRE(graph_small.getEdgeWeight(5,9) == 0.2);
    REQUIRE(graph_small.getEdgeWeight(6,9) == 0.333);
    REQUIRE(graph_small.getEdgeWeight(1,0) == 0.100);
   
}

TEST_CASE("test_graph_basic","[graph_class, test_extreme]"){
    DataParsing test_extreme("/workspaces/cs225/CS225_Final_Project/final_project/test_extreme.txt", 10);
    Graph graph_extreme = test_extreme.getGraph();
    //test: findAdjacency
    vector<int> adj_nodeID_one = graph_extreme.findAdjacency(1);
    REQUIRE(adj_nodeID_one.size() == 10);
    vector<int> adj_nodeID_two = graph_extreme.findAdjacency(2);
    const vector<int> expected_adj_two = {2};
    REQUIRE(adj_nodeID_two.size() == 1);
    for (int i: expected_adj_two){
        REQUIRE(find(adj_nodeID_two.begin(), adj_nodeID_two.end(), i) != adj_nodeID_two.end());
    }
}

TEST_CASE("test_graph_dfs","[graph_class, test_extreme]"){
    DataParsing test_extreme("/workspaces/cs225/CS225_Final_Project/final_project/test_extreme.txt", 10);
    Graph graph_extreme = test_extreme.getGraph();
    vector<vector<int>> expected_dfs = {
        {0,1,2,3,4,5,6,7,8,9},\
        {1,0,2,3,4,5,6,7,8,9},\
        {2},\
        {3,0,1,2,4,5,6,7,8,9},\
        {4,1,0,2,3,5,6,7,8,9},\
        {5,1,0,2,3,4,6,7,8,9},\
        {6,1,0,2,3,4,5,7,8,9},\
        {7,8,0,1,2,3,4,5,6,9},\
        {8,0,1,2,3,4,5,6,7,9},\
        {9,0,1,2,3,4,5,6,7,8}
    };

    for (unsigned i = 0; i < 10; i++){
        graph_extreme.getTraversalPath(i);
        vector<int> dfs_order = graph_extreme.findDFSorder();
        REQUIRE(dfs_order == expected_dfs[i]);
    }
}

TEST_CASE("test_dijkstras","[dijkstras, test_small]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_small.txt", 10);
    Graph graph_small = test_small.getGraph();
    //test: distance
    vector<vector<double>> expected_distance = {
        {0.000,0.333,0.433,0.333,0.433,0.433,0.433,0.433,0.433,0.333},\
        {0.100,0.000,0.100,0.100,0.100,0.100,0.100,0.100,0.100,0.100},\
        {0.433,0.333,0.000,0.333,0.433,0.433,0.433,0.433,0.433,0.333},\
        {0.633,0.533,0.633,0.000,0.533,0.333,0.533,0.633,0.333,0.533},\
        {0.433,0.333,0.333,0.433,0.000,0.433,0.433,0.433,0.433,0.433},\
        {0.300,0.200,0.300,0.300,0.200,0.000,0.200,0.300,0.300,0.200},\
        {0.433,0.333,0.433,0.433,0.433,0.433,0.000,0.433,0.433,0.333},\
        {0.350,0.250,0.350,0.350,0.250,0.250,0.350,0.000,0.350,0.250},\
        {0.350,0.250,0.350,0.350,0.250,0.250,0.250,0.350,0.000,0.350},\
        {1.100,1.000,1.100,1.100,1.100,1.100,1.100,1.100,1.100,1.100}
    };

    for(unsigned i = 0; i < 10; i++){
        for (unsigned j = 0; j < 10; j++){
            REQUIRE(Dijkstra(graph_small, i, j).first == expected_distance[i][j]);
        }
    }
    //test: path
    unordered_set<int> path_01_small = Dijkstra(graph_small, 0, 1).second;
    REQUIRE(path_01_small.size() == 2);
    REQUIRE(path_01_small.find(0) != path_01_small.end());
    REQUIRE(path_01_small.find(1) != path_01_small.end());
    REQUIRE(path_01_small.find(2) == path_01_small.end());

    unordered_set<int> path_06_small = Dijkstra(graph_small, 0, 6).second;
    REQUIRE(path_06_small.size() == 3);
    REQUIRE(path_06_small.find(0) != path_01_small.end());
    REQUIRE(path_06_small.find(1) != path_01_small.end());
    REQUIRE(path_06_small.find(6) != path_01_small.end());
    REQUIRE(path_06_small.find(2) == path_01_small.end());

    unordered_set<int> path_30_small = Dijkstra(graph_small, 3, 0).second;
    REQUIRE(path_06_small.size() == 4);
    REQUIRE(path_06_small.find(0) != path_01_small.end());
    REQUIRE(path_06_small.find(1) != path_01_small.end());
    REQUIRE(path_06_small.find(6) == path_01_small.end());
    REQUIRE(path_06_small.find(3) != path_01_small.end());
    REQUIRE(path_06_small.find(5) != path_01_small.end());
}

TEST_CASE("test_dijkstras","[dijkstras, test_extreme]"){
    DataParsing test_extreme("/workspaces/cs225/CS225_Final_Project/final_project/test_extreme.txt", 10);
    Graph graph_extreme = test_extreme.getGraph();
    //test: distance
    vector<vector<double>> expected_distance = {
        {0.000,0.333,0.333,0.333,0.433,0.433,0.433,0.433,0.433,0.433},\
        {0.100,0.000,0.100,0.100,0.100,0.100,0.100,0.100,0.100,0.100},\
        {INT_MAX,INT_MAX,0.000,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},\
        {0.100,0.100,0.100,0.000,0.100,0.100,0.100,0.100,0.100,0.100},\
        {1.100,0.100,1.100,1.100,0.000,1.100,1.100,1.100,1.100,1.100},\
        {0.600,0.500,0.500,0.600,0.500,0.000,0.600,0.600,0.600,0.600},\
        {0.600,0.500,0.600,0.500,0.600,0.600,0.000,0.600,0.600,0.600},\
        {1.100,1.100,1.100,1.100,1.100,1.100,1.100,0.000,1.000,1.100},\
        {0.100,0.100,0.100,0.100,0.100,0.100,0.100,0.100,0.100,0.100},\
        {1.000,1.333,1.333,1.333,1.433,1.433,1.433,1.433,1.433,0.000}
    };

    for(unsigned i = 0; i < 10; i++){
        for (unsigned j = 0; j < 10; j++){
            REQUIRE(Dijkstra(graph_extreme, i, j).first == expected_distance[i][j]);
        }
    }
    //test: path
    unordered_set<int> path_01_small = Dijkstra(graph_extreme, 0, 1).second;
    REQUIRE(path_01_small.size() == 2);
    REQUIRE(path_01_small.find(0) != path_01_small.end());
    REQUIRE(path_01_small.find(1) != path_01_small.end());
    REQUIRE(path_01_small.find(2) == path_01_small.end());

    unordered_set<int> path_06_small = Dijkstra(graph_extreme, 0, 6).second;
    REQUIRE(path_06_small.size() == 3);
    REQUIRE(path_06_small.find(0) != path_01_small.end());
    REQUIRE(path_06_small.find(1) != path_01_small.end());
    REQUIRE(path_06_small.find(6) != path_01_small.end());
    REQUIRE(path_06_small.find(2) == path_01_small.end());

    unordered_set<int> path_96_small = Dijkstra(graph_extreme, 9, 6).second;
    REQUIRE(path_96_small.size() == 4);
    REQUIRE(path_96_small.find(0) != path_01_small.end());
    REQUIRE(path_96_small.find(1) != path_01_small.end());
    REQUIRE(path_96_small.find(6) != path_01_small.end());
    REQUIRE(path_96_small.find(3) == path_01_small.end());
    REQUIRE(path_96_small.find(5) == path_01_small.end());
    REQUIRE(path_96_small.find(9) != path_01_small.end());
}

TEST_CASE("test_pagerank","[pagerank, test_small]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_small.txt", 10);
    PageRank rank_small(test_small);
    std::vector<double> iteration = rank_small.power_iteration(0.000000000001, 1000);
    
    vector<int> topTen = rank_small.findTopTen();
    for(unsigned i = 0; i < topTen.size(); i++) std::cout << topTen[i] << " " << std::endl;
    vector<int> expected_output = {1,9,3,5,6,8,4,2,7,0};
    REQUIRE(topTen == expected_output);
    
}