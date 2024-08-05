#include <bits/stdc++.h>
#define int long long
#define MAX 200100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], found[MAX], L[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, cur, res = 0, lst;
    bool check;
    cin >> T;

    while (T--) {
        cin >> N;
        fill(found, found + N + 1, 0);

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            found[arr[i]] = i;
        }

        check = true;
        for (int i = 1; i <= N; i++)
            check = check && (found[i] == i);
        if (check)
            res = 0;

        else {
            if (arr[1] == N && arr[N] == 1)
                res = 3;
            else if (arr[1] == 1 || arr[N] == N)
                res = 1;
            else if (arr[1] == N || arr[N] == 1)
                res = 2;
            else {
                res = 2;

                priority_queue<int> pq_f;
                priority_queue<int, vector<int>, greater<int>> pq_s;

                for (int i = 1; i <= N; i++) {
                    pq_f.push(arr[i]);
                    L[i] = (pq_f.top() == i);
                }

                for (int i = N; i >= 1; i--) {
                    pq_s.push(arr[i]);
                    R[i] = pq_s.top() == i;
                }

                for (int i = 2; i < N; i++) {
                    if (L[i - 1] && R[i + 1])
                        res = 1;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}