#include <limits.h>
#include <Graph.h>

#include <iomanip>
#include <sstream>

std::pair<double, std::unordered_set<int>> Dijkstra(Graph g, int source, int destination);
int findNext(std::unordered_map<int, bool> visited, std::unordered_map<int, double> distance);
double toPre(double input, int precision);

double toPre(double input, int precision) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << input;
    std::string s = stream.str();
    return std::stod(s);
}

std::pair<double, std::unordered_set<int>> Dijkstra(Graph g, int source, int destination){
    std::unordered_map<int, double> distance;
    std::unordered_map<int, int> previous;
    std::unordered_map<int, bool> visited;
    int count = 0;
    std::cout << __LINE__ << std::endl;
    for (auto i : g.getTraversalPath(source)){
        count++;
        distance[i] = (double) INT_MAX;
        visited[i] = false;
    }
    std::cout << __LINE__ << std::endl;
    //count = num of node connected to src
    int curr = source;
    distance[curr] = 0.000;
    visited[curr] = true;
    std::cout << __LINE__ << std::endl;
    for (auto i : g.findAdjacency(source)){
        //prevent new distance updated when src -> src
        if(i != source){
            distance[i] = g.getEdgeWeight(source, i);
            previous[i] = source;
        }   
    }
    std::cout << __LINE__ << std::endl;
    count--;
    for ( ; count > 0 ; count--){
        std::cout << __LINE__ << std::endl;
        curr = findNext(visited, distance);
        visited[curr] = true;
        std::cout << __LINE__ << std::endl;
        for (auto i : g.findAdjacency(curr)){
            std::cout << __LINE__ << std::endl;
            double dist = g.getEdgeWeight(curr, i) + distance[curr];
            if (dist < distance[i]){
                distance[i] = dist;
                previous[i] = curr;
            }
        }
    }
    std::cout << __LINE__ << std::endl;
    std::unordered_set<int> path;
    int x = destination;
    path.insert(x);
    while (x != source){
        x = previous[x];
        path.insert(path.begin(), x);
    }
    std::cout << __LINE__ << std::endl;
    std::pair<double, std::unordered_set<int>> ret = {distance[destination], path};
    return ret;
}

int findNext(std::unordered_map<int, bool> visited, std::unordered_map<int, double> distance){
    std::map<double, int> dist;
    for (auto i : distance){
        dist[i.second] = i.first;
    }
    for (auto i : dist){
        if (visited[i.second] == false) return i.second;
    }
    return -1;
}