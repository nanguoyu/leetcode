// Source : https://leetcode.com/problems/group-anagrams/
// Author : nanguoyu
// Date   : 2019/3/25
/**************************************************
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
["ate","eat","tea"],
["nat","tan"],
["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
 ***************************************************/

/*Import
 *
 * This code passed 98/101 test cases.
 * And it's not a good solution without HashMap.
 *
 *
 *
 * */


typedef struct cat{
    int value;
    int revalue;
    int rerevalue;
    int rererevalue;
    int rawIndex;
};

int comp(const void *a, const void *b)
{
    return (*(struct cat *)a).value - (*(struct cat *)b).value+(*(struct cat *)a).revalue - (*(struct cat *)b).revalue;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    int tringle[26]={2, 3, 5, 7, 11, 13, 17, 19,
                     23, 29, 31, 37, 41, 43, 47,
                     53, 59, 61, 67, 71, 73, 79,
                     83, 89,97, 101};
    printf("[Info] input: ");
    for (int i = 0; i < strsSize; ++i) {
        printf(" %s ",strs[i]);
    }   printf("\n");
    char ***res=(char ***)malloc(sizeof(char**)*strsSize);
    struct cat  cats[strsSize];
    for (int j = 0; j <strsSize; ++j) {
        int k=0,l=1,rl=1,rrl=1,rrrl=1;
        while(strs[j][k]){
            if(INT_MAX/tringle[strs[j][k]-'a'] < l){
                printf("%s %c\n",strs[j],strs[j][k]);
                if(INT_MAX/tringle[strs[j][k]-'a'] < rl){
                    if(INT_MAX/tringle[strs[j][k]-'a'] < rrl){
                        rrrl*=tringle[strs[j][k]-'a'];
                    }else{
                        rrl*=tringle[strs[j][k]-'a'];}
                } else{
                    rl*=tringle[strs[j][k]-'a'];
                }
            }else{
                l*=tringle[strs[j][k]-'a'];
            }

            k++;
        }
        // rererevalue
        cats[j].rawIndex=j;cats[j].value=l;cats[j].revalue=rl;cats[j].rerevalue=rrl;cats[j].rererevalue=rrrl;
    }
    for (int m = 0; m < strsSize; ++m) {
        printf(" cat[%d]=%d ",m,cats[m].value);
    }
    printf("\n");
    qsort(cats, (size_t) strsSize, sizeof(struct cat), comp);
    for (int m = 0; m < strsSize; ++m) {
        printf(" cat[%d]=%d ",m,cats[m].value);
    }
    printf("\n");
    *returnSize=0;
    if(!columnSizes){
        printf("columnSizes is null\n");
    }
    *columnSizes= (int *)malloc(sizeof(int )*strsSize);

    int *len = (int *)malloc(sizeof(int));
    *(len)=0;
    char **unit=(char **)malloc(sizeof(char*)*strsSize);
    unit[*len]=strs[cats[0].rawIndex];(*len)++;
    struct cat * pre= &cats[0];
    for (int i = 1; i < strsSize; ++i) {
        if(pre->value==cats[i].value && pre->revalue==cats[i].revalue && pre->rerevalue==cats[i].rerevalue && pre->rererevalue==cats[i].rererevalue){
            unit[*len] = strs[cats[i].rawIndex];(*len)++;
        }else{
            (*columnSizes)[*returnSize]=*len;

            res[*returnSize]=unit;
            printf("\n");
            printf("columnSizes[%d]=%d ",*returnSize,*len);
            for (int j = 0; j < *len; ++j) {
                printf(" unit[%d] = %s ",j,res[*returnSize][j]);
            }
            (*returnSize)++;
            printf("\n");
            len = (int *)malloc(sizeof(int));*(len)=0;
            unit=(char **)malloc(sizeof(char*)*strsSize);
            unit[*len]=strs[cats[i].rawIndex];(*len)++;
            pre= &cats[i];
        }
    }
    (*columnSizes)[*returnSize]=*len;
    res[*returnSize]=unit;
    printf("\n");
    printf("columnSizes[%d]=%d ",*returnSize,*len);
    for (int j = 0; j < *len; ++j) {
        printf(" unit[%d] = %s ",j,res[*returnSize][j]);
    }
    (*returnSize)++;
    printf("\n");
    return res;
}

int main()
{


    char *strs[]={"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize =6;
    int** columnSizes= (int **)malloc(sizeof(int *));
    int returnsSizes = 0; int * returnSize = &returnsSizes;
    char ***res =  groupAnagrams(strs,strsSize,columnSizes,returnSize);
    for (int i = 0; i < *returnSize; ++i) {
        printf(" *columnSizes[i] %d ",(*columnSizes)[i]);
        for (int j = 0; j < (*columnSizes)[i]; ++j) {
            printf(" %s ",res[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}