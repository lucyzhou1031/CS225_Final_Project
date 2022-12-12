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
<<<<<<< HEAD
    bool connected = false;
=======
    std::cout << __LINE__ << std::endl;
>>>>>>> bc3a17e1e7cde94580f28b1106b662d99bf59836
    for (auto i : g.getTraversalPath(source)){
        if (i == destination) connected = true;
        count++;
        distance[i] = (double)INT_MAX;
        visited[i] = false;
    }
<<<<<<< HEAD
    if (!connected){
        return std::pair<double, std::unordered_set<int>> {toPre(-1.0, 3), std::unordered_set<int>{}};
    }
=======
    std::cout << __LINE__ << std::endl;
>>>>>>> bc3a17e1e7cde94580f28b1106b662d99bf59836
    //count = num of node connected to src
    int curr = source;
    distance[curr] = toPre(0.0, 3);
    visited[curr] = true;
    std::cout << __LINE__ << std::endl;
    for (auto i : g.findAdjacency(source)){
        //prevent new distance updated when src -> src
        if(i != source){
            distance[i] = toPre(g.getEdgeWeight(source, i), 3);
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
            double dist = toPre(g.getEdgeWeight(curr, i) + distance[curr], 3);
            if (dist < toPre(distance[i], 3)){
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
    std::pair<double, std::unordered_set<int>> ret = {toPre(distance[destination], 3), path};
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