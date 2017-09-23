#include<bits/stdc++.h>
using namespace std;

vector<char> s;

bool isPalindrome(vector<char> x) {
    int l = 0;
    int r = (int) x.size() - 1;
    while (l < r) {
        if (x[l] != x[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    char c;
    scanf("%c", &c);
    while (c != '\n') {
        if ('a' <= c && c <= 'z')
            s.push_back(c);
        if ('A' <= c && c <= 'Z')
            s.push_back(c + 'a' - 'A');
        scanf("%c", &c);
    }

    cout << (isPalindrome(s) ? "YES" : "NO") << endl;
    return 0;
}
