#include <stdio.h>
#include <string.h>
#include <stdlib.h> //random fonksiyonu için
#include <time.h> //srand fonksiyonu için
int main()
{
    char tablo[10][10] =
    {
 		{ '_','_','_','_','_','_','_','_','_','_',},        // Boþ Tablo Oluþturulmasý
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',},
    	{ '_','_','_','_','_','_','_','_','_','_',}
	};

  	srand(time(0));
  	int puan=0;
  	int oyuncuSa=2, oyuncuSu=4;
  	int OyuncuCan=3;
  	int elmasSatir[5];
  	int elmasSutun[5];
  	int muhafizSatir[5];
  	int muhafizSutun[5];
  	tablo[oyuncuSa][oyuncuSu]='O';
   	int i,j;
	int muhafizSa,muhafizSu;
	int elmasSa,elmasSu;
	int elmasOK,muhafizOK;
	for(i=0;i<5;i++) // Elmaslarý ve Muhafýzlarý Rastgele Yerleþtirmek Ýçin Döngü
	{
		elmasOK=0; // Elmas Yerleþtirildi Deðeri
		while(!elmasOK) // Elmas Yerleþtirilmediði Sürece Döngü Olacak
		{
			elmasSa=rand()%9; // Elmas Satýr Deðeri Matrise Denk Gelecek Þekilde Ayarlandý (0-9)
			elmasSu=rand()%9; // Elmas Sutun Deðeri Matrise Denk Gelecek Þekilde Ayarlandý (0-9)
			if(tablo[elmasSa][elmasSu]!='E' && tablo[elmasSa][elmasSu]!='O' // Tablonun Ýlgili Ýndisinde
				&& tablo[elmasSa][elmasSu]!='M' )  // Oyuncu ya da Elmas Olup Olmadýðýnýn Kontrolü
			{
				tablo[elmasSa][elmasSu]='E'; // Eðer Tablonun Ýndisi Boþsa O indise Elmas Atamasý
				elmasSatir[i]=elmasSa; elmasSutun[i]=elmasSu; // Elmas Ýndislerinin Diziye Aktarýlmasý
				elmasOK=1; // Elmas Yerleþtirildi Deðerinin 1 Yapýlmasý
				muhafizOK=0; //Muhafýz Yerleþtirildi Deðerinin 0 yapýlmasý
			}

			while(!muhafizOK) // Muhafýz Yerleþtirilene Kadar Döngü
			{
				muhafizSa=elmasSa-1+rand()%3; // Muhafýzýn Elmasýn Etrafýnda Bir Konuma
				muhafizSu=elmasSu-1+rand()%3; // Yerleþtirilmesi Ýçin Satýr ve Sutun Deðerleri
				if(tablo[muhafizSa][muhafizSu]!='O' && tablo[muhafizSa][muhafizSu]!='M' && //Rastgele Gelen
					tablo[muhafizSa][muhafizSu]!='E' && muhafizSa>=0 &&  // Ýndislerde Bir Þey Olup Olmadýðý
					muhafizSu>=0 && muhafizSa <=10 && muhafizSu<=10 ) // ve Sýnýrlarýn Ýçinde Olup Olmadýðýnýn Kontrolü
				{
					tablo[muhafizSa][muhafizSu]='M'; // Eðer Ýlgili Ýndis Boþsa Ve Matris Ýçindeyse Muhafýz Yerleþtirilmesi
					muhafizSatir[i]=muhafizSa; muhafizSutun[i]=muhafizSu; // Muhafýz Dizisinin Deðiþkenlerine Ýlgili Ýndisin Atanmasý
					muhafizOK=1; // Muhafýz Yerleþtirildi Deðerinin 1 Yapýlmasý
				}
			}
		}
	}
	char git; // Gidilecek Konum Ýçin Veri
	while(OyuncuCan>=0)
	{
		for(i=0;i<5;i++)
		{
			if(elmasSatir[i]!=-1 || elmasSutun[i]!=-1)  // Alýnmýþ Elmaslar -1 Deðeri Alýyor Ve Mesafe
			{                                           // Hesaplamasýna Katýlmýyor
				printf("%d. Elmasa Uzaklik %d\n",i+1,abs(elmasSatir[i]-oyuncuSa) // Uzaklýklarýn Mutlak
													+abs(elmasSutun[i]-oyuncuSu)); // Deðerleri Toplanýyor
			}
		}
		printf("Kalan Can : %d \n",OyuncuCan);
		printf("Puan %d\n\n",puan);
		for(i=0;i<10;i++)    //Tablo Ekrana Yazdýrýlýyor
		{
			for(j=0;j<10;j++)
			{
				if(tablo[i][j]=='O') printf(" O "); // Oyuncunun Olduðu Konuma O Yazýlýyor Sadece
				else printf(" _ "); // Muhafýzlar ve Elmaslar Gizleniyor
			}
			printf("\n");

		}
		printf("Hangi Yone Gitmek Istersiniz? (W,A,S,D) --> ");
		fflush(stdin);
		scanf("%c",&git);
		switch(git) // Girilen Veriye Göre Konum Belirleniyor
		{
			case 'w':  // w tuþuna basýlýrsa
				if(oyuncuSa>0) // Oyuncunun Konumu Kontrol Ediliyor ve Sýnýrdan Ýçerdeyse Ýþlem Yapýlýyor
				{
					oyuncuSa--; // Oyuncu Satýr Deðeri Eksiliyor ve Konum Yukarý Kayýyor
					if(tablo[oyuncuSa][oyuncuSu]=='M') // Yeni Konumda Muhafýz Olup Olmadýðý Kontrolü
					{
						tablo[oyuncuSa+1][oyuncuSu]='_'; // Konumda Muhafýz Varsa Önceki Konumu _ Yapýlýyor
						oyuncuSa=2; oyuncuSu=4; OyuncuCan--; // Oyuncu Satýr Sutun Deðerleri Sýfýrlanýyor ve Can Kaybediyor
						tablo[2][4]='O'; // Matristeki Ýlk Yerine Gönderiliyor
						// Muhafýza Yakalandýðýyla Ýlgili Bilgi Veriliyor ve Kalan Can Ekrana Yazdýrýlýyor
						system("cls");
						if(OyuncuCan>=0)
						{
							printf("*** Muhafiza Yakalandiginiz Icin Basa Dondunuz Kalan Caniniz %d ***\n\n",OyuncuCan);
						}
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='E') // Yeni Konumda Elmas Olup Olmadýðý Kontrolü
					{
						tablo[oyuncuSa][oyuncuSu]='O'; //Tablodaki Yeni Konumuna O Yazýlýyor
						tablo[oyuncuSa+1][oyuncuSu]='_'; // ve Önceki Konumu _ oluyor
						puan+=10; // Puan Arttýrýlýyor
						if(puan==50) // Puan 50 Olduðunda Tablodaki Tüm Elmaslar Bitmiþ Oluyor
						{
							system("cls");
							printf("Puaniniz %d Tebrikler Kazandiniz",puan); // Ekrana Kazandýnýz Yazýlýyor ve Program Sonlanýyor
							return 0;
						}
						for(i=0;i<5;i++) //Elmas Dizisi Kontrol Ediliyor
						{
							if(elmasSatir[i]==oyuncuSa && elmasSutun[i]==oyuncuSu) //Oyuncu Konumuna Eþit Olan Elmas Bulunuyor
							{
								elmasSatir[i]=-1; elmasSutun[i]=-1; // Elmas Deðerleri -1 Yapýlýyor.Bu Mesafe Hesaplamasýna Katýlmasýný Önlemek Ýçin
								tablo[muhafizSatir[i]][muhafizSutun[i]]='_'; //Toplanan Elmasa Ait Muhafýzýn Tablodaki Yeri _ Yapýlýyor
																			 // ve Elmasla Birlikte Elmasý Koruyan Muhafýz da Siliniyor
							}
						}
						system("cls");
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='_') // Yeni Konumun Boþ Olup Olmadýðý Kontrol Ediliyor
					{
						tablo[oyuncuSa][oyuncuSu]='O'; //Oyuncu Yeni Konumuna Gidiyor ve
						tablo[oyuncuSa+1][oyuncuSu]='_'; // Eski Konumu _ Oluyor
						system("cls");
					}
				}
				else // Eðer Oyuncu Sýnýrdaysa O Yönde Gidemeyeceði Ekrana Yazdýrýlýyor
				{
					system("cls");
					printf("*** Yukari Gidemezsiniz ***\n\n");
				}
				break;
			case 'a':
				if(oyuncuSu>0)
				{
					oyuncuSu--;
					if(tablo[oyuncuSa][oyuncuSu]=='M')
					{
						tablo[oyuncuSa][oyuncuSu+1]='_';
						oyuncuSa=2; oyuncuSu=4; OyuncuCan--;
						tablo[2][4]='O';
						system("cls");
						if(OyuncuCan>=0)
						{
							printf("*** Muhafiza Yakalandiginiz Icin Basa Dondunuz Kalan Caniniz %d ***\n\n",OyuncuCan);
						}
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='E')
					{
						tablo[oyuncuSa][oyuncuSu]='O';
						tablo[oyuncuSa][oyuncuSu+1]='_';
						puan+=10;
						if(puan==50)
						{
							system("cls");
							printf("Puaniniz %d Tebrikler Kazandiniz",puan);
							return 0;
						}
						for(i=0;i<5;i++)
						{
							if(elmasSatir[i]==oyuncuSa && elmasSutun[i]==oyuncuSu)
							{
								elmasSatir[i]=-1; elmasSutun[i]=-1;
								tablo[muhafizSatir[i]][muhafizSutun[i]]='_';
								system("cls");
							}
						}
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='_')
					{
						tablo[oyuncuSa][oyuncuSu]='O';
						tablo[oyuncuSa][oyuncuSu+1]='_';
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("*** Sola Gidemezsiniz ***\n\n");
				}
				break;
			case 's':
				if(oyuncuSa<9)
				{
					oyuncuSa++;
					if(tablo[oyuncuSa][oyuncuSu]=='M')
					{
						tablo[oyuncuSa-1][oyuncuSu]='_';
						oyuncuSa=2; oyuncuSu=4; OyuncuCan--;
						tablo[2][4]='O';
						system("cls");
						if(OyuncuCan>=0)
						{
							printf("*** Muhafiza Yakalandiginiz Icin Basa Dondunuz Kalan Caniniz %d ***\n\n",OyuncuCan);
						}
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='E')
					{
						tablo[oyuncuSa][oyuncuSu]='O';
						tablo[oyuncuSa-1][oyuncuSu]='_';
						puan+=10;
						if(puan==50)
						{
							system("cls");
							printf("Puaniniz %d Tebrikler Kazandiniz",puan);
							return 0;
						}
						for(i=0;i<5;i++)
						{
							if(elmasSatir[i]==oyuncuSa && elmasSutun[i]==oyuncuSu)
							{
								elmasSatir[i]=-1; elmasSutun[i]=-1;
								tablo[muhafizSatir[i]][muhafizSutun[i]]='_';
								system("cls");
							}
						}
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='_')
					{
						tablo[oyuncuSa][oyuncuSu]='O';
						tablo[oyuncuSa-1][oyuncuSu]='_';
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("*** Asagi Gidemezsiniz ***\n\n");
				}
				break;
			case 'd':
				if(oyuncuSu<9)
				{
					oyuncuSu++;
					if(tablo[oyuncuSa][oyuncuSu]=='M')
					{
						tablo[oyuncuSa][oyuncuSu-1]='_';
						oyuncuSa=2; oyuncuSu=4; OyuncuCan--;
						tablo[2][4]='O';
						system("cls");
						if(OyuncuCan>=0)
						{
							printf("*** Muhafiza Yakalandiginiz Icin Basa Dondunuz Kalan Caniniz %d ***\n\n",OyuncuCan);
						}

					}
					else if(tablo[oyuncuSa][oyuncuSu]=='E')
					{
						tablo[oyuncuSa][oyuncuSu]='O';
						tablo[oyuncuSa][oyuncuSu-1]='_';
						puan+=10;
						if(puan==50)
						{
							system("cls");
							printf("Puaniniz %d Tebrikler Kazandiniz",puan);
							return 0;
						}
						for(i=0;i<5;i++)
						{
							if(elmasSatir[i]==oyuncuSa && elmasSutun[i]==oyuncuSu)
							{
								elmasSatir[i]=-1; elmasSutun[i]=-1;
								tablo[muhafizSatir[i]][muhafizSutun[i]]='_';
								system("cls");
							}
						}
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='_')
					{
						tablo[oyuncuSa][oyuncuSu]='O';
						tablo[oyuncuSa][oyuncuSu-1]='_';
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("*** Saga Gidemezsiniz***\n\n");
				}
				break;
			default:
				system("cls");
				printf("*** Hatali Tusa Bastiniz ***\n\n");
		}
	}
  	printf("Oyun Bitti Puaniniz %d Kaybettiniz",puan); // Caný 0'ýn altýna Düþtüðünde Döngüden Çýkýyor ve Ekrana Kaybettiniz Yazýyor
	return 0;
	getchar();
}








//Elmaslar Random OlarakAtandý
   	/* back: for(i = 0; i < 5; i++)
    {
        if(dizi[2][4]=='O')
		{
        	int a = (rand() % 8) +1;
        	int b = (rand() % 8) + 1;
    		e = (rand() % (1 +1 + 1)) -1;
    		f = (rand() % (1 +1 + 1)) -1;
    		p = (rand() % (3 + 1));
    		if(e == 0)
    		{
      			e = e + 1;
    		}
      		if(dizi[a+1][b] == 'E')
      		{
        		dizi[a+1][b] = '_';
        		dizi[a+p][b+p] = elmas;
    		}
    		else if(dizi[a-1][b] == 'E')
    		{
      			dizi[a-1][b] = '_';
     			dizi[a+p][b+p] = elmas;
    		}
    		else if(dizi[a][b+1] == 'E')
    		{
      			dizi[a][b+1] = '_';
      			dizi[a+p][b+p] = elmas;
    		}
    		else if(dizi[a][b-1] == 'E')
    		{
      			dizi[a][b-1] = '_';
      			dizi[a+p][b+p] = elmas;
    		}
    		if(dizi[a+ e + 1][b+f] == 'M')
      		{
        		dizi[a+ e + 1][b+f] = '_';
        		dizi[a+p][b+p] = muhafiz;
    		}
    		else if(dizi[a+e-1][b+f] == 'M')
      		{
        		dizi[a+e-1][b+f] = '_';
        		dizi[a+p][b+p] = muhafiz;
    		}
    		else if(dizi[a+e][b+f+1] == 'M')
      		{
        		dizi[a+e][b+f+1] = '_';
        		dizi[a+p][b+p] = muhafiz;
    		}
    		else if(dizi[a+e][b+f-1] == 'M')
      		{
        		dizi[a+e][b+f-1] = '_';
        		dizi[a+p][b+p] = muhafiz;
    		}
    		dizi[a][b] = elmas;
        	dizi[a+e][b+f] = muhafiz;
        }
        else
		{
        	goto back;
        }
  	}*/
       /*
// Elmas ve muhafýzlar gizlendi
  for(int k=0;k<10;k++)
  {
    for(int l=0;l<10;l++)
    {
      if(dizi[k][l]==muhafiz||dizi[k][l]==elmas)
      {
        printf("  _",dizi[k][l]);
      }
      else
      printf("  %c",dizi[k][l]);
    }
    printf("\n");
  }*/

  	/*
	  printf("\n%d",sayac);
  	printf("\n\n");
    for (i = 0; i < 10; ++i)
  	{
        for ( k = 0; k < 10; ++k)
    	{
        	printf("%c     ", dizi[i][k]);
     	}
    	printf("\n\n");
  	}
  	int m,n,sonuc=0;   //avcýnýn elmaslara olan uzaklýðýný buldurduðu kýsým
  	for(m=0;m<10;m++)
  	{
    	for(n=0;n<10;n++)
    	{
      		if(dizi[m][n]==elmas)
      	{
        sonuc=dizi[2][4]-dizi[m][n];
    }

    }
    printf("elmasa olan uzaklýðýnýz: %d\n",dizi[m][n]);
  }
	  */

/*char karakter;
printf("Oyuna Baslamak icin E Tusuna Basiniz\n");
scanf(" %c", &karakter);
*/

  /*
  char cd;
  int hak=0;
printf("Bu harflerden birini giriniz : [A]  [S]  [W]  [D]\n");
  scanf("%c", &cd);
    for(m=0;m<10;m++)
   {
     for(n=0;n<10;n++)
     {
   if(dizi[m][n]==oyuncu){
       switch(cd){
     while(hak>0){
        case 'a':
       dizi[m][n]='_';
      dizi[m][n-1]=oyuncu;
        system("cls");
       break;
        case 's':
       dizi[m][n]='_';
       dizi[++m][n]=oyuncu;
       system("cls");
       break;

       case 'w':

       dizi[m][n]='_';
       dizi[m-1][n]=oyuncu;
       system("cls");
       break;

        case 'd':

         dizi[m][n]='_';
         dizi[m][++n]=oyuncu;
         system("cls");
          break;

       default:
         system("cls");
}
}
  }
   }
}
	for(i=0;i<10;i++)
    {
    	for(j=0;j<10;j++)
      	{
        	printf("  %c",dizi[i][j]);
    	}
		printf("\n");
  	}
  */
