#include<bits/stdc++.h>

using namespace std;

int n;
queue<int> q;
int order[20];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);
    int k = 1;
    while (!q.empty()){
        for (int i = 0; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        order[q.front()] = k++;
        q.pop();
    }
    cout << order[1];
    for (int i = 2; i <= n; i++) {
        cout << " " << order[i];
    }
    cout << endl;
    return 0;
}
