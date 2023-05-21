#include <iostream>
#include <ctime>
#include <iomanip> 
using namespace std;

void generateRandomValue(int *arr, int size, int min, int max) 
{
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void BubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void SelectionSort(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        int minIndex = i;
        for (int j = i+1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

void Merge(int *arr, int aLeft, int aRight, int bLeft, int bRight) {
    int size = bRight - aLeft + 1;
    int tmp [size];
    int tIndex = 0;
    int aIndex = aLeft;
    int bIndex = bLeft;

    while (aIndex <= aRight && bIndex <= bRight) {
        if (arr[aIndex] <= arr[bIndex]) {
            tmp[tIndex] = arr[aIndex];
            ++aIndex;
        }

        else {
            tmp[tIndex] = arr[bIndex];
            ++bIndex;
        }

        ++tIndex;
    }

    while (aIndex <= aRight) {
        tmp[tIndex] = arr[aIndex];
        ++tIndex;
        ++aIndex;
    }

    while (bIndex <= bRight) {
        tmp[tIndex] = arr[bIndex];
        ++tIndex;
        ++bIndex;
    }

    for (int i = 0; i < size; ++i) {
        arr[aLeft+i] = tmp[i];
    }
}

void MergeSort(int *arr, int left, int right) {
    if (left == right) return;
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    Merge(arr, left, mid, mid+1, right);
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);

        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

long long fibonacciDynamicProgramming(int n) {
    static int dp[105];
    dp[0] = dp[1] = 1;

    if (dp[n] == 0) {
        dp[n] = fibonacciDynamicProgramming(n-1) + fibonacciDynamicProgramming(n-2);
    }

    return dp[n];
}

long long fibonacciRecursive(long long val) {
    if (val <=1) return val;
    return fibonacciRecursive(val-1) + fibonacciRecursive(val-2);
}
 
int main()
{
    srand(time(0));
    clock_t start, end;
   
    int size;
    cin >> size;
 
    
    start = clock();
    fibonacciDynamicProgramming(size);
    end = clock();
    
    
    double time_taken = double(end - start)/CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed
        << time_taken*1000 << setprecision(15);
    cout << " milisecond " << endl;
    return 0;
}
