//
//  main.cpp
//  ReverseString
//
//  Created by Büşra Abay on 14.12.2019.
//  Copyright © 2019 Büşra Abay. All rights reserved.
//

#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

  string tersListe1(string kelime) {
   
    int len = kelime.length();
    int n=len-1;
    for(int i=0;i<(len/2);i++){
      swap(kelime[i],kelime[n]);
      n = n-1;

    }
      return kelime;
  };



#include <stdlib.h>
#include <stdio.h>

struct dnode
{
    char info;
    struct dnode *left;
    struct dnode *right;
};

typedef struct dnode *DNODEPTR;

DNODEPTR getNode()
{
    DNODEPTR p = (DNODEPTR)malloc(sizeof(struct dnode));
    return p;
}

void insertNode(DNODEPTR *list, DNODEPTR p, char k, bool right)
{
    if (*list == NULL)
    {
        DNODEPTR yeni = getNode();
        yeni->info = k;
        yeni->left = NULL;
        yeni->right = NULL;
        *list = yeni;
    }
    else  
    {
        if (p != NULL)
        {
            DNODEPTR yeni = getNode();
            yeni->info = k;
            
            if (!right)
            {
                DNODEPTR sol = p->left;
                if (sol == NULL)
                {
                    yeni->left = NULL;
                    yeni->right = p;
                    *list = yeni;
                    p->left = yeni;
                }
                else
                {
                    yeni->left = sol;
                    yeni->right = p;
                    sol->right = yeni;
                    p->left = yeni;
                }
            }
            else
            {
                DNODEPTR sag = p->right;
                if (sag == NULL)
                {
                    yeni->right = NULL;
                    yeni->left = p;
                    p->right = yeni;
                }
                else
                {
                    yeni->left = p;
                    yeni->right = sag;
                    p->right = yeni;
                    sag->left = yeni;
                }
            }
        }
        else
            printf("Adres hatasi! Dugum ekleme yapilamadi!\n");
    }
}



class Stack
{
    public:
    int top;
    unsigned capacity;
    char* array;
};
  
Stack* createStack(unsigned capacity)
{
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = new char[(stack->capacity * sizeof(char))];
    return stack;
};
int isFull(Stack* stack)
{ return stack->top == stack->capacity - 1; }
  

int isEmpty(Stack* stack)
{ return stack->top == -1; }
void push(Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
  

char pop(Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
void reverse(char str[])
{
    int n = strlen(str);
    Stack* stack = createStack(n);
  

    int i;
    for (i = 0; i < n; i++)
        push(stack, str[i]);
  
    for (i = 0; i < n; i++)
        str[i] = pop(stack);
}

  

DNODEPTR tersListe(DNODEPTR p){ //çift bagli listeyi tanımladık.
    DNODEPTR ters=NULL;         //listenin basına null atıyoruz
    insertNode(&ters, NULL, p->info, true);
    DNODEPTR yedek=ters;//listenin basını tutuyoruz
    p=p->left;//p'yi sola dogru ılerletıyoruz
    while (p != NULL)// p listesi NULL olmayana kadar ilerletiyoruz
       {
           insertNode(&ters, yedek, p->info, true);//her seferinde listeye p den eleman atılıyor
           p = p->left; //p den sola dogru ilerleniyor
           yedek=yedek->right; // olusacak listemiz saga dogru ilerletiliyor
       }
    return ters; // veri geri donduruluyor.
};


void printList(DNODEPTR p, bool isLeft)
{
    while (p != NULL)
    {
        printf("%c ", p->info);
        if (isLeft)
            p = p->left;
        else
            p = p->right;
    }
}

int main()
{auto start2 = high_resolution_clock::now();
    DNODEPTR liste = NULL;

    insertNode(&liste, NULL, 'm', true);
    DNODEPTR p = liste;
    insertNode(&liste, p, 'e', true);
    p=p->right;
    insertNode(&liste, p, 'r', true);
    p = p->right;// p=7
    insertNode(&liste, p, 'h', true);
    p=p->right;
    insertNode(&liste, p, 'a', true);
    p=p->right;
    insertNode(&liste, p, 'b', true);
    p=p->right;
    insertNode(&liste, p, 'a', true);
    p=p->right;
    DNODEPTR ters =tersListe(p);  // liste sonundan itibaren sola dogru yazdirma
    printList(ters,false);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    //sonuç çıktısı
    cout << " \nCift baglantili liste ile calisan fonksiyonun suresi: " << duration2.count() << " mikrosaniye" << endl;
    
    
    
    //for ile terse çevirme
    auto start1 = high_resolution_clock::now();
    string kelime="merhaba";
    string tersKelime=tersListe1(kelime);
    cout << tersKelime;
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    //sonuç çıktısı
    cout << " \nDöngü ile calisan fonksiyonun suresi: " << duration1.count() << " mikrosaniye" << endl;
    
    
    
    //Stack* tersStack=createStack(8);
    auto start3 = high_resolution_clock::now();
    char stackKelime[]="merhaba";
    reverse(stackKelime);
    cout<<stackKelime;
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    //sonuç çıktısı
    cout << " \nStack ile calisan fonksiyonun suresi: " << duration3.count() << " mikrosaniye" << endl;};

