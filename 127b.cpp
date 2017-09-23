#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1010];
int graph[1010][1010];
int residual[1010][1010];
int parent[1010];

bool bfs(){
    bool visited[n];
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));

    queue<int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!visited[v] && residual[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    
    return (visited[n-1] == true);
}

long long find_max_flow(){
    long long max_flow = 0;

    while (bfs()) {
        int path_flow = INT_MAX;
        int u = n-1;
        while (parent[u] != -1) {
            int v = parent[u];
            path_flow = min(path_flow, residual[v][u]);
            u = v;
        }

        u = n-1;
        while (parent[u] != -1) {
            int v = parent[u];
            residual[v][u] -= path_flow;
            residual[u][v] += path_flow;
            u = v;
        }

        max_flow += (long long) path_flow;
    }
    return max_flow;
}


int main() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        residual[a][b] += c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << find_max_flow() << endl;
    return 0;
}
