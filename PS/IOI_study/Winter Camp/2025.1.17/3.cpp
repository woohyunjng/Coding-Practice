#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool checked[MAX];

int CCW(tp A, tp B, tp C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<tp> arr, upper;

    tp K;

    int T, N, A, B;
    cin >> T;

    while (T--) {
        cin >> N;
        arr.clear();
        upper.clear();

        fill(checked, checked + N, false);

        for (int i = 0; i < N; i++) {
            cin >> A >> B;
            arr.push_back({A, B, i});
        }
        sort(arr.begin(), arr.end());

        for (tp i : arr) {
            while (upper.size() >= 2 && CCW(upper[upper.size() - 2], upper[upper.size() - 1], i) > 0) {
                K = upper.back(), upper.pop_back();
                checked[K[2]] = false;
            }
            upper.push_back(i);
            checked[i[2]] = true;
        }

        for (tp i : upper)
            cout << i[2] << ' ';

        reverse(arr.begin(), arr.end());
        for (tp i : arr) {
            if (checked[i[2]])
                continue;
            cout << i[2] << ' ';
        }
        cout << '\n';
    }

    return 0;
}