/// Main program file.

#include <memory>
#include <print>

#include "./node/node.hpp"
#include "./edge/edge.hpp"

int main(int argc, char** argv) {
  std::shared_ptr<Node> node_a = std::make_shared<Node>(5, 5);
  std::shared_ptr<Node> node_b = std::make_shared<Node>(2, 2);
  Edge edge(node_a, node_b, 1, Direction::Bidirectional);
  std::println("node_a: {}", node_a.use_count());
  std::println("node_b: {}", node_b.use_count());
  return 0;
}
