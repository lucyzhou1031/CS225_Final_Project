#include "Graph.h"


GraphNode Graph::getStartingNode() const{
    return graph_adjacency_list.begin()->first;
}