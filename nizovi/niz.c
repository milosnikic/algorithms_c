#include<stdio.h>
#define MAX 50

void ispisiMatricu(int mat[][3], int m, int n){
    int i,j;
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

void proizvod(int niz[], int n){
    niz[0] = 4;
    niz[1] = 8;
    int i;
    for(i = 2; i < n; i++)
        niz[i] = (niz[i-1]*niz[i-2])%10;
}

void ispis(int niz[],int d){
    int i;
    for(i = 0;i < d;i++){
        printf("%d\t",niz[i]);
    }
}

int naGlavnoj(int mat[][5],int el){
    int i,j;
    for(i = 0;i<5;i++){
        for(j=0;j<5;j++){
            if(i == j && mat[i][j] == el){
                return 1;
            }
        }
    }
    return 0;
}

int ispitati(int mat[][5]){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i+j == 4 && naGlavnoj(mat,mat[i][j]) == 0){
                return 0;
            }
        }
    }
    return 1;
}

int main(void){
    int matrica[5][5] = {1, 2, 5,-1, 1,
                         4, 8, 4, 1, 6,
                         2, 4, 6, 7, 8,
                         3, 4, 7, 1, 2,
                         8, 8, 11,9, 3};
    //int niz[5];
    //proizvod(niz,5);
    //ispis(niz,5);
    //ispisiMatricu(matrica,3,3);
    printf("%s",ispitati(matrica) == 1 ? "Da" : "Ne");
}
