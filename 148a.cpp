#include<bits/stdc++.h>
using namespace std;

const int INF = RAND_MAX;

int n_, n;
int a[100010];
int q;

int gcd(int x, int y){
    if (x == INF) return y;
    if (y == INF) return x;
    if (y == 0) return x;
    return gcd(y, x%y);
}


void init() {
    cin >> n;
    cin >> q;
    n_ = 1;
    while (n_ < n*2)
        n_ *= 2;

    for (int i = 0; i < n_; i++)
        a[i] = INF;

    for (int i = 0; i < n; i++)
        cin >> a[i + n_/2];

    for (int i = n_/2 - 1; i > 0; i--) {
        a[i] = gcd(a[i*2], a[i*2+1]);
    }
}

void update(int idx, int v) {
    idx += n_/2 - 1;
    a[idx] = v;

    idx /= 2;
    while (idx > 0) {
        a[idx] = gcd(a[idx*2], a[idx*2+1]); 
        idx /= 2;
    }
}

int query(int x, int y, int root, int l, int r, int ans) {
    if (r <= x || y <= l) return INF;
    if (x <= l || r <= y) return gcd(ans, a[root]);
    int vl = query(x, y, r*2, l, (l + r)/2, ans);
    int vr = query(x, y, r*2+1, l, (l + r)/2, ans);
    return gcd(vl, vr);
}

int main() {
    while (q--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c=='u')
            update(a, b);
        else
            cout << query(a, b, 1, 1, n_, INF) << endl;
    }

    return 0;
}
