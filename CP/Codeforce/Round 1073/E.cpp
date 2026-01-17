#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int query(int X, int Y) {
    int res;
    cout << "? " << X << ' ' << Y << '\n', cout.flush();
    cin >> res;
    return res;
}

void answer(vector<int> &arr) {
    cout << "! ";
    if (arr.empty())
        cout << -1 << '\n', cout.flush();
    else {
        for (int i : arr)
            cout << i << ' ';
        cout << '\n', cout.flush();
    }
}

void solve() {
    int N, X = -1, Y = -1;
    vector<int> ans, arr, val, st;

    cin >> N;
    for (int i = 1; i <= N; i++)
        ans.push_back(i);

    for (int i = N; i - 1 >= 1; i--) {
        if (query(i - 1, i))
            continue;
        X = i;
        break;
    }

    for (int i = X - 1; i - 1 >= 1; i--) {
        if (query(i - 1, i) == 0)
            continue;
        Y = i - 1;
        break;
    }
    if (X == -1 || Y == -1) {
        ans.clear(), answer(ans);
        return;
    }

    for (int i = X; i > Y; i--)
        arr.push_back(i);
    for (int i = N; i > X; i--)
        val.push_back(i);
    reverse(arr.begin(), arr.end());

    st.push_back(X), arr.pop_back();
    while (!arr.empty()) {
        if (val.empty())
            st.push_back(arr.back()), arr.pop_back();
        else if (query(arr.back(), val.back()))
            st.push_back(arr.back()), arr.pop_back();
        else
            st.push_back(val.back()), val.pop_back();
    }
    arr = st, st.clear();

    for (int i = 0; i < arr.size(); i++) {
        if (query(Y, arr[i]) == 0)
            continue;
        ans[Y - 1] = arr[i], arr[i] = Y;
        break;
    }
    for (int i = 0; i < arr.size(); i++)
        ans[Y + i] = arr[i];
    answer(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}