 /* File : example.c */
 
//extern "C"
//{
 #include <time.h>
 double My_variable = 3.0;
 
 int fact(int n) {
     if (n <= 1) return 1;
     else return n*fact(n-1);
 }
 
 int my_mod(int x, int y) {
     return (x%y);
 }
 	
 char *get_time()
 {
     time_t ltime;
     time(&ltime);
     return ctime(&ltime);
 }


void emptyCall()
{
}

double returnDouble()
{
	return 1234.5;
}

const char* returnString()
{
	return "Hello World";
}

void passDouble(double num)
{
}

void passString(const char* str)
{
}


double passAndReturnDouble(double num)
{
	return num;
}

const char* passAndReturnString(const char* str)
{
	return str;
}

void pass2Double(double n1, double n2)
{
}

void pass2String(const char* str1, const char* str2)
{
}


double* returnDoubleArray2()
{
	static double somearray[2] = { 1.0, 2.0 };
	return somearray;
}

const char** returnStringArray2()
{
	static const char* somearray[2] = { "Hello", "World" };
	return somearray;
}

void multireturn2Double(double* n1, double* n2)
{
	if(NULL != n1)
	{
		*n1 = 1234.5;
	}
	if(NULL != n2)
	{
		*n2 = 1.0;
	}
}

void multireturn2String(const char** n1, const char** n2)
{
	if(NULL != n1)
	{
		*n1 = "Hello";
	}
	if(NULL != n2)
	{
		*n2 = "World";
	}
}

#include <stdio.h>
#ifdef __ANDROID__
	#undef fprintf
	#include <android/log.h>
	#define fprintf(stderr, ...) __android_log_print(ANDROID_LOG_INFO, "ALmixer", __VA_ARGS__)
#endif

        #if defined(__APPLE__)
                #include <QuartzCore/QuartzCore.h>
                #include <unistd.h>
                static CFTimeInterval s_ticksBaseTime = 0.0;
                
        #elif defined(_WIN32)
                #define WIN32_LEAN_AND_MEAN
                #include <windows.h>
                #include <winbase.h>
                        LARGE_INTEGER s_hiResTicksPerSecond;
                        double s_hiResSecondsPerTick;
                        LARGE_INTEGER s_ticksBaseTime;
        #else
                #include <unistd.h>
                #include <time.h>
                static struct timespec s_ticksBaseTime;
        #endif
        static void Example_InitTime()
        {
                #if defined(__APPLE__)
                        s_ticksBaseTime = CACurrentMediaTime();
                
                #elif defined(_WIN32)
                        LARGE_INTEGER hi_res_ticks_per_second;
                        if(TRUE == QueryPerformanceFrequency(&hi_res_ticks_per_second))
                        {
                                QueryPerformanceCounter(&s_ticksBaseTime);
                                s_hiResSecondsPerTick = 1.0 / hi_res_ticks_per_second;
                        }
                        else
                        {
                                fprintf(stderr, "Windows error: High resolution clock failed. Audio will not work correctly.\n");
                        }
                #else
                        /* clock_gettime is POSIX.1-2001 */
                        clock_gettime(CLOCK_MONOTONIC, &s_ticksBaseTime);
                #endif

        }
        static unsigned int Example_GetTicks()
        {
                #if defined(__APPLE__)
                        return (unsigned int)((CACurrentMediaTime()-s_ticksBaseTime)*1000.0);
                #elif defined(_WIN32)
                        LARGE_INTEGER current_time;
                        QueryPerformanceCounter(&current_time);
                        return (unsigned int)((current_time.QuadPart - s_ticksBaseTime.QuadPart) * 1000 * s_hiResSecondsPerTick);
                #else /* assuming POSIX */
                        /* clock_gettime is POSIX.1-2001 */
                        struct timespec current_time;
                        clock_gettime(CLOCK_MONOTONIC, &current_time);
                        return (unsigned int)((current_time.tv_sec - s_ticksBaseTime.tv_sec)*1000.0 + (current_time.tv_nsec - s_ticksBaseTime.tv_nsec) / 1000000);
						                #endif
        }
        static void Example_Delay(unsigned int milliseconds_delay)
        {
                #if defined(_WIN32)
                Sleep(milliseconds_delay);
                #else
                usleep(milliseconds_delay*1000);
                #endif
        }

void Example_DoNothing()
{
}

void measure_c_function()
{
	long i;
	unsigned int start_time;
	unsigned int end_time;
	Example_InitTime();

	start_time = Example_GetTicks();
	for(i=0; i<10000000; i++)
	{
		Example_DoNothing();
	}
	end_time = Example_GetTicks();
	fprintf(stderr, "Example_DoNothing time is %d ms for %d loops\n", end_time-start_time, i);
}

//}
