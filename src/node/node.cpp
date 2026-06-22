//! Implementation of node.hpp

#include "./node.hpp"

#include <cstdint>
#include <map>
#include <memory>
#include <optional>
#include <utility>
#include <vector>

/// Creates and insert a new edge in the the set.
/// If there is already a path to the node, it's cost is updated instead.
void Node::add_edge(const std::shared_ptr<Node>& node, std::int32_t cost) {
  path(node)
      .and_then([this, cost](const auto value) {
        this->adjacent_nodes.at(value) = cost;
        return std::make_optional(value);
      })
      .or_else([this, node, cost]() {
        const std::weak_ptr<Node> obs(node);
        this->adjacent_nodes.insert({obs, cost});
        return std::optional<std::weak_ptr<Node>>();
      });
}

/// Deletes an edge. It doesn't do anything if the node doesn't exist.
void Node::delete_edge(const std::shared_ptr<Node>& node) { this->adjacent_nodes.erase(node); }

/// Search and removes from adjacent_nodes the expired references.
void Node::clean_invalid_edges() noexcept {
  std::vector<std::weak_ptr<Node>> expired_obs;
  for (const auto& obs : this->adjacent_nodes) {
    if (obs.first.expired()) {
      expired_obs.push_back(obs.first);
    }
  }
  for (const auto& obs : expired_obs) {
    this->adjacent_nodes.erase(obs);
  }
}

/// Return the observer to the node if there is a path, nullopt otherwise.
std::optional<std::weak_ptr<Node>> Node::path(const std::shared_ptr<Node>& node) const {
  const auto iter = this->adjacent_nodes.find(node);
  if (iter != this->adjacent_nodes.end()) {
    return iter->first;
  } else {
    return {};
  }
}
