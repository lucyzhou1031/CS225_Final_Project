#include <limits.h>

// Dijkstra(Graph, source, destination):

//   initialize distances  // initialize tentative distance value
//   initialize previous   // initialize a map that maps current node -> its previous node
//   initialize priority_queue   // initialize the priority queue
//   initialize visited

//   while the top of priority_queue is not destination:
//       get the current_node from priority_queue
//       for neighbor in current_node's neighbors and not in visited:
//           if update its neighbor's distances:
//               previous[neighbor] = current_node
//       save current_node into visited

//   extract path from previous
//   return path and distance

Dijkstra(Graph g, int source, int destination){
    // initialize tentative distance value
    std::map<int, int> tentative_distance;
    std::map<int, int> previous;
    std::queue<int> priority_queue;
    std::unordered_set<int> visited;
    std::unorderd_set<int> vis = g.getTraversalPath(source);
    for (auto i : vis){
        if (i==source){
            tentative_distance[i] = 0;
        } else{
            tentative_distance[i] = INT_MAX;
        }
    }
    // initialize a map that maps current node -> its previous node


}