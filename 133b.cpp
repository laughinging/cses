#include<bits/stdc++.h>

using namespace std;
bool graph[2010][2010];
int a, b, c, d;

void draw(){
    if (a > c){
        swap(a, c);
        swap(b, d);
    }
    int width = c - a;
    int height = abs(d - b);
    int y = b;
    for (int i = a; i <= c; i++) {
        if (b < d) {
        }
    }
}

int main() {
    int n;
    while (n--) {
        cin >> a >> b >> c >> d;
    }

    return 0;
}
