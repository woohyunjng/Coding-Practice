#include <bits/stdc++.h>
#define int long long
#define MAX 5010
#define MAX_SUM 800000
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];
pr sm[MAX_SUM];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int W, N;
    cin >> W >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[i] + arr[j] >= W)
                continue;
            sm[arr[i] + arr[j]] = {i, j};
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[i] + arr[j] >= W)
                continue;
            pr p = sm[W - arr[i] - arr[j]];
            if (p.first && p.first != i && p.first != j && p.second != i && p.second != j) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}