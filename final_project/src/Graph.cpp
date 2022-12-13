#include "Graph.h"

/**
 * @brief add a vertex into graph given nodeID
 * 
 * @param s the nodeID of vertex
 */
void Graph::addVertex(int s) {
    if (graph.find(s) == graph.end()) {
        graph[s] = {};
    }
}

/**
 * @brief add an edge into the graph
 * 
 * @param s1 the fromID of vertex
 * @param s2 the toID of vertex
 * @param weight the weight of edge
 */
void Graph::addEdge(int s1, int s2, double weight) {
    if (graph.find(s1) != graph.end() && graph.find(s2) != graph.end()) {
        std::map<int, double> internal = graph.at(s1);
        internal.insert(std::pair<int, double>(s2, weight));
        graph[s1] = internal;
    } else {
        std::cout << "Wrong node ID" << std::endl;
    }
}

/**
 * @brief return graph
 * 
 * @return std::map<int, std::map<int, double>> 
 */
std::map<int, std::map<int, double>> Graph::getGraph() {
    return graph;
}

/**
 * @brief process a DFS traversal given the ID of starting node
 * 
 * @param start the node ID of starting node
 */
void Graph::DFS(int start) {
    order.push_back(start);
    visited.insert(start);
    for (auto adj : graph.at(start)) {
        if (visited.find(adj.first) == visited.end()) {
            DFS(adj.first);
        }
    }
}

/**
 * @brief return the order of DFS traversal as vector
 * 
 * @return std::vector<int> 
 */
std::vector<int> Graph::findDFSorder(){
    std::vector<int> or_re = order;
    order.clear();
    return or_re;
}

/**
 * @brief return adjacency vertexs of input ID
 * 
 * @param node the nodeID of node in the directed graph
 * @return std::vector<int> 
 */
std::vector<int> Graph::findAdjacency(int node) {
    std::vector<int> adjacency;
    for (auto it : graph.at(node)) {
        adjacency.push_back(it.first);
    }
    return adjacency;
}

/**
 * @brief 
 * 
 * @param source 
 * @param destination 
 * @return double 
 */
double Graph::getEdgeWeight(int source, int destination) {
    for (auto it : graph.at(source)) {
        if (it.first == destination) {
            return it.second;
        }
    }
    return -1;
}

std::unordered_set<int> Graph::getTraversalPath(int start) {
    DFS(start);
    std::unordered_set<int> to_return = visited;
    visited.clear();
    return to_return;
}

