#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    for (char i : S)
        cout << '\'' << i << '\'' << '\n';
}