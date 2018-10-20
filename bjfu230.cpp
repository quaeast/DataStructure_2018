//bjfu230
#include <iostream>

using namespace std;

typedef struct Node{
    int elem;
    struct Node *next;
}Node,*List;

void showList(List &head){
    Node *temp=head->next;
    while (temp){
        cout<<temp->elem;
        if (temp->next!=NULL){
            cout<<' ';
        }
        temp=temp->next;
    }
    cout<<endl;
}

void initList(List &head, int n){
    head = new Node;
    head->next=NULL;
    Node *j=head;
    for (int i = 0; i < n; ++i) {
        Node *temp=new Node;
        temp->next=NULL;
        cin>>temp->elem;
        j->next=temp;
        j=j->next;
    }
}

int findMAx(List head){
    int max=head->next->elem;
    Node *i=head->next;
    while (i){
        if(i->elem>max){
            max=i->elem;
        }
        i=i->next;
    }
    return max;
}

int main() {
    int n;
    while (cin>>n){
        if (n==0){
            break;
        }
        List lib;
        initList(lib, n);
        cout<<findMAx(lib)<<endl;
        //showList(lib);
    }
    return 0;
}