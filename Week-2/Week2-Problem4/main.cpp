#include <iostream>

using namespace std;

//FINDING LEAST COMMON MULTIPLE

long long gcd(long long int a, long long int b);
long long lcm(long long a,long long b);

int main() {
    int number1, number2;
    cin >> number1 >> number2;

    cout<< lcm(number1,number2);
    return 0;
}

long long gcd(long long int number1, long long int number2){
    if(number2 == 0)
        return number1;
    return gcd(number2 , number1 % number2);
}

long long lcm(long long number1, long long number2){
    if(number1 > number2)
        return (number1 / gcd(number1,number2)) * number2;
    else
        return (number2 / gcd(number1,number2)) * number1;
}