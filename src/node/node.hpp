//! Data structure representing a single node in the graph.

#pragma once

#include <cstdint>
#include <utility>
#include <memory>
#include <set>

class Node; // Fordward declaration.

/// Edge helper struct.
struct Edge {
  std::weak_ptr<Node> node;
  std::int32_t cost = 0;
  friend bool operator<(const Edge& a, const Edge& b);
};

/// Node class.
class Node {
public:
  /// Special methods.
  inline Node() noexcept : pos(0, 0) {}
  inline explicit Node(std::int32_t x, std::int32_t y) noexcept : pos(x, y) {}
  // Implicit default copy, move and destructor.

  /// Public methods.
  inline std::pair<std::int32_t, std::int32_t> get_pos() const noexcept { return pos; }
  inline void set_pos(std::int32_t x, std::int32_t y) noexcept { pos = {x, y}; };

  inline void add_edge(const Edge edge) noexcept {adjacent_nodes.insert(edge);}
  inline const std::set<Edge>& get_edges() const noexcept {return adjacent_nodes;};
  
private:
  /// Private methods.
  
  /// Attributes.
  std::pair<std::int32_t, std::int32_t> pos;
  std::set<Edge> adjacent_nodes;
};

///  "Less than" operator for Edge.
inline bool operator<(const Edge& a, const Edge& b) {
  const auto temp_shared_a = a.node.lock();
  const auto temp_shared_b = b.node.lock();
  return temp_shared_a < temp_shared_b;
}