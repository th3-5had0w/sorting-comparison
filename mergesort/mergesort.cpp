#include <bits/stdc++.h>
#include <sys/time.h>

void merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergesort(int arr[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    printf("--- Performing MergeSort ---\n");
    FILE *fd = fopen("./testcase", "r");
    int *buffer = (int *)calloc(1000000, sizeof(int));
    for (int i = 0; i<10; ++i){
        for (int j = 0; j<1000000; ++j){
            fscanf(fd, "%d", &buffer[j]);
        }
        printf("Test case number %d ", i+1);
        struct timeval stop, start;
        gettimeofday(&start, NULL);
        mergesort(buffer, 0, 999999);
        gettimeofday(&stop, NULL);
        double secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
        printf(" took %fs\n",secs);
    }
}