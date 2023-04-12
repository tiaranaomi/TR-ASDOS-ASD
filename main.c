#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

struct obat{
    int kode;
    char nama[30];
    int stok;
    float harga;
}o[50];

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void login()
{
    char username[10];
    char password[10];
    int i;
    for(i=1; i <= 15; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254); // Kode tampilan kotak
        Sleep (5);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (300);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (50);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (300);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 17
    {
        printf("%c", 254);
        Sleep (10);
    }
    printf("\n);
    gotoxy(50,7);

    printf("Harap Login Terlebih Dahulu\n");
    gotoxy(40,9);
    printf("Masukkan username : ");
    scanf("%s", username);
    gotoxy(40,10);
    printf("Masukkan password : ");
           
    for(i=0;i<6;i++);
    {
        password[i]=getch();
        printf("*");
    }
    printf("\n");
    gotoxy(35,12);
    for(i=1; i <= 15; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254); // Kode tampilan kotak
        Sleep (10);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (10);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (10);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 15
    {
        printf("%c", 254);
        Sleep (10);
    }
    for(i=1; i <= 10; i++) // Perulangan kotak loading 17
    {
        printf("%c", 254);
        Sleep (10);
    }      
           
    password[i]='\0';

    if(strcmp(username,"admin")==0 && strcmp(password,"cantik")==0)
    {
        printf("\n");
        gotoxy(55,14);
        printf("~~LOGIN BERHASIL~~");
        getch();
        system("cls");
    }
    else
    {
        printf("\n");
        gotoxy(57,14);
        printf("LOGIN GAGAL! SILAKAN COBA LAGI");
        getch();
        system("cls");
        login();
    }
}

void cari_obat()
{
int kode,i;
printf("Masukkan kode obat yang dicari: ");
scanf("%d",&kode);
for(i=0;i<50;i++)
{
if(o[i].kode==kode)
{
printf("Nama obat: %s\n",o[i].nama);
printf("Stok obat: %d\n",o[i].stok);
printf("Harga obat: %f\n",o[i].harga);
break;
}
}
if(i==50)
printf("Maaf, obat tidak ditemukan");
}

void lihat_obat()
{
int i;
printf("Daftar obat dalam apotek:\n");
for(i=0;i<50;i++)
{
if(o[i].kode!=0)
{
printf("Kode obat: %d\n",o[i].kode);
printf("Nama obat: %s\n",o[i].nama);
printf("Stok obat: %d\n",o[i].stok);
printf("Harga obat: %f\n",o[i].harga);
}
}
}

void ubah_obat()
{
int kode,i,new_stok;
float new_harga;
printf("Masukkan kode obat yang ingin diubah: ");
scanf("%d",&kode);
for(i=0;i<50;i++)
{
if(o[i].kode==kode)
{
printf("Masukkan stok obat yang baru: ");
scanf("%d",&new_stok);
printf("Masukkan harga obat yang baru: ");
scanf("%f",&new_harga);
o[i].stok=new_stok;
o[i].harga=new_harga;
printf("Data obat berhasil diubah\n");
break;
}
}
if(i==50)
printf("Maaf, obat tidak ditemukan");
}

void hapus_obat()
{
int kode,i;
printf("Masukkan kode obat yang ingin dihapus: ");
scanf("%d",&kode);
for(i=0;i<50;i++)
{
if(o[i].kode==kode)
{
o[i].kode=0;
o[i].stok=0;
o[i].harga=0;
strcpy(o[i].nama,"");
printf("Data obat berhasil dihapus\n");
break;
}
}
if(i==50)
printf("Maaf, obat tidak ditemukan");
}

void urutkan_obat()
{
int i,j,kode;
char nama[30];
int stok;
float harga;
for(i=0;i<50;i++)
{
for(j=i+1;j<50;j++)
{
if(o[i].kode>o[j].kode)
{
kode=o[i].kode;
o[i].kode=o[j].kode;
o[j].kode=kode;

strcpy(nama,o[i].nama);
strcpy(o[i].nama,o[j].nama);
strcpy(o[j].nama,nama);

stok=o[i].stok;
o[i].stok=o[j].stok;
o[j].stok=stok;

harga=o[i].harga;
o[i].harga=o[j].harga;
o[j].harga=harga;
}
}
}
printf("Data obat berhasil diurutkan berdasarkan kode obat\n");
}

void tambah_obat()
{
int i,kode,stok;
float harga;
char nama[30];
for(i=0;i<50;i++)
{
if(o[i].kode==0)
{

printf("Masukkan kode obat: ");
scanf("%d",&kode);
printf("Masukkan nama obat: ");
scanf("%s",nama);
printf("Masukkan stok obat: ");
scanf("%d",&stok);
printf("Masukkan harga obat: ");
scanf("%f",&harga);
o[i].kode=kode;
strcpy(o[i].nama,nama);
o[i].stok=stok;
o[i].harga=harga;
printf("Data obat berhasil ditambahkan\n");
break;
}
}
if(i==50)
printf("Maaf, sudah mencapai batas maksimal obat yang tersimpan");
}

int main()
{
int choice;
login(); //memanggil fungsi login
do
{
system("cls"); //membersihkan layar
printf("\n\n\t\t\t\tMENU UTAMA\n");
printf("\t\t1. Cari data obat\n");
printf("\t\t2. Lihat data obat\n");
printf("\t\t3. Ubah data obat\n");
printf("\t\t4. Hapus data obat\n");
printf("\t\t5. Urutkan data obat\n");
printf("\t\t6. Tambah data obat\n");
printf("\t\t7. Keluar\n");
printf("\n\t\tMasukkan pilihan: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
cari_obat();
getch();
break;
case 2:
lihat_obat();
getch();
break;
case 3:
ubah_obat();
getch();
break;
case 4:
hapus_obat();
getch();
break;
case 5:
urutkan_obat();
getch();
break;
case 6:
tambah_obat();
getch();
break;
case 7:
printf("\n\nTerima kasih telah menggunakan program ini!");
getch();
break;
default:
printf("\n\nMaaf, pilihan yang anda masukkan salah. Silakan coba lagi.");
getch();
break;
}
}while(choice!=7);
return 0;
}
