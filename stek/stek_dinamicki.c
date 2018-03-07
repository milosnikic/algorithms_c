/*
Stek implementiran dinamicki koristi listu kao strukturu. Svaki novi element je
novi cvor na steku.
*/

#include<stdio.h>
#include<stdlib.h> /*malloc*/
#include<stdbool.h>/*bool tip*/
#include<limits.h>/*INT_MIN,INT_MAX,etc.*/

//Pokazivac na strukturu cvora
typedef struct cvor *POKAZIVAC;
//Struktura cvora liste
typedef struct cvor{
  int pdt;
  POKAZIVAC sledeci;
}CVOR;

//Potpis metoda za stek
POKAZIVAC init(void);
void push(POKAZIVAC *stek, int broj);
int pop(POKAZIVAC *stek);
int top(POKAZIVAC stek);
bool is_empty(POKAZIVAC stek);
void print(POKAZIVAC stek);

/*
**IMPLEMENTACIJA FUNKCIJA I METODA
*/

/*
Metoda za stvaranje steka
*/
POKAZIVAC init(void){
  return NULL;
}

/*
Metoda za ubacivanje novog elementa na stek
*/
void push(POKAZIVAC *stek, int broj){
  POKAZIVAC novi = malloc(sizeof(CVOR));
  novi->pdt = broj;
  novi->sledeci = *stek;
  *stek = novi;
}

/*
Metoda za skidanje elementa sa steka
*/
int pop(POKAZIVAC *stek){
  if(*stek == NULL){
    printf("Stek je prazan\n");
    return INT_MIN;
  }
  POKAZIVAC brisanje = *stek;
  int podatak = brisanje->pdt;
  *stek = (*stek)->sledeci;
  free(brisanje);
  return podatak;
}
/*
Metoda vraca podatak na vrhu steka
*/
int top(POKAZIVAC stek){
  if (is_empty(stek)){
    printf("Stek je prazan\n");
    return INT_MIN;
  }
  return stek->pdt;
}

/*
Metoda vraca true ako je stek prazan, false ako nije
*/
bool is_empty(POKAZIVAC stek){
  return stek == NULL;
}

/*
Ispisivanje sadrzaja steka
*/
void print(POKAZIVAC stek){
    POKAZIVAC pom = stek;
    if(is_empty(stek)){
        printf("Stek je prazan.\n");
        return;
    }
    while(pom != NULL){
      printf("%d\n",pom->pdt);
      pom = pom->sledeci;
    }
}

int main(void) {
  POKAZIVAC stekP = init();
  print(stekP);
  push(&stekP,1);
  push(&stekP,5);
  push(&stekP,3);
  push(&stekP,9);
  print(stekP);
  printf("Vrh steka: %d\n",top(stekP));
  pop(&stekP);
  printf("\n");
  print(stekP);
  printf("Vrh steka: %d\n",top(stekP));
  pop(&stekP);
  printf("\n");
  print(stekP);
  printf("Vrh steka: %d\n",top(stekP));
  printf("Da li je stek prazan: %s\n", (is_empty(stekP))? "Jeste" : "Nije");
  return 0;
}
