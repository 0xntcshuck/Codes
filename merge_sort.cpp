#include <iostream>
using namespace std;

int main()
{
    int arr[50], temp[50];
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Merge Sort Logic (without function)
    for (int size = 1; size < n; size = size * 2)
    {
        for (int left = 0; left < n - 1; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);

            int i = left;
            int j = mid + 1;
            int k = left;

            while (i <= mid && j <= right)
            {
                if (arr[i] <= arr[j])
                {
                    temp[k++] = arr[i++];
                }
                else
                {
                    temp[k++] = arr[j++];
                }
            }

            while (i <= mid)
            {
                temp[k++] = arr[i++];
            }

            while (j <= right)
            {
                temp[k++] = arr[j++];
            }

            for (int x = left; x <= right; x++)
            {
                arr[x] = temp[x];
            }
        }
    }

    cout << "\n\nSorted Array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
