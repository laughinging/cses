#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    int n = (int) s.length();
    vector<int> z(n);
    int x = 0;
    int y = 0;
    for (int i = 1; i < n; i++){
        z[i] = max(0, min(z[i-x], y-x+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]){
            x = i;
            y = i + z[i];
            z[i] ++;
        }
    }
    cout << (*max_element(z.begin(), z.end())) << endl;

    return 0;
}
