#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "consts.h"

int main(int argc, char *argv[]) {
  long int m = M_VAL, n = N_VAL;
  clock_t ppstart, ppstop;
  double pswtime, pewtime;
  int blockSize = BLOCKSIZE;

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

  int numberOfBlocks = (n - m) / blockSize;
  if ((n - m) % blockSize != 0) {
    numberOfBlocks++;
  }

  int low = m + blockSize;
  int high = m + blockSize + blockSize;
  if (high > n) {
    high = n;
  }

  for (int i = 0; i < numberOfBlocks; i++) {
    for (int j = 2; j * j <= high; j++) {
      if (primeArray[j]) {
        int firstMultiple = (low / j);
        if (firstMultiple <= 1) {
          firstMultiple = j + j;
        } else if (low % j) {
          firstMultiple = (firstMultiple * j) + j;
        } else {
          firstMultiple = (firstMultiple * j);
        }
        for (int k = firstMultiple; k <= high; k += j) {
          result[k - m] = false;
        }
      }
    }
  }


  ppstop = clock();
  pewtime = omp_get_wtime();

  printf("Sito sekwencyjne bez lokalności dostępu do danych\n");
  printf("Czas procesorow przetwarzania sekwencyjnego: %f sekund\n",
         ((double)(ppstop - ppstart) / CLOCKS_PER_SEC));
  printf("Czas trwania obliczen sekwencyjnych - wallclock: %f sekund\n",
         pewtime - pswtime);
}
