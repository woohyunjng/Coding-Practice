#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 501;

vector<int> adj[MAX];
int D[MAX];

bool query(vector<int> arr) {
    string res;
    cout << "? " << arr.size() << ' ';
    for (int i : arr)
        cout << i << ' ';
    cout << '\n', cout.flush();
    cin >> res;
    return res == "YES";
}

void answer(int ans) { cout << "! " << ans << '\n', cout.flush(); }

signed main() {
    int N, U, V, ans;
    vector<int> arr, qarr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    for (int i = 1; i < N; i++)
        cin >> U >> V, D[U]++, D[V]++;
    sort(arr.begin(), arr.end(), [&](int x, int y) { return D[x] < D[y]; });

    for (int st = 0, en = N - 1, md; st <= en;) {
        md = (st + en + 1) >> 1, qarr.clear();
        for (int i = 0; i <= md; i++)
            qarr.push_back(arr[i]);
        if (md == 0 ? query({arr[0], arr[2]}) : query(qarr))
            en = md - 1, ans = md;
        else
            st = md + 1;
    }

    answer(arr[ans]);

    return 0;
}