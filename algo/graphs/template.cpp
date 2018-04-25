#include "Graph.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) 
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);  
  g.print();
  g.printEdges();

  return 0;
}
