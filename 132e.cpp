#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[110];
double graph[110][110];
double residual[110][110];

int parent[110];
int degree[110];

void generate_graph(double g) {
    for (int i = 1; i <= n; i++) {
        graph[i][n+1] = m + 2*g - degree[i];
    }

    cout << "check graph g=" << g << endl;

    for (int i = 0; i <= n+1; i++) {
        for (int j = 0; j <= n+1; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
}

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
    
    return (visited[n+1] == true);
}

double find_max_flow(){
    double max_flow = 0;

    for (int i = 0; i <= n+1; i++) 
        for (int j = 0; j <= n+1; j++) 
            residual[i][j] = graph[i][j];

    while (bfs()) {
        double path_flow = INT_MAX;
        int u = n+1;
        while (parent[u] != -1) {
            int v = parent[u];
            path_flow = min(path_flow, residual[v][u]);
            u = v;
        }

        cout << "check bfs" << endl;
        for (int i = 0; i <= n+1; i++)
            cout << parent[i] << ' ';

        u = n+1;
        while (parent[u] != -1) {
            int v = parent[u];
            residual[v][u] -= path_flow;
            residual[u][v] += path_flow;
            u = v;
        }

        max_flow += path_flow;
    }
    return max_flow;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a] ++;
        degree[b] ++;
    }
    
    for (int i = 1; i <= n; i++) {
        graph[0][i] = m;
        adj[0].push_back(i);
        adj[i].push_back(0);
        adj[i].push_back(n+1);
        adj[n+1].push_back(i);
    }

    double l = 1.0/n;
    double r = m;
    while (r - l > 1.0/n/n) {
        double g = (r+l) / 2;
        generate_graph(g);
        double t = find_max_flow();
        cout << "g:" << g << " max_flow:" << t << endl;
        if (t > 0) {
            l = g;
        } else {
            r = g;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << residual[0][i] << ' ';

    return 0;
}
