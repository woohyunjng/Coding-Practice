#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr arr[MAX];
int parent[MAX], mx[MAX], sm[MAX];
bool cycle[MAX];

int find(int A) {
    if (parent[A] == A)
        return A;
    return parent[A] = find(parent[A]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, res = 0;
    vector<int> comp;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i].first >> arr[i].second;
        res += arr[i].first + arr[i].second;
        comp.push_back(arr[i].first);
        comp.push_back(arr[i].second);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 0; i < comp.size(); i++) {
        parent[i] = i;
        mx[i] = sm[i] = comp[i];
    }

    for (int i = 1; i <= N; i++) {
        X = lower_bound(comp.begin(), comp.end(), arr[i].first) - comp.begin();
        Y = lower_bound(comp.begin(), comp.end(), arr[i].second) - comp.begin();

        if (find(X) == find(Y))
            cycle[find(X)] = true;
        else {
            X = find(X), Y = find(Y);
            parent[X] = Y;
            mx[Y] = max(mx[Y], mx[X]);
            sm[Y] = sm[Y] + sm[X];
            cycle[Y] |= cycle[X];
        }
    }

    for (int i = 0; i < comp.size(); i++) {
        if (i != find(i))
            continue;
        res -= sm[i];
        if (!cycle[i])
            res += mx[i];
    }

    cout << res;

    return 0;
}