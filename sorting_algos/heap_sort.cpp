#include <iostream>
#include <bits/stdc++.h>
#include "take_input.h"
using namespace std;
void max_heapify(float *array, int n, int i);
void heap_sort(float *arrray, int n);
int main()
{
    int size;
    cout << "Enter the number of elements u want to enter: ";
    cin >> size;
    float *a = array_generator(size);
    cout << "Sorting the array....\n";
    display_array(a, size);
    heap_sort(a, size);
    cout << "The sorted array is :" << endl;
    display_array(a, size);
    delete[] a;
    return 0;
}
void max_heapify(float *array, int n, int i)
{
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    while (l < n && array[l] > array[largest])
    {
        largest = l;
    }
    while (r < n && array[r] > array[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(array[i], array[largest]);
        max_heapify(array, n, largest);
    }
}
void heap_sort(float *array, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        max_heapify(array, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        max_heapify(array, i, 0);
    }
}