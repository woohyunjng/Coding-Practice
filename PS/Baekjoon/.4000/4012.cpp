#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> A_comp;
pr lectures[MAX];
int val[MAX], sparse[MAX][20];

int get_res(int S, int E) {
    int res = 0;

    S = lower_bound(A_comp.begin(), A_comp.end(), S) - A_comp.begin() + 1;

    for (int i = 19; i >= 0; i--) {
        if (sparse[S][i] != 0 && sparse[S][i] < E) {
            res += 1 << i;
            S = lower_bound(A_comp.begin(), A_comp.end(), sparse[S][i] + 1) - A_comp.begin() + 1;
        }
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<pr> arr;

    int N, A, B, M = 0, X = 0, Y;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        lectures[i] = {A, B};

        A_comp.push_back(A);
        arr.push_back({A, B});
    }

    sort(arr.begin(), arr.end());
    sort(A_comp.begin(), A_comp.end());
    A_comp.erase(unique(A_comp.begin(), A_comp.end()), A_comp.end());

    fill(val, val + A_comp.size() + 2, INF);

    for (int i = N; i >= 1; i--) {
        X = lower_bound(A_comp.begin(), A_comp.end(), arr[i - 1].first) - A_comp.begin() + 1;
        val[X] = min(val[X], arr[i - 1].second);
    }

    sparse[A_comp.size() + 1][0] = INF;
    for (int i = A_comp.size(); i >= 1; i--) {
        sparse[i][0] = min(sparse[i + 1][0], val[i]);
        for (int j = 1; j < 20; j++) {
            X = lower_bound(A_comp.begin(), A_comp.end(), sparse[i][j - 1] + 1) - A_comp.begin() + 1;
            sparse[i][j] = sparse[X][j - 1];
            if (!sparse[i][j])
                break;
        }
    }

    M = get_res(1, INF);
    cout << M << '\n';

    set<pr> st;
    set<pr>::iterator it;

    for (int i = 1; i <= N; i++) {
        tie(A, B) = lectures[i];
        it = st.lower_bound({A, 0});

        if (it == st.end())
            Y = INF;
        else {
            if (it->first <= B)
                continue;
            else
                Y = it->first;
        }

        if (it == st.begin())
            X = 1;
        else {
            it--;
            if (it->second >= A)
                continue;
            else
                X = it->second + 1;
        }

        if (get_res(X, A) + get_res(B + 1, Y) + 1 == get_res(X, Y)) {
            st.insert({A, B});
            cout << i << ' ';
        }
    }

    return 0;
}