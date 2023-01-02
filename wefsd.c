#include <stdio.h>
#include <string.h>
#include <stdlib.h> //random fonksiyonu i�in
#include <time.h> //srand fonksiyonu i�in
int main()
{
    char tablo[10][10] =
    {
 		{ '_','_','_','_','_','_','_','_','_','_',},        // Bo� Tablo Olu�turulmas�
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
	for(i=0;i<5;i++) // Elmaslar� ve Muhaf�zlar� Rastgele Yerle�tirmek ��in D�ng�
	{
		elmasOK=0; // Elmas Yerle�tirildi De�eri
		while(!elmasOK) // Elmas Yerle�tirilmedi�i S�rece D�ng� Olacak
		{
			elmasSa=rand()%9; // Elmas Sat�r De�eri Matrise Denk Gelecek �ekilde Ayarland� (0-9)
			elmasSu=rand()%9; // Elmas Sutun De�eri Matrise Denk Gelecek �ekilde Ayarland� (0-9)
			if(tablo[elmasSa][elmasSu]!='E' && tablo[elmasSa][elmasSu]!='O' // Tablonun �lgili �ndisinde
				&& tablo[elmasSa][elmasSu]!='M' )  // Oyuncu ya da Elmas Olup Olmad���n�n Kontrol�
			{
				tablo[elmasSa][elmasSu]='E'; // E�er Tablonun �ndisi Bo�sa O indise Elmas Atamas�
				elmasSatir[i]=elmasSa; elmasSutun[i]=elmasSu; // Elmas �ndislerinin Diziye Aktar�lmas�
				elmasOK=1; // Elmas Yerle�tirildi De�erinin 1 Yap�lmas�
				muhafizOK=0; //Muhaf�z Yerle�tirildi De�erinin 0 yap�lmas�
			}

			while(!muhafizOK) // Muhaf�z Yerle�tirilene Kadar D�ng�
			{
				muhafizSa=elmasSa-1+rand()%3; // Muhaf�z�n Elmas�n Etraf�nda Bir Konuma
				muhafizSu=elmasSu-1+rand()%3; // Yerle�tirilmesi ��in Sat�r ve Sutun De�erleri
				if(tablo[muhafizSa][muhafizSu]!='O' && tablo[muhafizSa][muhafizSu]!='M' && //Rastgele Gelen
					tablo[muhafizSa][muhafizSu]!='E' && muhafizSa>=0 &&  // �ndislerde Bir �ey Olup Olmad���
					muhafizSu>=0 && muhafizSa <=10 && muhafizSu<=10 ) // ve S�n�rlar�n ��inde Olup Olmad���n�n Kontrol�
				{
					tablo[muhafizSa][muhafizSu]='M'; // E�er �lgili �ndis Bo�sa Ve Matris ��indeyse Muhaf�z Yerle�tirilmesi
					muhafizSatir[i]=muhafizSa; muhafizSutun[i]=muhafizSu; // Muhaf�z Dizisinin De�i�kenlerine �lgili �ndisin Atanmas�
					muhafizOK=1; // Muhaf�z Yerle�tirildi De�erinin 1 Yap�lmas�
				}
			}
		}
	}
	char git; // Gidilecek Konum ��in Veri
	while(OyuncuCan>=0)
	{
		for(i=0;i<5;i++)
		{
			if(elmasSatir[i]!=-1 || elmasSutun[i]!=-1)  // Al�nm�� Elmaslar -1 De�eri Al�yor Ve Mesafe
			{                                           // Hesaplamas�na Kat�lm�yor
				printf("%d. Elmasa Uzaklik %d\n",i+1,abs(elmasSatir[i]-oyuncuSa) // Uzakl�klar�n Mutlak
													+abs(elmasSutun[i]-oyuncuSu)); // De�erleri Toplan�yor
			}
		}
		printf("Kalan Can : %d \n",OyuncuCan);
		printf("Puan %d\n\n",puan);
		for(i=0;i<10;i++)    //Tablo Ekrana Yazd�r�l�yor
		{
			for(j=0;j<10;j++)
			{
				if(tablo[i][j]=='O') printf(" O "); // Oyuncunun Oldu�u Konuma O Yaz�l�yor Sadece
				else printf(" _ "); // Muhaf�zlar ve Elmaslar Gizleniyor
			}
			printf("\n");

		}
		printf("Hangi Yone Gitmek Istersiniz? (W,A,S,D) --> ");
		fflush(stdin);
		scanf("%c",&git);
		switch(git) // Girilen Veriye G�re Konum Belirleniyor
		{
			case 'w':  // w tu�una bas�l�rsa
				if(oyuncuSa>0) // Oyuncunun Konumu Kontrol Ediliyor ve S�n�rdan ��erdeyse ��lem Yap�l�yor
				{
					oyuncuSa--; // Oyuncu Sat�r De�eri Eksiliyor ve Konum Yukar� Kay�yor
					if(tablo[oyuncuSa][oyuncuSu]=='M') // Yeni Konumda Muhaf�z Olup Olmad��� Kontrol�
					{
						tablo[oyuncuSa+1][oyuncuSu]='_'; // Konumda Muhaf�z Varsa �nceki Konumu _ Yap�l�yor
						oyuncuSa=2; oyuncuSu=4; OyuncuCan--; // Oyuncu Sat�r Sutun De�erleri S�f�rlan�yor ve Can Kaybediyor
						tablo[2][4]='O'; // Matristeki �lk Yerine G�nderiliyor
						// Muhaf�za Yakaland���yla �lgili Bilgi Veriliyor ve Kalan Can Ekrana Yazd�r�l�yor
						system("cls");
						if(OyuncuCan>=0)
						{
							printf("*** Muhafiza Yakalandiginiz Icin Basa Dondunuz Kalan Caniniz %d ***\n\n",OyuncuCan);
						}
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='E') // Yeni Konumda Elmas Olup Olmad��� Kontrol�
					{
						tablo[oyuncuSa][oyuncuSu]='O'; //Tablodaki Yeni Konumuna O Yaz�l�yor
						tablo[oyuncuSa+1][oyuncuSu]='_'; // ve �nceki Konumu _ oluyor
						puan+=10; // Puan Artt�r�l�yor
						if(puan==50) // Puan 50 Oldu�unda Tablodaki T�m Elmaslar Bitmi� Oluyor
						{
							system("cls");
							printf("Puaniniz %d Tebrikler Kazandiniz",puan); // Ekrana Kazand�n�z Yaz�l�yor ve Program Sonlan�yor
							return 0;
						}
						for(i=0;i<5;i++) //Elmas Dizisi Kontrol Ediliyor
						{
							if(elmasSatir[i]==oyuncuSa && elmasSutun[i]==oyuncuSu) //Oyuncu Konumuna E�it Olan Elmas Bulunuyor
							{
								elmasSatir[i]=-1; elmasSutun[i]=-1; // Elmas De�erleri -1 Yap�l�yor.Bu Mesafe Hesaplamas�na Kat�lmas�n� �nlemek ��in
								tablo[muhafizSatir[i]][muhafizSutun[i]]='_'; //Toplanan Elmasa Ait Muhaf�z�n Tablodaki Yeri _ Yap�l�yor
																			 // ve Elmasla Birlikte Elmas� Koruyan Muhaf�z da Siliniyor
							}
						}
						system("cls");
					}
					else if(tablo[oyuncuSa][oyuncuSu]=='_') // Yeni Konumun Bo� Olup Olmad��� Kontrol Ediliyor
					{
						tablo[oyuncuSa][oyuncuSu]='O'; //Oyuncu Yeni Konumuna Gidiyor ve
						tablo[oyuncuSa+1][oyuncuSu]='_'; // Eski Konumu _ Oluyor
						system("cls");
					}
				}
				else // E�er Oyuncu S�n�rdaysa O Y�nde Gidemeyece�i Ekrana Yazd�r�l�yor
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
  	printf("Oyun Bitti Puaniniz %d Kaybettiniz",puan); // Can� 0'�n alt�na D��t���nde D�ng�den ��k�yor ve Ekrana Kaybettiniz Yaz�yor
	return 0;
	getchar();
}








//Elmaslar Random OlarakAtand�
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
// Elmas ve muhaf�zlar gizlendi
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
  	int m,n,sonuc=0;   //avc�n�n elmaslara olan uzakl���n� buldurdu�u k�s�m
  	for(m=0;m<10;m++)
  	{
    	for(n=0;n<10;n++)
    	{
      		if(dizi[m][n]==elmas)
      	{
        sonuc=dizi[2][4]-dizi[m][n];
    }

    }
    printf("elmasa olan uzakl���n�z: %d\n",dizi[m][n]);
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
