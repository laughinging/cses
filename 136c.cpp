#include<bits/stdc++.h>

using namespace std;
int m, n;
vector<int> graph[1000010];
vector<int> reverse_graph[1000010];
bool visited[1000010];
int order[1000010];
int parent;
int comp[1000010];
int t;
int assign[1000010];

void dfs(int x) {
    visited[x] = true;
    for (auto e : graph[x]){
        if (!visited[e]){
            dfs(e);
        }
    }
    order[t++] = x;
}

int reverse_index(int x) {
    return (x % 2 == 0 ? x-1 : x+1);
}

void reverse_dfs(int x) {
    visited[x] = true;
    comp[x] = parent;
    if (assign[x] == 0) {
        assign[x] = -1;
        assign[reverse_index(x)] = 1;
    }

    for (auto e : reverse_graph[x]) {
        if (!visited[e]) {
            reverse_dfs(e);
        }
    }
}

int node_index(int x) {
    return (x > 0 ? 2*x : -2*x-1);
}

int main() {
    string str;
    cin >> str;
    cin >> str;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        int zero;
        cin >> a >> b;
        cin >> zero;
        if (a == -b) {
            cout << "s UNSATISFIABLE" << endl;
            return 0;
        }
        graph[node_index(-a)].push_back(node_index(b));
        reverse_graph[node_index(b)].push_back(node_index(-a));
        graph[node_index(-b)].push_back(node_index(a));
        reverse_graph[node_index(a)].push_back(node_index(-b));
    }

    for (int i = 1; i <= 2*n; i++) {
        if (!visited[i]) dfs(i);
    }

    memset(visited, false, sizeof(visited));
    int cnt = 0;

    for (int i = 2*n-1; i >= 0; i--) {
        if (!visited[order[i]]) {
            cnt ++;
            parent = order[i];
            reverse_dfs(order[i]);
        }
    }

    for (int i = 1; i <= n; i++) 
        if (comp[node_index(i)] == comp[node_index(-i)]){
            cout << "s UNSATISFIABLE" << endl;
            return 0;
        }

    cout << "s SATISFIABLE\nv ";

    for (int i = 1; i <= n; i++) {
        cout << i * assign[i * 2] << ' ';
    }
    cout << 0 << endl;


    return 0;
}
