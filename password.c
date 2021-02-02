#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void solve() {
    bool correct = false;
    char P[10001], H[10001];
    int alfa[26]={0},beta[26]={0};

    scanf("%s", P);
    scanf("%s", H);

    // WRITE YOUR SOLUTION HERE

    int lenP=0,lenH=0;
    do {
      lenH++;
    } while(H[lenH]!='\0');
    do {
      alfa[P[lenP]-'a']++;
      beta[H[lenP]-'a']++;
      lenP++;
    } while(P[lenP]!='\0');

    for(int i=0;i<=lenH-lenP;i++){
      correct=true;
      for(int j=0;j<26;j++){
        if(alfa[j]!=beta[j]) {
          correct=false;
        }
      }
      if(correct) break;
      beta[H[i]-'a']--;
      beta[H[i+lenP]-'a']++;
    }

    printf("%s\n", correct ? "1" : "0");
}

int main() {
  int T;
  scanf("%d", &T);

  for(int i=0; i<T; i++) {
    solve();
  }

  return 0;
}
