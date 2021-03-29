class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if len(intervals)==0:
            return [newInterval]
        s, e = newInterval[0:2]
        result_postive_order = []
        result_inverse_order = []

        len_interval = len(intervals)
        i, j = 0, len_interval-1
        i_ok,j_ok = False, False

        while i<=j:

            if not i_ok:
                if s>intervals[i][1]:
                    result_postive_order.append(intervals[i])
                    i+=1
                elif s>=intervals[i][0]:
                    # find s in an existing interval
                    i_ok = True
                    result_postive_order.append(intervals[i])
                else:
                    # s in an non-existing interval
                    i_ok = True
                    result_postive_order.append([s, -1])
            if not j_ok:
                if e<intervals[j][0]:
                    result_inverse_order.append(intervals[j])
                    j-=1
                elif e<=intervals[j][1]:
                    # find e in an existing interval
                    j_ok = True
                    result_inverse_order.append(intervals[j])
                else:
                    # e in an non-existing interval
                    j_ok = True
                    result_inverse_order.append([-1, e])
            if i_ok and j_ok:
                break
        if not j_ok:
            result_inverse_order.append([-1, e])
        if not i_ok:
            result_postive_order.append([s, -1])
            # check the last one in two new result lists
        # print(result_postive_order)
        # print(result_inverse_order)
        if result_postive_order[-1][0]>result_inverse_order[-1][1]:
            # Not find
            return intervals
        if result_postive_order[-1][1] == -1:
            if result_inverse_order[-1][0] == -1:
                result_postive_order[-1][1] = result_inverse_order[-1][1]
                result_inverse_order.remove(result_inverse_order[-1])
                return result_postive_order+result_inverse_order[::-1]
            else:
                if result_postive_order[-1][0]>=result_inverse_order[-1][0]:
                    result_postive_order.remove(result_postive_order[-1])
                    return result_postive_order+result_inverse_order[::-1]
                else:
                    result_postive_order[-1][1] = result_inverse_order[-1][1]
                    result_inverse_order.remove(result_inverse_order[-1])
                    return result_postive_order+result_inverse_order[::-1]
        else:
            if result_inverse_order[-1][0] == -1:
                if result_inverse_order[-1][1]>=result_postive_order[-1][1]:
                    result_postive_order[-1][1] = result_inverse_order[-1][1]
                    result_inverse_order.remove(result_inverse_order[-1])
                    return result_postive_order+result_inverse_order[::-1]
                else:
                    result_inverse_order.remove(result_inverse_order[-1])
                    return result_postive_order+result_inverse_order[::-1]
            else:
                if result_postive_order[-1][0]==result_inverse_order[-1][0] and result_postive_order[-1][1]==result_inverse_order[-1][1]:
                    return intervals
                else:
                    result_postive_order[-1][1] = result_inverse_order[-1][1]
                    result_inverse_order.remove(result_inverse_order[-1])
                    return result_postive_order+result_inverse_order[::-1]
