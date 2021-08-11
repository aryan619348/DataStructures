#include <iostream>
#include "take_input.h"
using namespace std;

void merge_sort(float *array, int lower_limit, int upper_limit);
void merge(float *array, int lower_limit, int mid, int upper_limit);
int main()
{
    int size;
    cout << "Enter the number of elements u want to enter: ";
    cin >> size;
    float *a = array_generator(size);
    cout << "Sorting the array....\n";
    display_array(a, size);
    merge_sort(a, 0, size - 1);
    cout << "The sorted array is :" << endl;
    display_array(a, size);
    delete[] a;
    return 0;
}
void merge_sort(float *array, int lower_limit, int upper_limit)
{
    if (lower_limit < upper_limit)
    {
        int mid = (upper_limit + lower_limit) / 2;
        merge_sort(array, lower_limit, mid);
        merge_sort(array, mid + 1, upper_limit);
        merge(array, lower_limit, mid, upper_limit);
    }
}
void merge(float *array, int lower_limit, int mid, int upper_limit)
{
    int temp[upper_limit + 1];
    int i = lower_limit;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= upper_limit)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= upper_limit)
        temp[k++] = array[j++];
    k--;
    while (k >= 0)
    {
        array[k + lower_limit] = temp[k];
        k--;
    }
}