#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N <= 2 || N == 12)
        cout << "winter";
    else if (N <= 5)
        cout << "spring";
    else if (N <= 8)
        cout << "summer";
    else
        cout << "fall";
}