#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 10000; i >= 1; i /= 10)
    {
        cout << '[' << i * (N / i) << "]\n";
        N %= i;
    }
}