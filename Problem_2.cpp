#include <iostream>
using namespace std;

/**
 * Alaa Mahmoud Ebrahim 20190105
 * Rana Ihab Ahmed 20190207
 * Omar Khaled Al Haj 20190351
 * */

long long m_w, m_z;
int arrSize;

long long get_random() {
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    long long res = (m_z << 16) + m_w;
    return res % 1000000000;
}

int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int k) {

    int pos = partition(arr, l, r);

    if (pos - l == k - 1)
        return arr[pos];
    if (pos - l > k - 1)
        return kthSmallest(arr, l, pos - 1, k);

    return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j ++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i ++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int main() {
    int K;
    cin >> arrSize >> K >> m_w >> m_z;
    int arr[arrSize];
    for (int i = 0; i < arrSize; i ++) {
        arr[i] = get_random();
        //cout << arr[i] << " ";
    }
    //cout << endl;
    cout << kthSmallest(arr, 0, arrSize - 1, K);
}
