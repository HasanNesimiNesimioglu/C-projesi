#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include<math.h>
using namespace std;

//struct yapýsýna kayýtlar aktarýlýr.
struct ogrenci
{
	int numara;
	char ad[15];
	char soyad[15];
	int ara_sinav;
	int final;
	int sonuc;
	char harf[2];
	
}student[1000];//1000 kayýt alacak þekilde struct student deðiþkeni oluþturuldu.

//Prototip Fonksiyonlar
int ogrenci_sayisi;//öðrenci sayýsý aktarýlýr.
int ana_menu();

int kayit_ekleme();
void dosya_kayit(int );

int dosya_oku();//ogrenci.txt dosyasýndaki öðrenci bilgileri alýnýr.öðrenci sayýsý=>ogrenci_sayisi deðiþkenine aktarýlýr.

int ekrana_sirali_liste_yazdirma();
int ad_sirali_yazdirma();
int numara_sirali_yazdirma();
int sonuc_sirali_yazdirma();

int ortalamaya_gore_liste_yazdirma();
int ort_bul();
int aro,fo,so;//öðrencilerin ortalamalý aktarýlýr.
int ara_sinav_ort_alti();
int ara_sinav_ort_ustu();
int final_sinav_ort_alti();
int final_sinav_ort_ustu();
int sonuc_sinav_ort_alti();
int sonuc_sinav_ort_ustu();


int main()
{
	setlocale(LC_ALL, "Turkish");
	
	ana_menu();//ana menü fonksiyonu açýlýr...
}

int ana_menu()
{
	int tercih;//Kullanýcýnýn yapacaðý tercih okutulur.
	cout << "\n\n----ANA MENÜ----\n\n";
	cout << "1. Kayýt Ekleme\n";
	cout << "2. Ekrana Sýralý Liste Yazdýrma\n";
	cout << "3. Ortalamaya Göre Liste Yazdýrma\n";
	cout << "4. Uygulamadan Çýk\n";
	cout << "=";
	cin >> tercih;
	while (tercih != 1 && tercih != 2 && tercih != 3 && tercih != 4)
	{
		printf("menüdeki numaralardan birini giriniz: ");
		cin >> tercih;
	}
	if (tercih == 1)
	{
		system("cls");kayit_ekleme();
	}
	else if (tercih == 2)
	{
		system("cls");ekrana_sirali_liste_yazdirma();
	}
	else if (tercih == 3)
	{
		system("cls");ortalamaya_gore_liste_yazdirma();
	}
	else if (tercih == 4)
	{
		exit(0);
	}
}

int kayit_ekleme()
{
	int n;
	cout<<"kayýt yapýlacak öðrenci sayýsýný giriniz:";
	cin>>n;
	     
		
		for(int i=0;i<n;i++)  //öðrenci bilgileri alýnýr.
		{
	    cout <<"\n"<<i+1<<".öðrencinin numarasýný giriniz=";
		scanf("%d",&student[i].numara);
		cout <<"\n"<<i+1<<".öðrencinin adýný giriniz=";
		scanf("%s",&student[i].ad);
		cout <<"\n"<<i+1<<".öðrencinin soyadýný giriniz=";
		scanf("%s",&student[i].soyad);
		
		cout <<"\n"<<i+1<<".öðrencinin ara sýnav notunu giriniz=";
		scanf("%d",&student[i].ara_sinav);
		while (student[i].ara_sinav < 0 || student[i].ara_sinav>100)//ara sýnavýn 0-100 arasýnda olmasý saðlanýr.
		{
			cout << "\nara sýnav notu 0-100 arasýnda olmalý tekrar girin:";
			scanf("%d",&student[i].ara_sinav);
		}
		
		cout <<"\n"<<i+1<<".öðrencinin final notunu giriniz=";
		scanf("%d",&student[i].final);
		while (student[i].final < 0 || student[i].final>100)// finalin 0-100 arasýnda olmasý saðlanýr.
		{
			cout <<"\nfinal notu 0-100 arasýnda olmalý tekrar girin:";
			scanf("%d",&student[i].final);
		}
		student[i].sonuc = (student[i].ara_sinav * 0.6) + (student[i].final*0.4);//sonuc hesaplanýr.
		
		//sonuca karþýlýk gelen harf deðerleri hesaplanýr.
		if(student[i].sonuc>=90) 		strcpy(student[i].harf,"AA");
		else if(student[i].sonuc>=80) 	strcpy(student[i].harf,"BA");	
		else if(student[i].sonuc>=70) 	strcpy(student[i].harf,"BB");	
		else if(student[i].sonuc>=60) 	strcpy(student[i].harf,"CB");	
		else if(student[i].sonuc>=50) 	strcpy(student[i].harf,"CC");	
		else if(student[i].sonuc>=40) 	strcpy(student[i].harf,"CD");  
		else if(student[i].sonuc>=30) 	strcpy(student[i].harf,"DD");
		else if(student[i].sonuc>=0)  	strcpy(student[i].harf,"FF");
		
		}
		dosya_kayit(n);//öðrenci kayýtlarý dosya_kayit fonksiyosuna gönderilir.
}
void dosya_kayit(int n)
{
	FILE *pkayit;
	pkayit=fopen("ogrenci.txt","a");
	if(pkayit == NULL)
	{
		printf("dosya açýlamadý program sonlandýrýlýyor.");
		exit(1);
	}
	for(int i=0;i<n;i++)
	{
		fprintf(pkayit,"%d %s %s %d %d %d %s\n",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	fclose(pkayit);
	system("cls");
	cout<<"bilgiler kaydedildi.";
	ana_menu();
}

int dosya_oku()
{
	int i;
	FILE *dosyaoku;
	dosyaoku=fopen("ogrenci.txt","r");
	if(dosyaoku==NULL)
	{
		system("cls");
		cout<<"dosya açýlamadý. Kayýt dosyasýný kontrol edin.";
		cout<<"\ndevam etmek için bir tuþa basýn";
		getch();
		system("cls");
		ana_menu();
	}
	for(i=0; !feof(dosyaoku); i++)//kayýtlý tutulan bütün öðrencilerin bilgileri struct yapýsýna aktarýlýr.
	{  
		  fscanf(dosyaoku,"%d %s %s %d %d %d %s",&student[i].numara,student[i].ad,student[i].soyad,&student[i].ara_sinav,&student[i].final,&student[i].sonuc,student[i].harf);
    }
    ogrenci_sayisi=i-1;
    fclose(dosyaoku);
}


int ekrana_sirali_liste_yazdirma()
{
	dosya_oku();//dosyadan öðrenci bilgileri çaðýrýlýr.
	//kullanýcýya seçenekler sorulur.
	int tercih;
	cout << "\n----Seçenekler----\n";
	cout << "1. Ad-Soyada Göre Sýralý Liste\n";
	cout << "2. Numaraya Göre Sýralý Liste\n";
	cout << "3. Sonuç Puana Göre Sýralý Liste\n";
	cout << "4 .Ana Menüye Dön\n";
	cout << "=";
	cin >> tercih;
	//yanlýþ numara girildiðinde tekrar numara istenilir.
	while (tercih != 1 && tercih != 2 && tercih != 3 && tercih != 4)
	{
		printf("menüdeki numaralardan birini giriniz: ");
		cin >> tercih;
	}
	if (tercih == 1)
	{
		system("cls");ad_sirali_yazdirma();
	}
	else if (tercih == 2)
	{
		system("cls");numara_sirali_yazdirma();
	}
	else if (tercih == 3)
	{
		system("cls");sonuc_sirali_yazdirma();
	}
	else if (tercih == 4)
	{
		system("cls");ana_menu();
	}
	

}

int ad_sirali_yazdirma()
{	//öðrencilerin adlarý a[1001] deðiþkenine aktarýlýr.
	string a[1001];
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		a[i]=student[i].ad;
	}
	//bubble sort ile öðrenciler ada göre sýralanýr.
	for(int i=0;i<ogrenci_sayisi-1;i++)
	{
		for(int j=0;j<ogrenci_sayisi-1;j++)
		{
			if(a[j]>a[j+1])
			{
			a[1000]=a[j];
			a[j]=a[j+1];
			a[j+1]=a[1000];
			student[999]=student[j];
			student[j]=student[j+1];
			student[j+1]=student[999];
			}
		}
		
	}
	printf("  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)//öðrenciler küçükten büyüðe ad sýrasýna göre yazdýrýlýr.
	{
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ekrana_sirali_liste_yazdirma();
	             
}

int numara_sirali_yazdirma(){
	long a[1001];
	//öðrencilerin numaralarý a[1001] deðiþkenine aktarýlýr.
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		a[i]=student[i].numara;
	}
	//bubble sort ile öðrenciler numaraya göre sýralanýr.
	for(int i=0;i<ogrenci_sayisi-1;i++)
	{
		for(int j=0;j<ogrenci_sayisi-1;j++)
		{
			if(a[j]>a[j+1])
			{
			a[1000]=a[j];
			a[j]=a[j+1];
			a[j+1]=a[1000];	
			student[999]=student[j];
			student[j]=student[j+1];
			student[j+1]=student[999];
			}
		}
		
	}
	printf("  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)//öðrenciler küçükten büyüðe numara sýrasýna göre yazdýrýlýr.
	{
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ekrana_sirali_liste_yazdirma();

}
int sonuc_sirali_yazdirma(){
	int a[1001];
	//öðrencilerin sonuç puanlarý a[1001] deðiþkenine aktarýlýr.
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		a[i]=student[i].sonuc;
	}
	//bubble sort ile öðrenciler sonuç puanýna göre sýralanýr.
	for(int i=0;i<ogrenci_sayisi-1;i++)
	{
		for(int j=0;j<ogrenci_sayisi-1;j++)
		{
			if(a[j]>a[j+1])
			{
			a[1000]=a[j];
			a[j]=a[j+1];
			a[j+1]=a[1000];	
			student[999]=student[j];
			student[j]=student[j+1];
			student[j+1]=student[999];
			}
		}
		
	}
	printf("  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)//öðrenciler küçükten büyüðe sonuç puanýna  göre yazdýrýlýr.
	{
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ekrana_sirali_liste_yazdirma();

}

int ortalamaya_gore_liste_yazdirma(){
	
	dosya_oku();//dosyadan öðrenci bilgileri çaðýrýlýr.
	
	int tercih;
	cout << "\n----Seçenekler----\n";
	cout << "1. Ara Sýnava Göre Ortalamanýn Altýnda Olanlarýn Listesi\n";
	cout << "2. Ara Sýnava Göre Ortalamanýn Üstünde Olanlarýn Listesi\n";
	cout << "3. Final Sýnavýna Göre Ortalamanýn Altýnda Olanlarýn Listesi\n";
	cout << "4 .Final Sýnavýna Göre Ortalamanýn Üstünde Olanlarýn Listesi\n";
	cout << "5 .Sonuç Puana Göre Ortalamanýn Altýnda Olanlarýn Listesi\n";
	cout << "6 .Sonuç Puana Göre Ortalamanýn Üstünde Olanlarýn Listesi\n";
	cout << "7 .Ana Menüye Dön\n";
	cout << "=";
	cin >> tercih;
	while (tercih != 1 && tercih != 2 && tercih != 3 && tercih != 4 && tercih != 5 && tercih != 6 && tercih != 7)
	{
		printf("menüdeki numaralardan birini giriniz: ");
		cin >> tercih;
	}
	if (tercih == 1)
	{
		system("cls");ara_sinav_ort_alti();;
	}
	else if (tercih == 2)
	{
		system("cls");ara_sinav_ort_ustu();
	}
	else if (tercih == 3)
	{
		system("cls");final_sinav_ort_alti();
	}
	else if (tercih == 4)
	{
		system("cls");final_sinav_ort_ustu();
	}
	else if (tercih == 5)
	{
		system("cls");sonuc_sinav_ort_alti();
	}
	else if (tercih == 6)
	{
		system("cls");sonuc_sinav_ort_ustu();
	}
	else if (tercih == 7)
	{
		system("cls");ana_menu();
	}
}
int ort_bul()
{	// öðrencilerin ara sýnav,final ve sonuç puanlarýnýn ortalamalarý hesaplanýr.aro,fo,so deðiþkenlerine aktarýlýr.
	int art=0,ft=0,st=0;
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		art=art+student[i].ara_sinav;
		ft=ft+student[i].final;
		st=st+student[i].sonuc;
	}
	aro=art/ogrenci_sayisi;
	fo=ft/ogrenci_sayisi;
	so=st/ogrenci_sayisi;
}
int ara_sinav_ort_alti(){
	ort_bul();
	cout<<"Öðrencilerin Ara Sýnav Ortalamasý:"<<aro<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].ara_sinav<aro)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
	
}
 
int ara_sinav_ort_ustu(){
	ort_bul();
	cout<<"Öðrencilerin Ara Sýnav Ortalamasý:"<<aro<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].ara_sinav>=aro)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();

}
int final_sinav_ort_alti()
{
ort_bul();
	cout<<"Öðrencilerin Final Ortalamasý:"<<fo<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].final<fo)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
}
int final_sinav_ort_ustu(){
	ort_bul();
	cout<<"Öðrencilerin Final Ortalamasý:"<<fo<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].final>=fo)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
}
int sonuc_sinav_ort_alti(){
	ort_bul();
	cout<<"Öðrencilerin Sonuç Ortalamasý:"<<so<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].sonuc<so)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();

}
int sonuc_sinav_ort_ustu(){
	ort_bul();
	cout<<"Öðrencilerin Sonuç Ortalamasý:"<<so<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara Sýnav\tFinal\tSonuç\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].sonuc>=so)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek için bir tuþa basýn";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
}
