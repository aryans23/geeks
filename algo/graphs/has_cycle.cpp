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

  if (g.isCyclic())
    std::cout << "This graph has cycles!!" << std::endl;
  else 
    std::cout << "This graph doesn't have cycles!!" << std::endl;

  Graph g2(4);
  g2.addEdge(0, 1);
  g2.addEdge(0, 2);
  g2.addEdge(1, 2);
  g2.addEdge(2, 0);
  g2.addEdge(2, 3);
  g2.addEdge(3, 3);
  g2.print();
  g2.printEdges();

  if (g2.isCyclic())
    std::cout << "This graph has cycles!!" << std::endl;
  else 
    std::cout << "This graph doesn't have cycles!!" << std::endl;
  
  return 0;
}
