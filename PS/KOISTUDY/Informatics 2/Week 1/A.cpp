#include <bits/stdc++.h>
#define int long long

#define MAX 51000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Vote {
    int A, B, index;
};

bool compare_A(Vote a, Vote b) { return a.A > b.A; }
bool compare_B(Vote a, Vote b) { return a.B > b.B; }

Vote arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].A >> arr[i].B;
        arr[i].index = i;
    }
    sort(arr + 1, arr + N + 1, compare_A);
    sort(arr + 1, arr + K + 1, compare_B);

    cout << arr[1].index;

    return 0;
}