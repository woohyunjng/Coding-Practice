#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 3000;

bool query(int X, int Y) {
    int res;
    cout << "? " << X << ' ' << Y << '\n', cout.flush();
    cin >> res;
    return res;
}

void answer(int X) { cout << "! " << X << '\n', cout.flush(); }

vector<int> child[MAX];
int parent[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, A, B, cnt = 0;
    vector<int> arr, tmp;

    cin >> N;
    while (N--) {
        cin >> X;
        for (int i = cnt + 1; i <= cnt + X; i++)
            arr.push_back(i);
        cnt += X;

        while (arr.size() > 1) {
            tmp = arr, arr.clear(), A = tmp.size();
            for (int i = 0; i + 1 < A; i += 2) {
                if (query(tmp[i], tmp[i + 1]))
                    arr.push_back(tmp[i + 1]), child[tmp[i + 1]].push_back(tmp[i]);
                else
                    arr.push_back(tmp[i]), child[tmp[i]].push_back(tmp[i + 1]);
            }
            if (A & 1)
                arr.push_back(tmp.back());
        }

        answer(arr[0]), X = arr[0], arr.pop_back();
        for (int i : child[X])
            arr.push_back(i);
    }

    return 0;
}