#include<bits/stdc++.h>
using namespace std;

int n;
map<string, vector<string>> m;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s, ss;
        cin >> s;
        ss = s;
        sort(ss.begin(), ss.end());
        m[ss].push_back(s);
    }

    int groups = 0;
    for (auto it = m.begin(); it != m.end(); it++)
        if (it->second.size() > 1) groups++;

    cout << groups << endl;
    for (auto it = m.begin(); it!= m.end(); it++) {
        if (it->second.size() == 1) continue;
        cout << it->second.size() << endl;
        for (auto itt = it->second.begin(); itt != it->second.end(); itt++)
            cout << *itt << endl;
    }
    return 0;
}
