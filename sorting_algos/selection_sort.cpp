#include <iostream>
#include <bits/stdc++.h>
#include "take_input.h"
using namespace std;
int main()
{
    int size;
    cout << "Enter the number of elements u want to enter: ";
    cin >> size;
    float *a = array_generator(size);
    cout << "Sorting the array....\n";
    display_array(a, size);

    //sorting loop:

    for (int i = 0; i < size - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[j] < a[minimum])
            {
                minimum = j;
            }
        }
        if (minimum != i)
        {
            swap(a[minimum], a[i]);
        }
    }
    cout << "The sorted array is :" << endl;
    display_array(a, size);
    delete[] a;
    return 0;
}
