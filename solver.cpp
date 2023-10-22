#include <iostream>
using namespace std;

int solver(string eq) {
    int i = 0;
    string prev_num = "";
    char sign_x = 'a';
    char sign = 'a';
    while (i<eq.length()) {
        if (isdigit(eq[i])) {
            string num = "";
            int j = i;
            while (j<eq.length() && isdigit(eq[j])) {
                num += eq[j];
                j++;
            }
            if (prev_num != "") {
                if (sign == '+') {
                    num = to_string(stoi(num) + stoi(prev_num));
                } else if (sign == '-' || sign == '=') {
                    num = to_string(stoi(num) - stoi(prev_num));
                }
            }
            prev_num = num;
            i = j-1;
        }
        else if (eq[i] == '+' || eq[i] == '-' || eq[i] == '=') {
            sign = eq[i];
        }
        else if (eq[i] == 'x') {
            sign_x = sign;
        }
        i++;
    }
    int ans = 0;
    if (sign_x == '+') {
        ans = stoi(prev_num);
    } else {
        ans = - stoi(prev_num);
    }
    return ans;
}

int main() {
    int ans = solver("2 + x = 19");
    cout << ans << '\n';
    int ans1 = solver("4 - x = 1");
    cout << ans1;
}