#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() 
{
    long int m = 2, n = 10000000;
    clock_t ppstart, ppstop;
    double pswtime, pewtime;

    bool *result = (bool *)malloc((n - m + 1) * sizeof(bool));
    memset(result, true, (n - m + 1) * sizeof(bool));

    bool *primeArray = (bool *)malloc((sqrt(n) + 1) * sizeof(bool));
    memset(primeArray, true, (sqrt(n) + 1) * sizeof(bool));

    pswtime = omp_get_wtime();
    ppstart = clock();

    for (int i = 2; i*i*i*i <= n; i++) 
    {
        if (primeArray[i] == true) 
        {
            for (int j = i*i; j*j <= n; j+=i) 
            {
                primeArray[j] = false;
            }
        }
    }

    #pragma omp parallel for
    for (int i = 2; i*i <= n; i++)
    {
        if (primeArray[i]) 
        {
            int firstMultiple = (m / i);

            if (firstMultiple <= 1) 
            {
                firstMultiple = i + i;
            }
            else if (m % i) 
            { 
                firstMultiple = (firstMultiple * i) + i;
            }
            else 
            {
                firstMultiple = (firstMultiple * i);
            }

            for (int j = firstMultiple; j <= n; j+=i)
            { 
                result[j-m] = false;
            }
        }
    }
}