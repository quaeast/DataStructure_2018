//bjfu228
//

#include <iostream>
using namespace std;

typedef struct Node{
    int elem;
    struct Node *next;
}Node,*List;


void initList(List &head, int n){
    head = new Node;
    head->next=NULL;
    Node *temp=head;
    for (int i = 0; i < n; ++i) {
        temp->next=new Node;
        temp->next->next=NULL;
        cin>>temp->next->elem;
        temp=temp->next;
    }
}

int showList(List head){  //return count
    Node *temp=head->next;
    int count=0;
    while (temp){
        cout<<temp->elem;
        count++;
        if(temp->next!=NULL){
            cout<<' ';
        }
        temp=temp->next;
    }
    cout<<endl;
    return count;
}



List difference(List h2,List h1){
    Node *t1=h1->next;
    while (t1){
        Node *t2Pre=h2;
        Node *t2=t2Pre->next;
        while (t2){
            if(t1->elem==t2->elem){
                t2Pre->next=t2->next;
                delete t2;
                break;
            }
            t2Pre=t2Pre->next;
            t2=t2->next;
        }
        t1=t1->next;
    }
    return h2;
}


int main() {
    int a,b;
    while (cin>>a>>b){
        if (a==0&&b==0){
            break;
        }
        List l1,l2,l3;
        initList(l1,a);
        initList(l2,b);
        l3=difference(l1,l2);
        cout<<showList(l3)<<endl;
    }
    return 0;
}