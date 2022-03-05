#include <bits/stdc++.h>
#include <sys/time.h>

int main(){
    printf("--- Performing CppLibrarySort ---\n");
    FILE *fd = fopen("./testcase", "r");
    int *buffer = (int *)calloc(1000000, sizeof(int));
    for (int i = 0; i<10; ++i){
        for (int j = 0; j<1000000; ++j){
            fscanf(fd, "%d", &buffer[j]);
        }
        printf("Test case number %d ", i+1);
        struct timeval stop, start;
        gettimeofday(&start, NULL);
        std::sort(buffer, buffer+1000000);
        gettimeofday(&stop, NULL);
        double secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
        printf(" took %fs\n",secs);
    }
}