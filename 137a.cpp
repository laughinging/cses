#include<bits/stdc++.h>
using namespace std;

int n, k, a[200010];
priority_queue<pair<long long, int> > pq;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);

    int u = 0;
    int ans;
    pq.push(make_pair(-a[0], 0));
    while (u++ < k) {
        ans = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if (idx == n-1) continue;
        pq.push(make_pair(ans+a[idx]-a[idx+1], idx+1));
        pq.push(make_pair(ans-a[idx+1], idx+1));
    }
    cout << -ans << endl;
    return 0;
}
