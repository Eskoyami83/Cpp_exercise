#include <iostream>
using namespace std;

string vampireNumbers(int n) {
    if (n<100) {
        return "Normal Number"
    }
    if (to_string(n).length()%2 == 0) {
        for (int i=0; i<to_string(n).length(); i++) 
        {
            for (int j=i+1; j<to_string(n).length(); j++)
            {
                string ntmp = n.substr([1,0][i!=0],j-1) + n[i] + n.substr(j,n.length()-1-(j-1));
                string n1 = to_string(ntmp).substr(0,to_string(ntmp).length()/2);
                string n2 = to_string(ntmp).substr(to_string(nntmp).length()/2,to_string(ntmp).length()/2);
                if (stoi(n1) * stoi(n2) == n) 
                {
                    return "True Vampire";
                }
            }  
        }
    }
    else {
        for (int i=0; i<to_string(n).length(); i++) 
        {
            for (int j=i+1; j<to_string(n).length(); j++)
            {
                string ntmp = n.substr([1,0][i!=0],j-1) + n[i] + n.substr(j,n.length()-1-(j-1));
                string n1 = to_string(ntmp).substr(0,to_string(ntmp).length()/2);
                string n2 = to_string(ntmp).substr(to_string(ntmp).length()/2,to_string(ntmp).length()/2);
                if (stoi(n1) * stoi(n2) == n) 
                {
                    return "Pseudovampire";
                }
                string n1 = to_string(ntmp).substr(0,to_string(ntmp).length()/2+1);
                string n2 = to_string(ntmp).substr(to_string(ntmp).length()/2+1,to_string(ntmp).length()/2-1);
                if (stoi(n1) * stoi(n2) == n) 
                {
                    return "Pseudovampire";
                }
            }  
        }
    }
    return "Normal Number"
}

int main() {
    cout vampireNumbers(1260);
}