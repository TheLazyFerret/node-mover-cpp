//! Main program file.

#include <expected>
#include <print>
#include <utility>

#include "graph/graph-spec.hpp"
#include "graph/graph.hpp"

constexpr GraphSpec generate_example_graph_spec() {
  GraphSpec graph_spec;
  graph_spec.nodes.reserve(5);
  NodeSpec node0_spec;
  node0_spec.position = std::make_pair(0, 0);
  node0_spec.edges.push_back({
    .cost = 0, 
    .destiny_node = 1
  });
  node0_spec.edges.push_back({
    .cost = 0,
    .destiny_node = 2
  });
  graph_spec.nodes.push_back(node0_spec);
  NodeSpec node1_spec;
  node1_spec.position = std::make_pair(1, 1);
  node1_spec.edges.push_back({
      .cost = 0,
      .destiny_node = 3
  });
  node1_spec.edges.push_back({
    .cost = 0,
    .destiny_node = 4
  });
  graph_spec.nodes.push_back(node1_spec);
  NodeSpec node2_spec;
  node2_spec.position = std::make_pair(2, 2);
  graph_spec.nodes.push_back(node2_spec);
  NodeSpec node3_spec;
  node3_spec.position = std::make_pair(3, 3);
  graph_spec.nodes.push_back(node3_spec);
  NodeSpec node4_spec;
  node4_spec.position = std::make_pair(4, 4);
  graph_spec.nodes.push_back(node4_spec);
  return graph_spec;
}

int main(/*int argc, char** argv*/) {
  GraphSpec gs = generate_example_graph_spec();
}
