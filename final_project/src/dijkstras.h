#include <limits.h>

std::pair<int, std::unordered_set<int>> Dijkstra(Graph g, int source, int destination);

std::pair<int, std::unordered_set<int>> Dijkstra(Graph g, int source, int destination){
    std::unordered_map<int, int> distance;
    std::unordered_map<int, int> previous;
    std::unordered_map<int, bool> visited;
    int count = 0;
    for (auto i : g.getTraversalPath(source)){
        count++;
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    int curr = source;
    distance[curr] = 0;
    visited[curr] = true;
    for (auto i : g.findAdjacency(source)){
        distance[i] = getEdgeWeight(source, i);
        previous[i] = source;
    }
    count --;
    for ( ; count > 0 ; count--){
        curr = findNext(visited);
        visited[curr] = true;
        for (auto i : g.findAdjacency(curr)){
            dist = getEdgeWeight(curr, i)+ distance[curr];
            if (dist < distance[i]){
                distance[i] = dist;
                previous[i] = curr;
            }
        }
    }
    std::unordered_set<int> path;
    int x = destination;
    path.insert(x);
    while (x!=source){
        x = previous[x];
        path.insert(path.begin(), x);
    }
    std::pair<int, std::unordered_set<int>> ret = {distance[destination], path};
    return ret;
}

int findNext(std::unordered_map<int, bool> visited, std::unordered_map<int, int> distance);
int findNext(std::unordered_map<int, bool> visited, std::unordered_map<int, int> distance){
    std::set<int> set;
    for (auto i : dist){
        set.insert(i.second);
    }
    for (int i : set){
        if (visited[i]==false){
            return i;
        }
    }
    return -1;
}