// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : nanguoyu
// Date   : 2018-02-19

/*************
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
************************/

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int p=0,q=0;
    int counter = 0;
    int flag = (nums1Size + nums2Size) % 2;
    int MediumIndex = (nums1Size + nums2Size) / 2+1;
    if(nums1Size&&!nums2Size){
        if(flag){
            return nums1[MediumIndex-1];
        }else{
            return (double)(nums1[MediumIndex-1]+nums1[MediumIndex-2])/2;
        }
    }
    if(!nums1Size&&nums2Size){
        if(flag){
            return nums2[MediumIndex-1];
        }else{
            return (double)(nums2[MediumIndex-1]+nums2[MediumIndex-2])/2;
        }
    }
    int smallNumber = 0;


    while (p<nums1Size||q<nums2Size)
    {
        counter++;
        if(nums1[p]<nums2[q])
        {
            p++;
            if(counter==MediumIndex)
            {
                return flag? nums1[p-1] :(double) (nums1[p-1]+smallNumber)/2;
            }
            else{
                if (p == nums1Size)
                {
                    if (flag)
                    {
                        return nums2[q + MediumIndex - counter - 1];
                    } else
                    {
                        if (counter == MediumIndex - 1)
                        {
                            return (double) (nums1[p - 1] + nums2[q]) / 2;
                        } else {
                            return (double) (nums2[q + MediumIndex - counter - 1] +
                                             nums2[q + MediumIndex - counter - 2]) / 2;
                        }
                    }
                }
            }
            smallNumber = nums1[p-1];

        } else
        {
            q++;
            if(counter==MediumIndex)
            {

                return flag ? nums2[q-1]:(double) (nums2[q-1]+smallNumber)/2;
            } else {
                if (q == nums2Size)
                {
                    if (flag) {
                        return nums1[p + MediumIndex - counter - 1];
                    } else {
                        if (counter == MediumIndex - 1) {
                            return (double) (nums2[q - 1] + nums1[p]) / 2;
                        } else {
                            return (double) (nums1[p + MediumIndex - counter - 1] +
                                             nums1[p + MediumIndex - counter - 2]) / 2;
                        }
                    }

                }
            }
            smallNumber = nums2[q-1];
        }

    }
    return 0;
}