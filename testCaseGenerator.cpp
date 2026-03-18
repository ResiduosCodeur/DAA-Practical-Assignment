#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(time(0));

    vector<int> sizes = {100, 500, 1000, 5000, 7500 ,10000, 20000};

    ofstream randomFile("Test Cases/random.txt");
    ofstream incFile("Test Cases/increasing.txt");
    ofstream decFile("Test Cases/decreasing.txt");

    int testcases = sizes.size();

    randomFile << testcases << endl;
    incFile << testcases << endl;
    decFile << testcases << endl;

    for (int n : sizes)
    {
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = rand() % 1000000;
        }

        // Random
        randomFile << n << endl;
        for (int x : arr)
            randomFile << x << " ";
        randomFile << endl;

        // Increasing
        sort(arr.begin(), arr.end());

        incFile << n << endl;
        for (int x : arr)
            incFile << x << " ";
        incFile << endl;

        // Decreasing
        reverse(arr.begin(), arr.end());

        decFile << n << endl;
        for (int x : arr)
            decFile << x << " ";
        decFile << endl;
    }

    randomFile.close();
    incFile.close();
    decFile.close();
}