#include<stdio.h>
#include<math.h> // pow ve fabs fonksiyonu kulland�m

void  vkiHesaplama(double [], int , double [], int , double *, int , double *);
void  vkisiniflama(double *, int, double*, double*, double*);
void  kiloboyOrt(double [] , int , double [] , int , double , double );
void  yashesaplama(int [] , int , double , double );	
int  yasBuyukKucukhesaplama(int* , int , int * , int *);

int main()
{
double iort, vki, boy_ort, kilo_ort, gencyuzde, yetiskinyuzde; //vki=v�cut kitle indeksi
double diziboy[10], dizikilo[10], indeksdizi[10]; 
double yuzdezayif, yuzdenormal, yuzdekilolu;
int diziyas[10], a[2][5];
int i,s,n,x,y,p,f, grup, sutun, enbuyukuzaklik, enkucukuzaklik;

printf("Spor salonunda olan 2 grupta kad�nlar i�in 1, erkekler i�in 0 giriniz.\n");
for(grup=0; grup<2; grup++){
	printf("%d . grup: \n", grup+1);
	for(sutun=0; sutun<5; sutun++)
	scanf("%d", &a[grup][sutun]);
}
p=0;
for(x=0; x<2; x++){
	for(y=0; y<5; y++)
		sutun[y] = sutun[y] + a[x][y];
	for(y=0; y<sutun; y++){
		p = p + sutun[y];
		}
	}
f= 10-p;
printf("Spor salonunda iki grupta toplam %d say�da kad�n, %d say�da erkek bulunmaktad�r.", p,f);

printf("10 ki�inin s�ras�yla boyunu giriniz (metre olarak): \n");
for(i=0; i<10; i++){
	scanf("%d", &diziboy[i]);
}

printf("10 ki�inin s�ras�yla kilosunu giriniz: \n");
for(s=0; s<10; s++){
	scanf("%d", &dizikilo[s]);
}

printf("10 ki�inin s�ras�yla ya��n� giriniz: \n");
for(n=0; n<10; n++){
	scanf("%d", &diziyas[n]);
}

	vkiHesaplama(diziboy, 10, dizikilo, 10, indeksdizi, 10, &iort);
		for (i=0; i<10; i++){
			printf("%d. ki�inin v�cut kitle indeksi %.2d dir.\n", i+1, indeksdizi[i]);
			while(i == 9){
				printf("Spor salonundaki 10 ki�inin v�cut kitle indeks ortalamalas� %.2d dir.\n", iort);
				i++;
			}
		}
		
	vkisiniflama(indeksdizi, 10, &yuzdezayif, &yuzdenormal, &yuzdekilolu);
		printf("Spor salonuna gelen ki�ilerin y�zde %.2d zay�f , %.2d'si normal kiloda, %.2d'si olmas� gerekenden fazla kilodad�r. \n ", yuzdezayif, yuzdenormal, yuzdekilolu);
	
	kiloboyOrt(diziboy, 10, dizikilo, 10, boy_ort, kilo_ort);
	
	yashesaplama(diziyas, 10, gencyuzde, yetiskinyuzde);
	
	yasBuyukKucukhesaplama(diziyas , 10 , &enbuyukuzaklik, &enkucukuzaklik);
		printf("En b�y�k ya�ta olan ki�i, ya� ortalamas�na %.2d uzakl�ktad�r.\nEn k���k ya�ta olan ki�i, ya� ortalamas�na %.2d uzakl�ktad�r.", enbuyukuzaklik, enkucukuzaklik);

return 0;
}


void  vkiHesaplama(double diziboy[], int m, double dizikilo[] , int l, double *dizi, int k, double *indeksort){
	
	int x,y,z,i;
	z=0;
	
	for(x=0; x<m; x++){
		y= diziboy[x];
		i = pow(y,2);
		*(dizi+x) = dizikilo[x] / i;
	}

	for(y=0; y<k; y++){
		z = z + *(dizi + y);
	}	
	
	z = z / 10;
	*indeksort = z;
}
void  vkisiniflama(double *indeksdizi, int m, double *yuzdezayif, double *yuzdenormal, double *yuzdekilolu){
	
	int x,y,zayif,normal,kilolu;
	zayif = 0;
	normal = 0;
	kilolu = 0;
	for(x=0; x<m; x++){
		while(*(indeksdizi + x) <= 18,5){
			zayif = zayif + 1;
			break;
		}
		if(*(indeksdizi + x) > 18,5){
			if(*(indeksdizi+x) < 24,9){
			normal = normal + 1;
		}
			if(*(indeksdizi+x) >= 24,9){
			kilolu = kilolu + 1;
			}	
		}
	}
	*yuzdezayif = zayif * 10;
	*yuzdenormal = normal * 10;
	*yuzdekilolu = kilolu * 10;
}

void  kiloboyOrt(double diziboy[], int m , double dizikilo[], int l, double boyortalama, double kilortalama){
	
	int x,y;
	boyortalama=0;
	kilortalama=0;
	for(x=0; x<m; x++){
		boyortalama = boyortalama + diziboy[x];
	}
	boyortalama = boyortalama /10;
	printf("Verileri verilen ki�ilerin boylar�n�n ortalamas� %.2d dir.\n", boyortalama);
	
	for(y=0; y<l; y++){
		kilortalama = kilortalama + dizikilo[y];
	}
	kilortalama = kilortalama /10;
	printf("Verileri verilen ki�ilerin kilolar�n�n ortalamas� %.2d dir.\n", kilortalama);
}	

void  yashesaplama(int diziyas[], int m, double gencyuzde, double yetiskinyuzde){
	
	int x, sayi1, sayi2;
	sayi1 = 0;
	sayi2 = 0;
	for(x=0; x<m; x++){
		if( diziyas[x] <30){ //30 ya� alt� gen� say�lm��t�r
			sayi1 = sayi1 + 1;	
		}	
		if( diziyas[x] >= 30){
			sayi2 = sayi2 + 1;
		}
	}
	printf("Spor salonuna gelenlerin %d'si gen�tir, %d'si yeti�kindir.\n", sayi1, sayi2);
	gencyuzde = sayi1 * 10;
	yetiskinyuzde = sayi2 * 10;
	printf("Spor salonuna gelenlerin y�zde %d'si gen�tir, y�zde %d'si yeti�kindir.\n", gencyuzde, yetiskinyuzde);
}

int  yasBuyukKucukhesaplama(int *diziyas , int m , int *enbuyukuzaklik , int *enkucukuzaklik){
	
	int x, y, p, enbuyuk, enkucuk, ortalama;
	double t,z;
	enbuyuk = enkucuk = *diziyas;
	ortalama=0;
	for(x=1; x<m; x++){
		if( *(diziyas + x) > enbuyuk){
			enbuyuk = *(diziyas + x);
		}
		if( *(diziyas + x) < enkucuk){
			enkucuk = *(diziyas + x);
		}
	}
	for(y=0; y<m; y++){
	p = p + *(diziyas + y);
	}
	ortalama = p / 10;
	z = ortalama - enbuyuk;
	*enbuyukuzaklik = fabs(z);
	
	t = ortalama - enkucuk;
	*enkucukuzaklik = fabs(t);	
}
