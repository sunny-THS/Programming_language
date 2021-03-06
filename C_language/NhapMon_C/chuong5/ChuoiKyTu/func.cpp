#include<stdio.h>
#include<string.h>
int kiemTraChuoiDoi(char *str);
void xoaPt(char *str, int n, int *len);
void xoaKhoangChanThua(char *str);
void lk_CHAR_inString(char *str);
int demSoTu(char *str);
char *layTenFILE(char *url, char *fName);
int kiemTraHe2(char *str);
int luyThua2(int);
char *chuyenSangHe10(char *str, char *n);
void inTu_lenMax(char *str);
int dem_char_a(char *str, char a);
void inVT_a(char *str, char a);
int kTraChuoiCon(char *a, char *b);

int kTraChuoiCon(char *a, char *b){
	char *c;
	c = strstr(a,b);
	if (c==NULL)
	{
		return 0;
	}
	return 1;
}
char *chuanHoaText(char *a){
  int len = strlen(a);
  if (a[0]>=97&&a[0]<=122){
  	a[0]-=32;
  }
  for (int i = 1; i < len; i++){
  	if (a[i]!=32&&a[i-1]==32&&(a[i]>=65&&a[i]<=90)){
  		continue;
  	}else if (a[i]!=32&&a[i-1]==32&&(a[i]>=97&&a[i]<=122)){
  		a[i]-=32;
  	}else if(a[i]!=32&&!(a[i]>=97&&a[i]<=122)){
  		a[i]+=32;
  	}
  }
  return a;
}

void tachTu(char *a){
  char *token;
  token = strtok(a, " ");
  while (token!=NULL) {
    printf("%s\n", token);
    token = strtok(NULL, " ");
  }
}


int kiemTraChuoiDoi(char *str){
   int len = strlen(str);
   for(int i=0; i<len/2; i++)
      if(str[i]!=str[len-i-1])
         return 0;
   return 1;
}

void xoaPt(char *str, int n, int *len){
   for(int i = n; i<*len-1; i++)
      str[i]=str[i+1];
   *len-=1;
}
void xoaKhoangChanThua(char *str){
   int len = strlen(str);
   //xoa dau chuoi
   while(str[0]==' '){
      xoaPt(str, 0, &len);
   }
   //xoa trong chuoi co 2 khoang chan
   for(int i=0; i<len-1;i++)
      if(str[i]==' '&&str[i+1]==' '){
         xoaPt(str, i, &len);
         i--;
      }
   str[len] = '\0';
}
void lk_CHAR_inString(char *str){
   int len = strlen(str);
   for(int i=0; i<len; i++){
      if(str[0]!=' '){
         char c = str[i];
         if(c!=' ')
            printf("%c", c);
         else if(str[i+1]!=' ')
            printf("\n");
      }else{
         xoaPt(str, i, &len);
         i--;
      }
   }
}
int demSoTu(char *str){
   int dem = 0, len= strlen(str);
   if(str[0]!=' ')
      dem++;
   for(int i=0;i<len-1;i++)
      if(str[i]==' '&&str[i+1]!=' ')
         dem++;
   return dem;
}
char *layTenFILE(char *url, char *fName){
   int i= strlen(url)-1, d=0;
   while(url[i]!='\\')
      i--;
   for(int j=i+1; j<strlen(url);j++)
      fName[d++]=url[j];
   return fName;
}




int kiemTraHe2(char *str){
   int len=strlen(str);
   for(int i=0;i<len;i++)
      if(str[i]!='1'&&str[i]!='0')
         return 0;
   return 1;
}
int luyThua2(int a){
   if(a==1) return 2;
   if (a==0) return 1;
   return 2*luyThua2(a-1);
}
char *chuyenSangHe10(char *str, char *n){
   int len = strlen(str), s=0, d=0;
   for(int i=0; i<len; i++)
     s+=luyThua2(len-i-1)*((int)str[i]-48);
   while(s!=0){
      int a=s%10;
      char c=(char)(a+48);//trong ascii 48 la so 0
      n[d++]=c;
      s/=10;
   }
   if(d==0){
      n[0]='0';
      n[1]='\0';
   }else{
      n[d]='\0';
   }
	//xuat ra roi dung ham strrev de dao lai
   return n;
}
void inTu_lenMax(char *str){
	xoaKhoangChanThua(str);
   int len = strlen(str), d, j, max=0,m,n;
   for(int i=0; i<len; i++){
      if(str[i]!=' '){
         d=1;
         j=i+1;
      }
      while(str[j]!=' '&&j<len){
         d++;
         if(max<d){
            max=d;
            m=i;
            n=j;
         }
         j++;
      }
      i=j;
   }
   for(int i=m;i<=n;i++)
      printf("%c", str[i]);
}
int dem_char_a(char *str, char a){
   int len= strlen(str),d=0;
   for(int i=0; i<len;i++)
      if(str[i]==a)
         d++;
   return d;
}
void inVT_a(char *str, char a){
   int len=strlen(str);
   printf("Vi tri ki tu \"%c\" xuat hien: ",a);
   for(int i=0; i<len; i++)
      if(str[i]==a)
         printf("%d ",i);
}
