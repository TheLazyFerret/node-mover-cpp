//! Edge (path) between two nodes.

#pragma once

#include <memory>

#include "../node/node.hpp"

class Edge {
public:
  /// Special methods.
  Edge() = delete;
  explicit Edge(std::shared_ptr<Node> a, std::shared_ptr<Node> b) noexcept : node_a(a), node_b(b) {}
  Edge(const Edge&) = delete;
  Edge& operator=(const Edge&) = delete;
  // Implicit default move and destructor.

  /// Normal methods.
  
private:
  /// Private methods.
  
  /// Attributes.
  std::shared_ptr<Node> node_a;
  std::shared_ptr<Node> node_b;
};