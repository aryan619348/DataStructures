#include <iostream>
#include <bits/stdc++.h>
#include "take_input.h"
using namespace std;
int create_partition(float *array, int lower_limit, int upper_limit);
void quicksort(float *array, int lower_limit, int upper_limit);
int main()
{
    int size;
    cout << "Enter the number of elements u want to enter: ";
    cin >> size;
    float *a = array_generator(size);
    cout << "Sorting the array....\n";
    display_array(a, size);
    quicksort(a, 0, size - 1);
    cout << "The sorted array is :" << endl;
    display_array(a, size);
    delete[] a;
    return 0;
}
int create_partition(float *array, int lower_limit, int upper_limit)
{
    float pivot = array[lower_limit];
    int start = lower_limit;
    int end = upper_limit;
    while (start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(array[start], array[end]);
        }
    }
    swap(array[lower_limit], array[end]);
    return end;
}
void quicksort(float *array, int lower_limit, int upper_limit)
{
    if (lower_limit < upper_limit)
    {
        int location = create_partition(array, lower_limit, upper_limit);
        quicksort(array, lower_limit, location - 1);
        quicksort(array, location + 1, upper_limit);
    }
}