// Buat kode program untuk mengimplementasikan algoritma Sorting: Bubble Sort, Selection Sort, Merge Sort dan Quick Sort. Lalu lengkapi data pada tabel berikut.

#include <iostream>
using namespace std;

//Function Declaration
void BubbleSort(int *arr, int size);
void SelectionSort(int *arr, int size);
void MergeSort(int *arr, int left, int right);
void Merge(int *arr, int aLeft, int aRight, int bLeft, int bRight);
void QuickSort(int *arr, int left, int right);

//Bubble Sort
void BubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

//Selection Sort
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

//Merge Sort
void MergeSort(int *arr, int left, int right) {
    if (left == right) return;
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);
    Merge(arr, left, mid, mid+1, right);
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

//Quick Sort
void QuickSort(int *arr, int left, int right) {
    if (left >= right) return;

    int pivot = arr[(left+right)/2];
    int pLeft = left;
    int pRight = right;

    while (pLeft <= pRight) {
        while (arr[pLeft] <= pivot) {
            ++pLeft;
        }

        while (arr[pRight] > pivot) {
            --pRight;
        }

        if (pLeft <= pRight) {
            swap(arr[pLeft], arr[pRight]);
            ++pLeft;
            --pRight;
        }
    }

    QuickSort(arr, left, pRight);
    QuickSort(arr, pLeft, right);
}

int main() 
{
    int arr[] = {3, 2, 1};
    BubbleSort(arr, 3);
    SelectionSort(arr, 3);
    MergeSort(arr, 0, 2);
    QuickSort(arr, 0, 2);

    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
  
    return 0;

} 
