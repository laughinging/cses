#include<bits/stdc++.h>
using namespace std;

int V;
vector<int> adj[40010];
int map_variable[100010];
map<int, int> 

int graph[40010][40010];
int residual[200000][200000];
int parent[200000];
int ans[100010];
int m, n;

map<int, int> constraint[100010];

void generate_graph() {
    cin >> m >> n;
    V = n + m + 2;
    for (int i = 1; i <= n; i++) {
        graph[0][i] = 1;
        adj[0].push_back(i);
        adj[i].push_back(0);
    }

    for (int i = n+1; i <= n+m; i++) {
        graph[i][V-1] = 1;
        adj[i].push_back(V-1);
        adj[V-1].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            int b;
            cin >> b;
            constraint[i][abs(b)] = b/abs(b);
            b = abs(b);
            graph[i][n+b] = 1;
            adj[i].push_back(n+b);
            adj[n+b].push_back(i);
        }
        int zero;
        cin >> zero;
    }
}

bool bfs(){
    bool visited[V];
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
    
    return (visited[V-1] == true);
}

long long find_max_flow(){
    long long max_flow = 0;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            residual[i][j] = graph[i][j];

    while (bfs()) {
        int path_flow = INT_MAX;
        int u = V-1;
        while (parent[u] != -1) {
            int v = parent[u];
            path_flow = min(path_flow, residual[v][u]);
            u = v;
        }

        u = V-1;
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

void print_graph(){
    for (int i = 0; i < V; i++) {
        cout << "node i: " << i << endl;
        for (auto x : adj[i])
            cout << x << ' ';
        cout << endl;
    }
}

void print_constraint() {
    for (int i = 1; i < 6; i++) {
        for (auto x : constraint[i]) 
            cout << "constraint" << i << ":" << x.first << ":" << x.second << endl;
    }
}


int main() {
    string s;
    cin >> s;
    cin >> s;
    generate_graph();

    find_max_flow();
    for (int i = n+1; i <= n+m; i++) {
        for (auto x : adj[i]) {
            if (x == V-1) 
                continue;
            if (residual[x][i] == 0) {
                ans[i-n] = constraint[x][i-n];
            }
        }
    }

    cout << "s SATISFIABLE\nv ";

    for (int i = 1; i <= m; i++) {
        cout << (ans[i]==0 ? i : i*ans[i]) << ' ';
    }
    cout << "0\n";

    return 0;
}
