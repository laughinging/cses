#include<bits/stdc++.h>

using namespace std;

bool w[26][26];
string x, y;
int a[1000020];
int b[1000020];

bool check(){
    int xl = (int) x.length();
    int yl = (int) y.length();
    if (xl != yl) 
        return false;
    for (int i = 0; i < 26; i++) {
        int u[26] = {};
        int c = 0;
        int d = 0;
        a[c++] = -1;
        b[d++] = -1;
        for (int j = 0; j < xl; j++) {
            if (x[j]-'a' == i)
                a[c++] = j;
            if (y[j]-'a' == i)
                b[d++] = j;
        } 
        if (c != d)
            return false;
        a[c++] = xl;
        b[d++] = xl;

        for (int j = 0; j < c-1; j++) {
            for (int k = a[j] + 1; k < a[j+1]; k++) {
                u[x[k]-'a']++;
            }
            for (int k = b[j] + 1; k < b[j+1]; k++) {
                u[y[k]-'a']--;
            }
            for (int k = 0; k < 26; k++) {
                if (w[i][k] && u[k] != 0) 
                    return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        char a, b;
        cin >> a >> b;
        w[a-'a'][b-'a'] = true;
        w[b-'a'][a-'a'] = true;
    }
    cin >> x >> y;
    cout << (check() ? "YES":"NO") << endl;
    return 0;
}
