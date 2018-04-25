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

  int s;
  std::cout << "Enter starting vertex: ";
  std::cin >> s;
  
  std::cout << "\tDFS from vertex " << s << ": ";
  g.dfs(s);
  std::cout << std::endl;

  std::cout << "Printing DFS from all vertex..." << std::endl;
  g.dfs();
  std::cout << std::endl;
  
  return 0;
}
