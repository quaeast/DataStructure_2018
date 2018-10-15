//
//  main.cpp
//  bjfu204
//
//  Created by fang on 2018/9/30.
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


int main() {
    SqList lib;
    InitSqList(lib);
    for(int i=0;;i++){
        scanf("%s%s%f", GetElem(lib,i).isbn, GetElem(lib,i).name, &(GetElem(lib,i).price));
    if(GetElem(lib,i).isbn[0]=='0'&&GetElem(lib,i).name[0]=='0'&&GetElem(lib,i).price<1e-6) {
            break;
        }
        lib.length++;
    }
    printf("%d\n",lib.length);
    for (int i=0; i<lib.length; i++) {
        printf("%s %s %.2f\n", GetElem(lib,i).isbn, GetElem(lib,i).name, GetElem(lib,i).price);
    }
    return 0;
}