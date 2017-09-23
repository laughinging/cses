#include<bits/stdc++.h>

using namespace std;
int m, n;
vector<int> graph[100010];
vector<int> reverse_graph[100010];
bool visited[100010];
int order[100010];
int parent;
int t;

void dfs(int x) {
    visited[x] = true;
    for (auto e : graph[x]){
        if (!visited[e]){
            dfs(e);
        }
    }
    order[t++] = x;
}

void reverse_dfs(int x) {
    visited[x] = true;
    for (auto e : reverse_graph[x]) {
        if (!visited[e]) {
            reverse_dfs(e);
        }
    }
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
        if (!visited[i]) dfs(i);
    }

    memset(visited, false, sizeof(visited));
    int cnt = 0;

    for (int i = n-1; i >= 0; i--) {
        if (!visited[order[i]]) {
            cnt ++;
            parent = order[i];
            reverse_dfs(order[i]);
            if (cnt > 1) {
                cout << "NO" << endl;
                cout << parent << ' ' << order[n-1] << endl; 
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}
