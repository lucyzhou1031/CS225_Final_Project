
#include "data.h"
#include "graph.h"
#include "pageRank.h"
#include "dfs.h"
#include "dijkstras.h"

#include <iostream>
#include <fstream>
#include <sstream>
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
        {0,1,0,0,0,0,0,0,0,0},\
        {0,1,1,0,0,1,0,0,0,1},\
        {0,0,0,0,0,1,1,1,0,1},\
        {0,0,0,0,0,0,0,1,1,0},\
        {0,0,1,0,0,1,0,0,1,0},\
        {0,0,1,0,0,1,1,0,1,0},\
        {0,0,1,0,0,0,0,1,0,0},\
        {0,0,0,0,1,0,0,0,0,0},\
        {0,0,0,0,1,0,0,0,0,0}
    };

    REQUIRE(testAdj == expected_adj);

    const vector<vector<double>> expected_tran = {
        {0.100,0.333,0.000,1.000,0.333,0.200,0.333,0.250,0.250,0.333},\
        {0.100,0.333,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000},\
        {0.100,0.333,0.250,0.000,0.000,0.200,0.000,0.000,0.000,0.333},\
        {0.100,0.000,0.000,0.000,0.000,0.200,0.333,0.250,0.000,0.333},\
        {0.100,0.000,0.000,0.000,0.000,0.000,0.000,0.250,0.250,0.000},\
        {0.100,0.000,0.250,0.000,0.000,0.200,0.000,0.000,0.250,0.000},\
        {0.100,0.000,0.250,0.000,0.000,0.200,0.333,0.000,0.250,0.000},\
        {0.100,0.000,0.250,0.000,0.000,0.000,0.000,0.250,0.000,0.000},\
        {0.100,0.000,0.000,0.000,0.333,0.000,0.000,0.000,0.000,0.000},\
        {0.100,0.000,0.000,0.000,0.333,0.000,0.000,0.000,0.000,0.000}
    };

    REQUIRE(testTran == expected_tran);
}


TEST_CASE("test_graph_basic","[graph_class, test_small]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_small.txt", 10);
    Graph graph_small = test_small.getGraph();
    //test: findAdjacency
    vector<int> adj_nodeID_one = findAdjacency(1);
    REQUIRE(adj_nodeID_one.size() == 0);
    vector<int> adj_nodeID_two = findAdjacency(2);
    const vector<int> expected_adj_two = {1,9,3};
    REQUIRE(adj_nodeID_two.size() == 3);
    for (int i: expected_adj_two){
        REQUIRE(adj_nodeID_two.find(i) != adj_nodeID_two.end());
    }
    //test: getEdgeWeight
    REQUIRE(getEdgeWeight(9,0) == -1.000);
    REQUIRE(getEdgeWeight(2,2) == -1.000);
    REQUIRE(getEdgeWeight(3,1) == -1.000);
    REQUIRE(getEdgeWeight(3,5) == 0.333);
    REQUIRE(getEdgeWeight(5.4) == 0.200);
    REQUIRE(getEdgeWeight(1,6) == 0.100);
}

TEST_CASE("test_graph_basic","[graph_class, test_extreme]"){
    DataParsing test_extreme("/workspaces/cs225/CS225_Final_Project/final_project/test_extreme.txt", 10);
    Graph graph_extreme = test_extreme.getGraph();
    //test: findAdjacency
    vector<int> adj_nodeID_one = findAdjacency(1);
    REQUIRE(adj_nodeID_one.size() == 0);
    vector<int> adj_nodeID_two = findAdjacency(2);
    const vector<int> expected_adj_two = {2};
    REQUIRE(adj_nodeID_two.size() == 1);
    for (int i: expected_adj_two){
        REQUIRE(adj_nodeID_two.find(i) != adj_nodeID_two.end());
    }
    //test: getEdgeWeight
    REQUIRE(getEdgeWeight(1,2) == 0.100);
    REQUIRE(getEdgeWeight(6,1) == 0.500);
    REQUIRE(getEdgeWeight(9,0) == 1.000);
    REQUIRE(getEdgeWeight(9,2) == -1.000);
    REQUIRE(getEdgeWeight(8.7) == 0.100);
    REQUIRE(getEdgeWeight(4,2) == -1.000);
}


TEST_CASE("test_graph_dfs","[graph_class, test_small]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_small.txt", 10);
    Graph graph_small = test_small.getGraph();
    vector<vector<int>> expected_dfs = {
        {0,1,2,3,5,4,8,6,9,7},\
        {1,0,3,5,4,2,9,8,6,7},\
        {2,1,0,3,5,4,8,6,9,7},\
        {3,5,1,0,9,2,4,8,6,7},\
        {4,1,0,3,5,6,9,8,2,7},\
        {5,1,0,3,8,4,2,9,6,7},\
        {6,1,0,3,5,4,2,9,8,7},\
        {7,1,0,3,5,4,2,9,8,6},\
        {8,1,0,3,5,4,2,9,6,7},\
        {9,1,0,3,5,4,2,8,6,7}
    };

    for (unsigned i = 0; i < 10, i++){
        getTraversalPath(i);
        vector<int> dfs_order = findDFSorder();
        REQUIRE(dfs_order == expected_dfs[i]);
    }
}

TEST_CASE("test_graph_dfs","[graph_class, test_extreme]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_extreme.txt", 10);
    Graph graph_extreme = test_extreme.getGraph();
    vector<vector<int>> expected_dfs = {
        {0,1,2,3,4,5,6,7,8,9},\
        {1,0,2,3,4,5,6,7,8,9},\
        {2},\
        {3,0,1,2,4,5,6,7,8,9},\
        {4,1,0,2,3,5,6,7,8,9},\
        {5,1,0,2,3,4,6,7,8,9},\
        {6,1,0,2,3,4,5,7,8,9},\
        {8,0,1,2,3,4,5,6,7,9},\
        {9,0,1,2,3,4,5,6,7,8}
    };

    for (unsigned i = 0; i < 10, i++){
        getTraversalPath(i);
        vector<int> dfs_order = findDFSorder();
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
            if(!Dijkstra(graph_small, i, j).empty()){
                REQUIRE(Dijkstra(graph_small, i, j)->first == expected_distance[i][j]);
            } 
        }
    }
    //test: path
    unordered_set<int> path_01_small = Dijkstra(graph_small, 0, 1)->second;
    REQUIRE(path_01_small.size() == 2);
    REQUIRE(path_01_small.find(0) != path_01_small.end());
    REQUIRE(path_01_small.find(1) != path_01_small.end());
    REQUIRE(path_01_small.find(2) == path_01_small.end());

    unordered_set<int> path_06_small = Dijkstra(graph_small, 0, 6)->second;
    REQUIRE(path_06_small.size() == 3);
    REQUIRE(path_06_small.find(0) != path_01_small.end());
    REQUIRE(path_06_small.find(1) != path_01_small.end());
    REQUIRE(path_06_small.find(6) != path_01_small.end());
    REQUIRE(path_06_small.find(2) == path_01_small.end());

    unordered_set<int> path_30_small = Dijkstra(graph_small, 3, 0)->second;
    REQUIRE(path_06_small.size() == 4);
    REQUIRE(path_06_small.find(0) != path_01_small.end());
    REQUIRE(path_06_small.find(1) != path_01_small.end());
    REQUIRE(path_06_small.find(6) == path_01_small.end());
    REQUIRE(path_06_small.find(3) != path_01_small.end());
    REQUIRE(path_06_small.find(5) != path_01_small.end());
}

TEST_CASE("test_dijkstras","[dijkstras, test_extreme]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_extreme.txt", 10);
    Graph graph_extreme = test_extreme.getGraph();
    //test: distance
    vector<vector<double>> expected_distance = {
        {0.000,0.333,0.333,0.433,0.433,0.433,0.433,0.433,0.433,0.433},\
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
            if(!Dijkstra(graph_small, i, j).empty()){
                REQUIRE(Dijkstra(graph_small, i, j)->first == expected_distance[i][j]);
            } 
        }
    }
    //test: path
    unordered_set<int> path_01_small = Dijkstra(graph_small, 0, 1)->second;
    REQUIRE(path_01_small.size() == 2);
    REQUIRE(path_01_small.find(0) != path_01_small.end());
    REQUIRE(path_01_small.find(1) != path_01_small.end());
    REQUIRE(path_01_small.find(2) == path_01_small.end());

    unordered_set<int> path_06_small = Dijkstra(graph_small, 0, 6)->second;
    REQUIRE(path_06_small.size() == 3);
    REQUIRE(path_06_small.find(0) != path_01_small.end());
    REQUIRE(path_06_small.find(1) != path_01_small.end());
    REQUIRE(path_06_small.find(6) != path_01_small.end());
    REQUIRE(path_06_small.find(2) == path_01_small.end());

    unordered_set<int> path_96_small = Dijkstra(graph_small, 9, 6)->second;
    REQUIRE(path_96_small.size() == 4);
    REQUIRE(path_96_small.find(0) != path_01_small.end());
    REQUIRE(path_96_small.find(1) != path_01_small.end());
    REQUIRE(path_96_small.find(6) != path_01_small.end());
    REQUIRE(path_96_small.find(3) == path_01_small.end());
    REQUIRE(path_96_small.find(5) == path_01_small.end());
    REQUIRE(path_96_small.find(9) != path_01_small.end());
}