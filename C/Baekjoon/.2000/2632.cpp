#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int M, N, K, res = 0, pizza_MAX = 2000000;
    cin >> K;
    cin >> M >> N;

    int A[M + 1], B[N + 1], sum_A[M * 2 + 1] = {0}, sum_B[N * 2 + 1] = {0}, sum_A_pizza[pizza_MAX + 1] = {0}, sum_B_pizza[pizza_MAX + 1] = {0};

    for (int i = 0 ; i < M ; i ++) {
        cin >> A[i];
    }
    for (int i = 0 ; i < M * 2 ; i ++) {
        sum_A[i + 1] = sum_A[i] + A[i % M];
    }

    for (int i = 0 ; i < N ; i ++) {
        cin >> B[i];
    }
    for (int i = 0 ; i < N * 2 ; i ++) {
        sum_B[i + 1] = sum_B[i] + B[i % N];
    }

    for (int i = 1 ; i <= M ; i ++) {
        for (int j = i ; j <= M * 2 ; j ++) {
            if (j - i >= M || (j - i == M - 1 && j >= M + 1))
                continue;

            sum_A_pizza[sum_A[j] - sum_A[i - 1]] += 1;
        }
    }

    for (int i = 1 ; i <= N ; i ++) {
        for (int j = i ; j <= N * 2 ; j ++) {
            if (j - i >= N || (j - i == N - 1 && j >= N + 1))
                continue;

            sum_B_pizza[sum_B[j] - sum_B[i - 1]] += 1;
        }
    }

    sum_A_pizza[0] = 1;
    sum_B_pizza[0] = 1;

    for (int i = 0 ; i <= K ; i ++) {
        res += sum_A_pizza[i] * sum_B_pizza[K - i];
    }

    cout << res;
}
