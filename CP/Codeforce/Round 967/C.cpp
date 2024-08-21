#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool checked[MAX];
int arr[MAX];

vector<pr> res;

void divide_and_conquer(int A, int B) {
    if (checked[B])
        return;
    int K;

    cout << "? " << A << " " << B << endl;
    cout.flush();
    cin >> K;

    if (K == A) {
        res.push_back({A, B});
        checked[B] = checked[A] = true;
        return;
    }

    if (checked[K])
        divide_and_conquer(K, B);
    else {
        divide_and_conquer(A, K);
        divide_and_conquer(K, B);
    }
}

signed main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;

        checked[1] = true;
        for (int i = 1; i <= N; i++)
            divide_and_conquer(1, i);

        cout << "! ";
        for (pr i : res)
            cout << i.first << " " << i.second << " ";
        cout.flush();

        for (int i = 1; i <= N; i++) {
            checked[i] = false;
            arr[i] = 0;
        }
        res.clear();
    }

    return 0;
}