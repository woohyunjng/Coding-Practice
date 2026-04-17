#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int A[MAX];
bool chk[MAX];
map<int, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans, S = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], cnt[A[i]]++;
        arr.push_back(A[i]);
    }

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
    X = arr.size();

    S = arr[0] * cnt[arr[0]];
    for (int i = 1; i < X - 1; i++) {
        S += arr[i] * cnt[arr[i]];
        if (S > arr[i + 1])
            chk[i] = true;
    }
    chk[X - 1] = true, ans = 1'000'000'000'000;

    if (X > 1)
        ans = min(ans, arr[X - 1]);

    for (int i = X - 2; i > 0; i--) {
        chk[i] &= chk[i + 1];
        if (chk[i])
            ans = min(ans, arr[i]);
    }

    for (int i = 1; i <= N; i++)
        cout << (A[i] >= ans ? "T" : "N");
    cout << '\n';
}