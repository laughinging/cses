#include<bits/stdc++.h>
using namespace std;

const long long P = 1e9+7;

long long x, y, n;
long long ans[2][2];


void mul(long long a[2][2], long long b[2][2], long long r[2][2]) {
    long long s[2][2] = {};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                s[i][j] += a[i][k] * b[k][j] % P;
            }
            s[i][j] %= P;
        }
    }
    memcpy(r, s, sizeof(s));
}

void fast_exp(long long a[2][2], long long e, long long r[2][2]) {
    long long k[2][2] = {};
    long long s[2][2] = {};
    
    for (int i = 0; i < 2; i++) 
        s[i][i] = 1;

    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 2; j++) 
            k[i][j] = a[i][j];

    while (e) {
        if (e & 1) 
            mul(s, k, s);
        mul(k, k, k);
        e >>= 1;
    }
    memcpy(r, s, sizeof(s));
}


int main() {
    cin >> x >> y >> n;
    long long mat[2][2] = {{0,1}, {1,1}};
    fast_exp(mat, n-1, ans);
    cout << (x * ans[0][0] % P + ans[0][1] * y % P) % P << endl;
    return 0;
}
