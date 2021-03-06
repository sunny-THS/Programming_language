#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {
  int chon;
  int soBai = 35;

  do {
    //in list bai tap
    printf("\n\t\t\t\t\tDanh sach bai tap chuong 3\n\n");
    for (int i = 1; i <= soBai; i++) {
      printf("%2d. Bai %d\t", i, i);
      if (i%3==0) {
        printf("\n");
      }
    }
    printf("0. Thoat chuong trinh");
    //lua cho bai tap
    printf("\nChon bai: ");
    scanf("%d", &chon);

    //xu ly chon bai
    switch (chon) {
      case 1: {
        int a;
        printf("Kiem tra so nguyen duong hay nguyen am\n\n");
        printf("Nhap so nguyen: ");
        scanf("%d", &a);
        if(a>0){
          printf("Do la so nguyen duong");
        }else{
          printf("Do la so nguyen am");
        }
        printf("\n");
        break;
      }
      case 2: {
        int a, b, max;
        printf("Tim Max-Min\n\n" );
        printf("Nhap 2 so: ");
        scanf("%d%d", &a, &b);
        if(a>b){
          max = a;
        }else{
          max = b;
        }
        printf("So lon nhat: %d\n", max);
        break;
      }
      case 3: {
        int a;
        printf("Xet tinh chan le\n\n");
        printf("Nhap mot so nguyen: ");
        scanf("%d", &a);
        if(a%2==0){
          printf("Do la so chan");
        }else{
          printf("Do la so le");
        }
        printf("\n");
        break;
      }
      case 4: {
        int a, b;
        printf("So sanh 2 so a va b \n\n");
        printf("Nhap 2 so: ");
        scanf("%d%d", &a, &b);
        if(a!=b){
          if(a>b){
            printf("%d > %d", a, b);
          }else{
            printf("%d < %d", a, b);
          }
        }else{
          printf("%d = %d", a, b);
        }
        printf("\n");
        break;
      }
      case 5: {
        int a, b;
        printf("Xac dinh boi so\n\n");
        printf("Nhap a, b: ");
        scanf("%d%d", &a, &b);
        if(a%b==0){
          printf("a la boi cua b");
        }
        else{
          printf("a khong phai la boi cua b");
        }
        printf("\n");
        break;
      }
      case 6: {
        const float S = 0.03;
        int donGia, soLuong, thanhTien;
        float giamGia=0, tongTien;
        printf("Nhap don gia va so luong: ");
        scanf("%d%d", &donGia, &soLuong);
        thanhTien= donGia * soLuong;
        if(thanhTien>100){
          giamGia= thanhTien * S;
        }
        tongTien= thanhTien - giamGia;
        printf("Tong tien: %.2f", tongTien);
        printf("\n");
        break;
      }
      case 7: {
        int a, b;
        float x;
        printf("Giai phuong trinh bac nhat\n\n");
        printf("Nhap a, b: ");
        scanf("%d%d", &a, &b);
        if(a!=0){
          x = -(float)b/a;
          printf("Nghiem cua pt bac nhat la: %.2f", x);
        }else{
          printf("Phuong trinh vo nghiem");
        }
        printf("\n");
        break;
      }
      case 8: {
        int a, b, c;
        float x1, x2, delta;
        printf("Giai phuong trinh bac hai\n\n");
        printf("Nhap a, b, c: ");
        scanf("%d%d%d", &a, &b, &c);
        delta = pow(b,2.0) - 4*a*c;
        if(delta!=0){
          if(delta>0){
            x1= (-b+sqrt(delta))/(2*a);
            x2= (-b-sqrt(delta))/(2*a);
            printf("Pt co 2 nghiem:\nx= %.2f\nx= %.2f", x1, x2);
          }else{
            printf("Pt trinh vo nghiem");
          }
        }else{
          x1= -(float)b/(2*a);
          printf("Pt co 1 nghiem duy nhat: %.2f", x1);
        }
        printf("\n");
        break;
      }
      case 9: {
        int thang;
        printf("Xac dinh so ngay trong thang\n\n");
        printf("Nhap 1 thang: ");
        scanf("%d", &thang);
        switch(thang){
          case 1:
          case 3:
          case 5:
          case 7:
          case 8:
          case 10:
          case 12: printf("Co 31 ngay"); break;
          case 4:
          case 6:
          case 9:
          case 11: printf("Co 30 ngay"); break;
          case 2: printf("Co 28 hoac 29 ngay"); break;
          default: printf("Invalid"); break;
        }
        printf("\n");
        break;
      }
      case 10: {
        int nam;
        printf("Kiem tra nam nhuan hay khong\n\n");
        printf("Nhap 1 nam: ");
        scanf("%d", &nam);
        if(nam%400==0 || nam%4==0 && nam%100!=0){
          printf("Do la nam nhuan");
        }else{
          printf("Do khong phai la nam nhuan");
        }
        printf("\n");
        break;
      }
      case 11: {
        const float PI = 3.14;
        int a, cd, cr, canh, bk;
        float dt, cv;
        printf("============================\n");
        printf("1. Hinh chu nhat\n");
        printf("2. Hinh vuong\n");
        printf("3. Hinh tron\n");
        printf("Chon hinh can tinh: ");
        scanf("%d", &a);
        switch(a){
          case 1:{
            printf("Nhap lan luot chieu dai va chieu rong: ");
            scanf("%d%d", &cd, &cr);
            cv= (cd+cr)*2;
            dt= cd*cr;
            printf("Chu vi: %.0f\nDien tich: %.0f", cv, dt);
            break;
          }
          case 2: {
            printf("Nhap canh hinh vuong: ");
            scanf("%d", &canh);
            cv= canh*4;
            dt= canh*canh;
            printf("Chu vi: %.0f\nDien tich: %.0f", cv, dt);
            break;
          }
          case 3: {
            printf("Nhap ban kinh: ");
            scanf("%d", &bk);
            cv= 2*PI*bk;
            dt= PI*bk*bk;
            printf("Chu vi: %.2f\nDien tich: %.2f", cv, dt);
            break;
          }
          default: printf("Invalid"); break;
        }
        printf("\n");
        break;
      }
      case 12: {
        int a, b, n;
        printf("Nhap 2 so nguyen: ");
        scanf("%d%d", &a, &b);
        printf("\n1. Phep cong");
        printf("\n2. Phep tru");
        printf("\n3. Phep nhan");
        printf("\n4. Phep chia\n");
        printf("Chon: ");
        scanf("%d", &n);
        switch(n){
          case 1: printf("%d + %d = %d", a, b, a+b); break;
          case 2: printf("%d - %d = %d", a, b, a-b); break;
          case 3: printf("%d * %d = %d", a, b, a*b); break;
          case 4: printf("%d / %d = %.2f", a, b, (float)a/b); break;
        }
        printf("\n");
        break;
      }
      case 13: {
        printf("In tu 1 den 100\n\n");
        for(int i=1;i<=100;i++){
          printf("%d ",i);
        }
        printf("\n");
        break;
      }
      case 14: {
        int tong = 0;
        for(int i=1;i<=20;i++){
          tong+=i;
        }
        printf("1 + 2 + 3 + ... + 20 = %d", tong);
        printf("\n");
        break;
      }
      case 15: {
        int kq = 1;
        int n;
        printf("Nhap so n(n>0): ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          kq*=i;
        }
        printf("1*2*3*...*%d = %d", n, kq);
        printf("\n");
        break;
      }
      case 16: {
        int tong=0;
        for(int i=2;i<=20;i+=2){
          tong+=i;
        }
        printf("2+4+6+8+...+20= %d", tong);
        printf("\n");
        break;
      }
      case 17: {
        int n, sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          sum+=i*(i+1);
        }
        printf("1*2 + 2*3 + 3*4+...+%d*(%d+1)= %d", n, n, sum);
        printf("\n");
        break;
      }
      case 18: {
        int n;
        float sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          sum+=(float)1/(n*(n+1)*(n+2));
        }
        printf("Tong: %f", sum);
        printf("\n");
        break;
      }
      case 19: {
        int n,sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          sum+=i*i;
        }
        printf("1^2 + 2^2 + 3^2+...+%d^2= %d", n, sum);
        printf("\n");
        break;
      }
      case 20: {
        int n,sum=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
          for(int j=1;j<=i;j++){
            sum+=j;
          }
        }
        printf("1 + 1+2 + 1+2+3+...+ (1+2+..n)= %d", sum);
        printf("\n");
        break;
      }
      case 21: {
        printf("In bang cuu chuong\n\n");
        for(int j=1;j<=10;j++){
          for(int i=1;i<=9;i++){
            printf("%d*%d=%d\t", i, j, i*j);
          }
          printf("\n");
        }
        printf("\n");
        break;
      }
      case 22: {
        int n;
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("Bang cuu chuong so %d", n);
        for(int i=1;i<=10;i++){
          printf("\n%d*%d=%d", n, i, i*n);
        }
        printf("\n");
        break;
      }
      case 23: {
        int cd, cr;
        printf("Ve hinh chu nhat\n\n");
        printf("Nhap chieu dai va chieu rong: ");
        scanf("%d%d", &cd, &cr);
        for(int i=0;i<cr;i++){
          for(int j=0;j<cd;j++){
            printf("* ");
          }
          printf("\n");
        }
        printf("\n");
        break;
      }
      case 24: {
        int n;
        printf("Tim so le nho hon n\n\n");
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("So le nho hon n: ");
        for(int i=1;i<n;i+=2){
          printf("%d ",i);
        }
        printf("\n");
        break;
      }
      case 25: {
        int sum=0,n;
        printf("Nhap n: ");
        scanf("%d", &n);
        for(int i=0;i<n;i+=2){
          sum+=i;
        }
        printf("Tong so chan nho hon n: %d", sum);
        printf("\n");
        break;
      }
      case 26: {
        int n;
        printf("Nhap n: ");
        scanf("%d", &n);
        printf("Boi so cua 5 nho hon n:");
        for(int i=1; i<n; i++){
          if(i%5==0){
            printf("%d ",i);
          }
        }
        printf("\n");
        break;
      }
      case 27: {
        int a, b, c, d, uc,bc;
        printf("Nhap 2 so nguyen: ");
        scanf("%d%d", &a, &b);
        if (a==b) {
          uc = a;
        }else{
          c=a; //thay the cho a va b
          d=b;
          while (c!=d) {
            if (c>d) {
              c-=d;
            }else{
              d-=c;
            }
          }
          uc = c;
        }
        bc = (float)(a*b)/uc;
        printf("UCLN(%d,%d)=%2d\nBCNN(%d,%d)=%2d\n", a,b,uc,a,b,bc);
        break;
      }
      case 28: {
        const int GMC = 10;
        const int GDC = 24;
        const int MG = 17;	 // moc phan biet 2 menh  gia tien phai tra
        const int GT = 20000; //gia truoc 17h
        const long GS = 45000; // gia sau 17h
        int gioVao, phutVao, gioRa, phutRa, gioTrc, phutTrc, gioSau, phutSau, tongH, tongM;
        long tongTien;

        printf("Tinh tien karaoke\n");
        do {
	        printf("=============================\n");
          printf("Gio vao(gom ca gio va phut cach nhau boi dau cach): \n");
          scanf("%d%d", &gioVao, &phutVao);
          printf("Gio ra(gom ca gio va phut cach nhau boi dau cach): \n");
          scanf("%d%d", &gioRa, &phutRa);
        } while(gioVao>24 || gioVao<1 || phutVao>59 || phutVao<0 || gioRa<1 || gioRa>24 || phutRa<0 || phutRa>59); //dieu kien nhap
		//Xu li tinh tien
        if (gioVao<GMC || gioVao>GDC) {
          printf("Quan da dong cua\n");
          break;
        }else{
          if (gioVao<MG && phutVao>=0 && gioRa>=MG && phutRa > 0){
            //Xu ly thoi gian truoc 17h
            gioTrc = (MG-1) - gioVao;
            phutTrc = 60- phutVao;
            //Xu ly thoi gian sau 17h
            gioSau = gioRa - MG;
            phutSau = phutRa;
            tongTien = (gioTrc+(float)phutTrc/60)*GT + (gioSau+(float)phutSau/60)*GS;
          }else{
            if (phutRa<phutVao) {
              phutRa+=60;
              gioRa-=1;
            }
            tongH = gioRa-gioVao;
            tongM = phutRa-phutVao;
            if (gioVao>=GMC && gioRa<=MG) {
              tongTien = (tongH + (float)tongM/60)*GT;
            }else{
              tongTien = (tongH + (float)tongM/60)*GS;
            }
          }
        }
        printf("Tien phai tra: %ld\n", tongTien);
        break;
      }
      case 29: {
        int tienDienThangTrc, tienDienThangSau, mucDienSD, tien;
      	printf("Nhap tien dien thang truoc: ");
      	scanf("%d", &tienDienThangTrc);
      	printf("Nhap tien dien thang sau: ");
      	scanf("%d", &tienDienThangSau);
      	mucDienSD = tienDienThangSau - tienDienThangTrc;
        if (mucDienSD>300){
      		tien = 100*5 + 50*7 + 50*10 + 100/15 + (mucDienSD-300)*20;
      	}else if(mucDienSD>=201&&mucDienSD<=300){
      		tien = 100*5 + 50*7 + 50*10 + (mucDienSD-200)*15;
      	}else if(mucDienSD>=151&&mucDienSD<=200){
      		tien = 100*5 + 50*7 + (mucDienSD-150)*10;
      	}else if(mucDienSD>=101&&mucDienSD<=150){
      		tien = 100*5 + (mucDienSD-100)*7;
      	}else if(mucDienSD>=1&&mucDienSD<=100){
      		tien = mucDienSD *5;
      	}
      	printf("tien: %d\n",tien);
        break;
      }
      case 30: {
        int n;
        printf("Nhap n: ");
        scanf("%d", &n);
        if (n>5) {
          n+=2;
        }else{
          n=0;
        }
        printf("n= %d\n", n);
        break;
      }
      case 31: {
        int m, n, dem=0;
        printf("Nhap n, m: ");
        scanf("%d%d", &n, &m);
        if (m>n) {
          for (int i = n; i <= m; i++) {
            if (i%2==0 && i!=0) {
              dem++;
            }
          }
          printf("So luong so chan trong [%d, %d]: %d\n", n, m, dem);
        }else{
          for (int i = m; i <= n; i++) {
            if (i%2==0 && i!=0) {
              dem++;
            }
          }
          printf("So luong so chan trong [%d, %d]: %d\n", m, n, dem);
        }
        break;
      }
      case 32: {
        int n, tong=0, i=0;
        printf("Nhap n: ");
        scanf("%d", &n);
        while (i<n) {
          tong+=i++;
        }
        printf("Tong cac so tu nhien nho hon n: %d\n", tong);
        break;
      }
      case 33: {
        int dv, c, t;
        printf("Cac so co 3 chu so doi mot khac nhau:\n");
        for (int i = 100; i < 1000; i++) {
          t= i/100;
          c= i/10 - t*10;
          dv= i%10;
          if (t!=c && t!=dv && c!=dv) {
            printf("%2d ", i);
          }
        }
        printf("\n");
        break;
      }
      case 34: {
        int dem=0, max, n, num, tong=0, a[10], kiemTra;
        printf("Nhap N: ");
        scanf("%d", &n);
        max= n%10; //dinh max la so hang dv
        while (n!=0) {
          num = n%10;
          a[dem++] = num;// gan tung gia tri cho mang

          if (max<num) {
            max = num;
          }//tim max
          tong+=num;//tinh tong
          n/=10;
        }
        printf("\n");
        //kiem tra so phai la so khac nhau doi mot
        for (int i = 0; i < dem-1; i++) {
          for (int j=i+1; j < dem; j++) {
            if (a[i]!=a[j]) {
              kiemTra = 1; //true
            }else{
              kiemTra = 0; //false
              break;
            }
          }
          if (kiemTra==0) {
            break;
          }
        }
        if (kiemTra==1) {
          printf("N la so cac chu so khac nhau doi mot\n");
        }else{
          printf("N khong phai la so cac chu so khac nhau doi mot\n");
        }

        printf("So hang dau tien cua N: %d\n", a[dem-1]);
        printf("Tong cac chu so cua N: %d\n", tong);
        printf("Chu so lon nhat trong k chu so do: %d\n", max);
        printf("So chu so cua N: %d\n", dem);
        break;
      }
      case 35: {
        int a, b, c;
        printf("Nhap vao ba canh cua tam giac: ");
        scanf("%d%d%d", &a, &b, &c);
        if (a<b+c && b<a+c && c<a+b) {
          if (a==b || b==c || a==c) {
            if (a==b&&b==c) {
              printf("Day la tam giac deu\n");
            }else if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a) {
              printf("Day la tam giac vuong can\n");
            }else{
              printf("Day la tam giac can\n");
            }
          }else if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==b*b+a*a) {
            printf("Day la tam giac vuong\n");
          }else if (a*a>b*b+c*c || b*b>a*a+c*c || c*c>a*a+b*b) {
            printf("Day la tam giac tu\n");
          }else {
            printf("Day la tam giac thuong\n");
          }
        }else printf("Khong phai 3 canh tam giac\n");
        break;
      }
      case 0: printf("Bam nut bat ki de thoat\n"); break;
      default: printf("Khong co du lieu\n"); break;
    }
	printf("==========================================================================================================");
  } while(chon!=0);

  getch();
}
