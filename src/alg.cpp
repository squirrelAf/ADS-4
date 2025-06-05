// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
 int cnt = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        cnt++;
      }
    }
}
int countPairs2(int *arr, int len, int value) {
  int cnt = 0;
  int endi = len - 1;
  while (endi > 0) {
    if (arr[endi] > value) {
      endi--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = endi; j > i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return cnt;
}
int countPairs3(int *arr, int len, int value) {
 int cnt = 0;
  for (int i = 0; i < len; ++i) {
    int targ = value - arr[i];
    int low = i + 1;
    int high = len - 1;
    while (low <= high) {
      int midi = low + (high - low) / 2;
      if (arr[midi] >= targ) {
        high = midi - 1;
      } else {
        low = midi + 1;
      }
    }
    int firsti = low;
    low = i + 1;
    high = len - 1;
    while (low <= high) {
      int midi = low + (high - low) / 2;
      if (arr[midi] <= targ) {
        low = midi + 1;
      } else {
        high = midi - 1;
      }
    }
    int lasti = high;
    if (firsti <= lasti) {
      cnt += lasti - firsti + 1;
    }
  }
  return cnt;
}
