#include <iostream>
using namespace std;

unsigned long coefficient(int rval, int k) {
	double coef = 1.0;
	for (int i = 0; i < k; i++) 
		coef *= (double)(rval-i) / (double)((i > 0) ?i : 1 );
    coef /= (double)k;
	return (unsigned long)(coef+.5);
}

string term(char c, unsigned long coef) {
	if (coef == 0) return "";
	if (coef == 1) return string(1,c);
	string res = string(1,c)+"^"+to_string(coef);
	return res;
}

string formula(int n) {
	if (n == 0) 
		return "1"; 
	
	string result("");
	int rval = n;
	if (n < 0) {
		result = "1/(";
		rval *= -1;
	}
	
	for (int i=0; i <= rval; i++) {
		unsigned long coef = coefficient(rval,i);
		if (coef > 1)
			result += to_string(coef);
        result += term('a', (rval-i));
		result += term('b', i);
    if (i < rval)
			result += "+";
	}
	if (n < 0)
		result += ")";
	return result;
}

int main() {
    cout << formula(2);
}