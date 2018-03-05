/*
Staticka implementacija steka podrazumeva koriscenje niza za skladistenje.
Karakteristika steka je da se elementi ubacuju i izbacuju sa istog kraja,
na koji pokazuje "stack pointer".
*/

#include<stdio.h>

#define MAXELEMENTS 100

//Stek na koji cemo dodavati elemente tipa int
int stack[MAXELEMENTS];
//Pokazivac na narednu slobodnu poziciju na steku
int stackPointer;

/*
Metoda koja element stavlja na stek
*/
void push(int el){
  if(stackPointer < 100){
    stack[stackPointer++] = el;
  }else{
    printf("GRESKA: Stek je pun.\n");
  }
}

/*
Metoda koja element skida sa steka
*/
int pop(void){
    if(stackPointer > 0){
      return stack[--stackPointer];
    }else{
      printf("GRESKA: Stek je prazan.\n");
    }
}

/*
Metoda koja vraca poslednji element sa steka
*/
int top(void){
  if(stackPointer > 0){
    return stack[stackPointer-1];
  }else{
    printf("GRESKA: Stek je prazan.\n");
  }
}

/*
Metoda koja ispisuje elemente na steku
*/
void ispis(){
  int i = 0;
  for(i;i < stackPointer;i++){
    printf("%d\t",stack[i]);
  }
}


int main(void) {
  push(1);
  push(28);
  push(3);
  push(111);
  push(21);
  push(12);
  printf("Ispis steka:\n");
  ispis();
  printf("\n");
  printf("TOP: %d\n",top());
  printf("Ispis steka:\n");
  ispis();
  printf("\nPozivanje funkcije pop: %d\n",pop());
  printf("Ispis steka:\n");
  ispis();

  return 0;
}
