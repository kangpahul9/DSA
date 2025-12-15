#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> m;

    m[101] = "rahul";
    m[110] = "neha";
    m[131] = "rahul";

    m[101] = "rajat";  

    cout << m[101] << endl;
    cout<< m.count(101)<<endl;
    for(auto it : m)
    {
    cout<< it.first<<" = "<<it.second<<endl;
       
    }

    for(auto it : m)
    {
    cout<< it.first * 2 <<endl;
       
    }
    

    return 0;
}
