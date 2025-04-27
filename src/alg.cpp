// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++cnt;
            }
        }
    }
    return cnt;
}
int countPairs2(int *arr, int len, int value) {
    int cnt = 0;
    int lt = 0, rt = len - 1;

    while (lt < rt) {
        int sum = arr[lt] + arr[rt];
        if (sum == value) {
            ++count;
            while (lt < rt && arr[lt] == arr[lt + 1]) ++lt;
            while (lt < rt && arr[rt] == arr[rt - 1]) --rt;
            ++lt;
            --rt;
        }
        else if (sum < value) {
            ++lt;
        }
        else {
            --rt;
        }
    }
    return cnt;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if (complement >= arr[i]) {
            if (B_search(arr, i + 1, len - 1, complement) != -1) {
                ++count;
            }
        }
    }
    return count;
}
