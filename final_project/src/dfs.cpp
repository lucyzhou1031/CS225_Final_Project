#include "dfs.h"

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const Graph & graph, const GraphNode & start) {
    g_ = graph;
    start_ = start;
    list_.push(start);
}

// /**
//  * Returns an iterator for the traversal starting at the first point.
//  */
// ImageTraversal::Iterator DFS::begin() {
//   /** @todo [Part 1] */
//   return ImageTraversal::Iterator(this, png_, tolerance_, start_);

// }

// /**
//  * Returns an iterator for the traversal one past the end of the traversal.
//  */
// ImageTraversal::Iterator DFS::end() {
//   /** @todo [Part 1] */
//   return ImageTraversal::Iterator();
// }

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const GraphNode & node) {
  list_.push(node);
}

/**
 * Removes and returns the current Point in the traversal.
 */
GraphNode DFS::pop() {
  GraphNode tr = list_.top();
  list_.pop();
  return tr;
}

/**
 * Returns the current Point in the traversal.
 */
GraphNode DFS::peek() const {
  return list_.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  return (list_.empty());
}
