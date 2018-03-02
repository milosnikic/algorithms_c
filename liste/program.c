#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct cvor{
    int pdt;
    struct cvor * sledeci;
}cvor_t;

//Dodavanje na pocetak
void dodajElement(cvor_t ** glava,int v){
    cvor_t * novi_element = malloc(sizeof(cvor_t));
    
    novi_element->pdt = v;
    novi_element->sledeci = *glava;

    *glava = novi_element;
}

//Ispisivanje liste
void ispis(cvor_t * glava){
    if(glava == NULL){
        printf("Lista je prazna.");
        return;
    }
    cvor_t * tekuci = glava;
    while(tekuci != NULL){
        printf("%d ->",tekuci->pdt);
        tekuci = tekuci->sledeci;
    }
}

//Brisanje sa odredjene pozicije
bool obrisi_i(cvor_t ** glava, int i){
    cvor_t * tekuci = *glava;
    int p = 0;
    while(tekuci != NULL){
        if(p == i-1){
            cvor_t * brisanje = tekuci->sledeci;
            tekuci->sledeci = tekuci->sledeci->sledeci;
            free(brisanje);
            return true;
        }
        p++;
        tekuci = tekuci->sledeci;
    }
    return false;
}


int main(void){
    cvor_t * glava = NULL;
    printf("Lista neparnih elemenata\n");    
    dodajElement(&glava,3);
    dodajElement(&glava,5);
    dodajElement(&glava,7);
    dodajElement(&glava,9);
    dodajElement(&glava,11);
    dodajElement(&glava,13);
    ispis(glava);
    printf("\nIzbrisi element sa pozicije 3.\n");
    const char * tekst = obrisi_i(&glava,3) ? "Element je obrisan\n" : "Element nije obrisan\n";
    printf("%s", tekst);
    ispis(glava);
return 0;
}
