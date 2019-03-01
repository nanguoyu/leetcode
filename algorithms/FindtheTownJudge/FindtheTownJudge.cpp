// Source : https://oj.leetcode.com/problems/find-the-town-judge/
// Author : nanguoyu
// Date   : 2019/3/1

//In a town, there are N people labelled from 1 to N.  There is a rumor that one of these people is secretly the town judge.
//
//If the town judge exists, then:
//
//The town judge trusts nobody.
//Everybody (except for the town judge) trusts the town judge.
//There is exactly one person that satisfies properties 1 and 2.
//You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
//
//If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {

    int Judge=-1;
    int people[N][2];
    for (int j = 0; j < N; ++j) {
        people[j][0]=0;
        people[j][1]=0;
    }


    for (int i = 0; i < trustRowSize; ++i) {

        people[trust[i][0]-1][0]+=1;
        people[trust[i][1]-1][1]+=1;
    }

    for (int k = 0; k < N; ++k) {
        if (people[k][0]==0&&people[k][1]==N-1){
            return k+1;
        }
    }
    return Judge;
}