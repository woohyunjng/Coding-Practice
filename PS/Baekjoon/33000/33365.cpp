#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;

    cin >> N;

    if (N % 2 == 1)
        cout << 1 + (N - 1) / 6 * 2 << ' ' << N << '\n';
    else
        cout << 2 + (N - 2) / 6 * 2 << ' ' << N << '\n';
}