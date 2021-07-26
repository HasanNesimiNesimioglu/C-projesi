#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include<math.h>
using namespace std;

//struct yap�s�na kay�tlar aktar�l�r.
struct ogrenci
{
	int numara;
	char ad[15];
	char soyad[15];
	int ara_sinav;
	int final;
	int sonuc;
	char harf[2];
	
}student[1000];//1000 kay�t alacak �ekilde struct student de�i�keni olu�turuldu.

//Prototip Fonksiyonlar
int ogrenci_sayisi;//��renci say�s� aktar�l�r.
int ana_menu();

int kayit_ekleme();
void dosya_kayit(int );

int dosya_oku();//ogrenci.txt dosyas�ndaki ��renci bilgileri al�n�r.��renci say�s�=>ogrenci_sayisi de�i�kenine aktar�l�r.

int ekrana_sirali_liste_yazdirma();
int ad_sirali_yazdirma();
int numara_sirali_yazdirma();
int sonuc_sirali_yazdirma();

int ortalamaya_gore_liste_yazdirma();
int ort_bul();
int aro,fo,so;//��rencilerin ortalamal� aktar�l�r.
int ara_sinav_ort_alti();
int ara_sinav_ort_ustu();
int final_sinav_ort_alti();
int final_sinav_ort_ustu();
int sonuc_sinav_ort_alti();
int sonuc_sinav_ort_ustu();


int main()
{
	setlocale(LC_ALL, "Turkish");
	
	ana_menu();//ana men� fonksiyonu a��l�r...
}

int ana_menu()
{
	int tercih;//Kullan�c�n�n yapaca�� tercih okutulur.
	cout << "\n\n----ANA MEN�----\n\n";
	cout << "1. Kay�t Ekleme\n";
	cout << "2. Ekrana S�ral� Liste Yazd�rma\n";
	cout << "3. Ortalamaya G�re Liste Yazd�rma\n";
	cout << "4. Uygulamadan ��k\n";
	cout << "=";
	cin >> tercih;
	while (tercih != 1 && tercih != 2 && tercih != 3 && tercih != 4)
	{
		printf("men�deki numaralardan birini giriniz: ");
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
	cout<<"kay�t yap�lacak ��renci say�s�n� giriniz:";
	cin>>n;
	     
		
		for(int i=0;i<n;i++)  //��renci bilgileri al�n�r.
		{
	    cout <<"\n"<<i+1<<".��rencinin numaras�n� giriniz=";
		scanf("%d",&student[i].numara);
		cout <<"\n"<<i+1<<".��rencinin ad�n� giriniz=";
		scanf("%s",&student[i].ad);
		cout <<"\n"<<i+1<<".��rencinin soyad�n� giriniz=";
		scanf("%s",&student[i].soyad);
		
		cout <<"\n"<<i+1<<".��rencinin ara s�nav notunu giriniz=";
		scanf("%d",&student[i].ara_sinav);
		while (student[i].ara_sinav < 0 || student[i].ara_sinav>100)//ara s�nav�n 0-100 aras�nda olmas� sa�lan�r.
		{
			cout << "\nara s�nav notu 0-100 aras�nda olmal� tekrar girin:";
			scanf("%d",&student[i].ara_sinav);
		}
		
		cout <<"\n"<<i+1<<".��rencinin final notunu giriniz=";
		scanf("%d",&student[i].final);
		while (student[i].final < 0 || student[i].final>100)// finalin 0-100 aras�nda olmas� sa�lan�r.
		{
			cout <<"\nfinal notu 0-100 aras�nda olmal� tekrar girin:";
			scanf("%d",&student[i].final);
		}
		student[i].sonuc = (student[i].ara_sinav * 0.6) + (student[i].final*0.4);//sonuc hesaplan�r.
		
		//sonuca kar��l�k gelen harf de�erleri hesaplan�r.
		if(student[i].sonuc>=90) 		strcpy(student[i].harf,"AA");
		else if(student[i].sonuc>=80) 	strcpy(student[i].harf,"BA");	
		else if(student[i].sonuc>=70) 	strcpy(student[i].harf,"BB");	
		else if(student[i].sonuc>=60) 	strcpy(student[i].harf,"CB");	
		else if(student[i].sonuc>=50) 	strcpy(student[i].harf,"CC");	
		else if(student[i].sonuc>=40) 	strcpy(student[i].harf,"CD");  
		else if(student[i].sonuc>=30) 	strcpy(student[i].harf,"DD");
		else if(student[i].sonuc>=0)  	strcpy(student[i].harf,"FF");
		
		}
		dosya_kayit(n);//��renci kay�tlar� dosya_kayit fonksiyosuna g�nderilir.
}
void dosya_kayit(int n)
{
	FILE *pkayit;
	pkayit=fopen("ogrenci.txt","a");
	if(pkayit == NULL)
	{
		printf("dosya a��lamad� program sonland�r�l�yor.");
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
		cout<<"dosya a��lamad�. Kay�t dosyas�n� kontrol edin.";
		cout<<"\ndevam etmek i�in bir tu�a bas�n";
		getch();
		system("cls");
		ana_menu();
	}
	for(i=0; !feof(dosyaoku); i++)//kay�tl� tutulan b�t�n ��rencilerin bilgileri struct yap�s�na aktar�l�r.
	{  
		  fscanf(dosyaoku,"%d %s %s %d %d %d %s",&student[i].numara,student[i].ad,student[i].soyad,&student[i].ara_sinav,&student[i].final,&student[i].sonuc,student[i].harf);
    }
    ogrenci_sayisi=i-1;
    fclose(dosyaoku);
}


int ekrana_sirali_liste_yazdirma()
{
	dosya_oku();//dosyadan ��renci bilgileri �a��r�l�r.
	//kullan�c�ya se�enekler sorulur.
	int tercih;
	cout << "\n----Se�enekler----\n";
	cout << "1. Ad-Soyada G�re S�ral� Liste\n";
	cout << "2. Numaraya G�re S�ral� Liste\n";
	cout << "3. Sonu� Puana G�re S�ral� Liste\n";
	cout << "4 .Ana Men�ye D�n\n";
	cout << "=";
	cin >> tercih;
	//yanl�� numara girildi�inde tekrar numara istenilir.
	while (tercih != 1 && tercih != 2 && tercih != 3 && tercih != 4)
	{
		printf("men�deki numaralardan birini giriniz: ");
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
{	//��rencilerin adlar� a[1001] de�i�kenine aktar�l�r.
	string a[1001];
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		a[i]=student[i].ad;
	}
	//bubble sort ile ��renciler ada g�re s�ralan�r.
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
	printf("  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)//��renciler k���kten b�y��e ad s�ras�na g�re yazd�r�l�r.
	{
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ekrana_sirali_liste_yazdirma();
	             
}

int numara_sirali_yazdirma(){
	long a[1001];
	//��rencilerin numaralar� a[1001] de�i�kenine aktar�l�r.
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		a[i]=student[i].numara;
	}
	//bubble sort ile ��renciler numaraya g�re s�ralan�r.
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
	printf("  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)//��renciler k���kten b�y��e numara s�ras�na g�re yazd�r�l�r.
	{
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ekrana_sirali_liste_yazdirma();

}
int sonuc_sirali_yazdirma(){
	int a[1001];
	//��rencilerin sonu� puanlar� a[1001] de�i�kenine aktar�l�r.
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		a[i]=student[i].sonuc;
	}
	//bubble sort ile ��renciler sonu� puan�na g�re s�ralan�r.
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
	printf("  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)//��renciler k���kten b�y��e sonu� puan�na  g�re yazd�r�l�r.
	{
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ekrana_sirali_liste_yazdirma();

}

int ortalamaya_gore_liste_yazdirma(){
	
	dosya_oku();//dosyadan ��renci bilgileri �a��r�l�r.
	
	int tercih;
	cout << "\n----Se�enekler----\n";
	cout << "1. Ara S�nava G�re Ortalaman�n Alt�nda Olanlar�n Listesi\n";
	cout << "2. Ara S�nava G�re Ortalaman�n �st�nde Olanlar�n Listesi\n";
	cout << "3. Final S�nav�na G�re Ortalaman�n Alt�nda Olanlar�n Listesi\n";
	cout << "4 .Final S�nav�na G�re Ortalaman�n �st�nde Olanlar�n Listesi\n";
	cout << "5 .Sonu� Puana G�re Ortalaman�n Alt�nda Olanlar�n Listesi\n";
	cout << "6 .Sonu� Puana G�re Ortalaman�n �st�nde Olanlar�n Listesi\n";
	cout << "7 .Ana Men�ye D�n\n";
	cout << "=";
	cin >> tercih;
	while (tercih != 1 && tercih != 2 && tercih != 3 && tercih != 4 && tercih != 5 && tercih != 6 && tercih != 7)
	{
		printf("men�deki numaralardan birini giriniz: ");
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
{	// ��rencilerin ara s�nav,final ve sonu� puanlar�n�n ortalamalar� hesaplan�r.aro,fo,so de�i�kenlerine aktar�l�r.
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
	cout<<"��rencilerin Ara S�nav Ortalamas�:"<<aro<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].ara_sinav<aro)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
	
}
 
int ara_sinav_ort_ustu(){
	ort_bul();
	cout<<"��rencilerin Ara S�nav Ortalamas�:"<<aro<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].ara_sinav>=aro)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();

}
int final_sinav_ort_alti()
{
ort_bul();
	cout<<"��rencilerin Final Ortalamas�:"<<fo<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].final<fo)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
}
int final_sinav_ort_ustu(){
	ort_bul();
	cout<<"��rencilerin Final Ortalamas�:"<<fo<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].final>=fo)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
}
int sonuc_sinav_ort_alti(){
	ort_bul();
	cout<<"��rencilerin Sonu� Ortalamas�:"<<so<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].sonuc<so)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();

}
int sonuc_sinav_ort_ustu(){
	ort_bul();
	cout<<"��rencilerin Sonu� Ortalamas�:"<<so<<endl;
	printf("\n  Numara\t    Ad \t\t    Soyad   Ara S�nav\tFinal\tSonu�\tHarf\n");
	printf("-----------------------------------------------------------------------------");
	for(int i=0;i<ogrenci_sayisi;i++)
	{
		if(student[i].sonuc>=so)
		printf("\n%9d %15s %15s\t%3d\t%3d\t%3d\t%2s",student[i].numara,student[i].ad,student[i].soyad,student[i].ara_sinav,student[i].final,student[i].sonuc,student[i].harf);
	}
	cout<<"\ndevam etmek i�in bir tu�a bas�n";
	getch();
	system("cls");
	ortalamaya_gore_liste_yazdirma();
}
