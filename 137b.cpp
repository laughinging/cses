#include<bits/stdc++.h>
using namespace std;

int n;
vector<long long> a;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n-2; i++){
        if (a[i] + a[i+1] > a[i+2]) {
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}
