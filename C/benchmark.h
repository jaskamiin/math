#ifndef BENCHMARK_H
#define BENCHMARK_H
    #ifdef WIN32
        #include <windows.h>

        static double get_time(void)
        {
            LARGE_INTEGER t, f;
            QueryPerformanceCounter(&t);
            QueryPerformanceFrequency(&f);
            return (double)t.QuadPart/(double)f.QuadPart;
        }

    #else
        #include <sys/time.h>
        #include <sys/resource.h>

        static double get_time(void)
        {
            struct timeval t;
            struct timezone tzp;
            gettimeofday(&t, &tzp);
            return t.tv_sec + t.tv_usec*1e-6;
        }

    #endif
#endif