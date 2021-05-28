 /*
										Name       : MUHAMMET FATİH KESKİN
										Description: MULLER METHOD - 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>//pow için
#include <complex.h>//kompleks sayılar için
#define f(x) pow(x,4)-3*pow(x,3)+pow(x,2)+x+1
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float complex Px (double complex x){//verilen fonksiyonu tanımlamak
	float complex y=0;//f(x) ilk olarak 0 eşitliği alındı
	y = x*x*x*x-3*x*x*x+x*x+x+1;
	return y;
}

float complex print(){//tablo için oluşturulan standart ve basit bir fonksiyon
	float complex p0=0.5;float complex p1=-0.5;float complex p2=0;//başlangıc degerleri tanımlama

	puts("\n\t\t f(x)=pow(x,4)-3*pow(x,3)+pow(x,2)+x+1");
	printf("\n\t\t\tP0=%.1f~~P1=%.1f~~P2=%.0f\n",creal(p0),creal(p1),creal(p2));//kompleks sayılar oldugu için complex.h sayesinde creal 
 	printf(" i \t\t Pi \t\t\t\t f(Pi) \t\t\t");
 	printf("\n~~~\t~~~~~~~~~~~~~~~~~~~~~~\t\t~~~~~~~~~~~~~~~~~~~~~~~~");}//tablo süsü
 	
float complex iterasyon(){//bu fonksiyonda ise iterasyonları yaptıracagım
	float complex p0=0.5;float complex p1=-0.5;float complex p2=0;//başlangıc degerleri tanımlama
	float complex y,a,c,s,q,w,b,p,h,D,E;//tanımlama hepsi kompleks sayı
	
	float complex h1=p1-p0;//kitapta bulunan muller algoritmasının aynısı 
	float complex h2=p2-p1;//kitapta bulunan muller algoritmasının aynısı 
	float complex s1 = (Px(p1)-Px(p0))/h1;//kitapta bulunan muller algoritmasının aynısı 
	float complex s2 = (Px(p2)-Px(p1))/h2;//kitapta bulunan muller algoritmasının aynısı 
	float complex d = (s2 -s1)/(h2 +h1);//kitapta bulunan muller algoritmasının aynısı 
	
	int i=3;int No=9;//No iterasyon sayısı(tolerans belirlenmediği için tablodaki kadar iterasyon yaptıracagım)

	while (i <= No){//7 iterasyon kadar tekrar edilecek
		
		b = s2 + (h2 * d);//kitapta bulunan muller algoritmasının aynısı 
		
		D = csqrt(b*b-4*Px(p2)*d);//kitapta bulunan muller algoritmasının aynısı 

		if (cabs(b-D)<cabs(b+D)){//kitapta bulunan muller algoritmasının aynısı  fabs yerine complex mutlak değeri cabs
			E = b+D;//kitapta bulunan muller algoritmasının aynısı 
		}
		else {//kitapta bulunan muller algoritmasının aynısı 
			E = b-D;//kitapta bulunan muller algoritmasının aynısı 
		}
		
		h = -2*Px(p2)/E;//kitapta bulunan muller algoritmasının aynısı 
		
		p = h + p2;//kitapta bulunan muller algoritmasının aynısı 
	
		if (cimag(p) != 0){//real ve imajinal kısmı tablo içine yazdırma
			printf(" \n %d\t%f + %fi  \t %f + %fi \n",i,creal(p),cimag(p),creal(Px(p)),cimag(Px(p)));
		}
		else{
			printf(" \n %d\t%f\t\t\t %f\t\t\t\n",i,creal(p),creal(Px(p)));
		}

		p0=p1; //kitapta bulunan muller algoritmasının aynısı
 		p1=p2; //kitapta bulunan muller algoritmasının aynısı
 		p2=p; //kitapta bulunan muller algoritmasının aynısı
 
 		h1=p1-p0; //kitapta bulunan muller algoritmasının aynısı
 		h2=p2-p1; //kitapta bulunan muller algoritmasının aynısı
 
 		s1=(Px(p1)-Px(p0))/h1; //kitapta bulunan muller algoritmasının aynısı
 		s2=(Px(p2)-Px(p1))/h2; //kitapta bulunan muller algoritmasının aynısı
 		d=(s2-s1)/(h2+h1); //kitapta bulunan muller algoritmasının aynısı
 
 		i++; //yeni iterasyona geç
 		}//while döngusu bitişi
	}//iterasyon fonksiyonu bitişi

 
int main(int argc, char *argv[]) {
//	float complex a,b,c,p,h,h1,h2,s1,s2,d,D,E;
	
	float p0=0.5; float p1=-0.5; float p2=0;//verilen başlangıç noktaları
	float complex x;
	
	Px(x);//verilen fonksiyonu çağır
	print();//print fonksiyonu çagır
	iterasyon();//iterasyon fonksiyonunu çağır

////	puts("\n\n\t\tSaygilarimla Muhammet Fatih KESKIN");
	
	return 0;
}
