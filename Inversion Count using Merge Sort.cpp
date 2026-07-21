#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int inv = 0;

    int temp[100];

    i = left;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];

            inv += (mid - i + 1);
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

    for (i = left, k = 0; i <= right; i++, k++)
    {
        arr[i] = temp[k];
    }

    return inv;
}

int mergeSort(int arr[], int left, int right)
{
    int inv = 0;

    if (left < right)
    {
        int mid = (left + right) / 2;

        inv += mergeSort(arr, left, mid);

        inv += mergeSort(arr, mid + 1, right);

        inv += merge(arr, left, mid, right);
    }

    return inv;
}

int main()
{
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Number of inversions: " << ans;

    return 0;
}