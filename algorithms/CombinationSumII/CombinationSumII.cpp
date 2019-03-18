// Source : https://leetcode.com/problems/combination-sum-ii/
// Author : nanguoyu
// Date   : 2019/3/18



int comp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

bool fun(int* buffer, int bufferSize, int * unit, int* unit_len, int target, int **res,int** columnSizes, int* returnSize, int candidatesSize){
    unit[*unit_len] = buffer[0];
    (*unit_len)+=1;

    if(target-buffer[0]==0){
        int *len = (int *)malloc(sizeof(int)); *len =(*unit_len);
        (*columnSizes)[(*returnSize)]= (*unit_len);

        int *new_unit = (int *)malloc(sizeof(int)*(*unit_len));

        for (int i = 0; i < (*len); ++i) {new_unit[i]=unit[i];}
        res[(*returnSize)] = new_unit;

        (*returnSize)+=1;
        (*unit_len)-=1;
        return true;
    }else if(target-buffer[0]>0){

        if(bufferSize==0){

            return false;
        }else{
            for (int i = 1; i < bufferSize; ++i) {
                if(target-buffer[0]<buffer[i]) continue;

                fun(buffer+i,bufferSize-i, unit, unit_len,target-buffer[0],res,columnSizes,returnSize, candidatesSize);
                while(i+1 < bufferSize && buffer[i+1]==buffer[i]) i++;
            }
            (*unit_len)-=1;

        }
    }else{

        (*unit_len)-=1;
        return false;
    }

    return false;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    qsort(candidates,(size_t)candidatesSize, sizeof(int), comp);

    int **res = (int **)malloc(sizeof(int *)*1000);

    *columnSizes = (int *)malloc(sizeof(int)*1000);
    *returnSize=0;
    for (int i = 0; i < candidatesSize; ++i) {

        int *unit = (int *)malloc(sizeof(int)*(target*2));
        int *unit_len = (int *)malloc(sizeof(int)); unit_len[0]=0;
        int *  buffer = &candidates[i]; int bufferSize = candidatesSize-i;
        fun(buffer,bufferSize, unit, unit_len,target,res,columnSizes,returnSize, candidatesSize);
        while(i+1 < candidatesSize && candidates[i+1]==candidates[i]) i++;
    }
    return res;
}


int main()
{
    int candidate[]={10,1,2,7,6,1,5}; int candidatesSize = 7; int target = 8;
    int*returnSize=(int *)malloc(sizeof(int));
    int *candidates = candidate;
    int **columnSizes = (int **)malloc(sizeof(int *));

    int** res= combinationSum(candidates,candidatesSize,target,columnSizes,returnSize);
    printf("\n%d\n",(*returnSize));
    for (int i = 0; i < *returnSize; ++i) {
        printf("(*columnSizes)[%d] = [%d] ",i,(*columnSizes)[i]);
        for (int j = 0; j < (*columnSizes)[i]; ++j) {
            printf(" %d ",res[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

