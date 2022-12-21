#include <limits.h>
#include <Graph.h>

#include <iomanip>
#include <sstream>
/**
 * @brief run Dijkstra algorithm given the nodeID of initial node and destination node
 * return a pair of distance and traversed nodes (as vector)
 * 
 * @param g the graph of pagerank
 * @param source the nodeID of source node
 * @param destination the nodeID of destination node
 * @return std::pair<double, std::vector<int>> 
 */
std::pair<double, std::vector<int>> Dijkstra(Graph g, int source, int destination);

/**
 * @brief return the nodeID of next unvisited adjacent node
 * 
 * @param visited the unordered map that map nodeID to its state (visited/unvisited)
 * @param distance the unordered map that map destinaion node to its shorted distance between source node
 * @return int 
 */
int findNext(std::unordered_map<int, bool> visited, std::unordered_map<int, double> distance);

/**
 * @brief percise a double to desired sig fig
 * 
 * @param input input double value
 * @param precision desired sig fig
 * @return double 
 */
double toPre(double input, int precision);

double toPre(double input, int precision) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << input;
    std::string s = stream.str();
    return std::stod(s);
}

std::pair<double, std::vector<int>> Dijkstra(Graph g, int source, int destination){
    std::unordered_map<int, double> distance;
    std::unordered_map<int, int> previous;
    std::unordered_map<int, bool> visited;
    int count = 0;
    bool connected = false;
    for (auto i : g.getTraversalPath(source)){
        if (i == destination) connected = true;
        count++;
        distance[i] = (double)INT_MAX;
        visited[i] = false;
    }
    if (!connected){
        return std::pair<double, std::vector<int>> {distance[source], std::vector<int>{}};
    }
    int curr = source;
    distance[curr] = toPre(0.0, 3);
    visited[curr] = true;
    for (auto i : g.findAdjacency(source)){
        if(i != source){
            distance[i] = toPre(g.getEdgeWeight(source, i), 3);
            previous[i] = source;
        }   
    }
    count--;
    for ( ; count > 0 ; count--){
        curr = findNext(visited, distance);
        visited[curr] = true;
        for (auto i : g.findAdjacency(curr)){
            if (i != curr) {
                double dist = toPre(g.getEdgeWeight(curr, i) + distance[curr], 3);
                if (dist < toPre(distance[i], 3)){
                    distance[i] = dist;
                    previous[i] = curr;
                }
            }
            
        }
    }
    std::unordered_set<int> path;
    std::vector<int> path_ordered;
    int x = destination;
    path.insert(x);
    path_ordered.push_back(x);
    while (x != source){
        x = previous[x];
        path.insert(path.begin(), x);
        path_ordered.insert(path_ordered.begin(), x);
    }
    std::pair<double, std::vector<int>> ret = {toPre(distance[destination], 3), path_ordered};
    
    return ret;
    
}

int findNext(std::unordered_map<int, bool> visited, std::unordered_map<int, double> distance){
    std::map<double, std::vector<int>> dist;
    for (auto i : distance){
        dist[i.second].push_back(i.first);
    }
    for (auto i : dist){
        for (auto j : i.second){
            if (visited[j] == false) return j;
        }
    }
    return -1;
}