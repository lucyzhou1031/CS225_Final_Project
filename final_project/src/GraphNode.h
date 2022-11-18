#pragma once

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

#include "edge.h"

class GraphNode{
    public:
        int getNodeId() {return node_id;}
        std::unordered_map<GraphNode, Edge> getAdjacentList() {return node_adjacency_list;}

    private:
        int node_id;
        std::unordered_map<GraphNode, Edge> node_adjacency_list;
};