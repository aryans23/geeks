#include "Graph.h"

int main(int argc, char** argv) 
{
  Graph g(6);
  g.addEdge(5, 0);
  g.addEdge(5, 2);
  g.addEdge(3, 1);
  g.addEdge(4, 1);
  g.addEdge(4, 0);
  g.addEdge(2, 3);
  g.print();
  g.printEdges();

  std::cout << "Topological Sort: " << std::endl;
  g.topologicalSort();
  std::cout << std::endl;
  
  return 0;
}
