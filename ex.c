#include <stdio.h>
int main(){
    int x = 5, y = 10;
    char n[10]="Abc";
    for(;y!=0;y--){
        x++;
    }
    printf("%s holds %d",n,x);
}