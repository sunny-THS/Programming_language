#include<stdio.h>
#include<conio.h>

void main(){
  int n,sum=0;
  printf("Nhap n: ");
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i,j++){
      sum+=j;     
    }
  }
  printf("Tong: %d", sum);
  getch();
}
