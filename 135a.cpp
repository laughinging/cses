#include<bits/stdc++.h>

using namespace std;
int m, n;
vector<int> graph[100010];
vector<int> reverse_graph[100010];
bool visited[100010];
int finish[100010];
int order[100010];
int parent;
int t;
int subgraph[100010];

void dfs(int x) {
    if (visited[x]) return;
    visited[x] = true;
    subgraph[x] = parent;
    for (auto e : graph[x]){
        if (!visited[e]){
            dfs(e);
        }
    }
}

void reverse_dfs(int x) {
    if (visited[x]) return;
    visited[x] = true;
    for (auto e : reverse_graph[x]) {
        if (!visited[e]) {
            reverse_dfs(e);
        }
    }
    order[t] = x;
    finish[x] = t++;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        reverse_dfs(i);
    }

    memset(visited, false, sizeof(visited));
    int cnt = 0;

    for (int i = n-1; i >= 0; i--) {
        if (!visited[order[i]]) {
            parent = order[i];
            dfs(order[i]);
            cnt++;
        }
    }

    if (cnt == 1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (subgraph[i] != subgraph[j]) {
                    printf("%d %d\n", i, j);
                    return 0;
                }
            }
        }
    }

    return 0;
}
