#include <bits/stdc++.h>
#define int long long

#define MAX 1024
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX];

string divide_and_conquer(int A, int B, int C, int D) {
    int one_count = 0, zero_count = 0;
    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            if (arr[i][j] == 1)
                one_count++;
            else
                zero_count++;
        }
    }

    if (!one_count)
        return "0";
    else if (!zero_count)
        return "1";
    else {
        string top_left, top_right, bottom_left, bottom_right;
        top_left = divide_and_conquer(A, B, (A + C) / 2, (B + D) / 2);
        top_right = divide_and_conquer(A, (B + D) / 2 + 1, (A + C) / 2, D);
        bottom_left = divide_and_conquer((A + C) / 2 + 1, B, C, (B + D) / 2);
        bottom_right = divide_and_conquer((A + C) / 2 + 1, (B + D) / 2 + 1, C, D);
        return "(" + top_left + top_right + bottom_left + bottom_right + ")";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++)
            arr[i][j] = S[j - 1] - '0';
    }

    cout << divide_and_conquer(1, 1, N, N);

    return 0;
}