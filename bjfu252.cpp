//bjfu252
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

void initList(List &head, int n){
    if(head==NULL){
        head=new Node;
    }
    if(n==0){
        return;
    }
    head->next=new Node;
    head->next->next=NULL;
    cin>>head->next->datum;
    initList(head->next, n-1);
}

void showList(List head){
    if (head->next->next==NULL){
        cout<<head->next->datum<<endl;
        return;
    }
    cout<<head->next->datum<<' ';
    showList(head->next);
}

int findMax(List head){
    if (head->next->next==NULL){
        return head->next->datum;
    }
    int max=findMax(head->next);
    return head->next->datum>max?head->next->datum:max;
}

int length(List head){
    if(head->next==NULL){
        return 0;
    }
    int len=length(head->next)+1;
    return len;
}

int main() {
    List lis=NULL;
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        initList(lis, n);
        cout<<length(lis)<<endl;
        //showList(lis);
    }
    return 0;
}