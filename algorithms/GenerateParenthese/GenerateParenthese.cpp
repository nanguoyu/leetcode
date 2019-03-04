// Source : https://leetcode.com/problems/generate-parentheses/
// Author : nanguoyu
// Date   : 2019/3/4

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//[
//"((()))",
//"(()())",
//"(())()",
//"()(())",
//"()()()"
//]

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool fun(char *Prefix, int a, char **Parenthesis, int l, int r, int *returnSize, int n, int m, char **result)
{

    if (l>n||r>n||r>l){
        return false;
    }
    char *pre = (char *) malloc(sizeof(char) * (2 * n + 1));
    pre[0] = 0;
    strcat(pre, Prefix);
    strcat(pre, Parenthesis[a]);
    if (a == 1) {
        r++;
        if(l-m>0&&r-1==m){
            m++;
        }
        if (l == n && r == n ) {
            result[*returnSize] = pre;
            *returnSize = *returnSize + 1;
            return true;
        }


        if (n - l > 0) {
            fun(pre, 0, Parenthesis, l, r, returnSize, n, m, result);
        }
        if (n - m > 0) {
            fun(pre, 1, Parenthesis, l, r, returnSize, n, m, result);
        }

    } else {
        // a==0
        l++;
        if (n - l > 0) {
            fun(pre, 0, Parenthesis, l, r, returnSize, n, m, result);
        }
        if (n - m > 0) {
            fun(pre, 1, Parenthesis, l, r, returnSize, n, m, result);
        }
    }


    return false;
}

char **generateParenthesis(int n, int *returnSize)
{
#define nullresult 0
    if (!n) {
        return nullresult;
    }

    char Parenthesis1[] = "(";
    char Parenthesis2[] = ")";
    char **Parenthesis = (char **) malloc(sizeof(char *) * 2);
    Parenthesis[0] = Parenthesis1;
    Parenthesis[1] = Parenthesis2;

    *returnSize = 0;
    int l = 1, r = 0;int m = 0;

    char **result = (char **) malloc(sizeof(char *) * 1000);

    fun(Parenthesis[0], 0, Parenthesis, l, r, returnSize, n, m, result);
    fun(Parenthesis[0], 1, Parenthesis, l, r, returnSize, n, m, result);

    return result;

}


int main()
{
//    Test
    int a=0;
    char **b = generateParenthesis(3, &a);
    for (int i = 0; i < a; ++i) {
        cout<<b[i]<<endl;
    }
    return 0;
}