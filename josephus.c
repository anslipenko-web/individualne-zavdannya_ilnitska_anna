#include <stdio.h>
#include <stdlib.h>

//функція для пошуку переможця
int josephus(int n){
    if(n==1)return 1; //базовий випадок
    if(n%2==0)
        return 2*josephus(n/2)-1;
    else
        return 2*josephus(n/2)+1;
}
int main(int argc,char* argv[]){
    //створюємо змінну для імені файлу
    char* imya_fayla="input.txt";

    //якщо в терміналі написали інше ім'я, беремо його
    if(argc>1){
        imya_fayla=argv[1];
    }

    FILE* f1=fopen(imya_fayla,"r");
    if(f1==NULL){
        printf("Файлу %s немає\n",imya_fayla);
        return 1;
    }
    int n;
    //читаємо число з файлу
    if(fscanf(f1,"%d",&n)!=1){
        printf("У файлі порожньо\n");
        fclose(f1);
        return 1;
    }
    fclose(f1);

    //перевірка на мінус або нуль
    if(n<1){
        printf("n maye buty bilshe 0\n");
        return 1;
    }
    int win=josephus(n);

    //виводимо результат на екран
    printf("Reading from: %s\n",imya_fayla);
    printf("N = %d, Winner = %d\n",n,win);

    //записуємо в аутпут
    FILE* f2=fopen("output.txt","w");
    if(f2!=NULL){
        fprintf(f2,"n = %d\nWinner = %d\n",n,win);
        fclose(f2);
        printf("Everything in: output.txt\n");
    }
    return 0;
}