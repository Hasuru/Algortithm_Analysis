#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

// Classe que representa um grafo
class Graph {
public:
    int n;                    // Numero de nos do grafo
    vector<vector <int>> adj; // Lista de adjacencias
    vector<vector <int>> cap; // Matriz de capacidades

    Graph(int n) {
        this->n = n;
        adj.resize(n);
        cap.resize(n);
        for (int i=0; i<n; i++) cap[i].resize(n+1);
    }
    
    void addLink(int a, int b, int c) {
        //printf("Added [%d - %d] -> %d\n", a, b, c);
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] = c;
        //cap[b][a] = c;
    }

    // BFS para encontrar caminho de aumento
    // devolve valor do fluxo nesse caminho
    int bfs(int s, int t, vector<int> &parent) {
        for (int i=0; i<n; i++) parent[i] = -1;

        parent[s] = -2;         
        queue<pair<int, int>> q; // fila do BFS com pares (no, capacidade)
        q.push({s, INT_MAX});    // inicializar com no origem e capacidade infinita

        while (!q.empty()) {
        // returar primeiro no da fila
            int cur = q.front().first;
            int flow = q.front().second;

            q.pop();

            for (int next : adj[cur]) {
            // se o vizinho ainda nao foi visitado (parent==-1)
            // e a aresta respetiva ainda tem capacidade para passar fluxo
                if (parent[next] == -1 && cap[cur][next] > 0) {
                    parent[next] = cur;                        
                    int new_flow = min(flow, cap[cur][next]);  
                    if (next == t) return new_flow;            
                    q.push({next, new_flow});                 
                }
            }
        }
        
        return 0;
    }
    
    // Algoritmo de Edmonds-Karp para fluxo maximo entre s e t
    // devolve valor do fluxo maximo (cap[][] fica com grafo residual)
    int maxFlow(int s, int t) {
        int flow = 0;             
        vector<int> parent(n+1);  
        
        while (true) {
            int new_flow = bfs(s, t, parent); 
            if (new_flow == 0) break;         

            // imprimir fluxo e caminho de aumento
            //cout << "Caminho de aumento: fluxo " << new_flow << " | " << t;
            
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];	
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
                //cout << " <- " << cur;
            }
            //cout << endl;
        }
        
        return flow;
    }
};

int main() {
    int k;
    cin >> k;;

    while(k--) {
        int n, e;
        cin >> n >> e;

        int size = 2*n;
        Graph *g = new Graph(size+2); //+2 por causa do no s(n+1) e o no t(n+2)

        int s = size, t = size+1;
        for (int i = 0; i < e; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            g->addLink(v1,v2+n,1);
            g->addLink(s,v1,1);
            g->addLink(v2+n,t,1);
        }

        int flow = g->maxFlow(s,t);
        //cout << flow << endl;

        if (flow == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}