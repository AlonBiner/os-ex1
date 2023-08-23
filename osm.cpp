#include <iostream>
#include <sys/time.h>
#include "osm.h"

double osm_operation_time(unsigned int iterations) {
    struct timeval start_time, end_time;
    long seconds, micro_seconds, nano_seconds;

    int a = 0;

    if (iterations == 0 || gettimeofday(&start_time, NULL) == -1) {
        return -1;
    }

    // What is supposed to be the unrolling factor of the loop
    // How many iterations are supposed to be in the loop, after the unrolling?
    // By how many iterations do we divide the total elapsed time in the final line of the function?
    // What is the type of README file.
    // Are exercises 2-4 recycled?
    for(unsigned int i = 0; i < ((iterations + 9) / 10); i++) {
        a = a + 1;
        a = a + 1;
        a = a + 1;
        a = a + 1;
        a = a + 1;
        a = a + 1;
        a = a + 1;
        a = a + 1;
        a = a + 1;
        a = a + 1;
    }

    if(gettimeofday(&end_time, NULL) == -1) {
        return -1;
    }

    seconds = (end_time.tv_sec - start_time.tv_sec);
    micro_seconds = (end_time.tv_usec - start_time.tv_usec);
    nano_seconds = 1000000000 * seconds + 1000 * micro_seconds;

    return (double)nano_seconds / (double)(((iterations + 9) / 10) * 10);
}

void empty_function() {}

double osm_function_time(unsigned int iterations) {
    struct timeval start_time, end_time;
    long seconds, micro_seconds, nano_seconds;

    if (iterations == 0 || gettimeofday(&start_time, NULL) == -1) {
        return -1;
    }

    // What is supposed to be the unrolling factor of the loop
    // How many iterations are supposed to be in the loop, after the unrolling?
    // By how many iterations do we divide the total elapsed time in the final line of the function?
    for(unsigned int i = 0; i < ((iterations + 9) / 10); i++) {
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
    }

    if(gettimeofday(&end_time, NULL) == -1) {
        return -1;
    }

    seconds = (end_time.tv_sec - start_time.tv_sec);
    micro_seconds = (end_time.tv_usec - start_time.tv_usec);
    nano_seconds = 1000000000 * seconds + 1000 * micro_seconds;

    return (double)nano_seconds / (double)(((iterations + 9) / 10) * 10);
}

double osm_syscall_time(unsigned int iterations) {
    struct timeval start_time, end_time;
    long seconds, micro_seconds, nano_seconds;

    if (iterations == 0 || gettimeofday(&start_time, NULL) == -1) {
        return -1;
    }

    for(unsigned int i = 0; i < ((iterations + 9) / 10); i++) {
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
    }

    if(gettimeofday(&end_time, NULL) == -1) {
        return -1;
    }

    seconds = (end_time.tv_sec - start_time.tv_sec);
    micro_seconds = (end_time.tv_usec - start_time.tv_usec);
    nano_seconds = 1000000000 * seconds + 1000 * micro_seconds;

    return (double)nano_seconds / (double)(((iterations + 9) / 10) * 10);
}


