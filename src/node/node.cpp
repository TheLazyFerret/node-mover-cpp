//! Implementation of node.hpp

#include "./node.hpp"

#include <cstdint>
#include <utility>

/// Return the current position.
std::pair<std::int32_t, std::int32_t> Node::get_pos() const noexcept { return std::make_pair(pos_x, pos_y); }

/// Update the current position.
void Node::set_pos(std::int32_t x, std::int32_t y) noexcept {
  pos_x = x;
  pos_y = y;
}
