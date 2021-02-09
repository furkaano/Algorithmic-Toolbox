#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

long long pairwise_Product_Fast(long long arr[], int size);
long long pairwise_Product_Slow(long long arr[], int size);

int main() {

    // STRESS TEST
    while(true) { // INFINITE LOOP
        int n = rand() % 4 + 2; // that was 10 + 2
        cout << n << "\n";

        long long arr[n];

        for (int i = 0; i < n; ++i)
            arr[i] = (long long)(rand() % 10); // that was 100000
        for (int j = 0; j < n; ++j)
            cout << arr[j] << " ";
        cout << "\n";

        long long result1 = pairwise_Product_Fast(arr, n);
        long long result2 = pairwise_Product_Slow(arr, n);

        if (result1 != result2) {
            cout << "WRONG ANSWER" << " -> " << "result 1 : " << result1 << " || " << "result 2 : " << result2<<"\n";
            break;
        } else
            cout << "TRUE ANSWER" << " -> " << "result 1 : " << result1 << " || " << "result 2 : " << result2 <<"\n";
    }

    /*
    int size;
    cin >> size;

    long long arr2[size];
    for (int i=0; i < size; ++i)
        cin >> arr2[i];
    cout << pairwise_Product_Fast(arr2, size);
    */

    /* // PRACTICAL SOLUTION
    //sort(arr, arr+size, greater<long long>());
    //long long result = (long long)(arr[0] * arr[1]);
    //cout << result;
     */

    return 0;
}

long long pairwise_Product_Fast(long long arr[], int size)
{
    if(size == 2)
        return (long long)((arr[0] * arr[1]));
    else if(size > 2){
        int maxIndex1 = -1;
        for (int i = 0; i < size; ++i)
            if ((maxIndex1 == -1) || arr[i] > arr[maxIndex1])
                maxIndex1 = i;

        int maxIndex2 = -1;
        for (int j = 0; j < size; ++j)
            if ((j != maxIndex1) && ((maxIndex2 == -1) || (arr[j] > arr[maxIndex2])))
                maxIndex2 = j;

        long long result = (long long)(arr[maxIndex1] * arr[maxIndex2]);
        return (long long)result;
    }
    else if(size == 1)
        return (long long)(arr[0]);
    else
        return (long long)NULL;
}

long long pairwise_Product_Slow(long long arr[], int size)
{
    long long result = 0;

    for(int i = 0; i < size; ++i)
        for(int j = i +1; j < size; ++j)
            if((long long)(arr[i] * arr[j]) > result)
                result = (long long)(arr[i] * arr[j]);

    return (long long)result;
}
