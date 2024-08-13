#include<stdio.h>
#include<string.h>

#define M 3
#define L 14

char H[M][L]; /* Hash Table */

int getChar(char ch){
  if ( ch == 'A') return 1;
  else if ( ch == 'C') return 2;
  else if ( ch == 'G') return 3;
  else if ( ch == 'T') return 4;
}

/* convert a string into an integer value */
long long getKey(char str[]){
  long long sum = 0, p = 1, i;
  for ( i = 0; i < strlen(str); i++ ){
    sum += p*(getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key){ return key % M; }
int h2(int key){ return 1 + (key % (M-1)); }

int find(char str[]){

    long long key, i, h;
    key = getKey(str);
    for(i=0;;i++){
        h = (h1(key) + i * h2(key)) % M;
        if(strcmp(H[h], str) == 0) return 1;
        else if(strlen(H[h]) == 0) return 0;
    }
    return 0;
}

int insert(char str[]){
    long long key, i, h;
    key = getKey(str);

    for(i=0;;i++){
        h = (h1(key) + i * h2(key)) % M;
        if(strcmp(H[h], str) == 0) return 1;
        else if(strlen(H[h]) == 0){
            strcpy(H[h], str);
            return 0;
        }
    }
    return 0;
}

int main(){
    for (int i = 0; i < 1000; i++)
    {
        printf("Hello World\n");
    }    
}