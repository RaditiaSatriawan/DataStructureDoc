#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <set>
#include <utility>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adjList;
    
public:
    Graph(int V) : V(V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // Untuk graf tak berarah
    }

    void DFTUtil(int v, vector<bool> &visited) {
        stack<int> stack;
        stack.push(v);

        while (!stack.empty()) {
            v = stack.top();
            stack.pop();

            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;
            }

            for (auto &i : adjList[v])
                if (!visited[i.first])
                    stack.push(i.first);
        }
    }

    void DFT(int v) {
        vector<bool> visited(V, false);
        DFTUtil(v, visited);
        cout << endl;
    }

    void BFT(int v) {
        vector<bool> visited(V, false);
        queue<int> queue;

        visited[v] = true;
        queue.push(v);

        while (!queue.empty()) {
            v = queue.front();
            cout << v << " ";
            queue.pop();

            for (auto &i : adjList[v]) {
                if (!visited[i.first]) {
                    visited[i.first] = true;
                    queue.push(i.first);
                }
            }
        }
        cout << endl;
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> setds;

        setds.insert({0, src});
        dist[src] = 0;

        while (!setds.empty()) {
            auto tmp = *(setds.begin());
            setds.erase(setds.begin());

            int u = tmp.second;

            for (auto &i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[v] > dist[u] + weight) {
                    if (dist[v] != INT_MAX)
                        setds.erase(setds.find({dist[v], v}));

                    dist[v] = dist[u] + weight;
                    setds.insert({dist[v], v});
                }
            }
        }

        cout << "Vertex   Distance from Source\n";
        for (int i = 0; i < V; ++i)
            cout << i << " \t\t " << dist[i] << endl;
    }
};

int main() {
    int V, E;
    cout << "Masukkan jumlah vertex: ";
    cin >> V;
    cout << "Masukkan jumlah edge: ";
    cin >> E;

    Graph g(V);

    cout << "Masukkan edge dalam format (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    cout << "Depth First Traversal (starting from vertex 0): ";
    g.DFT(0);

    cout << "Breadth First Traversal (starting from vertex 0): ";
    g.BFT(0);

    cout << "Dijkstra's shortest path algorithm (starting from vertex 0):" << endl;
    g.dijkstra(0);

    return 0;
}
