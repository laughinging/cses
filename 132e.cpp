#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[110];
double  residual[110][110];
int parent[110];
int d[110];
bool visited[110];

void generate_graph(double g){
    printf("constructing graph with g = %lf\n", g);

    for (int i = 1; i <= n; i++) {
        residual[i][n+1] = m + 2*g - d[i];
    }
}

bool bfs() {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));

    queue<int> q;
    while (!q.empty())
        q.pop();

    q.push(0);
    visited[0] = true;
    parent[0] = -1;

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!visited[v] && residual[u][v] > 0) {
                q.push(v);
                cout << "push in node: " << v << endl;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    if (visited[n+1] == true) {
        printf("find a path \n");
        int u = n+1;
        while (u != -1) {
            cout << u << ' ';
            u = parent[u];
        }
    }
    cout << endl;
    return visited[n+1] == true;
}

double find_max_flow(){
    double max_flow = 0;
    double path_flow = 0;
    int u;

    while (bfs()) {
        path_flow = INT_MAX ;
        u = n + 1;
        while (parent[u] != -1) {
            int v = parent[u];
            path_flow = min(path_flow, residual[v][u]);
            u = v;
        }
        printf("path_flow = %lf \n", path_flow);
    
        u = n + 1;
        while (parent[u] != -1) {
            int v = parent[u];
            residual[v][u] -= path_flow;
            residual[u][v] += path_flow;
            u = v;
        }
        
        max_flow += path_flow;
        printf("current max_flow = %lf\n", max_flow);
    }

    return max_flow;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < m; i++) {
        int a, b;
        cin >> a >> b;
        residual[a][b] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
        residual[b][a] = 1;
        d[a] ++;
        d[b] ++;
    }
    for (int i = 1; i <= n; i++) {
        residual[0][i] = m;
        adj[0].push_back(i);
        adj[i].push_back(0);
        adj[i].push_back(n+1);
        adj[n+1].push_back(i);
    }
    double l, r, mid, hg;
    l = 0; r = m;
    double precision = 1.0 / n / n;
    
    while (r - l >= precision) {
        mid = (l + r) / 2;
        generate_graph(mid);
        hg = (n*m - find_max_flow()) / 2;
        mid = (hg > 1e-8 ? l : r);
    }
    for (int i = 1; i <= n; i++)
        if (visited[i])
            cout << i << endl;

    return 0;
}
