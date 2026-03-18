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

// 3. Median of three
int medianOfThree(vector<int> &a, int low, int high)
{
    int mid = (low + high) / 2;
    vector<pair<int, int>> v = {{a[low], low}, {a[mid], mid}, {a[high], high}};
    sort(v.begin(), v.end());
    return v[1].second;
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
long long measure(function<void()> func)
{
    int repeat = 10;
    auto start = high_resolution_clock::now();
    for(int i = 0; i < repeat; i++)
        func();
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count() / repeat;
}

// ---------------- MAIN ----------------

int main()
{
    srand(time(0));
    string s;
    int i;
    cout<<"Enter the type of input you live to give.Type the row number\n1.Random\n2.Increasing\n3.Decreasing\n";
    cin>>i;
    if (i==1)
    {
        s="random";
    }else if (i==2)
    {
        s="increasing";
    }else if (i==3)
    {
        s="decreasing";
    }else
    {
        cout<<"Invalid choice of type."<<endl;
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
        vector<int> b = a;

        cout << "n=" << n << endl;

        b = a;
        cout << "Quick (first): " << measure([&]()
                                             { quickSort1(b, 0, n - 1); })
            << " us\n";

        b = a;
        cout << "Quick (random): " << measure([&]()
                                              { quickSort2(b, 0, n - 1); })
            << " us\n";

        b = a;
        cout << "Quick (median): " << measure([&]()
                                              { quickSort3(b, 0, n - 1); })
            << " us\n";
        cout<<endl;
    }
}