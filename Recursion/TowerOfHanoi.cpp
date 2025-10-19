#include<iostream>
#include<string>
#include<vector>
using namespace std;
void towerOfHanoi(int n, string src, string helper, string dest){
    if (n==1)
    {
        cout << "Transfer Disk"<<n<<" from "<< src << " To " << dest<< endl;
        return;
    }
    towerOfHanoi(n-1,src,dest,helper);
        cout << "Transfer Disk"<<n<<" from "<< src << " To " << dest<<endl;

    towerOfHanoi(n-1,helper,src,dest);
}

int main(){
    int n;
    cin >>n;
    towerOfHanoi(n,"A","B","C");
    return 0;
}