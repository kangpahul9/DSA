
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),false));
        q.push(make_pair(sr,sc));
        int oldColor=image[sr][sc];
        visited[sr][sc]=true;
        while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            image[cr][cc]=color;
            q.pop();
            if(cr+1<image.size() && (!visited[cr+1][cc] && image[cr+1][cc]==oldColor)){
                visited[cr+1][cc]=true;
                q.push(make_pair(cr+1,cc));
            }
            if(cr-1>=0 && (!visited[cr-1][cc] && image[cr-1][cc]==oldColor)){
                visited[cr-1][cc]=true;
                q.push(make_pair(cr-1,cc));
            }
            if(cc+1<image[cr].size() && (!visited[cr][cc+1]&& image[cr][cc+1]==oldColor)){
                visited[cr][cc+1]=true;
                q.push(make_pair(cr,cc+1));
            }
            if(cc-1>=0 && (!visited[cr][cc-1] && image[cr][cc-1]==oldColor)){
                visited[cr][cc-1]=true;
                q.push(make_pair(cr,cc-1));
            }

        }
        return image;
    }
};