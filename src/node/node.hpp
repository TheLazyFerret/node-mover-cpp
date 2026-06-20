//! Data structure representing a single node in the graph.

#pragma once

#include <cstdint>
#include <utility>
#include <memory>
#include <set>

class Node; // Fordward declaration.

/// Edge helper struct.
struct Edge {
  std::shared_ptr<Node> node;
  std::uint32_t cost = 0;
  friend bool operator<(const Edge& a, const Edge& b) noexcept;
};

/// Node class.
class Node {
public:
  /// Special methods.
  inline Node() noexcept : pos_x(0), pos_y(0) {}
  inline explicit Node(std::int32_t x, std::int32_t y) noexcept : pos_x(x), pos_y(y) {}
  // Implicit default copy, move and destructor.

  /// Public methods.
  std::pair<std::int32_t, std::int32_t> get_pos() const noexcept;
  void set_pos(std::int32_t, std::int32_t) noexcept;

  void add_edge(const Edge edge) noexcept;
  inline const std::set<Edge>& get_edges() const noexcept {return adjacent_nodes;};
  
private:
  /// Private methods.
  
  /// Attributes.
  std::int32_t pos_x;
  std::int32_t pos_y;
  std::set<Edge> adjacent_nodes;
};