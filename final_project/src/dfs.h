/**
 * @file DFS.h
 */

#pragma once

#include <iterator>
#include <cmath>
#include <list>
#include <stack>

#include "Graph.h"
class DFS
{
    public:
        DFS(const Graph & graph, const GraphNode & start);

        // ImageTraversal::Iterator begin();
        // Graph::Iterator end();

        void add(const GraphNode & node);
        GraphNode pop();
        GraphNode peek() const;
        bool empty() const;

    private:
        Graph g_;
        GraphNode start_;
        std::stack<GraphNode> list_;
};
