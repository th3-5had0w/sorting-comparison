#include <bits/stdc++.h>
#include <sys/time.h>

void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

int main(){
    printf("--- Performing QuickSort ---\n");
    FILE *fd = fopen("./testcase", "r");
    int *buffer = (int *)calloc(1000000, sizeof(int));
    for (int i = 0; i<10; ++i){
        for (int j = 0; j<1000000; ++j){
            fscanf(fd, "%d", &buffer[j]);
        }
        printf("Test case number %d ", i+1);
        struct timeval stop, start;
        gettimeofday(&start, NULL);
        quicksort(buffer, 0, 999999);
        gettimeofday(&stop, NULL);
        double secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
        printf(" took %fs\n",secs);
    }
}