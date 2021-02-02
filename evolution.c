#include <stdio.h>
#include <stdlib.h>


int intorno(int i, int j, char **P){
    return P[i-1][j-1]+P[i-1][j+1]+P[i+1][j-1]+P[i+1][j+1]+P[i][j-1]+P[i][j+1]+P[i+1][j]+P[i-1][j];
}

int main() {
    int N, M, K;

    scanf("%d %d %d\n", &N, &M, &K);

    char **G = (char **)malloc(N * sizeof(char *));
    for(int i=0; i<N; i++) {
        G[i] = (char *)malloc(M * sizeof(char));
    }

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            scanf("%c", &G[i][j]);
        scanf("\n");
    }

    char **P = (char **)malloc((N+2) * sizeof(char *));
    for(int i=0; i<N+2; i++) {
        P[i] = (char *)malloc((M+2) * sizeof(char));
        for(int j=0;j<M+2;j++)
            P[i][j]=0;
    }

    for(int round=0;round<K;round++){
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++){
                if(G[i][j]!='.') P[i+1][j+1]=1;
                else P[i+1][j+1]=0;
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++){
                int r=intorno(i+1,j+1,P);
                if(r>4&&G[i][j]=='.') G[i][j]='+';
                else if(r>4&&G[i][j]=='+') G[i][j]='*';
                else if(r<4&&G[i][j]=='+') G[i][j]='.';
                else if(r>4&&G[i][j]=='*') G[i][j]='+';
                else if(r<4&&G[i][j]=='*') G[i][j]='.';
            }
        }
    }
    


    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++)
            printf("%c", G[i][j]);
        printf("\n");
    }

    return 0;
}
