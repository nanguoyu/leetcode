// Source : https://leetcode.com/problems/multiply-strings/
// Author : nanguoyu
// Date   : 2019/3/19
/*******************************************************************************************
Given two non-negative integers num1 and num2 represented as strings, return
the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
 ********************************************************************************************/

char* multiply(char* num1, char* num2) {
    int num1_len=0;while(num1[num1_len]){num1_len++;}
    int num2_len=0;while(num2[num2_len]){num2_len++;}
    int len = num1_len*num2_len+3;
    char *res =(char *)malloc(sizeof(char)*len);
    char *stack =(char *)malloc(sizeof(char)*len);int k=0;int l=0;
    memset(stack,48,len);
    res[0]=0; int bg=0;
    if(num1[0]==48||num2[0]==48){res[0]=48;res[1]=0;return res;}
    if(num1_len>=num2_len){
        for (int i= num2_len-1; i >=0; i--) {
            bg=0;
            for (int j = num1_len-1; j >=0; j--) {
                int unit = (num2[i]-48)*(num1[j]-48);
                int t =stack[k]-48;
                stack[k]= (bg+unit+t)%10+48;
                k++;
                bg = (bg+unit+t)/10;
            }
            l=k;
            k=num2_len-1-i+1;
            if(bg>0){

                stack[l]= bg%10+48;
                l++;
            }
        }
    }else{
        for (int i= num1_len-1; i >=0; i--) {
            bg=0;
            for (int j = num2_len-1; j >=0; j--) {
                int unit = (num1[i]-48)*(num2[j]-48);
                int t =stack[k]-48;
                stack[k]= (bg+unit+t)%10+48;

                k++;
                bg = (bg+unit+t)/10;
            }
            l=k;
            k=num1_len-1-i+1;
            if(bg>0){
                stack[l]= bg%10+48;
                l++;
            }
        }
    }

    int p=0;
    for (int m = l-1; m >=0; m--,p++) {
        res[p]=stack[m];
    }
    res[p]=0;
    return res;
}


int main()
{
    char nums1[] = "999"; char * num1 = nums1;
    char nums2[] = "999"; char * num2 = nums2;
    char * res = multiply(num1,num2);
    int i=0;while(res[i])
    {
        printf("%c",res[i]);
        i++;
    }
    printf("\n");

    return 0;
}

