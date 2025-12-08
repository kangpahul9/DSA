#include <iostream>
#include<vector>

using namespace std;
void printBoard(vector<vector<char> > board){
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------"<<endl;
}
bool isSafe(vector<vector<char> > board,int row, int col){
    for (int i = 0; i < row; i++)
    {
        if (board[i][col]=='Q')
        {
            return false;
        }
    }
    for (int j = 0; j < col; j++)
    {
        if (board[row][j]=='Q')
        {
            return false;
        }
    }
    
        for (int i = row, j = col;i >=0 && j >=0 ;i--, j--)
    {
        if (board[i][j]=='Q')
        {
            return false;
        }
    }
   
        for (int i = row, j = col;i >=0 && j <board.size() ;i--, j++)
    {
        if (board[i][j]=='Q')
        {
            return false;
        }
    }
    return true;    
}
void nQueens(vector<vector<char> > board,int row,int col)
{
    if (row==board.size())
    {
        printBoard(board);
        return;
    }
    
        for (int j = 0; j < board.size(); j++)
        {
            if (isSafe(board,row,j))
            {
                board[row][j]='Q';
                nQueens(board,row+1,0);
                board[row][j]='.';   
            }
        }
}



int main()
{
    int n;
    cout<<"ENTER Size of Board (nXn)";
    cin>>n;
    vector<vector<char> > board(n,vector<char>(n,'.'));
    printBoard(board);
    nQueens(board,0,0);
    

    return 0;
}

