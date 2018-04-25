#include "Graph.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 0);
  g.addEdge(1, 2);
  g.addEdge(2, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 0);
  g.addEdge(3, 2);  
  g.print();
  g.printEdges();

  std::cout << "Printing result..." << std::endl;
  if (g.isBipartite())
    std::cout << "\tGraph is bipartite" << endl;
  else
    std::cout << "\tGraph is NOT bipartite" << endl;

  return 0;
}
