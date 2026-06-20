/// Main program file.

#include <memory>
#include <print>

#include "./node/node.hpp"

int main(int argc, char** argv) {
  std::shared_ptr<Node> node1 = std::make_shared<Node>(1, 1);
  std::shared_ptr<Node> node2 = std::make_shared<Node>(2, 2);
  std::shared_ptr<Node> node3 = std::make_shared<Node>(3, 3);
  node1->add_edge({node1});
  node1->add_edge({node2});
  node1->add_edge({node3});


  const auto node1_edges = node1->get_edges();
  for (const auto& edge: node1_edges) {
    if (edge.node == node1) {
      std::println("same node");
    }
  }

  return 0;
}
