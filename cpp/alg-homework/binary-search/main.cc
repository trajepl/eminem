#include <stdio.h>

int binary_search(int src[], int t, int l, int r) {
    int mid = (l + r) / 2;
    if(src[mid] == t) return mid;
    else if(src[mid] > t) return binary_search(src, t, l, mid - 1);
    else return binary_search(src, t, mid + 1, r);
    return -1;
}

int main() {
    int len = 10;
    int test[len] = {0, 1, 3, 4, 5, 6, 7, 8, 9, 19};

    for(int i = 0; i < len; i++) {
        int target = test[i];
        int position = binary_search(test, target, 0, len-1);
        if(position == -1) printf("not exist!");
        printf("position: %d -> %d\n", position, test[position]);
    }

    return 0;
}
