#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int T[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> arr;
    int N;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> T[i] >> S[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) {
        int xv = T[x] * S[y], yv = T[y] * S[x];
        if (xv != yv)
            return xv < yv;
        return x < y;
    });

    for (int i : arr)
        cout << i << ' ';
    cout << '\n';

    return 0;
}