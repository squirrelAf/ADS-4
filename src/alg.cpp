// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
   int ct = 0;
  for (int n = 0; n < len; ++n) {
    for (int b = n + 1; b < len; ++b) {
      if (arr[i] + arr[j] == value) {
        ct++;
      }
    }
  }
  return ct;
}
int countPairs2(int *arr, int len, int value) {
  int ct = 0;
  int fin = len;
  while (fin > 0 && arr[fin - 1] > value) {
    fin--;
  }
  for (int i = 0; i < fin; ++i) {
    for (int j = fin - 1; j > i; --j) {
      if (arr[i] + arr[j] == value) {
        ct++;
      }
    }
  }
  return ct;
}
int countPairs3(int *arr, int len, int value) {
  int ct = 0;
  const int* car = arr;
  for (int n = 0; n < len - 1; n++) {
      int kei = value - car[n];
      int left = n + 1;
      int right = len - 1;
      while (left <= right) {
          int midn = left + (right - left) / 2;
          if (car[midn] == kei) {
              ct++;
              int tempik = midn - 1;
              while (tempik >= left && car[tempik] == kei) {
                  ct++;
                  tempik--;
              }
              tempik = midn + 1;
              while (tempik <= right && car[tempik] == kei) {
                  ct++;
                  tempik++;
              }
              break;
          } else if (car[midn] < kei) {
              left = midn + 1;
          } else {
              right = midn - 1;
          }
      }
  }
  return ct;
}
