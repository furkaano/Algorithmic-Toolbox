#include <iostream>

using namespace std;

// LAST DIGIT SUM OF THE FIBONACCI NUMBER (range)

long long last_digit_of_fibonacci(long long first, long long last);

int main() {
    long long first, last;
    cin >> first >> last;

    cout << last_digit_of_fibonacci(first, last);
    return 0;
}



long long last_digit_of_fibonacci(long long from, long long to)
{
    if (to <= 1)
        return to;

    long prev = 0;
    long cur = 1;
    long sum = from <= 1 ? 1 : 0;

    from = from % 60;
    to = to % 60;
    if(to < from){
        to += 60;
    }

    for (long i = 2; i <= to; i++) {
        long temp_prev = prev;
        prev = cur;
        cur = (cur + temp_prev) % 10;

        if (i >= from) {
            sum = (sum + cur) % 10;
        }

    }
    return sum;


    /*
    long long current = 0;
    long long next  = 1;
    long long sum = 0;
    
    long long from = first % 60; 
    long long to = last % 60;

 	if(from == 0 && to == 0)
 	    return 0;

    long long i = 0;
    while(i <= to + 1){
        if(i >= from)
            sum += current;

        long long temp = next;
        next = next + current;
        current = temp;
        ++i;
    }


    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= last; ++i) {
        if (i >= first) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
     */
}