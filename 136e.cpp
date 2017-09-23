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
vector<int> coins;
int coin[100010];
int total;
int cnt;

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
    comp[x] = cnt;
    total += coin[x];

    for (auto e : reverse_graph[x]) {
        if (!visited[e]) {
            reverse_dfs(e);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        reverse_graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    cout << "order of nodes: \n";
    for (int i = 0; i < n; i++)
        cout << order[i] << ' ';
    cout << endl;

    memset(visited, false, sizeof(visited));

    cnt = 0;
    for (int i = n-1; i >= 0; i--) {    
        if (!visited[order[i]]) {
            cout << "now start at: " << order[i] << endl;
            total = 0;
            parent = order[i];
            reverse_dfs(order[i]);
            coins.push_back(total);
            cout << total << endl;
            cout <<"-----" << endl;
            cnt ++;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << comp[i] << ' ';
    cout << endl;

    for (auto x:coins)
        cout << x << endl;


    return 0;
}
