## Leading Question 

In this project, we will be finding which website has greater importance than others based on data collected from a specific web searching engine using various data structures and algorithms. To solve this goal, we will break the problem down to a few smaller ones and will implement algorithms using various data structures to solve each. From the dataset, we will process the data into matrices and use PageRank algorithm to rank websites by how important they’re. We will construct a weighted graph based on the matrix that comes from the data and use Dijkstra’s algorithm to find the shortest path between two websites. We will be using the DFS algorithm to traverse through the graph. We will then decide with websites are considered more important based on all analysis we made. We will be using Google web data collection to test our program, and we expect this program to be generalized for any valid data collections from other search engines.
## Dataset Acquisition

### Data Format

We are accessing our dataset from Stanford Large Network Dataset Collection (http://snap.stanford.edu/data/web-Google.html). In this dataset, each website is represented by a node ID, and the ID is unique for different web pages. Each line of the dataset has two nodes that are paired together, with the left one is the starting node (starting web page) and the left one is the destination (the ending web page), meaning that there is a hyperlink in the web page represented by node A that can direct the user to the web page represented by node B. The nodes and pairs are all unordered. Node IDs is a sequence of unique integers. We will be using the starting node IDs as the columns and the ending node IDs as the rows of the adjacent matrix. We initialize this adjacency matrix as a zero matrix, then changing the entry at row A and column B to be 1 when there exists a jump from node ID B to node ID A. We will then implement the transit matrix based on the adjacency matrix. We divide each entry (either 0 or 1) with the sum of its column or the height of the matrix if its column sums to 0. Each entry of the matrix represents the probability that node A links to node B. The entries of our transit matrix will then become the weight of our directed graph. After combining all pairs together, these nodes will form a directed graph. This dataset has 875714 nodes and 5105039 edges since a node can pair with multiple other different nodes. We are planning to use the whole dataset at this point. 

### Data Correction

To ensure that the data is correct, we need to make sure that it’s ID is valid (within the range of 0 - 875713). Since the data is paired, if there is one line that only has one node or greater than 2 nodes, we can skip this line.

### Data Storage

We will be implementing a directed graph class object to store the data. This directed graph class will have a map that includes all the nodes as keys, and the list of nodes the key points to as values. The class will also include an adjacency matrix.
The Big-O approximation should be at least O(V^2), where V is the number of vertices in the graph, because we’re dealing with V by V matrices.


## Algorithm

We will be using three algorithms in this project. We will first use DFS to traverse all nodes in a connected graph. The input of this algorithm is the starting node to traverse with. The output of this algorithm is a collection of nodes that are directly or indirectly connected with the starting node. Time Complexity of DFS is O(V+E) where V is the number of vertices and E is the number of edges. The space complexity is O(bm) where m is the length of the longest path and b is the number of extra nodes for each of the m nodes.

The expected inputs for our PageRank algorithm will be a transit matrix, which will be converted by each line’s data pair, and a vector of initial guesses of probability or importance for each node. The transit matrix will represent our directed graph for our algorithm with each entry representing the weight of the edge from one node to another. The expected output for our PageRank algorithm will be a vector of probability which shows how often people go to a specific web page, representing the importance of each web page. We will be using this vector to determine which one is the most visited or the most important and which one is the least visited or the least important. The time complexity for the PageRank algorithm is O(E*k) where E is the number of edges and k is the number of iterations.

To find the shortest path between nodes, we will implement our code using Dijkstra’s algorithm. The expected input for this algorithm is a source node, and a weighted directed source graph object. The expected output is a collection of integer values representing the shortest path from the source node to every other node in the source graph. The time complexity is approximately O((V+E)logV) where E is the number of edges and V is the number of vertices. The space complexity is O(V).


## Timeline
#### Week 0 (~11.04)
1. Complete Team Contract
2. Complete Team Proposal
3. Set up git repository
4. Complete development log 1
#### Week 1 (11.05 ~11.11)
1. Accessing dataset (which we have already done)
2. Data parsing
3. Construct DFS traversal (by 11.10)
4. Write our own test cases for DFS traversal
5. Complete development log 2
#### Week 2 (11.12~11.18)
1. Write our own test cases for Dijkstra’s algorithm
2. Construct Dijkstra’s algorithm (prefer by 11.17)
3. Expect to have DFS works and test cases for Dijkstra’s algorithm before meeting
4. Complete development log 3
#### Week 3 (11.28~12.02)
1. Write our own test cases for PageRank algorithm
2. Construct PageRank algorithm (by 12.01)
3. Complete development log 4
##### Week 4 (12.03~12.08)
1. Finalize project details
2. Finalize github repository with README.md
3. Make presentation video (by 12.05)
4. Write final report (by 12.07)
