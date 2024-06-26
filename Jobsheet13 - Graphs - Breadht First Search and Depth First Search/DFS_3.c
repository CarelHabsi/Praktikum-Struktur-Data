#include <stdio.h>
#include <windows.h>

void DFS(int);
int G[10][10], visited[10], n; // n is no of vertices and graph is sorted in array G[10][10]

int main()
{
    system("cls");
    int i, j;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    
    // read the adjacency matrix
    printf("\nEnter adjacency matrix of the graph:");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    
    // visited is initialized to zero
    for(i = 0; i < n; i++)
        visited[i] = 0;
    
    DFS(0);
}

void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    
    for(j = 0; j < n; j++)
        if(!visited[j] && G[i][j] == 1)
            DFS(j);
}