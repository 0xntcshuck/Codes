#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

    int n;
    int arr[20], target;

    cout << "Enter the number of elements= ";
    cin >> n;

    cout << "Enter your elements= ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n); //  for ascending order
                        // sort(arr,arr+n,greater<int>()); // for desending order
    cout << "Sorted elements= ";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }

    cout << "Enter the elements to search= ";
    cin >> target;

    int first = 0, last = n - 1, mid;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (target > arr[mid])
        {
            first = mid + 1;
        }

        else if (target < arr[mid])
        {
            last = mid - 1;
        }
        else if (target == arr[mid])
        {
            cout << "Element found at index= " << mid << endl;
            return 0;
        }
    }

    cout << "elements not found!" << endl;
}