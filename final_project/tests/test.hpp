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

template <typename T>
string print_matrix(vector<vector<T>> matrix, string file, string type){
    string filename = "test_" + file + "_" + type + "_output.txt";
    ofstream file;
    file.open(filename);
    if(matrix.length() < 0 || matrix[0].length() < 0){
        file << "invalid demension";
        return "invalid demension";
    }
    if(file.is_open()){
        for (int i = 0; i < matrix.length(); i++){
            for (int j= 0; j < matrix[0].length(); j++){
                file << to_string(matrix[i][j]);
                file << " ";
            }
            file << "\n";
        }
    }
    file.close();
    return filename;
}

TEST_CASE("test_extreme","[matrix_input, test_extreme_case]"){
    DataParsing test_extreme = new DataParsing("final_project\extreme.txt",10);
    vector<vector<int>> testAdj = test_extreme.getAdjacencyMatrix();
    print_matrix(testAdj);
    vector<vector<int>> testTran = test_extreme.getTransitMatrix();
    print_matrix(testTran);
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
    print_matrix(testAdj);
    vector<vector<int>> testTran = test_small.getTransitMatrix();
    print_matrix(testTran);
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

