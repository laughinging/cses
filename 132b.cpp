#include<bits/stdc++.h>

using namespace std;

int constraint[10010][3];
int forward_match[10010];
int index_of_variable[10010];
int backward_match[100010];
bool visited[100010];
int ans[100010];

bool find(int x){
    for (int i = 0; i < 3; i++) {
        int u = abs(constraint[x][i]);
        if (!visited[u]){
            visited[u] = true;
            if (backward_match[u] == -1 || (find(backward_match[u]))) {
                forward_match[x] = u;
                backward_match[u] = x;
                index_of_variable[x] = i;
                return true;
            }
        }
    }
    return false;
}


int main() {
    int n, m;
    string s;
    cin >> s;
    cin >> s;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++){
            cin >> constraint[i][j];
        }
        int zero;
        cin >> zero;
    }
    for (int i = 0; i < m; i++)
        forward_match[i] = -1;
    for (int i = 1; i <= n; i++)
        backward_match[i] = -1;

    int match = 0;
    for (int i = 0; i < m; i++) {
        memset(visited, false, sizeof(visited));
        if (find(i)) match++;
    }
    assert(match == m);

    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u = constraint[i][index_of_variable[i]];
        if (u < 0) {
            ans[abs(u)] *= -1;
        }
    }

    cout << "s SATISFIABLE\nv ";

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << 0 << endl;
    return 0;
}
