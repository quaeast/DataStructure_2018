//bjfu225_3
//

#include <iostream>

using namespace std;

typedef struct Node{
    int datum;
    struct Node *next;
}Node,*List;

void showList(List head){
    if(head->next==NULL){
        cout<<endl;
        return;
    }
    Node *cur=head->next;
    while (cur!=NULL){
        cout<<cur->datum;
        if(cur->next!=NULL){
            cout<<' ';
        }
        cur=cur->next;
    }
    cout<<endl;
}

void initList(List &head,int n) {
    head = new Node;
    head->next = NULL;
    Node *cur = head;
    for (int i = 0; i < n; ++i) {
        Node *temp = new Node;
        cin >> temp->datum;
        temp->next = NULL;
        cur->next = temp;
        cur = cur->next;
    }
}

void deleteList(List &head){
    Node *cur=head->next;
    Node *curPre=head;
    while (cur!=NULL){
        delete curPre;
        curPre=cur;
        cur=cur->next;
    }
}


List combine(List h1, List h2){
    List h3=h1;
    Node *i=h1->next;
    Node *j=h2->next;
    while (i&&j){
        if(i->datum<j->datum){
            h3->next=i;
            h3=h3->next;
            i=i->next;
        } else if(i->datum==j->datum){
            h3->next=i;
            h3=h3->next;
            Node *temp=j->next;
            delete j;
            j=temp;
            i=i->next;
        } else{
            h3->next=j;
            h3=h3->next;
            j=j->next;
        }
    }
    i?h3->next=i:h3->next=j;
    delete h2;
    return h1;
}


void deWight(List head){
    Node *cur = head;
    //Node *curPre = head;
    while (cur->next){
        if (cur->next->datum==cur->datum){
            Node *temp=cur->next->next;
            delete cur->next;
            cur->next=temp;
            continue;
        }
        cur=cur->next;
    }
}

int main() {
    int a,b;
    List l1,l2;
    while (cin>>a>>b){
        if(a==0&&b==0){
            break;
        }
        initList(l1, a);
        initList(l2, b);
        Node *c=combine(l1,l2);
        //deWight(c);
        showList(c);
    }
    return 0;
}