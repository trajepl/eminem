#include <stdio.h>

int partition(int *arr, int left, int right) {
    int i = left, j = right;
    int k = arr[left];
    while(i < j) {
        for(; i < j; j--)
            if(arr[j] < k) {
                arr[i++] = arr[j];
                break;
            }
        for(; i < j; i++)
            if(arr[i] > k) {
                arr[j--] = arr[i];
                break;
            }
    }
    arr[i] = k;
    return i;
}

void insertsort(int *arr, int left, int right) {
    for(int i = left; i <= right; i++) {
        int val = arr[i];
        int j = i - 1;
        for(; j >= left && val < arr[j]; j--) 
            arr[j+1] = arr[j];
        arr[j+1] = val;
    }
}

void swap(int *arr, int p1, int p2) {
    int tmp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = tmp;
}

int select2(int *arr, int left, int right, int k, int r = 5) {
    int len = right - left + 1;
    if(len < r){
        insertsort(arr, left, right);
        return left + k - 1;
    }
    
    for(int i = 0; i < len / r; i++) {
       insertsort(arr, left + i * r, left + (i + 1) * r - 1);
       swap(arr, left + i, (left + i * r + r / 2));
    }
    swap(arr, left, select2(arr, left, left + len / r - 1, (len / r + 1) / 2));
    
    int t = partition(arr, left, right);
    if(left+k-1 == t)
        return t;
    else if(left+k-1 < t)
        return select2(arr, left, t-1, k);
    else
        return select2(arr, t+1, right, k-(t-left+1));
}

void print(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {19, 17, 1, 5, 14, 6, 0, 198, 235};
    int len = sizeof(arr) / sizeof(int);

    printf("original array: ");
    print(arr, len);

    for(int i = 0; i < len; i++) {
        int ret = select2(arr, 0, len, i+1);
        printf("No.%d number: %d\n", ret, arr[ret]);
    }

    return 0;
}
