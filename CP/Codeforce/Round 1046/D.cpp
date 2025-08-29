#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100000;

int query(vector<int> &v) {
    cout << "? " << (int)v.size() << ' ';
    for (int i : v)
        cout << i << ' ';
    cout << '\n', cout.flush();

    int res;
    cin >> res;
    return res;
}

void answer(int W) { cout << "! " << W << '\n', cout.flush(); }

void solve() {
    vector<int> arr;

    for (int i = 1; i <= MAX; i++)
        arr.push_back(1);
    int X = query(arr), L, R;

    if (X == 1) {
        answer(MAX);
        return;
    } else if (X == MAX) {
        answer(1);
        return;
    }

    L = (MAX + X - 1) / X,
    R = (MAX - 1) / (X - 1);

    if (L == R) {
        answer(L);
        return;
    }

    arr.clear();
    for (int i = L + 1; i <= R; i++)
        arr.push_back(L), arr.push_back(i - L);

    answer(2 * R - L - query(arr)), arr.clear();
}

signed main() {
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}