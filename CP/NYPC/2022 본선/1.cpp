#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int N, M, K, mx = -1;
    cin >> N >> M >> K;

    long long int A[N], B[M], sumA[N + 1], sumB[M + 1];
    for (int i = 0 ; i < N ; i ++) {
        cin >> A[i];
    }
    for (int i = 0 ; i < M ; i ++) {
        cin >> B[i];
    }

    sort(A, A + N);
    sort(B, B + M);
    sumA[0] = 0;
    sumB[0] = 0;

    for (int i = N - 1 ; i >= 0 ; i --) {
        if (i == N - 1) {
            sumA[1] = A[i];
        } else {
            sumA[N - i] = A[i] + sumA[N - 1 - i];
        }
    }

    for (int i = M - 1 ; i >= 0 ; i --) {
        if (i == M - 1) {
            sumB[1] = B[i];
        } else {
            sumB[M - i] = B[i] + sumB[M - 1 - i];
        }
    }

    long long int i, j;
    for (i = 0 ; i <= (int)(K / N) ; i ++) {
        j = max((long long int)((K - N * i) / (M - i)), 0);
        mx = max(mx, sumA[j] + sumB[i]);
    }

    cout << mx;
}
