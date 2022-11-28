#include "final_project/src/Graph.h"
#include "final_project/src/data.h"
#include "final_project/src/pageRank.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;
DataParsing web_google = new DataParsing("final_project\web-Google.txt",5105043);
DataParsing test_small = new DataParsing("final_project\test.txt",30);
DataParsing test_extreme = new DataParsing("final_project\extreme.txt",15);

template <typename T>
string print_matrix(std::vector<std::vector<T>> matrix){
    if (matrix.length() < 0 || matrix[0].length() < 0) return "invaild demension";
    string output = "demension: " + matrix.length() + " * " + matrix[0].length();
    for (int i = 0; i < matrix.length(); i++){
        for (int j = 0; j < matrix[0].length(); j++){
            output += matrix[i][j];
            output += "  ";
        }
        output += "/n";
    }
    return output;
}

TEST_CASE("test_extreme","[matrix_input, test_extreme_case]"){
    DataParsing test_extreme = new DataParsing("final_project\extreme.txt",10);
    vector<vector<int>> testAdj = test_extreme.getAdjacencyMatrix();
    vector<vector<int>> testTran = test_extreme.getTransitMatrix();
    REQUIRE(testAdj == {
        {0,1,1,1,0,0,0,0,0,1,0},\
        {1,0,0,0,1,1,1,0,0,0,0},\
        {1,0,1,0,0,1,0,0,0,0,0},\
        {1,0,0,0,0,0,1,0,0,0,0},\
        {0,1,0,0,0,0,0,0,0,0,0},\
        {0,1,1,0,0,0,0,0,0,0,0},\
        {0,1,0,1,0,0,0,0,0,0,0},\
        {0,0,0,0,0,0,0,0,1,0,0},\
        {0,0,0,0,0,0,0,1,0,0,0},\
        {1,0,0,0,0,0,0,0,0,0,0},\
        {0,0,0,0,0,0,0,0,0,0,0}
    });

    REQUIRE(testTran = {
        {0.000,0.250,0.333,0.500,0.000,0.000,0.000,0.000,0.000,1.000,0.111},\
        {0.250,0.000,0.000,0.000,1.000,0.500,0.500,0.000,0.000,0.000,0.111},\
        {0.250,0.000,0.333,0.000,0.000,0.500,0.000,0.000,0.000,0.000,0.111},\
        {0.250,0.000,0.000,0.000,0.000,0.000,0.500,0.000,0.000,0.000,0.111},\
        {0.000,0.250,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.111},\
        {0.000,0.250,0.333,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.111},\
        {0.000,0.250,0.000,0.500,0.000,0.000,0.000,0.000,0.000,0.000,0.111},\
        {0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,1.000,0.000,0.111},\
        {0.000,0.000,0.000,0.000,0.000,0.000,0.000,1.000,0.000,0.000,0.111},\
        {0.250,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.111},\
        {0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.000,0.111}
    });

}

TEST_CASE("test_small","[matrix_input, test_small_case]"){
    DataParsing test_small = new DataParsing("final_project\extreme.txt",10);
    vector<vector<int>> testAdj = test_small.getAdjacencyMatrix();
    vector<vector<int>> testTran = test_small.getTransitMatrix();
    REQUIRE(testAdj == {
        {0,1,0,1,0,0,0,0,0,1},\
        {1,0,1,0,1,1,1,1,1,1},\
        {0,1,0,1,1,0,0,0,0,1},\
        {1,0,1,1,0,1,0,0,1,0},\
        {0,1,1,0,0,0,0,1,1,0},\
        {0,1,0,1,0,1,1,0,1,1},\
        {0,1,0,0,0,1,1,0,1,1},\
        {0,1,0,0,1,0,0,1,0,1},\
        {0,1,0,1,1,1,1,0,0,0},\
        {1,1,1,0,0,1,1,1,0,0}
    });

    REQUIRE(testTran == {
        {0.000,0.125,0.000,0.200,0.000,0.000,0.000,0.000,0.000,0.167},\
        {0.333,0,000,0.250,0.000,0.250,0.167,0.200,0.250,0.200,0.167},\
        {0.000,0.125,0.000,0.250,0.250,0.000,0.000,0.000,0.000,0.167},\
        {0.333,0,000,0.250,0.250,0.000,0.167,0.000,0.000,0.200,0.000},\
        {0.000,0.125,0.250,0.000,0.000,0.000,0.000,0.250,0.200,0.000},\
        {0.000,0.125,0.000,0.250,0.000,0.167,0.200,0.000,0.200,0.167},\
        {0.000,0.125,0.000,0.000,0.000,0.167,0.200,0.000,0.200,0.167},\
        {0.000,0.125,0.000,0.000,0.250,0.000,0.000,0.250,0.000,0.167},\
        {0.000,0.125,0.000,0.250,0.250,0.167,0.200,0.000,0.000,0.000},\
        {0.333,0.125,0.250,0.000,0.000,0.167,0.200,0.250,0.000,0.000}
    });
}

