#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int* createarr(int len)
{
    int* arr = new int[len];
    return arr;
}
int checklength(int *arr)
{
    int length = _msize(arr) / sizeof(int);
    return length;
}
void putin(int *arr)
{
    int length = checklength(arr); int buf = 0;
    for (int i = 0; i < length; i++)
    {
        cin >> buf; arr[i] = buf;
    }
}
void putout(int* arr)
{
    int length = checklength(arr);
    for (int i = 0; i < length; ++i)
        cout << arr[i] << " ";
}
int *resize(int *arr)
{
    int oldlen = checklength(arr);
    int newlen; cout << "new length:"; cin >> newlen;
        int* newarr = new int[newlen];  
        for (int i = 0; i < newlen; ++i)
            newarr[i] = arr[i];
    delete[] arr;         
    //cout << checklength(newarr);
    return newarr;
}
void changeitem(int*& arr, int index)
{
    int buf; cout << ":"; cin >> buf;
    arr[index] = buf;
}
int *delitem(int* arr, int index)
{
    int oldlen = checklength(arr); int trick = 0;
    int* newarr = new int[oldlen-1];
    for (int i = 0; i < oldlen; ++i)
        if (i != index) { newarr[i-trick] = arr[i]; }
        else { trick++; }
    delete[] arr;
    return newarr;
}
void deletearr(int *&arr)
{
    delete[] arr;
}
int* insertitem(int* arr, int index)
{
    int oldlen = checklength(arr); int trick = 0; int buf = 0;
    cout << ":"; cin >> buf;
    int* newarr = new int[oldlen + 1];
    for (int i = 0; i < oldlen+1; ++i)
        if (i != index) { newarr[i] = arr[i-trick]; }
        else { newarr[i] = buf; trick++; }
    delete[] arr;
    return newarr;
}
int main()
{
    int* array = createarr(4);

    //cout << checklength(array);
    putin(array);
    //changeitem(array, 1);
   // putout(array);
    //array = resize(array);
    //array = delitem(array, 0);
    array = insertitem(array, 0);
    putout(array);
   
}