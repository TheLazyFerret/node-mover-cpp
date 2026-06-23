//! Source code of graph structure.

#include "./graph.hpp"

#include <expected>
#include <memory>

#include "./graph-spec.hpp"

/// Builds a new graph.
std::expected<Graph, GraphError> Graph::build(const GraphSpec& graph_spec) noexcept {
  Graph graph; // Creates an empty graph.
  // Creates the nodes.
  for (const auto& node_spec : graph_spec.nodes) {
    graph.nodes.push_back(std::make_shared<Node>(node_spec.position.first, node_spec.position.second));
  }
  // Add the edges.
  std::size_t index = 0;
  for (const auto& node_spec : graph_spec.nodes) {
    for (const auto& edge_spec : node_spec.edges) {
      if (edge_spec.destiny_node >= graph.nodes.size()) {
        return std::unexpected(GraphError::InvalidNodeReference);
      }
      graph.nodes.at(index)->add_edge(graph.nodes.at(edge_spec.destiny_node), edge_spec.cost);
    }
    ++index;
  }
  return std::move(graph);
}
