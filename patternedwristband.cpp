#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPatternedWristband(vector<vector<char>> band) 
{
    int arr[4] = {1, 1, 1, 1};
    for (int i=0; i<band.size(); i++) {
        for (int j=0; j<band[i].size(); j++) {
            if (band[i][j] != band[i][0]) {
                arr[0] = 0;
            }
            if (band[i][j] != band[0][j]) {
                arr[1] = 0;
            }
            if (i+1<band.size() && j+1<band[i].size() && band[i+1][j+1] != band[i][j]) {
                arr[2] = 0;
            }
            if (i+1<band.size() && j-1>=0 && band[i+1][j-1] != band[i][j]) {
                arr[3] = 0;
            }
        }
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    return (count(arr, arr+n, 0) == 4) ? false : true;
}

int main() {
    cout << isPatternedWristband({{'A', 'B'},{'A', 'C'},{'C', 'B'}});
}