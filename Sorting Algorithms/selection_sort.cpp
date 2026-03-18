#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

void selectionSort(vector<int>& a) {
    int n = a.size();
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minIdx]) minIdx=j;
        }
        swap(a[i],a[minIdx]);
    }
}

int main() {

    ifstream file("../Test Cases/random.txt");

if (!file) {
    cout << "File not opened!\n";
    return 0;
}

    int t;
    file >> t;

    while(t--){
        int n;
        file >> n;

        vector<int> arr(n);
        for(int i=0;i<n;i++) file >> arr[i];

        auto start = high_resolution_clock::now();
        selectionSort(arr);
        auto end = high_resolution_clock::now();

        cout << n << " -> "
             << duration_cast<nanoseconds>(end-start).count()
             << " us\n";
    }
}