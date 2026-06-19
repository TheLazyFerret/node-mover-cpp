//! Data structure representing a single node in the graph.

#pragma once

#include <cstdint>
#include <utility>

class Node {
public:
  /// Special methods.
  inline Node() noexcept : pos_x(0), pos_y(0) {}
  inline explicit Node(std::int32_t x, std::int32_t y) noexcept : pos_x(x), pos_y(y) {}
  // Implicit default copy and move.

  /// Public methods.
  std::pair<std::int32_t, std::int32_t> get_pos() const noexcept;
  void set_pos(std::int32_t, std::int32_t) noexcept;
private:
  /// Private methods.
  
  /// Attributes.
  std::int32_t pos_x;
  std::int32_t pos_y;
};
