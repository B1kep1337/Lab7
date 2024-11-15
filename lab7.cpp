// lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "string.h"
#include <cmath>
#include <cstdlib>

int **createG(int size){
    int **G = NULL;
    G = (int**)malloc(size*sizeof(int *));
    for(int i = 0; i < size; i++){
        G[i] = (int *)malloc(size*sizeof(int));
    }
    for(int i = 0; i < size; i++){
        for (int j = i; j < size; j++){
            G[i][j] = rand()%2;
            if(i == j) G[i][j] = 0;
            G[j][i] = G[i][j];
        }
    }
    return G;
}

void printG(int **G, int size)
{
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    return;
}
int **G=NULL, size=5, vis[5]={0};
void DFS(int s,int **G, int size, int *vis){
    vis[s]=1;
    printf("%d ", s);
    for(int i=0; i<size; i++){
        if(G[s][i]==1&&vis[i]==0){
            DFS(i, G, size, vis);
        }
    }
}



int main () {
	setlocale(LC_ALL, "Russian");
    int **G=NULL;
    int *vis=NULL;
    int size=5;
    int s=1;
    printf("Введите количество вершин: ");
    scanf("%d", &size);
    G=createG(size);
    printG(G, size);
    printf("Введите начальную вершину: ");
    
    vis= (int*)malloc(size*sizeof(int));

    scanf("%d", &s);
    printf("Обход графа:\n");
    DFS(s, G, size, vis);


getchar();
getchar();
return 0;
}








