#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    char oku,secim,secim2, ad[100];
    FILE *dosya;
    
    setlocale(LC_ALL,"turkish");
    menu:
    	
    system("cls");
    printf("A)Yeni kay�t yap \nB)Kay�tlar� okut \nC)Program� kapat\n\nSeciminiz nedir: ");
    scanf("%c", &secim); // Bo�luk karakterini al�r, di�er verileri almaz

    secim = toupper(secim);

    switch(secim)
    {
        case 'A':{
        	system("cls");
            printf("�sim soyisim giriniz: "); scanf(" %[^\n]", ad); 
            dosya = fopen("ogr/bilgi.txt", "a"); 
            fprintf(dosya, "%s\n", ad);
            fclose(dosya);
            printf("Menuye geri d�n�ls�n m� (E/H) :");scanf("%s",&secim2);
            secim2 = toupper(secim2);
            if (secim2 == 'H')
            {
            printf("Program kapat�l�yor...");
			exit(0);
            }
            if (secim2 == 'E')
            {
            printf("Menuye d�n�� yap�l�yor...");
            goto menu;
            }
            break;
        }
        case 'B':{
        	system("cls");
            dosya = fopen("ogr/bilgi.txt","r");
            printf("\n******************************************\n");
            do
			{
            oku=getc(dosya);
            printf("%c",oku);
			}
			while (!feof(dosya));
            fclose(dosya);
            printf("\n*****************************************\n\n");
            printf("Menuye geri d�n�ls�n m� (E/H) :");scanf("%s",&secim2);
            secim2 = toupper(secim2);
            if (secim2 == 'H')
            {
            printf("Program kapat�l�yor...");
			exit(0);
            }
            if (secim2 == 'E')
            {
            printf("Menuye d�n�� yap�l�yor...");
            goto menu;
			}
			break;
		}
        case 'C':{
            printf("C se�ildi. ��k�� yap�l�yor.\n");
            exit(0);
            break;
        }
        default:{
        	{
        	system("cls");
            goto menu;
            }
            break;
        }
    }

    goto menu;
}

