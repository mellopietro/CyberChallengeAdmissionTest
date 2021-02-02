#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;

    scanf("%d %d\n", &N, &K);

    int *V = (int *)malloc(N * sizeof(int));

    for(int i=0; i<N; i++)
      scanf("%d", &V[i]);

    int max[K+1];
    int solution = 0;

    int pos=0;

    for(int i=0;i<K+1;i++) max[i]=0;
    

    for(int i=0;i<N;i++){
      if(V[i]>max[0]){
        max[0]=V[i];
        for(int j=0;j<K;j++){
          if(max[j]>max[j+1]){
            int c=max[j];
            max[j]=max[j+1];
            max[j+1]=c;
          } else break;
        }
      }
    }

    for(int i=0;i<K+1;i++) solution += max[i];

    printf("%d\n", solution);

    return 0;
}
