#include <bits/stdc++.h>
using namespace std;

const int MAX = 200;

string ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N + 2; i++) {
        for (int j = 0; j < N + 1 - i; j++)
            ans[i].push_back('.');
        for (int j = 0; j < i * 2 + 1; j++)
            ans[i].push_back('*');
        for (int j = 0; j < N + 1 - i; j++)
            ans[i].push_back('.');
    }

    for (int i = N + 2; i < N + 4; i++) {
        for (int j = 0; j < (N + 3) / 2; j++)
            ans[i].push_back('.');
        for (int j = 0; j < N; j++)
            ans[i].push_back('*');
        for (int j = 0; j < (N + 3) / 2; j++)
            ans[i].push_back('.');
    }

    for (int i = 0; i < N + 4; i++)
        cout << ans[i] << '\n';

    return 0;
}