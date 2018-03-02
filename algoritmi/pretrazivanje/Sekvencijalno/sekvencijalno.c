#include<stdio.h>

int sekvencijalno_pretrazivanje(int n, int el, int niz[]){
    int i;
    i = 0;
    while(i < n){
        if(niz[i] == el)
            return i;
        i++;
    }
    return -1;
}
/*
Metod za optimizaciju sekvencijalnog pretrazivanja jeste izbaciti proveru uslova
da li je i prevazislo velicinu niza. Umesto toga mozemo prosiriti "laznim" eleme
ntom niz tako sto cemo trazeni element dodati na kraj niza, iterirati dok ne
naidjemo na element i zatim proveriti index dobijeni. Ukoliko je manji od dimenzije
niza znaci da je trazeni element u nizu, u suprotnom nije.
*/
int sekvencijalno_pretrazivanje_opt(int n, int el, int niz[]){
  int i = 0;
  niz[n] = el;
  while(niz[i] != el) i++;
  if(i < n)
    return i;
  return -1;
}

void ispis_niza(int niz[],int n){
  int i = 0;
  printf("[");
  while(i < n){
    printf("%d\t",niz[i]);
    i++;
  }
  printf("]\n");
}

int main(void){
    int niz[5] = {1,3,5,7,8};

    /*
    Primer sekvencijalnog pretrazivanja
    */
    printf("SEKVENCIJALNO PRETRAZIVANJE SA USLOVOM ZA IZLASKA IZ PETLJE");
    printf("Da li se broj 5 nalazi u nizu?\n");
    ispis_niza(niz,5);
    printf("%s",sekvencijalno_pretrazivanje_opt(5,5,niz) != -1 ? "Nalazi se\n" : "Ne nalazi se\n");
    printf("Da li se broj 3 nalazi u nizu?\n");
    ispis_niza(niz,5);
    printf("%s",sekvencijalno_pretrazivanje_opt(5,3,niz) != -1 ? "Nalazi se\n" : "Ne nalazi se\n");
    printf("Da li se broj 2 nalazi u nizu?\n");
    ispis_niza(niz,5);
    printf("%s",sekvencijalno_pretrazivanje_opt(5,2,niz) != -1 ? "Nalazi se\n" : "Ne nalazi se\n");

    /*
    Primer sekvencijalnog pretrazivanja optimizovanog
    */
    printf("SEKVENCIJALNO PRETRAZIVANJE OPTIMIZOVANO");
    printf("Da li se broj 5 nalazi u nizu?\n");
    ispis_niza(niz,5);
    printf("%s",sekvencijalno_pretrazivanje(5,5,niz) != -1 ? "Nalazi se\n" : "Ne nalazi se\n");
    printf("Da li se broj 3 nalazi u nizu?\n");
    ispis_niza(niz,5);
    printf("%s",sekvencijalno_pretrazivanje(5,3,niz) != -1 ? "Nalazi se\n" : "Ne nalazi se\n");
    printf("Da li se broj 2 nalazi u nizu?\n");
    ispis_niza(niz,5);
    printf("%s",sekvencijalno_pretrazivanje(5,2,niz) != -1 ? "Nalazi se\n" : "Ne nalazi se\n");


    }
