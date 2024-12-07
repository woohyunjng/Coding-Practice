#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dis(int A, int B, int C, int D) { return abs(A - C) + abs(B - D); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, D, res = 0, N, cur;
    string S;
    vector<pr> arr;

    cin >> H >> W >> D;

    for (int i = 1; i <= H; i++) {
        cin >> S;
        for (int j = 1; j <= W; j++)
            if (S[j - 1] == '.')
                arr.push_back({i, j});
    }

    N = arr.size();
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            cur = 0;
            for (pr k : arr)
                cur += dis(arr[i].first, arr[i].second, k.first, k.second) <= D || dis(arr[j].first, arr[j].second, k.first, k.second) <= D;
            res = max(res, cur);
        }

    cout << res << '\n';

    return 0;
}