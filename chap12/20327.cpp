#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void op(int size, vector<vector<int> > &arr, int k, int l) {
    int grid = pow(2, l);
    if(k <= 4 && grid == 1) return;
    if(k > 4 && grid == size) return;
    if(k == 1) {
        for(int i = 0; i < size; i += grid) {
            for(int j = 0; j < size; j ++) {
                for(int t = 0; t < grid/2; t ++) {
                    int tmp = arr[i+t][j];
                    arr[i+t][j] = arr[i+grid-1-t][j];
                    arr[i+grid-1-t][j] = tmp;
                }
            }
        }
    } else if(k == 2) {
        for(int j = 0; j < size; j += grid) {
            for(int i = 0; i < size; i ++) {
                for(int t = 0; t < grid/2; t ++) {
                    int tmp = arr[i][j+t];
                    arr[i][j+t] = arr[i][j+grid-1-t];
                    arr[i][j+grid-1-t] = tmp;
                }
            }
        }
    } else if(k == 3) {
        vector<vector<int> > tmp(arr);
        for(int i = 0; i < size; i += grid) {
            for(int j = 0; j < size; j += grid) {
                for(int t1 = 0; t1 < grid; t1 ++) {
                    for(int t2 = 0; t2 < grid; t2 ++) {
                        arr[i+t2][j+grid-1-t1] = tmp[i+t1][j+t2];
                    }
                }
            }
        }
    } else if(k == 4) {
        vector<vector<int> > tmp(arr);
        for(int i = 0; i < size; i += grid) {
            for(int j = 0; j < size; j += grid) {
                for(int t1 = 0; t1 < grid; t1 ++) {
                    for(int t2 = 0; t2 < grid; t2 ++) {
                        arr[i+grid-1-t2][j+t1] = tmp[i+t1][j+t2];
                    }
                }
            }
        }
    } else if(k == 5) {
        for(int i = 0; i < size/2; i += grid) {
            for(int j = 0; j < size; j ++) {
                for(int t = 0; t < grid; t ++) {
                    int tmp = arr[i+t][j];
                    arr[i+t][j] = arr[size-grid-i+t][j];
                    arr[size-grid-i+t][j] = tmp;
                }
            }
        }
    } else if(k == 6) {
        for(int i = 0; i < size; i ++) {
            for(int j = 0; j < size/2; j += grid) {
                for(int t = 0; t < grid; t ++) {
                    int tmp = arr[i][j+t];
                    arr[i][j+t] = arr[i][size-grid-j+t];
                    arr[i][size-grid-j+t] = tmp;
                }
            }
        }
    } else if(k == 7) {
        vector<vector<int> > tmp(arr);
        for(int i = 0; i < size; i += grid) {
            for(int j = 0; j < size; j += grid) {
                for(int t1 = 0; t1 < grid; t1 ++) {
                    for(int t2 = 0; t2 < grid; t2 ++) {
                        arr[j+t1][size-grid-i+t2] = tmp[i+t1][j+t2];
                    }
                }
            }
        }
    } else if(k == 8) {
        vector<vector<int> > tmp(arr);
        for(int i = 0; i < size; i += grid) {
            for(int j = 0; j < size; j += grid) {
                for(int t1 = 0; t1 < grid; t1 ++) {
                    for(int t2 = 0; t2 < grid; t2 ++) {
                        arr[size-grid-j+t1][i+t2] = tmp[i+t1][j+t2];
                    }
                }
            }
        }
    }
}

int main() {
    int n, r;
    cin >> n >> r;

    int size = pow(2, n);
    vector<vector<int> > arr(size, vector<int>(size, 0));

    for(int i = 0; i < size; i ++) {
        for(int j = 0; j < size; j ++) {
            cin >> arr[i][j];
        }
    }


    int k, l;
    for(int i = 0; i < r; i ++) {
        cin >> k >> l;
        op(size, arr, k, l);
    }

    for(auto i : arr) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << "\n";
    }


    return 0;
}