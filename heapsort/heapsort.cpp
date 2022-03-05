#include <bits/stdc++.h>
#include <sys/time.h>


void heapify(int arr[], int n, int i){
    int lowend = i;
    int left = i*2+1;
    int right = i*2+2;

    if (left < n && arr[left] < arr[lowend]){
        lowend = left;
    }

    if (right < n && arr[right] < arr[lowend]){
        lowend = right;
    }

    int tmp;
    if (lowend != i){
        tmp = arr[i];
        arr[i] = arr[lowend];
        arr[lowend] = tmp;
        heapify(arr, n, lowend);
    }
}


void heapsort(int arr[], int last){
    for (int i=last/2-1; i>=0; --i){
        heapify(arr, last, i);
    }
    
    int tmp;
    for (int i=last-1; i>=0; --i){
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}

int main(){
    printf("--- Performing HeapSort ---\n");
    FILE *fd = fopen("./testcase", "r");
    int *buffer = (int *)calloc(1000000, sizeof(int));
    for (int i = 0; i<10; ++i){
        for (int j = 0; j<1000000; ++j){
            fscanf(fd, "%d", &buffer[j]);
        }
        printf("Test case number %d ", i+1);
        struct timeval stop, start;
        gettimeofday(&start, NULL);
        heapsort(buffer, 1000000);
        gettimeofday(&stop, NULL);
        double secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
        printf(" took %fs\n",secs);
    }
}