//bjfu238
//
#include <iostream>
using namespace std;
const int len=200;

void getStringWithSpace(char *str,int len){
    for (int i = 0; i < len; ++i) {
        cin>>str[i];
    }
    str[len]=0;
}

int main() {
    int a,b;
    while (cin>>a>>b){
        if (a==0&&b==0){
            break;
        }
        char str1[len],str2[len];
        getStringWithSpace(str1, a);
        getStringWithSpace(str2, b);
        for (int i=a-1, j=b-1; i>0&&j>0 ; --i,--j) {
            if (str1[i]!=str2[j]){
                cout<<str1[++i]<<endl;
                break;
            }
        }
    }
    return 0;
}