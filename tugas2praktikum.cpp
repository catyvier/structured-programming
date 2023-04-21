// #1
double cube (int length, int width) {
    return length * width;
}

double cube (int length, int width, int height) {
    return length * width * height;
}

// #2
void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void print(int *arr, int sz) {
    for (int i = 0; i < sz; ++i) {
        cout << arr[i] << " ";
    }
}

// #3
#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    cin.ignore();

    string str;

    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        cout << str << " " << str.size() << endl;
    }
}

// #4
void sum (int *p, int size) {
    long long sum = 0;
    
    for (int i = 0; i < size; ++i) {
        sum += *p;
        ++p;
    }

    cout << sum << endl;
}

// #5
string balik (string str) {
    string res;
    int sz = str.size();
    
    for (int i = 0; i < sz; ++i) {
        res.push_back(str[sz-i-1]);
    }

    return res;
}

// #6
int search(int *arr, int query, int sz)
{
    int index = 0;

    while (index < sz) {
        if (arr[index] == query) {
            index = index;
            break;
        }
        ++index;
    }

    if (index == sz) return -1;

    return index;
}
