#include <iostream>

using namespace std;

// FIND LAST DIGIT OF THE FIBONACCI
long long int last_digit_fibonacci(int number);

int main() {

    int number;
    cin >> number;

    cout << last_digit_fibonacci(number);
    return 0;
}

long long int last_digit_fibonacci(int number)
{
    if(number <= 1)
        return number;

    long long int previous = 0;
    long long int current = 1;

    long long int res;

    for (int i = 2; i <= number; i++) {
        res = (previous + current) % 10;
        previous = current;
        current = res;
    }

    return (long long int)(res);
}