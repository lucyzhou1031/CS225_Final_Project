#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>

// #include "edge.h"
// #include "GraphNode.h"

// /**
//  * Represents a graph; used by the GraphTools class.
//  */
// class Graph{

//     public:
//         Graph();

//         /**
//          * Returns one vertex in the graph. This function can be used
//          *  to find a random vertex with which to start a traversal.
//          * @return a vertex from the graph
//          * Adapted from Lab Machine Learning
//          */
//         GraphNode getStartingNode() const;
        
//         /**
//          * Gets all vertices in the graph.
//          * @return a vector of all vertices in the graph
//          */
//         std::vector<GraphNode> getNodes() const;

//         /**
//          * Gets an edge between two vertices.
//         * @param source - one vertex the edge is connected to
//         * @param destination - the other vertex the edge is connected to
//         * @return - if exist, return the corresponding edge
//         *         - if edge doesn't exist, return Edge()
//         */
//         Edge getEdge(GraphNode source, GraphNode destination) const;
        
//         /**
//         * Gets an edge between two vertices.
//          * @param source - one vertex the edge is connected to
//          * @param destination - the other vertex the edge is connected to
//          * @return - if exist, return the corresponding edge
//          *         - if edge doesn't exist, return Edge()
//          */
//         double getEdgeWeight(GraphNode source, GraphNode destination) const;

//         /**
//          * Gets all the edges in the graph.
//          * @return a vector of all the edges in the graph
//          */
//         std::vector<Edge> getEdges() const;

//         /**
//          * Inserts a new vertex into the graph and initializes its label as "".
//          * @param v - the name for the vertex
//          */
//         void insertGraphNode(GraphNode v);

//         /**
//          * Removes a given vertex from the graph.
//          * @param v - the vertex to remove
//          */
//         void removeGraphNode(GraphNode v);

//         void clear();

//     private:
//         std::unordered_map<GraphNode, std::unordered_map<GraphNode, Edge>> graph_adjacency_list;
//         // std::unordered_map<GraphNode, string> vertex_label_map;

// };

class Graph {
    
    private:
        std::map<int, std::vector<std::pair<int, double>>> graph;
        std::unordered_set<int> visited;
    public:
        Graph() = default;
        void addVertex(int s);
        void addEdge(int s1, int s2, int weight);
        void DFS(int start);
        std::map<int, std::vector<std::pair<int, double>>> getGraph();
        std::vector<int> findAdjacency(int node);
        std::unordered_set<int> getTraversalPath(int start);
        double getEdgeWeight(int source, int destination);
            
};