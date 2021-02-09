#include <iostream>

using namespace std;

//FIND GREATEST COMMON DIVISOR

int find_gcd(int number1, int number2);

int main() {
    int number1, number2;
    cin >> number1 >> number2;

    cout << find_gcd(number1, number2);
    return 0;
}

int find_gcd(int number1, int number2)
{
    int remainder;
    while((number1 % number2) > 0){
        remainder = number1 % number2;
        number1 = number2;
        number2 = remainder;
    }
    return number2;
}