#include<iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    float profit[20], weight[20], ratio[20];

    cout << "Enter profit and weight:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> profit[i] >> weight[i];

        ratio[i] = profit[i] / weight[i];
    }

    // Sort by ratio
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                swap(ratio[i], ratio[j]);
                swap(profit[i], profit[j]);
                swap(weight[i], weight[j]);
            }
        }
    }

    float capacity;

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    float totalProfit = 0;

    for(int i = 0; i < n; i++)
    {
        if(weight[i] <= capacity)
        {
            totalProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    cout << "Maximum Profit = " << totalProfit;

    return 0;
}