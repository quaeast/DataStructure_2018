//bjfu295
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    struct Node *pre;
    struct Node *next;

}Node, *DList, *Np;

int initDList(DList &head){
    int n;
    cin>>n;
    if(n==0){
        return 0;
    }
    head=new Node;
    head->next=NULL;
    head->pre=NULL;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        Node *nt=new Node;
        nt->next=head->next;
        nt->pre=head;
        nt->datum=t;
        if(head->next!=NULL){
            head->next->pre=nt;
        }
        head->next=nt;
    }
    return 1;
}

void swf(Np &a){   //swf a and its next
    Node *b=a->next;
    a->pre->next=b;
    if(b->next!=NULL){
        b->next->pre=a;
    }
    a->next=b->next;
    b->pre=a->pre;
    a->pre=b;
    b->next=a;
}

int showList(DList &head){
    Node *t=head;
    while (t->next->next!=NULL){
        cout<<t->next->datum<<' ';
        t=t->next;
    }
    cout<<t->next->datum<<endl;
}

void sort(DList &head){
    Node *t=head->next;
    int len=0;
    while (t!=NULL){
        len++;
        t=t->next;
    }
    for (int i = 0; i < len-1; ++i) {
        Node *ti=head;
        for (int j = 0; j < len-1-i; ++j) {
            ti=ti->next;
            if(ti->datum>ti->next->datum){
                swf(ti);
                ti=ti->pre;
            }
        }
    }
}



int main() {
    while (1){
        DList l;
        if(!initDList(l)){
            break;
        }
        //showList(l);
        sort(l);
        showList(l);
    }
    return 0;
}