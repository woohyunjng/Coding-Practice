#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, 3, 2}, dy[4] = {2, 3, 0, 1};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, X, V = 1, H = 1;

    char C;
    vector<char> arr;

    vector<vector<int>> ans, tmp;

    cin >> K;
    for (int i = 0; i < K << 1; i++)
        cin >> C, arr.push_back(C);
    reverse(arr.begin(), arr.end());

    cin >> X;
    ans.resize(1, vector<int>(1, X));

    for (char i : arr) {
        tmp.clear(), tmp.resize(V, vector<int>(H, 0));

        for (int j = 0; j < V; j++)
            for (int k = 0; k < H; k++)
                tmp[j][k] = ((i == 'L' || i == 'R') ? dx[ans[j][H - 1 - k]] : dy[ans[V - 1 - j][k]]);

        if (i == 'L') {
            for (int j = 0; j < V; j++)
                ans[j].insert(ans[j].end(), tmp[j].begin(), tmp[j].end());
            H <<= 1;
        } else if (i == 'R') {
            for (int j = 0; j < V; j++)
                ans[j].insert(ans[j].begin(), tmp[j].begin(), tmp[j].end());
            H <<= 1;
        } else if (i == 'U')
            ans.insert(ans.end(), tmp.begin(), tmp.end()), V <<= 1;
        else
            ans.insert(ans.begin(), tmp.begin(), tmp.end()), V <<= 1;
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < H; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}