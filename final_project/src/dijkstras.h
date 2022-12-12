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
    for (auto i : g.getTraversalPath(source)){
        count++;
        distance[i] = (double) INT_MAX;
        visited[i] = false;
    }
    //count = num of node connected to src
    int curr = source;
    distance[curr] = 0.000;
    visited[curr] = true;
    for (auto i : g.findAdjacency(source)){
        //prevent new distance updated when src -> src
        if(i != source){
            distance[i] = g.getEdgeWeight(source, i);
            previous[i] = source;
        }   
    }
    count--;
    for ( ; count > 0 ; count--){
        curr = findNext(visited, distance);
        visited[curr] = true;
        for (auto i : g.findAdjacency(curr)){
            double dist = g.getEdgeWeight(curr, i) + distance[curr];
            if (dist < distance[i]){
                distance[i] = dist;
                previous[i] = curr;
            }
        }
    }
    std::unordered_set<int> path;
    int x = destination;
    path.insert(x);
    while (x != source){
        x = previous[x];
        path.insert(path.begin(), x);
    }
    std::pair<double, std::unordered_set<int>> ret = {distance[destination], path};
    return ret;
}

int findNext(std::unordered_map<int, bool> visited, std::unordered_map<int, double> distance){
    std::set<int> set;
    for (auto i : distance){
        set.insert(i.first);
    }
    for (int i : set){
        if (visited[i] == false){
            return i;
        }
    }
    return -1;
}