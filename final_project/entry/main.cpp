#include <Graph.h>
#include <data.h>
#include <dijkstras.h>
#include <pageRank.h>

int main() {
    DataParsing data("web-Google.txt", 875713);
    std::map<int, unsigned> mapping = data.getMap();
    std::vector<std::vector<double>> transit = data.getTransitMatrix();
    Graph g;
    for (auto it = mapping.begin(); it != mapping.end(); it++) {
        g.addVertex(it -> first);
    }
    
    for (unsigned i = 0; i < transit.size(); i++) {
        for (unsigned j = 0; j < transit.at(i).size(); j++) {
            int fromID = 0;
            int toID = 0;
            int count = 0;
            for (auto it = mapping.begin(); it != mapping.end(); it++) {
                if (it -> second == i) {
                    toID = it -> first;
                    count++;
                }
                if (it -> first == j) {
                    fromID = it -> first;
                    count++;
                }
                if (count == 2) {
                    break;
                }
            }
            g.addEdge(fromID, toID, transit.at(i).at(j));
        }
    }
    int user_input;
    std::cout << "Please type a node ID to check it's connected component: ";
    std::cin >> user_input;
    std::cout << "Here is a sequence of node IDs of traversal: ";
    for (auto i: g.getTraversalPath(user_input)){
        std::cout << i << " ";
    }
    std::cout << '\n';
    PageRank rank(data);
    std::vector<int> result = rank.findTopTen();
    std::cout << "Your top ten popular websites (in decending order) are: ";
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << '\n';
    
    int start;
    int end;
    std::cout << "Enter the starting point for finding the shortest path: ";
    std::cin >> start;
    std::cout << "Now enter the destination: ";
    std::cin >> end;
    std::cout << "This is the shortest path for your starting and ending points: ";
    // Dijkstra d(g, start, end);
    //Print the output out

    return 0;
}