#include <Graph.h>
#include <data.h>
#include <dijkstras.h>
#include <pageRank.h>

int main() {
    std::cout << __LINE__ << std::endl;
    DataParsing data("/workspaces/cs225/CS225_Final_Project/final_project/web-Google_copy.txt", 2000);
    std::cout << __LINE__ << std::endl;
    std::map<int, unsigned> mapping = data.getMap();
    std::cout << __LINE__ << std::endl;
    std::vector<std::vector<double>> transit = data.getTransitMatrix();
    std::cout << __LINE__ << std::endl;
    Graph g = data.getGraph();
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
    // std::pair<double, std::unordered_set<int>> dijkstra = Dijkstra(g, start, end);
    std::pair<double, std::vector<int>> dijkstra = Dijkstra(g, start, end);
    for (int it : dijkstra.second) {
        std::cout << it << " ";

    }
    std::cout << "\n";
    std::cout << "This is the shortest distance in total: ";
    std::cout << dijkstra.first << std::endl;
    //Print the output out

    return 0;
}