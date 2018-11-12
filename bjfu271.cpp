//bjfu271
//
#include <iostream>
using namespace std;

typedef struct Node{
    char datum;
    struct Node *L;
    struct Node *R;
}Node,*BiTree;

int init(BiTree &root){
    char t;
    cin>>t;
    if(t=='0'){
        root=NULL;
        return 0;
    }
    root=new Node;
    root->datum=t;
    init(root->L);
    init(root->R);
    return 1;
}

void Pre(BiTree root){  //test init
    if(root==NULL){
        return;
    }
    cout<<root->datum;
    Pre(root->L);
    Pre(root->R);
}

int height(BiTree root){
    if(root==0){
        return 0;
    }
    return max(height(root->L),height(root->R))+1;
}


int main() {
    while (1){
        BiTree tree;
        if(!init(tree)){
            break;
        }
        cout<<height(tree)<<endl;
    }
    return 0;
}