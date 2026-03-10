#include <iostream>
using namespace std;

int medianOfThree(int arr[], int low, int high)
{
    int mid = (low + high) / 2;

    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);

    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);

    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);

    swap(arr[mid], arr[high]); // move median to end
    return arr[high];
}

int partition(int arr[], int low, int high)
{
    int pivot = medianOfThree(arr, low, high);
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}