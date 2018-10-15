//
//  main.cpp
//  bjfu211.2
//
//  Created by fang on 2018/10/8.
//  Copyright © 2018 fang. All rights reserved.
//

#include <iostream>
#include "cstring"
const int N = 500;
using namespace std;

typedef struct{
    char isbn[100];
    char name[100];
    float price;
}Book;

typedef struct{
    Book *elem;
    int length;
}SqList;

void InitSqList(SqList &L){
    L.elem = new Book[N];
    L.length = 0;
}

Book& GetElem(SqList L, int i){
    return L.elem[i];
}

void ShowList(SqList L){
    for (int i=0; i<L.length; i++) {
        printf("%s %s %.2f\n", GetElem(L,i).isbn, GetElem(L,i).name, GetElem(L,i).price);
    }
}

void SortList(SqList &L){
    for (int i=0; i<L.length-1; i++) {
        for (int j=0; j<L.length-1-i; j++) {
            if (L.elem[j].price<L.elem[j+1].price) {
                Book temp = L.elem[j];
                L.elem[j]=L.elem[j+1];
                L.elem[j+1]=temp;
            }
        }
    }
}

void ReverseList(SqList &L){
    for (int i=0; i<L.length/2; i++) {
        Book temp = L.elem[i];
        L.elem[i] = L.elem[L.length-i-1];
        L.elem[L.length-i-1] = temp;
    }
}

void FindFavourate(char *target, SqList L){
    int amount = 0;
    for (int i=0; i<L.length; i++) {
        if (!strcmp(target, L.elem[i].name)) {
            amount++;
        }
    }
    if (amount) {
        printf("%d\n",amount);
        for (int i=0; i<L.length; i++) {
            if (!strcmp(target, L.elem[i].name)) {
                printf("%s %s %.2f\n", GetElem(L,i).isbn, GetElem(L,i).name, GetElem(L,i).price);
            }
        }
    }
    else{
        printf("Sorry，there is no your favourite!\n");
    }
}

void InsertList(int pos,const Book &tar, SqList &L){
    for (int i=L.length-1; i>=pos; i--) {
        L.elem[i+1] = L.elem[i];
    }
    L.elem[pos] = tar;
    L.length++;
}

int main() {
    SqList lib;
    InitSqList(lib);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%s%s%f", GetElem(lib,i).isbn, GetElem(lib,i).name, &(GetElem(lib,i).price));
        lib.length++;
    }
    int pos;
    Book tar;
    scanf("%d", &pos);
    scanf("%s%s%f", tar.isbn, tar.name, &tar.price);
    InsertList(pos-1, tar, lib);
    ShowList(lib);
    return 0;
}