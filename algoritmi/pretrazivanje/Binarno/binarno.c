#include <stdio.h>
#include <time.h>
#include "niz.h"

/*
 * REKURZIVNA IMPLEMENTACIJA
 *Ovakav nacin pretrazivanja vec sortiran niz. Njegova vremenska kompleksnost je O(log2N).
da * */
int binarno_pretrazivanje_rek(int d,int g,int niz[],int el){
    if(d <= g){
        /*
         * Odredjivanje pozicije srednjeg elementa
         * */
        int s = (d + g)/2;
        /*
         *Provera da li je srednji element niza upravo trazeni element
         * */
        if(niz[s] == el)
            return s;
        /*
         *Ukoliko je srednji element veci od trazenog onda znamo
         da se nalazi u levoj polovini niza. U suprotnom je u desnoj
         polovini niza. Rekurzivno pozivamo metodu da promenjenom donjom,
         odnosno gornjom granicom.
         * */
        if(niz[s] > el)
            return binarno_pretrazivanje_rek(d,s-1,niz,el);
        else
            return binarno_pretrazivanje_rek(s+1,g,niz,el);
    }
    /*
     Ukoliko dospemo do ovog dela znaci da je donja granica presla
     gornju granicu tj. da nismo nasli element u nizu.
     * */
    return -1;
}

/*
 *ITERATIVNA IMPLEMENTACIJA
 U ovom primeru necemo prosledjivati broj elemenata niza, jer se
 podrazumeva da onaj ko koristi algoritam, unosi validne podatke tj.
 da se za gornju granicu unosi broj elemenata - 1.
 * */
int binarno_pretrazivanje(int d, int g, int niz[],int el){
    /*
     *Potrebno je proveriti uslov da li je donja granica manja ili jednaka od gornje
     * */
    while(d <= g){
        int s = (d + g)/2;
        if(niz[s] == el)
            return s;
        if(niz[s] > el)
            g = s-1;
        else
            d = s+1;
    }
    /*
     *Ukoliko ne nadjemo element vracamo -1
     * */
    return -1;
}
int main(void){
    int niz[10] = {1,3,7,11,12,23,33,34,51,88};
    /*
     *Kako ne bi doslo do pogresnog unosa broja elemenata iskoristimo funkciju sizeof()
     * */
    int n = sizeof(niz) / sizeof(niz[0]);
    ispis(niz,n);
    printf("\n");
    int pozicija = binarno_pretrazivanje_rek(0,n-1,niz,23);
    printf("Rekurzivni algoritam\n");
    printf("Pozicija broja 23: %d\n",pozicija);

    clock_t start = clock();
    pozicija = binarno_pretrazivanje_rek(0,n-1,niz,50);
    clock_t end = clock();

    printf("Pozicija broja 50: %d\n", pozicija);
    printf("Vreme izvrsavanja je %fs\n",(double)(end - start)/CLOCKS_PER_SEC);

    printf("Iterativni algoritam\n");
    start = clock();
    pozicija = binarno_pretrazivanje(0,n-1,niz,50);
    end = clock();
    printf("Pozicija broja 50: %d\n",pozicija);
    printf("Vreme izvrsavanja je %fs\n",(double)(end - start)/CLOCKS_PER_SEC);

    pozicija = binarno_pretrazivanje(0,n-1,niz,100);
    printf("Pozicija broja 100: %d\n",pozicija);
    return 0;
}
