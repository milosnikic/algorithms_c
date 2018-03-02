#include <stdio.h>
#include "niz.h"
int binarno_pretrazivanje_mod(int niz[], int n, int el){
    /*
    Umesto gornje i donje granice koristimo centar(srednji element) i
    poluprecnik.
    */
    int s,p;
    s = (n-1)/2;
    p = n;
    do{
      p = p / 2;
      if(niz[s] == el)
        return s;
      if(niz[s] > el)
        s -= (p+1)/2;
      else
        s += (p+1)/2;
    }while(p);
    return -1;
}



int main(void){
  int niz[8] = {1,3,6,10,11,23,51,66};
  //Koristimo promenljivu n za broj elemenata
  int n = sizeof(niz) / sizeof(niz[0]);
  ispis(niz,n);
  printf("\nPozicija elementa 10 u nizu:%d\n", binarno_pretrazivanje_mod(niz,n,10));
  printf("Pozicija elementa 9 u nizu:%d\n", binarno_pretrazivanje_mod(niz,n,9));
  printf("Pozicija elementa 66 u nizu:%d\n", binarno_pretrazivanje_mod(niz,n,66));
  return 0;
}
