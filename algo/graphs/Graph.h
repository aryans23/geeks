#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <stack>

class AdjListNode;
class Graph;

class AdjListNode {
  private:
    int _v;
    int _weight;
  public:
    AdjListNode(int v, int weight = 1);
    int getV();
    int getWeight();
};

class Graph {
  private:
    int _V;
    std::list<AdjListNode> *_adj;

  public:
    Graph();
    Graph(int V);
    ~Graph();
    void addEdge(int u, int v, int weight = 1);
    // void delEdge(int u, int v);
    void print();
    void printEdges();
    int bfs();
    int bfs(int s);
    int dfs();
    int dfs(int s);
    void topologicalSortUtil(int i, std::stack<int>& st, bool visited[]);
    int topologicalSort();
    bool isCyclic();
    bool isCyclicUtil(int i, bool *visited, bool *recPath);
    void longestPath(int s, int *dist);
    bool isBipartiteUtil(int v,int *color);
    bool isBipartite();
};

#endif

/*
   g++ -g -o output Graph.cpp bfs.cpp
*/
