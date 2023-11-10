#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long A, R, N;
    cin >> A >> R >> N;
    cout << A * (long long)pow(R, N - 1);
}