#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> mat, int n) 
{
    vector<vector<int>> ans;
    vector<int> a(mat.size(), 0);
    for (int i=0; i<mat.size(); i++) {
        ans.push(a);
    }
    for (int i=0; i<mat.size(); i++) {
        vector<int> tmp;
        for (int j=0; j<mat[i].size(); j++) {
            int pos;
            if (i+j>size && i>j) {
                pos = 1;
            }   
            else if (i+j>size && i<j) {
                pos = 2;
            }
            else if (i+j<size && i>j) {
                pos = 0;
            }
            else {
                pos = 3;
            }
            int part = (n / (mat.size()-2*i)) % 4 + pos;
            if (mat.size()%2 != 0 && i==j && i==mat.size()/2) {
                tmp.push(mat[i][j]);
            }
            else {
                if (part == 0) {
                    if (pos == 1 || pos == 3) {
                        tmp.push(mat[]);
                    }
                } else if (part == 1) {
                    tmp.push();
                } else if (part == 2) {
                    tmp.push();
                } else {
                    tmp.push();
                }
            }
        }
        ans.push(tmp);
    }
}