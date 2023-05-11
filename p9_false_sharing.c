#include <sys/times.h>
#include <time.h>
#include <stdio.h> 
#include <pthread.h> 
#include <stdlib.h>

struct timespec tpBegin1, tpEnd1, tpBegin2, tpEnd2, tpBegin3, tpEnd3;  

double computeTime(struct timespec start,struct timespec end); 
void *work(void *param);

int array[100];

int main(int argc, char *argv[]) { 
    int first_elem  = 0;
    int bad_elem    = 8;
    int good_elem   = 99;
    double time1, time2, time3;
    pthread_t thread_1, thread_2;

    //---------------------------START----Serial
    clock_gettime(CLOCK_MONOTONIC, &tpBegin1);
    work((void*)&first_elem);
    work((void*)&bad_elem);
    clock_gettime(CLOCK_MONOTONIC, &tpEnd1);
    //----------------------------END-----Serial


    //---------------------------START-----False Sharing
    clock_gettime(CLOCK_MONOTONIC, &tpBegin2);
    pthread_create(&thread_1, NULL, work, (void*)&first_elem);
    pthread_create(&thread_2, NULL, work, (void*)&bad_elem);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    clock_gettime(CLOCK_MONOTONIC, &tpEnd2);
    //----------------------------END-----False Sharing


    //---------------------------START----NO False Sharing
    clock_gettime(CLOCK_MONOTONIC, &tpBegin3);   
    pthread_create(&thread_1, NULL, work, (void*)&first_elem);
    pthread_create(&thread_2, NULL, work, (void*)&good_elem);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    clock_gettime(CLOCK_MONOTONIC, &tpEnd3);
    //----------------------------END------NO False Sharing


    printf("array[first_element]: %d\t array[bad_element]: %d\t array[good_element]: %d\n", array[first_elem],array[bad_elem],array[good_elem]);

    time1 = computeTime(tpBegin1, tpEnd1);
    time2 = computeTime(tpBegin2, tpEnd2);
    time3 = computeTime(tpBegin3, tpEnd3);
    printf("Serial               : %lf ms\n", time1);
    printf("CU false sharing     : %lf ms\n", time2);
    printf("FARA false sharing   : %lf ms\n", time3);


return EXIT_SUCCESS; 
}

void *work(void *param) {     
    int index = *((int*)param);
    for (int i = 0; i < 100000000; i++) {
        array[index] += 1;
    }
}

double computeTime(struct timespec start, struct timespec end) {
    double t;   
    t  = (end.tv_sec - start.tv_sec) * 1.0e3;
    t += (end.tv_nsec - start.tv_nsec) * 1.0e-6;
    
    return t;
}