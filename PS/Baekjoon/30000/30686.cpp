#include <bits/stdc++.h>
#define int long long
#define MAX 1010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int D[MAX], cur[MAX];
vector<int> need[MAX], vec;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, A, val, res = LLONG_MAX;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> D[i];

    for (int i = 1; i <= M; i++) {
        vec.push_back(i);
        cin >> K;

        while (K--) {
            cin >> A;
            need[i].push_back(A);
        }
    }

    do {
        val = 0;
        fill(cur, cur + N + 1, -10);
        for (int i = 1; i <= M; i++) {
            for (int j : need[vec[i - 1]]) {
                if (i - cur[j] >= D[j]) {
                    cur[j] = i;
                    val++;
                }
            }
        }
        res = min(res, val);
    } while (next_permutation(vec.begin(), vec.end()));

    cout << res;

    return 0;
}