
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


TEST_CASE("test_graph_basic","[graph_class, test_all]"){
    DataParsing test_small("/workspaces/cs225/CS225_Final_Project/final_project/test_small.txt", 10);
    Graph graph_small = test_small.getGraph();
    //TEST: findAdjacency
    vector<int> adj_nodeID_one = findAdjacency(1);
    const vector<int> expected_adj_one = {0,4,5,6,7,8,9,2};
    for (int i: expected_adj_one){
        REQUIRE(adj_nodeID_one.find(i) != adj_nodeID_one.end());
    }

    vector<int> adj_nodeID_two = findAdjacency(2);
    const vector<int> expected_adj_two = {1,9,3,4};
    for (int i: expected_adj_two){
        REQUIRE(adj_nodeID_two.find(i) != adj_nodeID_two.end());
    }
    //TEST: getEdgeWeight
    
}
