/// Main program file.

#include <memory>
#include <print>

#include "./node/node.hpp"

//void recursive_deep_search(const std::shared_ptr<Node> initial_node) {}

int main(/*int argc, char** argv*/) {
  std::shared_ptr<Node> node1 = std::make_shared<Node>(1, 1);
  std::shared_ptr<Node> node2 = std::make_shared<Node>(2, 2);
  std::shared_ptr<Node> node3 = std::make_shared<Node>(3, 3);
  node1->add_edge({node1});
  node1->add_edge({node2});
  node1->add_edge({node3});

  const auto node1_set = node1->get_edges();
  for (const auto& edge: node1_set) {
    const auto pos = edge.node.lock()->get_pos();
    std::println("pos: {}, {}", pos.first, pos.second);
  }


  return 0;
}
