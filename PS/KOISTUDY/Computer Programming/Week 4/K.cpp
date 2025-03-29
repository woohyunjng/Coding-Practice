#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &arr) {
    vector<int> st;
    int X;

    for (int i : arr) {
        X = i;
        while (!st.empty() && st.back() == X)
            X *= 2, st.pop_back();
        st.push_back(X);
    }

    return st;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A[4][4], T, X, Y, C;

    vector<int> arr;

    cin >> N;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> A[i][j];

    while (N--) {
        cin >> T >> X >> Y >> C, X--, Y--;
        if (T == 1 || T == 3) {
            for (int i = 0; i < 4; i++) {
                arr.clear();
                for (int j = 0; j < 4; j++) {
                    if (A[j][i] != 0)
                        arr.push_back(A[j][i]);
                    A[j][i] = 0;
                }
                if (T == 3)
                    reverse(arr.begin(), arr.end());
                arr = merge(arr);
                if (T == 1)
                    for (int j = 0; j < arr.size(); j++)
                        A[j][i] = arr[j];
                else
                    for (int j = 0; j < arr.size(); j++)
                        A[3 - j][i] = arr[j];
            }
        } else {
            for (int i = 0; i < 4; i++) {
                arr.clear();
                for (int j = 0; j < 4; j++) {
                    if (A[i][j] != 0)
                        arr.push_back(A[i][j]);
                    A[i][j] = 0;
                }
                if (T == 4)
                    reverse(arr.begin(), arr.end());
                arr = merge(arr);
                if (T == 2)
                    for (int j = 0; j < arr.size(); j++)
                        A[i][j] = arr[j];
                else
                    for (int j = 0; j < arr.size(); j++)
                        A[i][3 - j] = arr[j];
            }
        }
        A[X][Y] = C;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            cout << A[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}