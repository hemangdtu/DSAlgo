#include<bits/stdc++.h>
using namespace std;

void swapping(int &a, int &b)
{
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void display(int *array, int size)
{
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

void bubbleSort(int *array, int size)
{
   for(int i = 0; i<size; i++)
   {
      int swaps = 0;
      for(int j = 0; j<size-i-1; j++)
      {
         if(array[j] > array[j+1])
         {
            swapping(array[j], array[j+1]);
            swaps = 1;
         }
      }
      if(!swaps)
         break;
   }
}

void bubbleSortOptimized(int* arr, int n)
{
   int i, j;
   bool swapped;
   for(i = 0; i<n; i++)
   {
      swapped = false;
      for(int j = 0; j<n-i-1; j++)
      {
         if(arr[j] > arr[j+1])
         {
            swapping(arr[j], arr[j+1]);
            swapped = true;
         }
      }
      if(swapped == false)
         break;
   }
}

int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n];

   cout << "Enter elements:" << endl;
   for(int i = 0; i<n; i++)
      cin >> arr[i];

   cout << "Array before Sorting: ";
   display(arr, n);

   bubbleSortOptimized(arr, n);
   // bubbleSort(arr, n);
   
   cout << "Array after Sorting: ";
   display(arr, n);

   return 0;
}