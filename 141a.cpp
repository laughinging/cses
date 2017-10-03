#include<bits/stdc++.h>
using namespace std;

int a[10010];
int n, q;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = a[i-1] + x; 
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << a[y] - a[x-1] << endl;
    }
    
    return 0;
}
