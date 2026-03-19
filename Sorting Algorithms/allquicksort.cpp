#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// ---------------- QuickSort Variants ----------------

int partition(vector<int> &a, int low, int high, int pivotIndex)
{
    swap(a[pivotIndex], a[high]);
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// 1. First element pivot
void quickSort1(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high, low);
        quickSort1(a, low, pi - 1);
        quickSort1(a, pi + 1, high);
    }
}

// 2. Random pivot
void quickSort2(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = low + rand() % (high - low + 1);
        int pi = partition(a, low, high, pivotIndex);
        quickSort2(a, low, pi - 1);
        quickSort2(a, pi + 1, high);
    }
}
int comparisons=0;
int medianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[low], arr[mid]);
    if (arr[high] < arr[low]) swap(arr[low], arr[high]);
    if (arr[high] < arr[mid]) swap(arr[mid], arr[high]);
    // median is now at mid
    swap(arr[low], arr[mid]);
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (true) {
        while (i <= high && arr[i] <= pivot) { ++comparisons; ++i; }
        if (i > high) ++comparisons;
        while (j > low && arr[j] > pivot) { ++comparisons; --j; }
        if (j > low) ++comparisons;
        if (i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[low], arr[j]);
    return j;
}


void quickSort3(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = medianOfThree(arr, low, high);
        quickSort3(arr, low, pi - 1);
        quickSort3(arr, pi + 1, high);
    }
}

// Measure time
long long measure(function<void(vector<int>&)> func, vector<int> a)
{
    int repeat = 10;
    auto start = high_resolution_clock::now();

    for (int i = 0; i < repeat; i++)
    {
        vector<int> temp = a;   // fresh copy every time
        func(temp);
    }

    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count() / repeat;
}

// ---------------- MAIN ----------------

int main()
{
    srand(time(0));

    string s;
    int i;

    cout << "Enter the type of input you like to give.\n";
    cout << "1.Random\n2.Increasing\n3.Decreasing\n";
    cin >> i;

    if (i == 1)
        s = "random";
    else if (i == 2)
        s = "increasing";
    else if (i == 3)
        s = "decreasing";
    else
    {
        cout << "Invalid choice.\n";
        return 0;
    }

    string path = "../Test Cases/" + s + ".txt";
    ifstream file(path);

    if (!file)
    {
        cout << "File not opened!\n";
        return 0;
    }

    int t;
    file >> t;

    while (t--)
    {
        int n;
        file >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            file >> a[i];

        vector<int> b;
        cout << "n = " << n << endl;
        cout << "Quick (first): "
             << measure([](vector<int> &v)
                        { quickSort1(v, 0, v.size() - 1); }, a)
             << " us\n";

        cout << "Quick (random): "
             << measure([](vector<int> &v)
                        { quickSort2(v, 0, v.size() - 1); }, a)
             << " us\n";

        cout << "Quick (median): "
             << measure([](vector<int> &v)
                        { quickSort3(v, 0, v.size() - 1); }, a)
             << " us\n";

    }
}