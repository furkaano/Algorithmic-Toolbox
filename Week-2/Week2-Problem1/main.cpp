#include <iostream>

using namespace std;

// THIS IS FOR CALCULATING OF FIBONACCI NUMBER
long fibonacci(int number);

int main() {

    int number;
    cin >> number;

    cout << fibonacci(number);

    return 0;
}

long fibonacci(int number)
{
    if(number <= 1)
        return number;

    int arr[number];
    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i < number + 1; ++i)
        arr[i] = arr[i-1] + arr[i-2];

    return arr[number];
}