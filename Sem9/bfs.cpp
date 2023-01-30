// Exemplo de pesquisa em largura (BFS) num grafo nao dirigido
// (codigo adaptado do codigo em Java feito na teorica)
// (inclui calculo de distancias)
// (esta versao nao tem "garbage collection", ou seja, nao limpa no final a memoria)

#include <iostream>
#include <list>

using namespace std;

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) {
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
  }

  void addLink(int a, int b) {
    nodes[a].adj.push_back(b);
    nodes[b].adj.push_back(a);
  }
  
  void bfs(int v) {
    list<int> q;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    
    q.push_back(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;

    while (q.size() > 0) {
      int u = q.front(); q.pop_front();
      cout << u << " [dist=" << nodes[u].distance << "]" << endl;
      for (auto w : nodes[u].adj)
	if (!nodes[w].visited) {
	  q.push_back(w);
	  nodes[w].visited  = true;
	  nodes[w].distance = nodes[u].distance + 1; 	  
	}
    }
  }
};

int main() {
  int n, e, a, b;
  
  cin >> n;
  Graph *g = new Graph(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b;
    g->addLink(a, b);
  }

  // Pesquisa em largura a partir do no 1
  g->bfs(1);

  return 0;
}