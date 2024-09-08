#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][2], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, L, res = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
        if (arr[i][0] > arr[i][1])
            swap(arr[i][0], arr[i][1]);
    }
    cin >> L;

    vector<int> comp;
    for (int i = 1; i <= N; i++) {
        if (arr[i][1] - arr[i][0] > L)
            continue;
        comp.push_back(arr[i][0]);
        comp.push_back(arr[i][1] - L);
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= N; i++) {
        if (arr[i][1] - arr[i][0] > L)
            continue;
        A = lower_bound(comp.begin(), comp.end(), arr[i][1] - L) - comp.begin();
        B = lower_bound(comp.begin(), comp.end(), arr[i][0]) - comp.begin();

        sm[A]++, sm[B + 1]--;
    }

    res = sm[0];
    for (int i = 1; i < comp.size(); i++) {
        sm[i] += sm[i - 1];
        res = max(res, sm[i]);
    }

    cout << res;

    return 0;
}