#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isVowel(char const c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

vector<string> getVowelSubstrings(string str)
{
	vector<string> result;
	for (size_t i = 0; i < str.size(); ++i)
	{
		for (size_t j = i; j < str.size(); ++j)
		{
			auto s = str.substr(i, str.size() - j);
			if (isVowel(s.front()) && isVowel(s.back()))
				result.emplace_back(s);
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}

int main() {
    vector<string> vec = getVowelSubstrings("ahagdtehaa");
    cout << '[' ;
    for (int i=0; i<vec.size()-1; i++) {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.size()-1]; 
    cout << ']' ;
    return 0;
}