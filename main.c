#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define DOSYA_YOLU  "kayit.txt"
#define DOSYA_YOLU2 "bolenlineer.txt"
#define DOSYA_YOLU3 "bolenayrik.txt"
#define DOSYA_YOLU4 "katlamalineer.txt"
#define DOSYA_YOLU5 "katlamaayrik.txt"
#define DOSYA_YOLU6 "kareortasilineer.txt"
#define DOSYA_YOLU7 "kareortasiayrik.txt"
//140202073 Aytül Türkseven - 140202005 Furkan Dirik 
struct Ogrenci {
		char Ad[10];
		int  No ;
       	char Soyad[10];
	};
int lineer(int xa) {
	xa=(xa+1)%500 ;
	return xa;
}
int bolenkalanlineer(struct Ogrenci x[500]) {
	 FILE * dosya;
	 struct Ogrenci y[500];
	 int i,c=0;
	 int ADR;
	 for(i=0;i<500;i++) {
	 	y[i].No=0;
	 }
		if ((dosya = fopen(DOSYA_YOLU2, "w")) == NULL) {
			printf("dosya acilamadi!\n");
			exit(1);
		}
	 for(i=0;i<500;i++)  {
	 ADR= x[i].No%500;
	 c++;
     if(y[ADR].No!=0) {
        while(y[ADR].No!=0) {
		c++;
		ADR=lineer(ADR);
		}
	}
	 y[ADR]=x[i];
}
 for(i=0;i<500;i++)
	 fprintf(dosya ,"%d %d %s %s \n" , i , y[i].No ,  y[i].Ad , y[i].Soyad );
fclose(dosya);
printf("1- Bolen Kalan ve Lineer Yoklama (Dosyaya Yerlestirme): %d \n" , c);
return c;
}
int bolenkalanayrik(struct Ogrenci x[500]) {
	 FILE * dosya;
	 struct Ogrenci y[1000];
	 int i,c=0;
	 int ADR;
	 int  a=0;
	 for(i=0;i<1000;i++) {
	 	y[i].No=0;
	 	}
		if ((dosya = fopen(DOSYA_YOLU3, "w")) == NULL) {
			printf("dosya acilamadi!\n");
			exit(1);
		}
	 for(i=0;i<500;i++)  {
	 ADR= x[i].No%500;
	 c++;
     if(y[ADR].No!=0) {
        while(y[ADR].No!=0) {
		   ADR=500+a;
		   a++;
		   c=a+c;
		}
	}
	 y[ADR]=x[i];
}
 for(i=0;i<1000;i++)
 if(y[i].No==0)
	 fprintf(dosya ,"%d 000000000 .......... .......... \n" , i );
	 else
	 fprintf(dosya ,"%d %d %s %s \n" , i , y[i].No ,  y[i].Ad , y[i].Soyad );
 printf("4- Bolen Kalan ve Ayrik Tasma(Dosyaya Yerlestirme): %d \n" , c);
 fclose(dosya);
 return c;
 }
int katlamalineer(struct Ogrenci x[500]){
	FILE * dosya;
	int i,j=0;
	int c=0;
	int basamak[9];
	struct Ogrenci y[500];
	int k1 , k2, k3 , ks ;
    int gecici;
  for(i=0;i<500;i++) {
	 	y[i].No=0;
	 }
		if ((dosya = fopen(DOSYA_YOLU4, "w")) == NULL) {
			printf("dosya acilamadi!\n");
			exit(1);
		}
for(i=0;i<500;i++) {
 gecici = x[i].No;
 j=0;
 while ( gecici > 0 ){
 basamak[j] = gecici % 10;
 gecici /= 10;
 j++;
 }
 k1=basamak[0]+basamak[1]*10+basamak[2]*100;
 k2=basamak[5]+basamak[4]*10+basamak[3]*100;
 k3=basamak[6]+basamak[7]*10+basamak[8]*100;
 ks=k1+k2+k3;
 ks=ks% 500 ;
 c++;
 if(y[ks].No!=0) {
        while(y[ks].No!=0) {
        c++;
		ks=lineer(ks);
		}
	}
	 y[ks]=x[i];
}
 for(i=0;i<500;i++)
	 fprintf(dosya ,"%d %d %s %s \n" , i , y[i].No ,  y[i].Ad , y[i].Soyad );
    fclose(dosya);
printf("2- Katlama ve Lineer Yoklama(Dosyaya Yerlestirme): %d \n" , c);
 return c;
}
int katlamaayrik(struct Ogrenci x[500]) {
	FILE * dosya;
	int i,j=0;
	int a=0 , c=0;
	int basamak[9];
	struct Ogrenci y[1000];
	int k1 , k2, k3 , ks , gecici;
	 for(i=0;i<1000;i++) {
	 	y[i].No=0;
	 	}
		if ((dosya = fopen(DOSYA_YOLU5, "w")) == NULL) {
			printf("dosya acilamadi!\n");
			exit(1);
		}
for(i=0;i<500;i++) {
 gecici = x[i].No;
 j=0;
 while ( gecici > 0 ){
 basamak[j] = gecici % 10;
 gecici /= 10;
 j++;
 }
 k1=basamak[0]+basamak[1]*10+basamak[2]*100;
 k2=basamak[5]+basamak[4]*10+basamak[3]*100;
 k3=basamak[6]+basamak[7]*10+basamak[8]*100;
 ks=k1+k2+k3;
 ks=ks% 500 ;
 c++;
 if(y[ks].No!=0) {
        while(y[ks].No!=0) {
		ks=500+a;
		   a++;
		c=a+c;
		}
	}
	 y[ks]=x[i];
}
 for(i=0;i<1000;i++)
 if(y[i].No==0)
	 fprintf(dosya ,"%d 000000000 .......... .......... \n", i  );
	 else
	 fprintf(dosya ,"%d %d %s %s \n" , i , y[i].No ,  y[i].Ad , y[i].Soyad );
fclose(dosya);
printf("5- Katlama ve Ayrik Tasma (Dosyaya Yerlestirme): %d \n" , c);
return c;
}
int kareortasilineer(struct Ogrenci x[500]) {
		FILE * dosya;
		int i , j, basamak[20];
		int c=0;
		long long int gecici;
		struct Ogrenci y[500];
		int ks;
		if ((dosya = fopen(DOSYA_YOLU6, "w")) == NULL) {
			printf("dosya acilamadi!\n");
			exit(1);
		}
	 for(i=0;i<500;i++) {
	 	y[i].No=0;
	 }
	 for(i=0;i<500;i++) {
  gecici = pow(x[i].No,2);
 j=0;
 while ( gecici > 0 ){
 basamak[j] = gecici % 10;
 gecici /= 10;
 j++;
 }
   ks=basamak[7]+basamak[8]*10+basamak[9]*100;
   ks=ks%500;
    c++;
 if(y[ks].No!=0) {
        while(y[ks].No!=0) {
        c++;
		ks=lineer(ks);
		}
	}
	 y[ks]=x[i];
}
 for(i=0;i<500;i++)
	 fprintf(dosya ,"%d %d %s %s \n" , i , y[i].No ,  y[i].Ad , y[i].Soyad );
    fclose(dosya);
	printf("3- Kare Ortasi ve Lineer Yoklama(Dosyaya Yerlestirme): %d \n" , c);
	    return c;
}
int kareortasiayrik(struct Ogrenci x[500]){
FILE * dosya;
		int i , j, basamak[20];
		int c=0;
		long long int gecici;
		struct Ogrenci y[1000];
		int ks,a=0;
	 for(i=0;i<1000;i++) {
	 	y[i].No=0;
	 	}
		if ((dosya = fopen(DOSYA_YOLU7, "w")) == NULL) {
			printf("dosya acilamadi!\n");
			exit(1);
		}
	 for(i=0;i<500;i++) {
  gecici = pow(x[i].No,2);
 j=0;
 while ( gecici > 0 ){
 basamak[j] = gecici % 10;
 gecici /= 10;
 j++;
 }
   ks=basamak[7]+basamak[8]*10+basamak[9]*100;
   ks=ks%500;
   c++;
 if(y[ks].No!=0) {
        while(y[ks].No!=0) {
			ks=500+a;
		    a++;
		    c=a+c;
		}
	}
	 y[ks]=x[i];
}
  for(i=0;i<1000;i++)
 if(y[i].No==0)
	 fprintf(dosya ,"%d 000000000 .......... .......... \n" , i  );
	 else
	 fprintf(dosya ,"%d %d %s %s \n" , i , y[i].No ,  y[i].Ad , y[i].Soyad );
 fclose(dosya);
 printf("6- Kare Ortasi ve Ayrik Tasma(Dosyaya Yersletirme): %d \n" , c);
return c;
}
 int bolenkalanlineeryoklama(int aranan){
     FILE * dosya;
    int numara;
	char ad[500][10];
	char soyad[500][10];
	int sira;
    int c=0;
     int ara;
    int i=0;
    int b,z,v;
        ara=aranan%500;
        if(ara<=10)
        b=ara*36;
       if(10<ara||ara<=100){
        z=ara-10;
        b=ara*36+z;}
      if(ara>100){
        z=ara-10;
        v=ara-100;
        b=ara*36+z+v;}
if((dosya=fopen(DOSYA_YOLU2 , "r" ))!=NULL){
fseek (dosya, b , SEEK_SET);
    char get[100]= { };
        while(!feof(dosya)){
       fgets(get,100,dosya);
     	sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
        if(aranan==numara){
              if(ara==0)
                return c+1;
    	     fclose(dosya);
     	   return c;
    		}
	c++;
}
fseek (dosya, 0 , SEEK_SET);
c--;
while(!feof(dosya)){
         fgets(get,100,dosya);
              sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
        if(aranan==numara){
        fclose(dosya);
        return c ;
}
c++;
}
    }
 fclose(dosya);
 }
int katlamalineeryoklama(int aranan){
   FILE * dosya;
    int numara;
	char ad[500][10];
	char soyad[500][10];
	int sira;
     int ara,i,a1,a2,a3;
     long long int gecici;
       int c=0;
    int b,z,v;
    int basamak[10];
    gecici = aranan;
 i=0;
 while ( gecici > 0 ){
 basamak[i] = gecici % 10;
 gecici /= 10;
 i++;
 }
    a1=basamak[0]+basamak[1]*10+basamak[2]*100;
    a2=basamak[5]+basamak[4]*10+basamak[3]*100;
    a3=basamak[6]+basamak[7]*10+basamak[8]*100;
        ara=a1+a2+a3;
        ara=ara% 500 ;
        if(ara<=10)
        b=ara*36;
       if(10<ara||ara<=100){
        z=ara-10;
        b=ara*36+z;}
      if(ara>100){
        z=ara-10;
        v=ara-100;
        b=ara*36+z+v;}
if((dosya=fopen(DOSYA_YOLU4 , "r" ))!=NULL){
fseek (dosya, b , SEEK_SET);
char get[100]= { };
i=0;
        while(!feof(dosya)){
         fgets(get,100,dosya);
           sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
        if(aranan==numara){
        fclose(dosya);
        return c ;
}
c++;
}
fseek (dosya, 0 , SEEK_SET);
 if(aranan!=numara){
while(!feof(dosya)){
        fgets(get,100,dosya);
        sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
        if(aranan==numara){
       fclose(dosya);
        return c;
}
c++;
} }
 }
 fclose(dosya);
 }
 int kareortasilineeryoklama(int aranan){
    FILE * dosya;
    int numara;
	char ad[500][10];
	char soyad[500][10];
	int sira;
     int ara,i;
     long long int gecici;
       int c=0;
    int b,z,v;
    int basamak[20];
    gecici = pow(aranan,2);
 i=0;
 while ( gecici > 0 ){
 basamak[i] = gecici % 10;
 gecici /= 10;
 i++;
 }
   ara=basamak[7]+basamak[8]*10+basamak[9]*100;
   ara=ara%500;
        if(ara<=10)
        b=ara*36;
       if(10<ara||ara<=100){
        z=ara-10;
        b=ara*36+z;}
      if(ara>100){
        z=ara-10;
        v=ara-100;
        b=ara*36+z+v;}
  char get[100]= { };
if((dosya=fopen(DOSYA_YOLU6 , "r" ))!=NULL){
fseek (dosya, b , SEEK_SET);
        while(!feof(dosya)){
         fgets(get,100,dosya);
           sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
		c++;
        if(aranan==numara){
    	     fclose(dosya);
     	   return c;
		}
}
fseek (dosya, 0 , SEEK_SET);
while(!feof(dosya)){
         fgets(get,100,dosya);
          	sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
		c++;
        if(aranan==numara){
        fclose(dosya);
        return c;
}
}
 }
 fclose(dosya);
}
int bolenkalanayriktasma(int aranan){
     FILE * dosya;
 int numara;
	char ad[1000][20];
	char soyad[1000][20];
	int sira;
     int ara;
       int c=0;
       int i;
    int b,z,v;
        ara=aranan%500;
        if(ara<10)
        b=ara*36;
       if(10<=ara||ara<100){
        z=ara-10;
        b=ara*36+z;}
      if(ara>=100){
        z=ara-10;
        v=ara-100;
        b=ara*36+z+v;}
 if((dosya=fopen(DOSYA_YOLU3 , "r" ))==NULL){
  printf("dosya acilamadi");
  exit(1);
}
 i=0;
 char get[100]={ };
fseek (dosya, b , SEEK_SET);
        fgets(get,100,dosya);
          	sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
          	//printf("ilk %d %d %s %s\n" , sira , numara, ad[i], soyad[i]);
        if(aranan==numara){
        c++;
        fclose(dosya);
        return c;
		}
fseek (dosya, 18852 , SEEK_SET);
 while(!feof(dosya)){
   c++;
        fgets(get,100,dosya);
          	sscanf(get,"%d %d %s %s" , &sira , &numara , ad[i] , soyad[i]);
          //	printf("%d %d %s %s\n" , sira , numara, ad[i], soyad[i]);
        if(aranan==numara){
        fclose(dosya);
        return c ;
	}
        }
 fclose(dosya);
 }
int katlamaayriktasma(int aranan){
   FILE * dosya;
    int numara;
	char ad[500][10];
	char soyad[500][10];
	int sira;
     int ara,i,a1,a2,a3;
     long long int gecici;
       int c=0;
    int b,z,v;
    int basamak[10];
    gecici = aranan;
 i=0;
 while ( gecici > 0 ){
 basamak[i] = gecici % 10;
 gecici /= 10;
 i++;
 }
    a1=basamak[0]+basamak[1]*10+basamak[2]*100;
    a2=basamak[5]+basamak[4]*10+basamak[3]*100;
    a3=basamak[6]+basamak[7]*10+basamak[8]*100;
        ara=a1+a2+a3;
        ara=ara% 500 ;
        if(ara<10)
        b=ara*36;
       if(10<=ara||ara<100){
        z=ara-10;
        b=ara*36+z;}
      if(ara>=100){
        z=ara-10;
        v=ara-100;
        b=ara*36+z+v;}
	char get[100]={ };
if((dosya=fopen(DOSYA_YOLU5 , "r" ))!=NULL){
fseek (dosya, b , SEEK_SET);
        fgets(get,100,dosya);
           sscanf(get,"%d %d %s %s" , &sira , &numara , ad[0] , soyad[0]);
        //  printf("%d %d %s %s" , sira , numara, ad[i], soyad[i]);
         if(aranan==numara){
         	c++;
         	fclose(dosya);
        return c;
		}
        c++;
fseek (dosya, 18852 , SEEK_SET);
 while(!feof(dosya)){
	c++;
        fgets(get,100,dosya);
          sscanf(get,"%d %d %s %s" , &sira , &numara , ad[0] , soyad[0]);
        if(aranan==numara){
        fclose(dosya);
        return c ;
		}
        }
}
fclose(dosya);
 }
int kareortasiayriktasma(int aranan){
   FILE * dosya;
    int numara;
	char ad[500][10];
	char soyad[500][10];
	int sira;
     int ara,i;
     long long int gecici;
       int c=0;
    int b,z,v;
    int basamak[20];
    gecici = pow(aranan,2);
 i=0;
 while ( gecici > 0 ){
 basamak[i] = gecici % 10;
 gecici /= 10;
 i++;
 }
   ara=basamak[7]+basamak[8]*10+basamak[9]*100;
   ara=ara%500;
        if(ara<10)
        b=ara*36;
       if(10<=ara||ara<100){
        z=ara-10;
        b=ara*36+z;}
      if(ara>=100){
        z=ara-10;
        v=ara-100;
        b=ara*36+z+v;}
        char get[100]={ };
if((dosya=fopen(DOSYA_YOLU7 , "r" ))!=NULL){
fseek (dosya, b , SEEK_SET);
      fgets(get,100,dosya);
          sscanf(get,"%d %d %s %s" , &sira , &numara , ad[0] , soyad[0]);
        if(aranan==numara){
        	c++;
			fclose(dosya);
        	return c;
         }
fseek (dosya, 18852 , SEEK_SET);
if(aranan!=numara){
 while(!feof(dosya)){
 c++;
         fgets(get,100,dosya);
          sscanf(get,"%d %d %s %s" , &sira , &numara , ad[0] , soyad[0]);
        if(aranan==numara){
        	fclose(dosya);
        return c;
		}
        }}
}
fclose(dosya);
 }
int main(int argc, char** argv) {
	FILE * dosya;
		if ((dosya = fopen(DOSYA_YOLU, "w")) == NULL) {
			printf("dosya acilamadi!\n");
			exit(1);
		}
	int a,s,r,r1,r2,r3,i,j;
	struct Ogrenci ogr[500];
	int  dizi[6];
	int numaralar[500];
	char adlar[500][10];
	char soyadlar[500][10];
	srand(time(NULL));
for (i=0;i<500;i++){
			// printf("\n");
			 fprintf(dosya,"\n");
			 r1 = (rand() % 6)*10000000;
			 r2=(rand() %1000)*1000;
			 r3=(rand() %1000);
			 r=100000000+r1+r2+r3;
			 numaralar[i]=r;
			// printf("%d %d  " , i+1,ogr[i].No);
			 fprintf(dosya,"%d %d   ", i , numaralar[i]);
			for (j = 0; j <10 ; j++) {
				a =rand() %25+97;
				adlar[i][j]=a;
				//printf("%c" , ogr[i].Ad[j]);
			    fprintf(dosya,"%c", adlar[i][j]);
		}
	       //	printf("  ");
	       	fprintf(dosya," ");
			for(j=0; j<10 ;j++){
             	s= rand() %25+97;
				soyadlar[i][j]=s;
			//	printf("%c" , ogr[i].Soyad[j]);
				fprintf(dosya,"%c", soyadlar[i][j]);
			}
	  }
	  fclose(dosya);
	  int sirano[500];
	  i=0;
			if((dosya=fopen("kayit.txt" , "r" ))!=NULL){
		while(!feof(dosya)) {
			fscanf(dosya ,"%d %d %s %s" , &sirano[i] , &ogr[i].No , &ogr[i].Ad , &ogr[i].Soyad);
			printf("%d %d %s %s \n" , sirano[i], ogr[i].No , ogr[i].Ad , ogr[i].Soyad);
			i++;
		}
	}
    else {
    	printf("dosya bulunamadi.");
	}
fclose(dosya);
     	for(i=0;i<6;i++)
		 dizi[i]=0;
		   dizi[0]=bolenkalanlineer(ogr);
		   dizi[1]=katlamalineer(ogr) ;
		    dizi[2]=kareortasilineer(ogr);
		    dizi[3]=bolenkalanayrik(ogr);
            dizi[4]=katlamaayrik(ogr);
            dizi[5]=kareortasiayrik(ogr);
		   for(i=0;i<500;i++) {
					dizi[0]+=bolenkalanlineeryoklama(ogr[i].No) ;
		        dizi[1]+=katlamalineeryoklama(ogr[i].No);
		       dizi[2]+=kareortasilineeryoklama(ogr[i].No);
			   dizi[3]+= bolenkalanayriktasma(ogr[i].No);
		    dizi[4]+=katlamaayriktasma(ogr[i].No);
		    dizi[5]+=kareortasiayriktasma(ogr[i].No);
	}
		printf("\n -----TOPLAM MALIYETLER(Dosyaya Yazma + Arama)-----\n");
		for(i=0;i<6;i++) {
          printf("%d - Toplam Maliyet : %d \n" , i+1 , dizi[i]);
     }
  int min_sayi=dizi[0];
  int y=0;
    for(i=0;i<3;i++){
       if(min_sayi>dizi[i]){
            min_sayi=dizi[i];
            y=i;
    }
    }
  printf("--------------------SONUC-------------------------\n");
printf("En az maaliyet = %d\n" , dizi[y] );
printf("                 -En uygun yontem- \n");
    if(y==0) {
      printf("Bolen Kalan ve Lineer Yoklama");
  }
    if(y==1) {
     printf("Katlama ve Lineer Yoklama");
 }
    if(y==2) {
     printf("Kare Ortasi ve Lineer Yoklama");
}
    if(y==3) {
   printf("Bolen Kalan ve Lineer Yoklama");
}
    if(y==4) {
   printf("Katlama ve Ayrik Tasma");
}
    if(y==5) {
   printf("Kare Ortasi ve Ayrik Tasma");
}
return 0;
}
