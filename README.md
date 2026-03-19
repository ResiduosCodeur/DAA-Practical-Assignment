<h1> DAA Practical Assignment </h1>
This Assigment aims to test and analyse various sorting algorithms. The various sorting algorithms involved are:<br>
1) Bubble sort<br>
2) Insertion sort<br>
3) Selection sort<br>
4) Merge sort<br>
5) Heap sort<br>
6) Radix sort<br>
7) Quick sort<br>
<ul>
<li> Pivot as the first element in the array
<li> Pivot as a random element in the array
<li> Pivot as the median of first, middle and last elements in the array
</ul>

<h2> Name and Roll No; </h2>

S Ashwin <br>
241CS250 <br>

Samarth Talawar <br>
241CS252

<h2> Instructions to generate test cases </h2>
Use the file testCaseGenerator.cpp to generate the three types of test cases - 
<ul>
<li> Test cases in random order
<li> Test cases in increasing order
<li> Test cases in decreasing order
</ul>
<br>
The format of the input files is:
<br>
Total number of test cases in the file<br>
The next 2n lines contains the size of each array k and the numbers<br>

```
n
k1
a b c d ...
k2
e f g h...
.
.
.
```

Example:

```
2
3
3 6 1
5
8 4 7 2 4
```
In our analysis, we have taken ```t = 7```

<strong>Running the File:</strong>

```
g++ testCaseGenerator.cpp -o a
./a
```

This will generate three files:<br>

1. random.txt
2. increasing.txt
3. decreasing.txt


<h2> Instructions to run allsortcount.cpp </h2>
This is the file which contains all the sorting algorithms and is used to see all the running time and number of comparsion associated with the sorting algorithms.<br><br>
<strong>Running the File:</strong>

```
g++ allsortcount.cpp -o a
./a
```
<strong>Program input</strong>
<br>
When you run the program,select the input type:
<br>
```
1. Random
2. Increasing
3. Decreasing
```
<br>
Based on your choice, the program reads:
<br>

```
../Test Cases/<type>.txt
```

<strong>Output format</strong>
<br>
for each test case:
<br>
```
n = XX

Selection: XXX us, Comparisons: XXX
Bubble: XXX us, Comparisons: XXXX
Insertion: XX us, Comparisons: XXXX
Merge: XX us, Comparisons: XXXX
Quick(first): XX us, Comparisons: XXXX
Quick(random): XX us, Comparisons: XXXX
Quick(median): XX us, Comparisons: XXXX
Heap: XX us, Comparisons: XXXX
Radix: XX us (no comparisons)
```
<br>
<br>
<h2> Instructions to run allquicksort.cpp </h2>
This is the file which contains all the quick sorting algorithms and is used to see all the running time associated with all three versions of quicksort based on pivot selection(first element pivot, random pivot and Median between first element, last element and middle element).<br><br>
<strong>Running the File:</strong>

```
g++ allquicksort.cpp -o a
./a
```
<strong>Program input</strong>
<br>
When you run the program,select the input type:
<br>
```
1. Random
2. Increasing
3. Decreasing
```
<br>
Based on your choice, the program reads:
<br>

```
../Test Cases/<type>.txt
```

<strong>Output format</strong>
<br>
for each test case:
<br>
```
n = XX
Quick(first): XX us
Quick(random): XX us
Quick(median): XX us
```