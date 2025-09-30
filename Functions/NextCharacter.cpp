#include<iostream>
using namespace std;

char nextCharacter(char c){
    if ((int)c < 65 || (int) c > 122)
    {
        return ' ';
    }
    
    if (c == 'z')
    {
        return 'a';
    }
    if (c== 'Z')
    {
        return 'A';
    }
    return c + 1;
}

int main(){
    char c;
    cin >> c;
    cout << nextCharacter(c);
    
    return 0;
}