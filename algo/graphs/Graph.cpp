#include "Graph.h"

//***** AdjListNode functions *****//

// Constructor
AdjListNode::AdjListNode(int v, int weight): _v(v), _weight(weight) {}

int AdjListNode::getV()
{
  return _v;
}

int AdjListNode::getWeight()
{
  return _weight;
}

//***** Graph functions *****//

// Empty Constructor
Graph::Graph(): _V(0), _adj(NULL)
{
  std::cout << "Graph initiallized" << std::endl;
}

// Constructor
Graph::Graph(int V): _V(V) 
{
  _adj = new std::list<AdjListNode> [_V];
  std::cout << "Graph initiallized" << std::endl;
}

// Destructor
Graph::~Graph() {}

void Graph::addEdge(int u, int v, int weight) 
{
  if (u >= _V || v >= _V || u < 0 || v < 0) {
    std::cout << "\tEdge can't be added. Please check your input" << std::endl;
    return;
  }
  // AdjListNode node = new AdjListNode(v,weight);
  AdjListNode node(v, weight);
  _adj[u].push_back(node);
  std::cout << "\tEdge added from " << u << " to " << v << " of weight " << weight << std::endl;
}

void Graph::print() 
{
  std::cout << "Printing Graph... " << std::endl;
  for (int i = 0; i < _V; i++) {
    std::cout << "\t" << i << "->";
    for (std::list<AdjListNode>::iterator it = _adj[i].begin(); it != _adj[i].end(); it++) {
      // std::cout << "(" << it->getV() << "," << it->getWeight() << ")" << "->";
      std::cout << it->getV() << " ";
    }
    std::cout << std::endl;
  }
}

void Graph::printEdges() 
{
  std::cout << "Printing Edges... " << std::endl;
  for (int i = 0; i < _V; i++) {
    for (std::list<AdjListNode>::iterator it = _adj[i].begin(); it != _adj[i].end(); it++) {
      std::cout << "\tFrom " << i << " to " << it->getV() << " of weight " << it->getWeight() << std::endl;
    }
  }
}

int Graph::bfs()
{
  for (int i = 0; i < _V; i++) {
    std::cout << "\tBFS from " << i << ": ";
    bfs(i);
    std::cout << std::endl;
  }

  return 0;
}


int Graph::bfs(int s)
{
  if (s < 0 || s >= _V) {
    std::cout << "Can't do BFS. Please check input" << std::endl;
    return 0;
  }

  bool *visited = new bool[_V];
  for (int i = 0; i<_V; i++) 
    visited[i] = false;

  std::list<int> q;
  visited[s] = true;
  q.push_back(s);
  std::list<AdjListNode>::iterator it;

  while (!q.empty()) {
    s = q.front();
    std::cout << s << " ";
    q.pop_front();

    for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
      int node = it->getV();
      if (!visited[node]) {
        visited[node] = true;
        q.push_back(node);
      }
    }
  }

  return 0;
}

int Graph::dfs()
{
  for (int i = 0; i < _V; i++) {
    std::cout << "\tDFS from " << i << ": ";
    dfs(i);
    std::cout << std::endl;
  }
  return 0;
}

int Graph::dfs(int s)
{
  if (s < 0 || s >= _V) {
    std::cout << "Can't do DFS. Please check input" << std::endl;
    return 0;
  }

  bool *visited = new bool[_V];
  for (int i = 0; i<_V; i++) 
    visited[i] = false;

  std::stack<int> st;
  visited[s] = true;
  st.push(s);
  std::list<AdjListNode>::iterator it;

  while (!st.empty()) {
    s = st.top();
    std::cout << s << " ";
    st.pop();

    for (it = _adj[s].begin(); it != _adj[s].end(); it++) {
      if (!visited[it->getV()]) {
        visited[it->getV()] = true;
        st.push(it->getV());
      }
    }
  }

  return 0;
}

void Graph::topologicalSortUtil(int i, std::stack<int>& st, bool visited[])
{
  visited[i] = true;
  std::list<AdjListNode>::iterator it;
  for (it = _adj[i].begin(); it != _adj[i].end(); it++) {
    if (!visited[it->getV()])
      topologicalSortUtil(it->getV(),st,visited);
  }
  st.push(i);
}

int Graph::topologicalSort()
{
  std::stack<int> st;
  bool *visited = new bool[_V];
  for (int i = 0; i<_V; i++) 
    visited[i] = false;

  for (int i = 0; i < _V; i++) {
    if (!visited[i])
      topologicalSortUtil(i,st,visited);
  }

  while (!st.empty()) {
    std::cout << st.top() << " ";
    st.pop();
  }
  return 0;
}

bool Graph::isCyclic()
{
  bool *visited = new bool[_V];
  bool *recPath = new bool[_V];
  for (int i = 0; i < _V; i++) {
    visited[i] = false;
    recPath[i] = false;
  }

  for (int i = 0; i < _V; i++)
    if (isCyclicUtil(i,visited,recPath))
      return true;
  return false;
}

bool Graph::isCyclicUtil(int i, bool *visited, bool *recPath)
{
  if (!visited[i]) {
    recPath[i] = true;
    visited[i] = true;

    std::list<AdjListNode>::iterator it;
    for (it = _adj[i].begin(); it != _adj[i].end(); it++) {
      if (!visited[it->getV()] && isCyclicUtil(it->getV(),visited,recPath)) {
        return true;
      }
      else if (recPath[it->getV()]) {
        return true;
      }
    }
  }
  recPath[i] = false;
  return false;
}

void Graph::longestPath(int s, int *dist)
{
  bool *visited = new bool[_V];
  std::stack<int> st;

  for (int i = 0; i < _V; i++) {
    visited[i] = false;
    dist[i] = INT_MIN;
  }
  
  for (int i = 0; i < _V; i++)
    if (!visited[i])
      topologicalSortUtil(i,st,visited);
    
  dist[s] = 0;

  while (!st.empty()) {
    int u = st.top();
    st.pop();

    std::list<AdjListNode>::iterator it;
    if (dist[u] != INT_MIN) {
      for (it = _adj[u].begin(); it != _adj[u].end(); it++) 
        if (dist[it->getV()] <  it->getWeight() + dist[u]) 
          dist[it->getV()] = it->getWeight() + dist[u];
    }
  }
}

bool Graph::isBipartiteUtil(int v,int *nodeColor) 
{
  // Can also be implemented using BFS
  // color it 0 only if its coming for the first time
  if (nodeColor[v] == -1)
    nodeColor[v] = 0;

  std::list<AdjListNode>::iterator it;
  for (it = _adj[v].begin(); it != _adj[v].end(); it++) {
    // if neighbour has same color as the current node
    if (nodeColor[it->getV()] == nodeColor[v])
      return false;
    
    // flip the color of the current node and assign it to the uncolored neighbour
    if (nodeColor[it->getV()] == -1)
      nodeColor[it->getV()] = 1-nodeColor[v];
    else 
      continue;

    // Call for the uncolored neighbour
    if (!isBipartiteUtil(it->getV(),nodeColor))
      return false;
  } 
  return true;
}

bool Graph::isBipartite()
{
  // assign default color to the graph nodes
  int nodeColor[_V];
  for (int i = 0; i < _V; i++) 
    nodeColor[i] = -1;

  // call for every vertex the utility function
  for (int i = 0; i < _V; i++) {
    if (nodeColor[i] == -1){
      if (!isBipartiteUtil(i,nodeColor)) {
        return false;
      }
    }
  }

  return true;
}

