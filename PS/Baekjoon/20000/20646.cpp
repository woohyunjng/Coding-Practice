#include <bits/stdc++.h>
#define int long long

#define MAX 210
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr P[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, cnt = 0, D, l, r, X, Y, A, B, C;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i].first >> P[i].second;

    res = N + 1;

    for (int x = 0; x < 2; x++) {
        for (int i = 1; i <= N; i++)
            swap(P[i].first, P[i].second);

        sort(P + 1, P + N + 1);
        P[0].first = -1;

        for (int i = 1; i <= N; i++) {
            if (P[i].first == P[i - 1].first)
                continue;

            arr.clear();

            for (int j = i + 1; j <= N; j++) {
                if (i < j - 1)
                    arr.push_back(P[j - 1].second);
                D = P[j].first - P[i].first;
                X = max(P[i].second, P[j].second) - D, Y = min(P[i].second, P[j].second);
                if (X > Y)
                    continue;

                sort(arr.begin(), arr.end());
                l = 0, r = -1;

                while (l < arr.size() && arr[l] < X)
                    l++;
                while (r + 1 < arr.size() && arr[r + 1] - D <= X)
                    r++;

                while (true) {
                    res++;
                    A = Y, B = X + D;
                    if (l <= r)
                        A = min(A, arr[l]), B = max(B, arr[r]);
                    cnt += B - A == D;

                    A = l < arr.size() ? arr[l] + 1 : INF;
                    B = r + 1 < arr.size() ? arr[r + 1] - D : INF;
                    C = min(A, B);

                    if (C > Y)
                        break;
                    l += A == C, r += B == C;
                }
            }
        }
    }

    cout << res - cnt / 2 << '\n';

    return 0;
}