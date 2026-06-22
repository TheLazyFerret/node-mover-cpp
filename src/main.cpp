//! Main program file.

#include <memory>
#include <print>

#include "node/node.hpp"

// void recursive_deep_search(const std::shared_ptr<Node> initial_node) {}

int main(/*int argc, char** argv*/) {
  std::shared_ptr<Node> node1 = std::make_shared<Node>(1, 1);
  std::shared_ptr<Node> node2 = std::make_shared<Node>(2, 2);
  std::shared_ptr<Node> node3 = std::make_shared<Node>(3, 3);

  node1->add_edge(node2, 90);
  node1->add_edge(node3, 100);
  
  //node2.reset();
  //node1->clean_invalid_edges();
  node1->delete_edge(node2);
  
  std::println("node2 use_cost: {}", node2.use_count());

  for (const auto& obs : node1->get_adjacent()) {
    if (auto lock = obs.first.lock()) {
      const auto pos = lock->get_pos();
      std::println("pos: {}, {}", pos.first, pos.second);
    } else {
      std::println("skipping expired observer");
    }
  }

  return 0;
}
