#include <iostream>

int main() {
    int n=5;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        for (int k = 1; k < n-i; k++)
        {
            std::cout << " ";
        }
        for (int k = 1; k < n-i; k++)
        {
            std::cout << " ";
        }
        for(int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
    for (int i = n-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        for (int k = 1; k < n-i; k++)
        {
            std::cout << " ";
        }
        for (int k = 1; k < n-i; k++)
        {
            std::cout << " ";
        }
        for(int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        std::cout<<std::endl;
    }
    
    return 0;
}