#include "Graph.h"

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

  int s;
  std::cout << "Enter starting vertex: ";
  std::cin >> s;
  
  std::cout << "\tBFS from vertex " << s << ": ";
  g.bfs(s);
  std::cout << std::endl;

  std::cout << "Printing BFS from all vertex..." << std::endl;
  g.bfs();
  std::cout << std::endl;
  
  return 0;
}
