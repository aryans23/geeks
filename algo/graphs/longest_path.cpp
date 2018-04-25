#include "Graph.h"

int main(int argc, char** argv) 
{
  Graph g(6);
  g.addEdge(0, 1, 5);
  g.addEdge(0, 2, 3);
  g.addEdge(1, 3, 6);
  g.addEdge(1, 2, 2);
  g.addEdge(2, 4, 4);
  g.addEdge(2, 5, 2);
  g.addEdge(2, 3, 7);
  g.addEdge(3, 5, 1);
  g.addEdge(3, 4, -1);
  g.addEdge(4, 5, -2); 
  g.print();
  g.printEdges();

  int s;
  int dist[6];
  std::cout << "Enter the source: ";
  std::cin >> s;
  std::cout << "Following are longest distances from source vertex " << s << std::endl;
  std::cout << "\t" ;
  g.longestPath(s,dist);
  for (int i = 0; i < 6; i++) {
    std::cout << "(To " << i << ": ";
    (dist[i] == INT_MIN)? std::cout << "INF ": std::cout << dist[i];
    std::cout << ") ";
  }
  std::cout << std::endl;

  return 0;
}
