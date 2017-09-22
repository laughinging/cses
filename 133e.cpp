#include<bits/stdc++.h>

using namespace std;

string x;

bool apple_win(){
    int l = (int) x.length();
    if (x[0] == 'C')
        return x[l-1] == 'B';
    if (x[l-1] == 'C')
        return x[0] == 'B';
    if (x[0] == x[l-1])
        return x[0] == 'B';

    queue<char> a, b;
    int c = (int) x.find('C') - 1;
    for (int i = c-1; i >= 0; i--)
        a.push(x[i]);
    for (int i = c+1; i < l; i++)
        b.push(x[i]);
    if (x[0] != 'A')
        swap(a, b);

    bool apple = true;
    while (!a.empty() && !b.empty()) {
        if (a.empty()) return true;
        if (b.empty()) return false;
        if (apple) {
            if (!a.empty() && a.front() == 'A'){
                a.pop();
            } else if (!b.empty() && b.front() == 'A'){
                b.pop();
            } 
        } else {
            if (!b.empty() && b.front() == 'B') {
                b.pop();
            } else if (!a.empty() && a.front() == 'B') {
                a.pop();
            }
        }
        apple = !apple;
    }
    return !apple;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        cin >> x;
        cout << (apple_win() ? "Uolevi" : "Maija") << endl;
    }

    return 0;
}
