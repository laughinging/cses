#include<bits/stdc++.h>

using namespace std;

int n, a, b;
void print_double(int x, string s) {
    assert(x % 2== 0);
    for (int i = 0; i < x/2; i++)
        cout << s;
}

bool even(int x) {
    return x % 2 == 0;
}

int main() {
    cin >> n >> a >> b;
    if (!even(n) || !even(b-a+1)){
        cout << "QAQ" << endl;
        return 0;
    }

    if (even(a)) {
        cout << "(";
        print_double(a-2, "()");
        print_double(b-a+1, "[]");
        print_double(n-b-1, "()");
        cout << ")";
    } else {
        print_double(a-1, "()");
        print_double(b-a+1, "[]");
        print_double(n-b, "()");
    }
    cout << endl;
    return 0;
}
