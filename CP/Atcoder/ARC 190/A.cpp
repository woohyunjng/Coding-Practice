#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 3> tp;

int L[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0, X = -1, L_max = -1, L_min = -1, R_max = -1, R_min = -1;
    bool flag = false;
    vector<tp> arr;
    vector<int> st;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> L[i] >> R[i];
        if (L[i] == 1 && R[i] == N)
            flag = true, res = i;
        arr.push_back({L[i], -R[i], i});

        if (L_max == -1 || L[L_max] < L[i])
            L_max = i;
        if (L_min == -1 || L[L_min] > L[i])
            L_min = i;
        if (R_max == -1 || R[R_max] < R[i])
            R_max = i;
        if (R_min == -1 || R[R_min] > R[i])
            R_min = i;
    }

    if (flag) {
        cout << 1 << '\n';
        for (int i = 1; i <= M; i++) {
            if (i == res)
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
        return 0;
    }

    if (L[L_max] > R[R_min]) {
        cout << 2 << '\n';
        for (int i = 1; i <= M; i++) {
            if (i == L_max || i == R_min)
                cout << 2 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
        return 0;
    }

    if (L[L_min] == 1 && R[R_max] == N) {
        cout << 2 << '\n';
        for (int i = 1; i <= M; i++) {
            if (i == L_min || i == R_max)
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
        return 0;
    }

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        while (!st.empty() && -i[1] > R[st.back()])
            st.pop_back();
        if (!st.empty()) {
            cout << 2 << '\n';
            for (int j = 1; j <= M; j++) {
                if (j == i[2])
                    cout << 2 << ' ';
                else if (j == st.back())
                    cout << 1 << ' ';
                else
                    cout << 0 << ' ';
            }
            cout << '\n';
            return 0;
        }
        st.push_back(i[2]);
    }

    if (M <= 2)
        cout << -1 << '\n';
    else {
        cout << 3 << '\n';
        for (int i = 1; i <= M; i++) {
            if (i == arr[0][2] || i == arr[2][2])
                cout << 2 << ' ';
            else if (i == arr[1][2])
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << '\n';
    }

    return 0;
}