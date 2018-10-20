//bjfu232
//
#include <iostream>
using namespace std;

typedef struct Node{
    int datum;
    Node *next;
}Node,*List;

void initList(List &head, int n){
    head=new Node;
    head->next=NULL;
    Node *cur=head;
    for (int i = 0; i < n; ++i) {
        Node *temp=new Node;
        temp->next=NULL;
        cin>>temp->datum;
        cur->next=temp;
        cur=cur->next;
    }
}

void showList(List head){
    Node *temp=head->next;
    while (temp){
        cout<<temp->datum;
        if (temp->next!=NULL){
            cout<<' ';
        }
        temp=temp->next;
    }
    cout<<endl;
}

void deletePar(List head, int min, int max){
    Node *pre=head;
    Node *cur=head->next;
    while (cur){
        if(cur->datum>=min&&cur->datum<=max){
            pre->next=cur->next;
            delete cur;
            cur=pre->next;
            continue;
        }
        cur=cur->next;
        pre=pre->next;
    }
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        List lis;
        initList(lis, n);
        int min,max;
        cin>>min>>max;
        deletePar(lis, min, max);
        showList(lis);
    }
    return 0;
}