#include <bits/stdc++.h>
#define int long long

#define MAX 5100
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res = 1, val = 0;
    vector<pr> srt;

    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        srt.push_back({arr[i], i});
    }
    sort(srt.begin(), srt.end());

    for (pr i : srt) {
        val = 1;

        for (int j = i.second - 1; arr[j] + i.first <= X && j >= 1; j--) {
            if (arr[j] < arr[i.second] || (arr[j] == arr[i.second] && j < i.second))
                continue;
            val++;
        }

        for (int j = i.second + 1; arr[j] + i.first <= X && j <= N; j++) {
            if (arr[j] < arr[i.second] || (arr[j] == arr[i.second] && j < i.second))
                continue;
            val++;
        }

        res = res * val % MOD;
    }

    cout << res;

    return 0;
}