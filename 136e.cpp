#include<bits/stdc++.h>

using namespace std;
int m, n;
vector<int> graph[100010];
vector<int> reverse_graph[100010];
bool visited[100010];
int order[100010];
int comp[100010];
int t;
vector<long long> coins;
long long coin[100010];
long long total;
int cnt;
vector<int> new_graph[100010];
long long ans[100010];

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

    memset(visited, false, sizeof(visited));

    cnt = 0;
    for (int i = n-1; i >= 0; i--) {    
        if (!visited[order[i]]) {
            total = 0;
            reverse_dfs(order[i]);
            coins.push_back(total);
            cnt ++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto x : graph[i]) {
            if (comp[x] != comp[i])
                new_graph[comp[x]].push_back(comp[i]);
        }
    }

    for (int i = 0; i < cnt; i++) {
        long long mx = 0;
        for (auto x : new_graph[i]) 
            mx = max(ans[x], mx);
        ans[i] = coins[i] + mx;
    }
    
    long long mx = 0;
    for (int i = 0; i < cnt; i++)
        mx = max(ans[i], mx);
    cout << mx << endl;


    return 0;
}
