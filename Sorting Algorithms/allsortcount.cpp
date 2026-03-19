// #include <bits/stdc++.h>
// using namespace std;
// using namespace chrono;

// // ---------------- Comparison Counters ----------------
// long long comp_selection, comp_bubble, comp_insertion;
// long long comp_merge, comp_quick1, comp_quick2, comp_quick3;
// long long comp_heap, comp_radix;

// // ---------------- Sorting Algorithms ----------------

// void selectionSort(vector<int> &a) {
//     int n = a.size();
//     for (int i = 0; i < n - 1; i++) {
//         int minIdx = i;
//         for (int j = i + 1; j < n; j++) {
//             comp_selection++;
//             if (a[j] < a[minIdx])
//                 minIdx = j;
//         }
//         swap(a[i], a[minIdx]);
//     }
// }

// void bubbleSort(vector<int> &a) {
//     int n = a.size();
//     for (int i = 0; i < n - 1; i++)
//         for (int j = 0; j < n - i - 1; j++) {
//             comp_bubble++;
//             if (a[j] > a[j + 1])
//                 swap(a[j], a[j + 1]);
//         }
// }

// void insertionSort(vector<int> &a) {
//     int n = a.size();
//     for (int i = 1; i < n; i++) {
//         int key = a[i], j = i - 1;
//         while (j >= 0) {
//             comp_insertion++;
//             if (a[j] > key) {
//                 a[j + 1] = a[j];
//                 j--;
//             } else break;
//         }
//         a[j + 1] = key;
//     }
// }

// // Merge Sort
// void merge(vector<int> &a, int l, int m, int r) {
//     vector<int> left(a.begin() + l, a.begin() + m + 1);
//     vector<int> right(a.begin() + m + 1, a.begin() + r + 1);

//     int i = 0, j = 0, k = l;
//     while (i < left.size() && j < right.size()) {
//         comp_merge++;
//         if (left[i] < right[j])
//             a[k++] = left[i++];
//         else
//             a[k++] = right[j++];
//     }
//     while (i < left.size()) a[k++] = left[i++];
//     while (j < right.size()) a[k++] = right[j++];
// }

// void mergeSort(vector<int> &a, int l, int r) {
//     if (l >= r) return;
//     int m = (l + r) / 2;
//     mergeSort(a, l, m);
//     mergeSort(a, m + 1, r);
//     merge(a, l, m, r);
// }

// // Heap Sort
// void heapify(vector<int> &a, int n, int i) {
//     int largest = i, l = 2 * i + 1, r = 2 * i + 2;

//     if (l < n) {
//         comp_heap++;
//         if (a[l] > a[largest]) largest = l;
//     }

//     if (r < n) {
//         comp_heap++;
//         if (a[r] > a[largest]) largest = r;
//     }

//     if (largest != i) {
//         swap(a[i], a[largest]);
//         heapify(a, n, largest);
//     }
// }

// void heapSort(vector<int> &a) {
//     int n = a.size();
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(a, n, i);
//     for (int i = n - 1; i > 0; i--) {
//         swap(a[0], a[i]);
//         heapify(a, i, 0);
//     }
// }

// // Radix Sort (no comparisons in classic sense)
// void countingSort(vector<int> &a, int exp) {
//     int n = a.size();
//     vector<int> output(n);
//     int count[10] = {0};

//     for (int i = 0; i < n; i++)
//         count[(a[i] / exp) % 10]++;

//     for (int i = 1; i < 10; i++)
//         count[i] += count[i - 1];

//     for (int i = n - 1; i >= 0; i--) {
//         output[count[(a[i] / exp) % 10] - 1] = a[i];
//         count[(a[i] / exp) % 10]--;
//     }
//     a = output;
// }

// void radixSort(vector<int> &a) {
//     int mx = *max_element(a.begin(), a.end());
//     for (int exp = 1; mx / exp > 0; exp *= 10)
//         countingSort(a, exp);
// }

// // ---------------- QuickSort Variants ----------------

// int partition(vector<int> &a, int low, int high, int pivotIndex, long long &comp) {
//     swap(a[pivotIndex], a[high]);
//     int pivot = a[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         comp++;
//         if (a[j] < pivot) {
//             i++;
//             swap(a[i], a[j]);
//         }
//     }
//     swap(a[i + 1], a[high]);
//     return i + 1;
// }

// void quickSort1(vector<int> &a, int low, int high) {
//     if (low < high) {
//         int pi = partition(a, low, high, low, comp_quick1);
//         quickSort1(a, low, pi - 1);
//         quickSort1(a, pi + 1, high);
//     }
// }

// void quickSort2(vector<int> &a, int low, int high) {
//     if (low < high) {
//         int pivotIndex = low + rand() % (high - low + 1);
//         int pi = partition(a, low, high, pivotIndex, comp_quick2);
//         quickSort2(a, low, pi - 1);
//         quickSort2(a, pi + 1, high);
//     }
// }

// int medianOfThree(vector<int> &a, int low, int high)
// {
//     int mid = (low + high) / 2;

//     // Order low, mid, high
//     if (a[low] > a[mid]) swap(a[low], a[mid]);
//     if (a[low] > a[high]) swap(a[low], a[high]);
//     if (a[mid] > a[high]) swap(a[mid], a[high]);

//     // Now: a[low] <= a[mid] <= a[high]
//     return mid;
// }

// void quickSort3(vector<int> &a, int low, int high) {
//     if (low < high) {
//         int pivotIndex = medianOfThree(a, low, high);
//         int pi = partition(a, low, high, pivotIndex, comp_quick3);
//         quickSort3(a, low, pi - 1);
//         quickSort3(a, pi + 1, high);
//     }
// }

// // ---------------- Timing ----------------

// long long measure(function<void(vector<int>&)> func,
//                   vector<int> &orig,
//                   long long &comp)
// {
//     int repeat = 10;
//     long long total_time = 0;
//     long long total_comp = 0;

//     for (int i = 0; i < repeat; i++) {
//         vector<int> temp = orig;

//         long long local_comp = 0;

//         // temporarily redirect global counter
//         long long *old = &comp;
//         comp = 0;

//         auto start = high_resolution_clock::now();
//         func(temp);
//         auto end = high_resolution_clock::now();

//         total_time += duration_cast<microseconds>(end - start).count();
//         total_comp += comp;
//     }

//     comp = total_comp / repeat;
//     return total_time / repeat;
// }
// // ---------------- MAIN ----------------

// int main() {
//     srand(time(0));

//     int choice;
//     cout << "1.Random\n2.Increasing\n3.Decreasing\n";
//     cin >> choice;

//     string s;
//     if (choice == 1) s = "random";
//     else if (choice == 2) s = "increasing";
//     else if (choice == 3) s = "decreasing";
//     else return 0;

//     ifstream file("../Test Cases/" + s + ".txt");

//     if (!file) {
//         cout << "File not opened!\n";
//         return 0;
//     }

//     int t;
//     file >> t;

//     while (t--) {
//         int n;
//         file >> n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++) file >> a[i];

//         cout << "\nn = " << n << endl;

//         vector<int> b;

//       // Selection
// cout << "Selection: "
//      << measure(selectionSort, a, comp_selection)
//      << " us, Comparisons: " << comp_selection << endl;

// // Bubble
// cout << "Bubble: "
//      << measure(bubbleSort, a, comp_bubble)
//      << " us, Comparisons: " << comp_bubble << endl;

// // Insertion
// cout << "Insertion: "
//      << measure(insertionSort, a, comp_insertion)
//      << " us, Comparisons: " << comp_insertion << endl;

// // Merge
// cout << "Merge: "
//      << measure([&](vector<int>& v){ mergeSort(v,0,v.size()-1); }, a, comp_merge)
//      << " us, Comparisons: " << comp_merge << endl;

// // Quick1
// cout << "Quick(first): "
//      << measure([&](vector<int>& v){ quickSort1(v,0,v.size()-1); }, a, comp_quick1)
//      << " us, Comparisons: " << comp_quick1 << endl;

// // Quick2
// cout << "Quick(random): "
//      << measure([&](vector<int>& v){ quickSort2(v,0,v.size()-1); }, a, comp_quick2)
//      << " us, Comparisons: " << comp_quick2 << endl;

// // Quick3
// cout << "Quick(median): "
//      << measure([&](vector<int>& v){ quickSort3(v,0,v.size()-1); }, a, comp_quick3)
//      << " us, Comparisons: " << comp_quick3 << endl;

// // Heap
// cout << "Heap: "
//      << measure(heapSort, a, comp_heap)
//      << " us, Comparisons: " << comp_heap << endl;

// // Radix
// cout << "Radix: "
//      << measure(radixSort, a, comp_radix)
//      << " us (no comparisons)" << endl;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// using namespace chrono;

// // ---------------- Sorting Algorithms ----------------

// void selectionSort(vector<int> &a, long long &comp) {
//     int n = a.size();
//     for (int i = 0; i < n - 1; i++) {
//         int minIdx = i;
//         for (int j = i + 1; j < n; j++) {
//             comp++;
//             if (a[j] < a[minIdx])
//                 minIdx = j;
//         }
//         swap(a[i], a[minIdx]);
//     }
// }

// void bubbleSort(vector<int> &a, long long &comp) {
//     int n = a.size();
//     for (int i = 0; i < n - 1; i++)
//         for (int j = 0; j < n - i - 1; j++) {
//             comp++;
//             if (a[j] > a[j + 1])
//                 swap(a[j], a[j + 1]);
//         }
// }

// void insertionSort(vector<int> &a, long long &comp) {
//     int n = a.size();
//     for (int i = 1; i < n; i++) {
//         int key = a[i], j = i - 1;
//         while (j >= 0) {
//             comp++;
//             if (a[j] > key) {
//                 a[j + 1] = a[j];
//                 j--;
//             } else break;
//         }
//         a[j + 1] = key;
//     }
// }

// // Merge Sort
// void merge(vector<int> &a, int l, int m, int r, long long &comp) {
//     vector<int> L(a.begin() + l, a.begin() + m + 1);
//     vector<int> R(a.begin() + m + 1, a.begin() + r + 1);

//     int i = 0, j = 0, k = l;
//     while (i < L.size() && j < R.size()) {
//         comp++;
//         if (L[i] < R[j])
//             a[k++] = L[i++];
//         else
//             a[k++] = R[j++];
//     }
//     while (i < L.size()) a[k++] = L[i++];
//     while (j < R.size()) a[k++] = R[j++];
// }

// void mergeSort(vector<int> &a, int l, int r, long long &comp) {
//     if (l >= r) return;
//     int m = (l + r) / 2;
//     mergeSort(a, l, m, comp);
//     mergeSort(a, m + 1, r, comp);
//     merge(a, l, m, r, comp);
// }

// // Heap Sort
// void heapify(vector<int> &a, int n, int i, long long &comp) {
//     int largest = i, l = 2*i+1, r = 2*i+2;

//     if (l < n) {
//         comp++;
//         if (a[l] > a[largest]) largest = l;
//     }

//     if (r < n) {
//         comp++;
//         if (a[r] > a[largest]) largest = r;
//     }

//     if (largest != i) {
//         swap(a[i], a[largest]);
//         heapify(a, n, largest, comp);
//     }
// }

// void heapSort(vector<int> &a, long long &comp) {
//     int n = a.size();
//     for (int i = n/2 - 1; i >= 0; i--)
//         heapify(a, n, i, comp);
//     for (int i = n - 1; i > 0; i--) {
//         swap(a[0], a[i]);
//         heapify(a, i, 0, comp);
//     }
// }

// // Radix Sort
// void countingSort(vector<int> &a, int exp) {
//     int n = a.size();
//     vector<int> output(n);
//     int count[10] = {0};

//     for (int i = 0; i < n; i++)
//         count[(a[i] / exp) % 10]++;

//     for (int i = 1; i < 10; i++)
//         count[i] += count[i - 1];

//     for (int i = n - 1; i >= 0; i--) {
//         output[count[(a[i] / exp) % 10] - 1] = a[i];
//         count[(a[i] / exp) % 10]--;
//     }
//     a = output;
// }

// void radixSort(vector<int> &a, long long &comp) {
//     comp = 0;  // prevent garbage
//     int mx = *max_element(a.begin(), a.end());
//     for (int exp = 1; mx / exp > 0; exp *= 10)
//         countingSort(a, exp);
// }

// // ---------------- QuickSort ----------------

// int partition(vector<int> &a, int low, int high, int pivotIndex, long long &comp) {
//     swap(a[pivotIndex], a[high]);
//     int pivot = a[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         comp++;
//         if (a[j] < pivot) {
//             i++;
//             swap(a[i], a[j]);
//         }
//     }
//     swap(a[i+1], a[high]);
//     return i+1;
// }

// void quickSort1(vector<int> &a, int l, int r, long long &comp) {
//     if (l < r) {
//         int pi = partition(a, l, r, l, comp);
//         quickSort1(a, l, pi-1, comp);
//         quickSort1(a, pi+1, r, comp);
//     }
// }

// void quickSort2(vector<int> &a, int l, int r, long long &comp) {
//     if (l < r) {
//         int p = l + rand() % (r - l + 1);
//         int pi = partition(a, l, r, p, comp);
//         quickSort2(a, l, pi-1, comp);
//         quickSort2(a, pi+1, r, comp);
//     }
// }

// int medianOfThree(vector<int> &a, int l, int r) {
//     int m = (l + r) / 2;
//     if (a[l] > a[m]) swap(a[l], a[m]);
//     if (a[l] > a[r]) swap(a[l], a[r]);
//     if (a[m] > a[r]) swap(a[m], a[r]);
//     return m;
// }

// void quickSort3(vector<int> &a, int l, int r, long long &comp) {
//     if (l < r) {
//         int p = medianOfThree(a, l, r);
//         int pi = partition(a, l, r, p, comp);
//         quickSort3(a, l, pi-1, comp);
//         quickSort3(a, pi+1, r, comp);
//     }
// }

// // ---------------- Measure ----------------

// template <typename Func>
// long long measure(Func func, vector<int> &orig, long long &comp)
// {
//     int repeat = 10;
//     long long total_time = 0;
//     long long total_comp = 0;

//     for (int i = 0; i < repeat; i++) {
//         vector<int> temp = orig;

//         volatile long long local_comp = 0;  //  KEY FIX
//         asm volatile("" ::: "memory");
//         auto start = high_resolution_clock::now();
//         func(temp, (long long&)local_comp);
//         auto end = high_resolution_clock::now();

//         total_time += duration_cast<microseconds>(end - start).count();
//         total_comp += local_comp;
//     }

//     comp = total_comp / repeat;
//     return total_time / repeat;
// }
// // ---------------- MAIN ----------------

// int main() {
//     srand(time(0));

//     int choice;
//     cout << "1.Random\n2.Increasing\n3.Decreasing\n";
//     cin >> choice;

//     string s;
//     if (choice == 1) s = "random";
//     else if (choice == 2) s = "increasing";
//     else if (choice == 3) s = "decreasing";
//     else return 0;

//     ifstream file("../Test Cases/" + s + ".txt");

//     if (!file) {
//         cout << "File not opened!\n";
//         return 0;
//     }

//     int t;
//     file >> t;

//     while (t--) {
//         int n;
//         file >> n;

//         vector<int> a(n);
//         for (int i = 0; i < n; i++) file >> a[i];

//         cout << "\nn = " << n << endl;

// long long c1, c2, c3, c4, c5, c6, c7, c8;

// // Selection
// cout << "Selection: "
//      << measure(selectionSort, a, c1)
//      << " us, Comparisons: " << c1 << endl;

// // Bubble
// cout << "Bubble: "
//      << measure(bubbleSort, a, c2)
//      << " us, Comparisons: " << c2 << endl;

// // Insertion
// cout << "Insertion: "
//      << measure(insertionSort, a, c3)
//      << " us, Comparisons: " << c3 << endl;

// // Merge
// cout << "Merge: "
//      << measure([](vector<int>& v, long long& c){
//             mergeSort(v,0,v.size()-1,c);
//         }, a, c4)
//      << " us, Comparisons: " << c4 << endl;

// // Quick first
// cout << "Quick(first): "
//      << measure([](vector<int>& v, long long& c){
//             quickSort1(v,0,v.size()-1,c);
//         }, a, c5)
//      << " us, Comparisons: " << c5 << endl;

// // Quick random
// cout << "Quick(random): "
//      << measure([](vector<int>& v, long long& c){
//             quickSort2(v,0,v.size()-1,c);
//         }, a, c6)
//      << " us, Comparisons: " << c6 << endl;

// // Quick median
// cout << "Quick(median): "
//      << measure([](vector<int>& v, long long& c){
//             quickSort3(v,0,v.size()-1,c);
//         }, a, c7)
//      << " us, Comparisons: " << c7 << endl;

// // Heap
// cout << "Heap: "
//      << measure(heapSort, a, c8)
//      << " us, Comparisons: " << c8 << endl;

// // Radix
// long long dummy = 0;
// cout << "Radix: "
//      << measure(radixSort, a, dummy)
//      << " us (no comparisons)" << endl;
//     }
// }


#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

// ---------------- Sorting Algorithms ----------------

void selectionSort(vector<int> &a, long long &comp) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            comp++;
            if (a[j] < a[minIdx])
                minIdx = j;
        }
        swap(a[i], a[minIdx]);
    }
}

void bubbleSort(vector<int> &a, long long &comp) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
}

void insertionSort(vector<int> &a, long long &comp) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0) {
            comp++;
            if (a[j] > key) {
                a[j + 1] = a[j];
                j--;
            } else break;
        }
        a[j + 1] = key;
    }
}

// Merge Sort
void merge(vector<int> &a, int l, int m, int r, long long &comp) {
    vector<int> L(a.begin()+l, a.begin()+m+1);
    vector<int> R(a.begin()+m+1, a.begin()+r+1);

    int i=0,j=0,k=l;
    while(i<L.size() && j<R.size()){
        comp++;
        if(L[i] < R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while(i<L.size()) a[k++] = L[i++];
    while(j<R.size()) a[k++] = R[j++];
}

void mergeSort(vector<int> &a, int l, int r, long long &comp) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(a, l, m, comp);
    mergeSort(a, m + 1, r, comp);
    merge(a, l, m, r, comp);
}

// Heap Sort
void heapify(vector<int> &a, int n, int i, long long &comp) {
    int largest = i, l = 2*i+1, r = 2*i+2;

    if (l < n) {
        comp++;
        if (a[l] > a[largest]) largest = l;
    }

    if (r < n) {
        comp++;
        if (a[r] > a[largest]) largest = r;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest, comp);
    }
}

void heapSort(vector<int> &a, long long &comp) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, comp);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0, comp);
    }
}

// Radix Sort
void countingSort(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(a[i]/exp)%10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i-1];

    for (int i = n-1; i >= 0; i--) {
        output[count[(a[i]/exp)%10]-1] = a[i];
        count[(a[i]/exp)%10]--;
    }
    a = output;
}

void radixSort(vector<int> &a, long long &comp) {
    comp = 0;
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx/exp > 0; exp *= 10)
        countingSort(a, exp);
}

// ---------------- QuickSort ----------------

int partition(vector<int> &a, int low, int high, int pivotIndex, long long &comp) {
    swap(a[pivotIndex], a[high]);
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comp++;
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i+1;
}

void quickSort1(vector<int> &a, int l, int r, long long &comp) {
    if (l < r) {
        int pi = partition(a, l, r, l, comp);
        quickSort1(a, l, pi-1, comp);
        quickSort1(a, pi+1, r, comp);
    }
}

void quickSort2(vector<int> &a, int l, int r, long long &comp) {
    if (l < r) {
        int p = l + rand() % (r - l + 1);
        int pi = partition(a, l, r, p, comp);
        quickSort2(a, l, pi-1, comp);
        quickSort2(a, pi+1, r, comp);
    }
}

int medianOfThree(vector<int> &a, int l, int r) {
    int m = (l + r)/2;
    if (a[l] > a[m]) swap(a[l], a[m]);
    if (a[l] > a[r]) swap(a[l], a[r]);
    if (a[m] > a[r]) swap(a[m], a[r]);
    return m;
}

void quickSort3(vector<int> &a, int l, int r, long long &comp) {
    if (l < r) {
        int p = medianOfThree(a, l, r);
        int pi = partition(a, l, r, p, comp);
        quickSort3(a, l, pi-1, comp);
        quickSort3(a, pi+1, r, comp);
    }
}

// ---------------- Measure ----------------

template <typename Func>
pair<long long, long long> measure(Func func, vector<int> &orig) {
    int repeat = 10;
    long long total_time = 0, total_comp = 0;

    for (int i = 0; i < repeat; i++) {
        vector<int> temp = orig;
        long long comp = 0;

        auto start = high_resolution_clock::now();
        func(temp, comp);
        auto end = high_resolution_clock::now();

        total_time += duration_cast<microseconds>(end - start).count();
        total_comp += comp;
    }

    return {total_time / repeat, total_comp / repeat};
}

// ---------------- MAIN ----------------

int main() {
    srand(time(0));

    int choice;
    cout << "1.Random\n2.Increasing\n3.Decreasing\n";
    cin >> choice;

    string s;
    if (choice == 1) s = "random";
    else if (choice == 2) s = "increasing";
    else if (choice == 3) s = "decreasing";
    else return 0;

    ifstream file("../Test Cases/" + s + ".txt");
    if (!file) {
        cout << "File not opened!\n";
        return 0;
    }

    int t;
    file >> t;

    while (t--) {
        int n;
        file >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) file >> a[i];

        cout << "\nn = " << n << endl;

        auto res = measure(selectionSort, a);
        cout << "Selection: " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure(bubbleSort, a);
        cout << "Bubble: " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure(insertionSort, a);
        cout << "Insertion: " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure([&](vector<int>& v, long long& c){ mergeSort(v,0,v.size()-1,c); }, a);
        cout << "Merge: " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure([&](vector<int>& v, long long& c){ quickSort1(v,0,v.size()-1,c); }, a);
        cout << "Quick(first): " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure([&](vector<int>& v, long long& c){ quickSort2(v,0,v.size()-1,c); }, a);
        cout << "Quick(random): " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure([&](vector<int>& v, long long& c){ quickSort3(v,0,v.size()-1,c); }, a);
        cout << "Quick(median): " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure(heapSort, a);
        cout << "Heap: " << res.first << " us, Comparisons: " << res.second << endl;

        res = measure(radixSort, a);
        cout << "Radix: " << res.first << " us (no comparisons)" << endl;
    }
}