#include <iostream>
#include <vector>
using namespace std;

int largestIsland(vector<vector<int>> map) 
{
    int real_max = 0, curr_max = 0, chain_is_not_broken = 0;
    for (int i=0; i<map.size(); i++) {
        for (int j=0; j<map[i].size(); j++) {
            if (map[i][j] == 1) {
                if (i+1 < map.size()) {
                    chain_is_not_broken |= map[i+1][j];
                    if (j+1 < map[i].size()) {
                        chain_is_not_broken |= map[i+1][j+1];
                    }
                    if (j-1 >= 0) {
                        chain_is_not_broken |= map[i+1][j-1];
                    }
                }
                if (i-1 >= 0) {
                    chain_is_not_broken |= map[i+1][j];
                    if (j+1 < map[i].size()) {
                        chain_is_not_broken |= map[i-1][j+1];
                    }
                    if (j-1 >= 0) {
                        chain_is_not_broken |= map[i-1][j-1];
                    }
                }
                if (j+1 < map[i].size()) {
                    chain_is_not_broken |= map[i][j+1];
                }
            }
            if (!chain_is_not_broken) {
                real_max = max(curr_max, real_max);
                curr_max = 0;
            } else {
                curr_max += 1;
            }
            chain_is_not_broken = 0;
        }
    }
    return  real_max;
}

int main() {
    cout << largestIsland({{1,0,0}, {0,1,1}, {0,0,1}})
    return 0;
}