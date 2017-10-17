#include<bits/stdc++.h>

#define N 500010

using namespace std;

int n;
int cnt[N];
int p[N];
long long ans;

int low_bit(int x){
    return x&(-x);
}

void insert(int c[], int x, long long v) {
    while (x <= n) {
        c[x] += v;
        x += low_bit(x);
    }
}

int get_sum(int c[], int x) {
    int s = 0;
    while (x) {
        s += c[x];
        x -= low_bit(x);
    }
    return x;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(cnt, x, 1);
        ans += get_sum(p, N) - get_sum(p, x);
        insert(p, x, get_sum(cnt, n) - get_sum(cnt, x));
    }
    cout << ans << endl;


    
    return 0;
}
