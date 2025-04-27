// Copyright 2021 NNTU-CS
int countPairs1(int arr, int len, int value) {
int count = 0;
  for (int a = 0; a < len; a++) {
    for (int b = a + 1; b < len; b++) {
      if (arr[a] + arr[b] == value) {
        ++count;
      } else if (arr[a] + arr[b] > value) {
        break;
      }
    }
  }
  return count;
}
int countPairs2(int arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int cnt = 0;
  while (left < right) {
    int curSum = arr[left] + arr[right];
    if (curSum == value) {
      int l = left;
      int r = right;
      while (l < r && arr[l] + arr[r] == value) {
        ++cnt;
        ++l;
      }
      --right;
    } else if (curSum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return cnt;
}
int countPairs3(int arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int pos = value - arr[i];
    int left = i + 1, right = len - 1;
    while (left <= right) {
      int mi = (left + right) / 2;
      if (arr[mi] < pos) {
        left = mi + 1;
      } else {
        right = mi - 1;
      }
    }
    int low = left;
    left = i + 1;
    right = len - 1;
    while (left <= right) {
      int mi = (left + right) / 2;
      if (arr[mi] <= pos) {
        left = mi + 1;
      } else {
        right = mi - 1;
      }
    }
    int high = right;
    if (low <= high) {
      count += (high - low + 1);
    }
  }
  return count;
}
