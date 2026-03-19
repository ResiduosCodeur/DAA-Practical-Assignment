#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// ---------------- Sorting Algorithms ----------------

void selectionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int> &a, int l, int m, int r)
{
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
        a[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    while (i < left.size())
        a[k++] = left[i++];
    while (j < right.size())
        a[k++] = right[j++];
}
void mergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

// Heap Sort
void heapify(vector<int> &a, int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// Radix Sort
void countingSort(vector<int> &a, int exp)
{
    int n = a.size();
    vector<int> output(n);
    int count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    a = output;
}
void radixSort(vector<int> &a)
{
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(a, exp);
}

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

// 3. Median of three
int medianOfThree(vector<int> &a, int low, int high)
{
    int mid = (low + high) / 2;

    // Order low, mid, high
    if (a[low] > a[mid]) swap(a[low], a[mid]);
    if (a[low] > a[high]) swap(a[low], a[high]);
    if (a[mid] > a[high]) swap(a[mid], a[high]);

    // Now: a[low] <= a[mid] <= a[high]
    return mid;
}

void quickSort3(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = medianOfThree(a, low, high);
        int pi = partition(a, low, high, pivotIndex);
        quickSort3(a, low, pi - 1);
        quickSort3(a, pi + 1, high);
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
    int choice;

    cout << "Enter the type of input you like to give.\n";
    cout << "1.Random\n2.Increasing\n3.Decreasing\n";
    cin >> choice;

    if (choice == 1)
        s = "random";
    else if (choice == 2)
        s = "increasing";
    else if (choice == 3)
        s = "decreasing";
    else
    {
        cout << "Invalid choice!\n";
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

        cout << "n = " << n << endl;

        cout << "Selection: "
             << measure(selectionSort, a) << " us\n";

        cout << "Bubble: "
             << measure(bubbleSort, a) << " us\n";

        cout << "Insertion: "
             << measure(insertionSort, a) << " us\n";

        cout << "Merge: "
             << measure([](vector<int> &v)
                        { mergeSort(v, 0, v.size() - 1); }, a)
             << " us\n";

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

        cout << "Heap: "
             << measure(heapSort, a) << " us\n";

        cout << "Radix: "
             << measure(radixSort, a) << " us\n";

        cout << endl;
    }

    file.close();
    return 0;
}