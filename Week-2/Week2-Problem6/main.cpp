#include <iostream>

using namespace std;
// FIND LAST DIGIT OF THE SUM OF THE FIBONACCI NUMBER

long long last_digit_of_fibonacci(long number);

int main() {
    long long number;
    cin >> number;
    cout << last_digit_of_fibonacci(number);
    return 0;
}

long long last_digit_of_fibonacci(long number)
{
    if (number <= 1)
        return number;
    /*
    long long previous = 0;
    long long current  = 1;
    long long sum = 1;

    long long i = 0;
    while(i < number){
        long long temp = previous;
        previous = current;
        current = temp + current;
        sum += current;
        ++i;
    }
    */
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    long long number1 = number % 60;
    if(number1 == 0)
        return 0;
    for (long long i = 0; i < number1 - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}