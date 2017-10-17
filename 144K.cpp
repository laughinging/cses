#include<bits/stdc++.h>
using namespace std;

int T;
long long r, s, q;
long long x, y;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

// find x, y st. ax + by = gcd(a, b)
long long ext_euclid(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    long long x1, y1;
    long long g = ext_euclid(b,  a % b, &x1, &y1);

    *x = y1; 
    *y = x1 - (a / b) * y1;
    return g;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> r >> s >> q;
        long long g = ext_euclid(r, -s, &x, &y);
        x *= g;
        y *= -g;
        cout << x <<  ' ' << y << endl;
        while (x < 0 || y < 0) {
            x += r/g;
            y += s/g;
        }
        cout << x << " " << y << endl;
    }
    
    return 0;
}
