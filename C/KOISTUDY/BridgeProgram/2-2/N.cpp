#include <iostream>
using namespace std;

int main()
{
    long long A, M, D, N;
    cin >> A >> M >> D >> N;
    for (int i = 0; i < N - 1; i++)
        A = A * M + D;
    cout << A;
}