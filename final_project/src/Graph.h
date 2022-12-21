#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

class Graph {
    
    private:
        //the whole graph
        std::map<int, std::map<int, double>> graph;
        //path of DFS traversal
        std::unordered_set<int> visited;
        //path of DFS traversal that is easier for the test cases
        std::vector<int> order;
    public:
        //default constructor
        Graph() = default;
        //To creat a graph
        void addVertex(int s);
        void addEdge(int s1, int s2, double weight);
        //Traversal
        void DFS(int start);
        std::map<int, std::map<int, double>> getGraph();
        //findAdjacency: return vector of adj node (directed)
        std::vector<int> findAdjacency(int node);
        std::vector<int> findDFSorder();
        std::unordered_set<int> getTraversalPath(int start);
        double getEdgeWeight(int source, int destination);
            
};