#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

#include "edge.h"

/**
 * Represents a graph; used by the GraphTools class.
 */
class Graph{
    class GraphNode{
        public:
            int getNodeId() {return node_id;}
            std::vector<std::pair<int, int>> getAdjacentList() {return adjacency_list;}

        private:
            int node_id;
            std::vector<std::pair<int, int>> adjacency_list;    // vector of <pair: neighbor node, edge weight>
    };

    public:
        Graph(bool weighted);
        Graph(bool weighted, bool directed);

        /**
         * Returns one vertex in the graph. This function can be used
         *  to find a random vertex with which to start a traversal.
         * @return a vertex from the graph
         * Adapted from Lab Machine Learning
         */
        GraphNode getStartingVertex() const;
        
        /**
         * Gets all vertices in the graph.
         * @return a vector of all vertices in the graph
         */
        std::vector<GraphNode> getVertices() const;

        /**
        * Gets an edge between two vertices.
         * @param source - one vertex the edge is connected to
         * @param destination - the other vertex the edge is connected to
         * @return - if exist, return the corresponding edge
         *         - if edge doesn't exist, return Edge()
         */
        int getEdgeWeight(GraphNode source, GraphNode destination) const;


    private:


};