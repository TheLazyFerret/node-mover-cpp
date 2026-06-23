//! Axuliar stucture for an easy parsable graph configuration.

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

/// Auxiliar specification of a node's edge.
struct EdgeSpec {
  std::int32_t cost;        // Cost of the edge.
  std::size_t destiny_node; // Destiny node.
  // The origin node is the NodeSpec itself.
};

/// Auxiliar specification of a node.
struct NodeSpec {
  std::optional<std::string> name;                // Optional name.
  std::pair<std::int32_t, std::int32_t> position; // Node coordinates position.
  std::vector<EdgeSpec> edges;
};

/// Graph specification auxiliar structure.
struct GraphSpec {
  std::optional<std::string> name; // Optional name.
  std::vector<NodeSpec> nodes;
};
