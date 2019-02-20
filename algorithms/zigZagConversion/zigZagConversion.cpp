// Source : https://oj.leetcode.com/problems/zigzag-conversion/
// Author : nanguoyu
// Date   : 2019-02-20

/**********************************************************************************
*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
* (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
*
* And then read line by line: "PAHNAPLSIIGYIR"
*
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
*
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*
*
**********************************************************************************/

char* convert(char* s, int numRows) {
//    cout<<"[INPUT]: s= "<<s<<" numRows= "<<numRows<<endl;
    int length = 0;
    int i = 0;
    int index=0;
    while(s[i]){
        length++;
        i++;
    }
    char *result = (char *)malloc(sizeof(char)*length+1);
    if(length<numRows){
        return s;
    }
    if(numRows==1)
        return s;
    if(numRows==2){
        int x= length%2;
        for (int j = 0; j <length-1+x; j+=2,index++) {
            result[index]=s[j];
        }
        for (int k = 1; k < length-x; k+=2,index++) {
            result[index]=s[k];
        }
        result[length]=0;
        return result;
    }

    //case that no less than 3 rows

    int rol = length/(2*numRows-2);

    for (int l = 0; l < numRows; ++l) {

//        cout<<"Print row "<<l<<": ";
        for (int j = 0; j < rol+1; ++j) {
            if (l+j*(2*numRows-2)<length) {
                result[index++] = s[l + j*(2 * numRows - 2)];
//                    cout<<result[index-1]<<" ";
            }
            if(l+j*(2*numRows-2)+(2 * numRows - 2)-l*2<length&&l!=0&&l!=numRows-1){
                result[index++] = s[l +j*(2 * numRows - 2)+(2 * numRows - 2)-l*2];
//                    cout<<result[index-1]<<" ";
            }
        }
//        cout<<endl;

    }
    result[length]=0;
    return result;
}