#include <iostream>

using namespace std;
// FIND LAST DIGIT OF THE FIBONACCI NUMBER

int fib(long long num );

int main() {
    long long number = 0;
    cin >> number;

    int a = fib(number);
    int b = fib(number + 1);

    cout<< (a * b) % 10;

    return 0;
}

int fib(long long num){
    int pre=0,cur=1;
    num = num %60;
    if(num==0){
        return 0;}
    else if (num == 1){
        return 1;
    }
    else{
        for (int i =2; i<=num; i++){
            int temp = (pre+cur)%60;
            pre = cur;
            cur = temp;
        }
    }

    return(cur);
}