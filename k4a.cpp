#include <math.h>
#include <omp.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "consts.h"

int main() {
  long int m = M_VAL, n = N_VAL;
  clock_t ppstart, ppstop;
  double pswtime, pewtime;

  bool *result = (bool *)malloc((n - m + 1) * sizeof(bool));
  memset(result, true, (n - m + 1) * sizeof(bool));

  bool *primeArray = (bool *)malloc((sqrt(n) + 1) * sizeof(bool));
  memset(primeArray, true, (sqrt(n) + 1) * sizeof(bool));

  pswtime = omp_get_wtime();
  ppstart = clock();

  for (int i = 2; i * i * i * i <= n; i++) {
    if (primeArray[i] == true) {
      for (int j = i * i; j * j <= n; j += i) {
        primeArray[j] = false;
      }
    }
  }

  int sqrtn = sqrt(n);

#pragma omp parallel for
  for (int i = 2; i <= sqrtn; i++) {
    if (primeArray[i]) {
      int firstMultiple = (m / i);

      if (firstMultiple <= 1) {
        firstMultiple = i + i;
      } else if (m % i) {
        firstMultiple = (firstMultiple * i) + i;
      } else {
        firstMultiple = (firstMultiple * i);
      }

      for (int j = firstMultiple; j <= n; j += j) {
        if (result[j-m]) 
          result[j-m] = false;}
      }
    }
  }

  ppstop = clock();
  pewtime = omp_get_wtime();

  printf("Sito równoległe funkcyjne bez lokalności dostępu do danych\n");
  printf("Czas procesorow przetwarzania sekwencyjnego: %f sekund\n",
         ((double)(ppstop - ppstart) / CLOCKS_PER_SEC));
  printf("Czas trwania obliczen sekwencyjnych - wallclock: %f sekund\n",
         pewtime - pswtime);
}
