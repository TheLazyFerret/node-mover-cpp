//! Data structure representing a single node in the graph.
//!
//! Each node can have NONE or ONE path to any other node, including itself.
//! Therefore, there can't be multiple paths to the same node.

#pragma once

#include <cstdint>
#include <map>
#include <memory>
#include <optional>
#include <utility>

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

  void add_edge(const std::shared_ptr<Node>&, std::int32_t);
  void delete_edge(const std::shared_ptr<Node>&);

  void clean_invalid_edges() noexcept;

  // temporal method for debugging.
  inline const std::map<std::weak_ptr<Node>, std::int32_t, std::owner_less<>>& get_adjacent() const noexcept {
    return adjacent_nodes;
  }

private:
  /// Private methods.
  std::optional<std::weak_ptr<Node>> path(const std::shared_ptr<Node>&) const;

  /// Attributes.
  std::pair<std::int32_t, std::int32_t> pos;
  std::map<std::weak_ptr<Node>, std::int32_t, std::owner_less<>> adjacent_nodes;
};
