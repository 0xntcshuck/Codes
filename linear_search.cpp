#include <iostream>
using namespace std;
int main()
{
    int arr[30], search;
    int n, index = -1;

    cout << "Enter the number of the elements= ";
    cin >> n;

    cout << "Enter the elements= ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Your elements= \n";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]= " << arr[i] << endl;
    }

    cout << "Enter the number to search= ";
    cin >> search;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "The value is not found!" << endl;
    }
    else
    {
        cout << "Number " << search << " found at index " << index << "." << endl;
    }

    return 0;
}