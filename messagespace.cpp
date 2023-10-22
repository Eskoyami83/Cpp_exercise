#include <iostream>
using namespace std;

string decryptize(string word) {
    string ans = "";
    int tmp = 0;
    int i = 0;  
    string tmp_word = "";
    int nb_word = 0;
    while (i < word.length()) {
        if (tmp==0 && !isdigit(word[i]) && word[i] != '[' && word[i] != ']') {
            ans += word[i];
        }
        else if (word[i] == '[') {
            tmp = 1;
        }
        else if (word[i] == ']') {
            for (int i=0; i<nb_word; i++) {
                ans += tmp_word;
            }
            tmp = 0;
            tmp_word = "";
            nb_word = 0;
        }
        else if (isdigit(word[i])) {
            string num = "";
            while (isdigit(word[i])) {
                num += word[i];
                i++;
            }
            i--;
            nb_word = stoi(num);
        }
        else {
            tmp_word += word[i];
        }
        i++;
    }
    return ans;
}

int main() {
    string ans = decryptize("AB[3CD]");
    string ans1 = decryptize("IF[2E]LG[5O]D");
    cout << ans << "\n";
    cout << ans1;
}