#include <iostream>
using namespace std;

vector<string> bucketize(string phrase, int n) {
	int len = phrase.length();
	vector<string> v;
	for (int i = 0; i < len; i++) {
		string s = "";
		while (i < len && phrase[i] != ' ') {
			s += phrase[i];
			i++;
		}
		if (s.length() != 0) v.push_back(s);
	}
	int max = 0;
	for (auto x : v) if (max < x.length()) max = x.length();
	if (max > n) return {};
	vector<string> list;
	for (int i = 0; i < v.size(); i++) {
		string s = v[i];
		while (i+1 < v.size() && (s+" "+v[i+1]).length() <= n) {
			s += " "+v[i+1];
			i++;
		}
		list.push_back(s);
	}
	return list;
}

int main(){
    std::vector<string> ans = bucketize("she sells sea shells by the sea", 10);
    cout << ans;
}