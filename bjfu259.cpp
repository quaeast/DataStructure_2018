//bjfu259
//
#include <iostream>
#include <cstring>
using namespace std;

int maxSize=200;

void insert(char *tar, char *soc,int pos){
    int move=strlen(soc);
    int len=strlen(tar);
    for (int i = len-1; i >=pos ; --i) {
        tar[i+move]=tar[i];
    }
    for (int i = 0; i < move; ++i) {
        tar[i+pos]=soc[i];
    }
    tar[move+len]=0;
}

int main() {
    while (1){
        int n;
        cin>>n;
        if (n==0){
            break;
        }
        char tar[maxSize],soc[maxSize];
        cin>>tar>>soc;
        insert(tar,soc,n-1);
        cout<<tar<<endl;
    }
    return 0;
}