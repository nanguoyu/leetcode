
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include<string>
#include<windows.h>

using namespace std;

char* longestCommonPrefix(char** strs, int strsSize) {

    int i=0;
    char buffer;
    int j=0;
    char * result;
    if(!strsSize)return "\0";
    if(strsSize==1)return strs[0];
    while (strs[0][j]) {
        buffer = strs[0][j];
        for (i = 1; i < strsSize; ++i) {
            if (strs[i][j]!=buffer) {
                result=(char* ) malloc(sizeof(char)*(j+1));
                for (int k = 0; k < j; ++k) {
                    result[k]=strs[0][k];
                }
                result[j]=0;
                return result;
            }
        }
        j++;
    }
    result=(char* ) malloc(sizeof(char)*(j+1));
    for (int k = 0; k < j; ++k) {
        result[k]=strs[0][k];
    }
    result[j]=0;
    return result;
}


int main()
{
    char* strs[]={"c","c"};
    cout<<longestCommonPrefix(strs,2);
    return 0;
}