#include <iostream>

using namespace std;

// FIND LAST FIBONACCI NUMBER AND TAKE ITS MOD AS USING INDEX

long long fibonacci_naive(long long number1, long long number2);

int main() {
    long long number1, number2;
    cin >> number1 >> number2;
    cout << fibonacci_naive(number1, number2);
}

long long fibonacci_naive(long long number1, long long number2) {
    if (number1 <= 1)
        return number1;

    long long previous = 0;
    long long current  = 1;

    number1 = number1 % 60;
    number2 = number2 % 60;

    if(number2 < number1){
        number2 += 60;
    }
    long long i = 0;
    while(i < number1 + 1){
        long long temp = previous;
        previous = current;
        current = temp + current;
        ++i;
    }

    return current % number2;
}