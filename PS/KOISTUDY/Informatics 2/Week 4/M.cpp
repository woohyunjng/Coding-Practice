#include <bits/stdc++.h>
#define MAX 8

using namespace std;

char arr[MAX][MAX];
int pw[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, cnt = 0;
    string S, K, A, B;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++)
            arr[i][j] = S[j];
    }

    cin >> M;
    cin >> S;

    pw[0] = 1;
    for (int i = 1; i <= M; i++)
        pw[i] = pw[i - 1] * N;

    for (int i = 0; i < M - 1; i++)
        K += arr[S[i] - 'A'][S[i + 1] - 'A'];

    cout << K;

    for (int i = 0; i < pw[M]; i++) {
        B = "", X = i;
        for (int j = 0; j < M; j++) {
            B += 'A' + X % N;
            X /= N;
        }

        reverse(B.begin(), B.end());

        A = "";
        for (int i = 0; i < M - 1; i++)
            A += arr[B[i] - 'A'][B[i + 1] - 'A'];

        if (A == K)
            cnt++;
        if (B == S) {
            cout << cnt;
            break;
        }
    }

    return 0;
}