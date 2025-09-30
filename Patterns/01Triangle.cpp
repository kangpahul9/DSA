#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int val = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i%2==0){
        val=0;
        }
        else{
            val=1;
        }
        for (int j = 0; j <= i; j++)
        {
            if (i%2==0)
        {
            if (j%2==0)
            {
                val++;
            }
            else{
                val--;
            }
        }
            else{
                if (j%2==0)
            {
                val--;
            }
            else{
                val++;
            }
            }
            cout << val;
        }
        cout << endl;
    }
    
    return 0;
}