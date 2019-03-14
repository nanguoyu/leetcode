// Source : https://leetcode.com/problems/count-and-say/
// Author : nanguoyu
// Date   : 2019/3/14

/*********************************************************************************************
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.



Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
 ********************************************************************************************/



char *countAndSay(int n)
{
    if (n == 1) {
        char *res = (char *) malloc(sizeof(char) * 2);
        res[0] = 49;
        res[1] = 0;
        return res;
    } if(n==2){
        char *res = (char *) malloc(sizeof(char) * 3);
        res[0] = 49;
        res[1] = 49;
        res[2] = 0;
        return res;
    }else {
        char *prefix = countAndSay(n - 1);
        int len = 0;
        while (prefix[len]) { len++; }
        char *res = (char *) malloc(sizeof(char) * (len * 2+1));
        int k=0, j = 1; char pre=0;
        for (int i = 0; i < len; ++i) {
            if (!pre) {
                pre = prefix[i];
            } else {
                if (pre == prefix[i] ) { j++; }
                else {
                    res[k]=(char )(j+48);res[k+1]=pre;k+=2;
                    pre=prefix[i];j=1;
                }
            }
        }
        res[k]=(char )(j+48);res[k+1]=pre;k+=2;
        res[k]=0;
        free(prefix);
        return res;
    }

}

int main()
{

    char * res = countAndSay(4);
    int i=0;
    while(res[i]){
        printf("%c",res[i]);i++;
    }
    printf("\n");
    return 0;
}
