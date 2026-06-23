//! Graph structure.
//! It has an static number of nodes.

#pragma once

#include <expected>
#include <memory>
#include <vector>

#include "../node/node.hpp"
#include "./graph-spec.hpp"

/// Errors of the class.
enum class GraphError { InvalidNodeReference };

/// Graph class.
class Graph {
public:
  /// Special methods.
  Graph(const Graph&) = delete;            // Copy constructor.
  Graph& operator=(const Graph&) = delete; // Copy assignment.
  Graph(Graph&&) = default;                // Move constructor.
  Graph& operator=(Graph&&) = default;     // Move assignment;

  /// Public methods.
  static std::expected<Graph, GraphError> build(const GraphSpec&) noexcept;

public:
  Graph() = default; // Default constructor.
  /// Private methods.

  /// Attributes.
  std::vector<std::shared_ptr<Node>> nodes;
};
