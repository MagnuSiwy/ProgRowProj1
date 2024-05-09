#include <iostream>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        throw std::invalid_argument("Not enough arguments");
    }

    int m = atoi(argv[0]);
    int n = atoi(argv[1]);

    bool* result = (bool*)malloc((n - m + 1) * sizeof(bool));
    memset(result, true, (n - m + 1) * sizeof(bool));

    bool* primeArray = (bool*)malloc((sqrt(n) + 1) * sizeof(bool));
    memset(primeArray, true, (sqrt(n) + 1) * sizeof(bool));

    for (int i = 2; i*i*i*i <= n; i++) 
    {
        if (primeArray[i] == true) 
        {
            for (int j = i * i; j*j <= n; j+=i) 
            {
                primeArray[j] = false;
            }
        }
    }

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