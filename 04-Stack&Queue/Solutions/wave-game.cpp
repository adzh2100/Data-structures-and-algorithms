/* Имате предоставен лабиринт като двумерна матрица, като ако в матрицата има -1, това означава, че в тази клетка има стена и през нея не може да се минава,
в противен случай в нея има цяло положително число. Ако се намирате в клетка (A, B), то от нея може да се премине единствено в клетките (A-1, B), (A+1, B),
(A, B-1) и (A, B+1) .
Подава се клетка (X,Y) от която се започва играта. 
Търси се сумата на числата от всички клетки които са точно на разстояние R от началната
(ако до една клетка има няколко пътя с различна големина то разстоянието до нея е равно на дължината на най-късият от тези пътища)
Разстоянията се мерят по брой клетки през които се преминава, като се включва в разстоянието и първата и последната клетка.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int rows,columns;

void solve(int i,int j, int dist, vector<vector<pair<int,int>>>& matrix)
{
    queue<pair<int,int>> q;
    int sum=0;
    int level=1;
    q.push({i,j});
    q.push({-1,-1});
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(r==-1 && c==-1)
        {
            level++;
            if(level>dist) break;
            if(!q.empty() && q.front().first!=-1) q.push({-1,-1});
            continue;
        }
        if(matrix[r][c].second==1) continue;
        else matrix[r][c].second=1;
        
        if(level==dist) sum+=matrix[r][c].first;
        
        if(r>0 && matrix[r-1][c].first!=-1 && matrix[r-1][c].second==0) q.push({r-1,c});
        if(r<rows-1 && matrix[r+1][c].first!=-1 && matrix[r+1][c].second==0) q.push({r+1,c});
        if(c>0 && matrix[r][c-1].first!=-1 && matrix[r][c-1].second==0) q.push({r,c-1});
        if(c<columns-1 && matrix[r][c+1].first!=-1 && matrix[r][c+1].second==0) q.push({r,c+1});     
    }
    cout<<sum;
}
int main() {
    int start_x,start_y,dist;
    cin>>rows>>columns;
    vector<vector<pair<int,int>>> matrix(rows);
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            int el;
            cin>>el;
            matrix[i].push_back({el,0});
        }
    }
    cin>>start_x>>start_y;
    cin>>dist;
    
    solve(start_x-1,start_y-1,dist,matrix);
    return 0;
}


