#include <stdio.h>
#include <stdlib.h>

/*
Definisanje strukture binarnog stabla pretrage
Cvor stabla sadrzi podataka(tipa int) i pokazivac na levo i desno dete.
Odlika binarnog stabla pretrage jeste da su vrednosti svih cvorova u levom
podstablu manji od cvora koji se posmatra, a u desnom podstablu svi su veci od
vrednosti podatka cvora koji se posmatra
*/

typedef struct cvor * POKAZIVAC;

typedef struct cvor{
  int pdt;
  POKAZIVAC levo, desno;
}CVOR;

POKAZIVAC kreiraj_cvor(int podatak){
  /*
  Kreiranje pokazivaca na novi cvor i podesavanje njegovih vrednosti
  Novi cvor uvek dodajemo kao list.(levo i desno dete pokazuju na NULL)
  */
  POKAZIVAC novi = (POKAZIVAC) malloc(sizeof(CVOR));
  novi->pdt = podatak;
  novi->levo = NULL;
  novi->desno = NULL;
  return novi;
}
/*
Ubacivanje novog elementa u binarno stablo pretrage
*/
POKAZIVAC ubaci(POKAZIVAC koren, int podatak){
  if(koren == NULL){
    return kreiraj_cvor(podatak);
  }
  if(koren->pdt > podatak){
    koren->levo = ubaci(koren->levo,podatak);
  }else{
    koren->desno = ubaci(koren->desno,podatak);
  }
  return koren;
}
/*
Prefiksni obilazak stabla. Prvo ispisvanje korena, obilazak levog podstabla, pa
desnog podstabla.
*/
void prefiksno(POKAZIVAC cvor){
  if(cvor == NULL)
    return;
  printf("%d ", cvor->pdt);
  prefiksno(cvor->levo);
  prefiksno(cvor->desno);
}
/*
Infiskni obilazak stabla. Prvo obilazak levog podstabla, pa ispisivanje korena,
zatim obilazak desnog podstabla.
*/
void infiksno(POKAZIVAC cvor){
  if(cvor == NULL)
    return;
  infiksno(cvor->levo);
  printf("%d ", cvor->pdt);
  infiksno(cvor->desno);
}
/*
Postfiksni obilazak stabla. Prvo se obilazi levo podstablo, zatim desno podsta-
blo pa se onda ispisuje koren.
*/
void postfiksno(POKAZIVAC cvor){
  if(cvor == NULL)
    return;
  postfiksno(cvor->levo);
  postfiksno(cvor->desno);
  printf("%d ", cvor->pdt);
}

/*
Vraca veci od dva elementa
*/
int max(int a, int b){
  return (a > b) ? a : b;
}

/*
Dubina stabla
*/
int dubina(POKAZIVAC cvor){
  if(cvor == NULL){
    return 0;
  }
  return 1 + max(dubina(cvor->levo),dubina(cvor->desno));
}


int main(void) {
  POKAZIVAC koren = NULL;
  koren = ubaci(koren,50);
  ubaci(koren,30);
  ubaci(koren,20);
  ubaci(koren,60);
  ubaci(koren,70);
  ubaci(koren,35);
  ubaci(koren,40);
  // printf("%d",koren->levo->pdt);
  printf("PREFIKSNO: ");
  prefiksno(koren);
  printf("\n");
  printf("INFIKSNO: ");
  infiksno(koren);
  printf("\n");
  printf("POSTFIKSNO: ");
  postfiksno(koren);
  printf("\n");
  printf("Dubina stabla: %d",dubina(koren));
  return 0;
}
