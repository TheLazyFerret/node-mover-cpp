//! Implementation of node.hpp

#include "./node.hpp"

#include <cstdint>
#include <utility>

/// Less than operator for Edge (friend standalone).
bool operator<(const Edge& a, const Edge& b) noexcept {
  return a.node < b.node; // Call the inner std::shared_ptr<Node> comparison.
}

/// Return the current position.
std::pair<std::int32_t, std::int32_t> Node::get_pos() const noexcept { return std::make_pair(pos_x, pos_y); }

/// Update the current position.
void Node::set_pos(std::int32_t x, std::int32_t y) noexcept {
  pos_x = x;
  pos_y = y;
}

/// Add an edge to the vector.
void Node::add_edge(const Edge edge) noexcept {
  adjacent_nodes.insert(edge);
}
