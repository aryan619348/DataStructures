#include <iostream>
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
        float temp;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "The sorted array is :" << endl;
    display_array(a, size);
    delete[] a;
    return 0;
}
