#include <iostream>
using namespace std;
float *array_generator(int size)
{

    char *array = new char[size];
    cout << "Enter the elements of the array :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> array[i];
    }
    return array;
}

void display_array(char *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}