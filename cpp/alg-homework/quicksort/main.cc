#include <stdio.h>

void quicksort(int *arr, int l, int r) {
    if(l >= r) return ;
    int i = l, j = r;
    int k = arr[l];
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
    quicksort(arr, l, i);
    quicksort(arr, i + 1, r);
}

void print(int *arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

void test(int *arr, int len) {

    printf("orginal array: ");
    print(arr, len);

    quicksort(arr, 0, len-1);
    printf("sorted array: ");
    print(arr, len);
}

int main() {
    int arr[] = {1, 5, 2, 10, 9, 16, 5, 8};
    int len = sizeof(arr) / sizeof(int);
    test(arr, len);

    int arr1[] = {5, 2, 10, 9, 16, 5, 8};
    len = sizeof(arr1) / sizeof(int);
    test(arr1, len);

    int arr2[] = {9, 6, 5, 8};
    len = sizeof(arr2) / sizeof(int);
    test(arr2,len);

    return 0;
}
