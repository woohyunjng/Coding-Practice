#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;

int val[MAX], A[MAX][MAX];

int get(int X, int Y) {
    for (int i = 0; i < 14; i++)
        if ((X & (1 << i)) && !(Y & (1 << i)))
            return i;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0;
    string S;

    for (int i = 0; i < (1 << 14); i++) {
        if (__builtin_popcount(i) != 7)
            continue;
        val[X++] = i;
    }

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> S;
        for (int j = 0; j < i; j++) {
            if (S[j] == '1')
                cout << (char)('a' + get(val[i], val[j]));
            else
                cout << (char)('a' + get(val[j], val[i]));
        }
        cout << '\n';
    }

    return 0;
}