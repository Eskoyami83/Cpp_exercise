#include <iostream>
#include <vector>
using namespace std;

int bowlingscore(vector<int> vec)
{
    int ans = 0, strike = 0, spare = 0;
    for (int i=0; i<vec.size(); i++) 
    {   
        if (strike || spare) 
        {
            ans += vec[i] * 2;
            spare = 0;
            if (i%2 != 0 && vec[i] != 10) {
                strike = 0;
            }
        } 
        else if (vec[i] == 10) 
        {
            strike = 1;
            ans += 10;
        }
        else if (i%2 != 0 and vec[i]+vec[i-1] == 10)
        {
            spare = 1;
            ans += 5;
        }
        else
        {
            ans += vec[i];
        }
    }
    return ans;
}

int main() {
    cout << bowlingscore({10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << "ok\n";
    cout << bowlingscore({5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}) << "ok\n";
    cout << bowlingscore({4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4}) << "ok\n";
    cout << bowlingscore({10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 10});
}