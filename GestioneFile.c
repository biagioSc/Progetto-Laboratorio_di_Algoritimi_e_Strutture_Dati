//Gestionefile.c

#include <stdio.h>
#include <string.h>
#include "StruttureAccessorie.h"
#include "GestioneGrafica.h"


void inviaRichiestaIsola(int cittaStart)
{
    FILE *fpIN = fopen("NOTIFICHE.txt","w");
    fprintf(fpIN,"%d \n",cittaStart);
    fclose(fpIN);
    
}
void pulisciFile()
{
    FILE *fpIN = fopen("NOTIFICHE.txt","w");
    fprintf(fpIN,"");
    fclose(fpIN);
}
int isFileEmpty()
{
    FILE *fpOUT = fopen("NOTIFICHE.txt","r");
    if(NULL == fpOUT)
    {
        printf("File vuoto!!!\n");
    }
    if (NULL != fpOUT)
    {
        fseek (fpOUT, 0, SEEK_END);
        int size = ftell(fpOUT);
        if (0 == size)
        {
            printf("File vuoto!!!\n");
            return 1;
            fclose(fpOUT);
        }
    }
    return 0;
    fclose(fpOUT);
}


