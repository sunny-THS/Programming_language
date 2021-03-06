#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define YEARNOW 2019
#define MAX 20

struct Date
{
	int ngay;
	int thang;
	int nam;
};
struct SinhVien
{
	char mssv[7];
	char hoten[15];
	char diaChi[15];
	Date ngaySinh;
	char nganhHoc[10];
	float dtb;
};
void docFile(SinhVien * sv, int &n);
void xuatThongTin(SinhVien sv);
void xuatDSThongTin(SinhVien * sv, int n);
char * TinhDiemChu(SinhVien sv);
char * XepLoai(SinhVien sv);
bool XuatSVCNTT(SinhVien sv);
void XuatDSSVCNTT(SinhVien * sv, int n);
int demSoSVTren22(SinhVien * sv, int n);
SinhVien TimSV_DTBMAX(SinhVien * sv, int n);
template <typename ItemType>
void Swap(ItemType &a, ItemType &b);
void sortDescending_WithDTB(SinhVien *sv, int n);
void sortDescending_WithKhoa(SinhVien *sv, int n);
void DSSinhVienQueTPHCM(SinhVien *sv, int n);
void ThongKeSinhVienGioi(SinhVien * sv, int n, char * khoa);
void ThongKeSinhVienTheoXL(SinhVien * sv, int n, char * xl);
int Tim_MSSV(SinhVien *sv, int n, char * khoa, char *mssv);
int demSoNganhHoc(SinhVien *sv, int n);
int main()
{
	SinhVien sv[MAX];
	int n;
	docFile(sv, n);
	xuatDSThongTin(sv, n);
	XuatDSSVCNTT(sv, n);
	printf("\nDs sinh vien tren 22: %d", demSoSVTren22(sv, n));
	DSSinhVienQueTPHCM(sv, n);
	printf("\nSinh vien co diem tb cao nhat\n");
	xuatThongTin(TimSV_DTBMAX(sv, n));
	printf("\nThong sinh vien gioi\n");
	printf("\tKhoa CNTT:\n");
	ThongKeSinhVienGioi(sv, n, "cntt");
	printf("\tKhoa CNTP:\n");
	ThongKeSinhVienGioi(sv, n, "cntp");
	printf("\nTim mssv(012015)\n");
	int t = Tim_MSSV(sv, n, "cntt", "012015");
	if (t!=-1)
	{
		xuatThongTin(sv[t]);
	}else printf("Khong tim thay\n");
	printf("\nDem so nganh hoc cua sinh vien\n");
	t = demSoNganhHoc(sv, n);
	if (t!=-1)
	{
		printf("%d nganh hoc\n", t);
	}else printf("Khong tim thay\n");
	printf("\nThong sinh vien theo tung nhom xep loai\n");
	printf("\tGioi:\n");
	ThongKeSinhVienTheoXL(sv, n, "Gioi");
	printf("\tKha:\n");
	ThongKeSinhVienTheoXL(sv, n, "Kha");
	printf("\tTrung binh:\n");
	ThongKeSinhVienTheoXL(sv, n, "Trung binh");
	printf("\tTrung binh yeu:\n");
	ThongKeSinhVienTheoXL(sv, n, "Trung binh yeu");
	printf("\tKem:\n");
	ThongKeSinhVienTheoXL(sv, n, "Kem");
	getch();
	return 1;
}
void docFile(SinhVien * sv, int &n)
{
	FILE *f;
	char date[40];
	char tmp[2];
	if ((f = fopen("input.txt", "r")) == NULL)
	{
		printf("ERROR");
		exit(1);
	}
	fscanf(f, "%d", &n);
	for (size_t i = 0; i < n; i++)
	{
		fscanf(f, "%s", &sv[i].mssv);
		fscanf(f, "%s", &sv[i].hoten);
		fscanf(f, "%d", &sv[i].ngaySinh.ngay);
		fscanf(f, "%c", &tmp);
		fscanf(f, "%d", &sv[i].ngaySinh.thang);
		fscanf(f, "%c", &tmp);
		fscanf(f, "%d", &sv[i].ngaySinh.nam);
		fscanf(f, "%s", &sv[i].diaChi);
		fscanf(f, "%s", &sv[i].nganhHoc);
		fscanf(f, "%f", &sv[i].dtb);
	}
	fclose(f);
}
void xuatThongTin(SinhVien sv)
{
	printf("%s\t-- %s\t-- %d/%d/%d\t-- %s\t-- %s\t-- %.1f\t-- ", sv.mssv, sv.hoten, sv.ngaySinh.ngay, sv.ngaySinh.thang, sv.ngaySinh.nam, sv.diaChi, sv.nganhHoc, sv.dtb);
	printf("%s\t-- ", TinhDiemChu(sv));
	printf("%s\n", XepLoai(sv));
}
void xuatDSThongTin(SinhVien * sv, int n)
{
	printf("Danh Sinh vien\n");
	for (size_t i = 0; i < n; i++)
	{
		xuatThongTin(sv[i]);
	}
}
char * TinhDiemChu(SinhVien sv)
{
	if (sv.dtb>=8.5) return "A";
	else if (sv.dtb >= 8) return "B+";
	else if (sv.dtb >= 7) return "B";
	else if (sv.dtb >= 6.5) return "C+";
	else if (sv.dtb >= 5.5) return "C";
	else if (sv.dtb >= 5) return "D+";
	else if (sv.dtb >= 4) return "D";
	else return "F";
}
char * XepLoai(SinhVien sv)
{
	if (sv.dtb>=8.5) return "Gioi";
	else if (sv.dtb >= 7) return "Kha";
	else if (sv.dtb >= 5.5) return "Trung Binh";
	else if (sv.dtb >= 4) return "Trung Binh Yeu";
	else return "Kem";
}
bool XuatSVCNTT(SinhVien sv)
{
	if (strcmpi(sv.nganhHoc, "CNTT") == 0) return true;
	return false;
}
void XuatDSSVCNTT(SinhVien * sv, int n)
{
	printf("\nDs sinh vien cntt\n");
	for (size_t i = 0; i < n; i++)
	{
		if (XuatSVCNTT(sv[i])) xuatThongTin(sv[i]);
	}
}
int demSoSVTren22(SinhVien * sv, int n)
{
	int dem = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (YEARNOW - sv[i].ngaySinh.nam>22)
		{
			dem++;
		}
	}
	return dem;
}
// ________  _________  ___      ___ ________
//|\   __  \|\___   ___\\  \    /  /|\   ___  \
//\ \  \|\ /\|___ \  \_\ \  \  /  / | \  \\ \  \
// \ \   __  \   \ \  \ \ \  \/  / / \ \  \\ \  \
//  \ \  \|\  \   \ \  \ \ \    / /   \ \  \\ \  \
//   \ \_______\   \ \__\ \ \__/ /     \ \__\\ \__\
//    \|_______|    \|__|  \|__|/       \|__| \|__|


void DSSinhVienQueTPHCM(SinhVien *sv, int n)
{
	printf("\n\nDs sinh vien que TPHCM\n");
	for (size_t i = 0; i < n; i++)
	{
		if (strstr(sv[i].diaChi, "TPHCM")!=NULL) xuatThongTin(sv[i]);
	}
}
SinhVien TimSV_DTBMAX(SinhVien * sv, int n)
{
	sortDescending_WithDTB(sv, n);
	return sv[0];
}
void sortDescending_WithDTB(SinhVien *sv, int n)
{
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			if (sv[i].dtb<sv[j].dtb)
			{
				Swap(sv[i], sv[j]);
			}
		}
	}
}
void sortDescending_WithKhoa(SinhVien *sv, int n)
{
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			if (strcmpi(sv[i].nganhHoc, sv[j].nganhHoc)==1)
			{
				Swap(sv[i], sv[j]);
			}
		}
	}
}
template <typename ItemType>
void Swap(ItemType &a, ItemType &b)
{
	ItemType t = a;
	a = b;
	b = t;
}
void ThongKeSinhVienGioi(SinhVien * sv, int n, char * khoa)
{
	bool isempty = true;
	for (size_t i = 0; i < n; i++)
	{
		if (strcmpi(XepLoai(sv[i]), "Gioi") == 0 && strcmpi(sv[i].nganhHoc, khoa) == 0)
		{
			xuatThongTin(sv[i]);
			isempty = false;
		}
	}
	if (isempty)
	{
		printf("Khong co sinh vien nao\n");
	}
}
int Tim_MSSV(SinhVien *sv, int n, char * khoa, char *mssv)
{
	for (size_t i = 0; i < n; i++) {
		if (strcmpi(sv[i].nganhHoc, khoa) == 0 && strcmpi(mssv, sv[i].mssv) == 0) {
			return i;
		}
	}
	return -1;
}
int demSoNganhHoc(SinhVien *sv, int n)
{
	if(n<1) return -1;
	sortDescending_WithKhoa(sv, n);

	int d = 1;
	for (size_t i = 0; i < n-1; i++) {
		if (strcmpi(sv[i].nganhHoc, sv[i+1].nganhHoc)!=0) {
			d++;
		}
	}
	return d;
}
void ThongKeSinhVienTheoXL(SinhVien * sv, int n, char * xl)
{
	bool isempty = true;
	for (size_t i = 0; i < n; i++)
	{
		if (strcmpi(XepLoai(sv[i]), xl) == 0)
		{
			xuatThongTin(sv[i]);
			isempty = false;
		}
	}
	if (isempty)
	{
		printf("Khong co sinh vien nao\n");
	}
}
