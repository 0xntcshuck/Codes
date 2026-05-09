#include <iostream>
using namespace std;
int main()
{
    int arr[30];
    int n;

    cout << "Enter the number of elements= ";
    cin >> n;

    cout << "Enter the elemens= ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Your Elements=\n ";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // Ascending Order
            // if(arr[j]<arr[j+1]) //Descending Order
            {
                // swap(arr[j],arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted Elements=\n ";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }
}