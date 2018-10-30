//bjfu257
//
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    while (1){
        char str[200];
        char dict[200];
        cin>>str;
        int len=strlen(str);
        if (str[0]=='0'&&len){
            break;
        }
        memset(dict, 0, sizeof(char)*200);
        for (int i = 0; i < len; ++i) {
            dict[str[i]]++;
        }
        for (int i = 0; i < 128; ++i) {
            if (dict[i]>0){
                cout<<(char)i<<':'<<(int)dict[i]<<endl;
            }
        }
    }
    return 0;
}