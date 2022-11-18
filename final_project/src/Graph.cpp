#include "Graph.h"

Graph::Graph(){
    // i don know what to do with this constructor :(
}

GraphNode Graph::getStartingNode() const{
    return graph_adjacency_list.begin()->first;
}

std::vector<GraphNode> Graph::getNodes() const{
    std::vector<GraphNode> to_return;
    for(auto it = graph_adjacency_list.begin(); it != graph_adjacency_list.end(); it++){
        to_return.push_back(it->first);
    }
    return to_return;
}

Edge Graph::getEdge(GraphNode source, GraphNode destination) const{
    // if(assertEdgeExists(source, destination, __func__) == false) // make sure edge exist
    //     return Edge();
    Edge e = graph_adjacency_list.at(source).at(destination);
    return e;
}

int Graph::getEdgeWeight(GraphNode source, GraphNode destination) const{
    Edge e = graph_adjacency_list.at(source).at(destination);
    return e.getWeight();
}

std::vector<Edge> Graph::getEdges() const{
    if (graph_adjacency_list.empty())
        return std::vector<Edge>();

    std::vector<Edge> ret;
    std::set<std::pair<GraphNode, GraphNode>> seen;

    for (auto it = graph_adjacency_list.begin(); it != graph_adjacency_list.end(); it++)
    {
        GraphNode source = it->first;
        for (auto its = graph_adjacency_list.at(source).begin(); its != graph_adjacency_list.at(source).end(); its++)
        {
            GraphNode destination = its->first;
            if(seen.find(std::make_pair(source, destination)) == seen.end()){
                //this pair is never added to seen
                ret.push_back(its->second);
                seen.insert(std::make_pair(source,destination));
            }
        }
    }

    return ret;
}

void Graph::insertGraphNode(GraphNode v){
    removeGraphNode(v);
    // make it empty again
    graph_adjacency_list[v] = std::unordered_map<GraphNode, Edge>();
    graph_adjacency_list.at(v) = v.getAdjacentList();
}

void Graph::removeGraphNode(GraphNode v){
    if (graph_adjacency_list.find(v) != graph_adjacency_list.end()){        
        graph_adjacency_list.erase(v);
        // vertex_label_map.erase(v);
        for(auto it2 = graph_adjacency_list.begin(); it2 != graph_adjacency_list.end(); it2++)
        {
            GraphNode u = it2->first;
            if (it2->second.find(v)!=it2->second.end()){
                it2->second.erase(v);
            }
        }
        return;
    }
}