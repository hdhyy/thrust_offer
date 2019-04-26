#include <bits/stdc++.h>

using namespace std;
/**
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1
 * 2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 **/
class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size() == 0)
            return 0;
        int low = 0;
        int high = (int)rotateArray.size()-1;
        int mid = low;
        while (low < high && rotateArray[low] >= rotateArray[high])
        {
            if(high - low == 1)
            {
                low = high;
                break;
            }
            mid = (low + high + 1) >> 1;
            if (rotateArray[low] == rotateArray[high] && rotateArray[low] == rotateArray[mid])
            {
                return getMinOfArray(rotateArray);
            }
            // if (rotateArray[low] > rotateArray[mid])
            //     high = mid;
            // else if (rotateArray[mid] > rotateArray[high])
            //     low = mid;
            // else if(rotateArray[low] == rotateArray[mid])
            //     low = mid;
            // else if(rotateArray[high] == rotateArray[mid])
            //     high = mid;
            if (rotateArray[low] <= rotateArray[mid])
                low = mid;
            else if (rotateArray[mid] <= rotateArray[high])
                high = mid;
        }
        return rotateArray[low];
    }

    int getMinOfArray(vector<int> rotateArray)
    {
        int min = rotateArray[0];
        for(auto item : rotateArray)
        {
            if(item < min)
                min = item;
        }
        return min;
    }
};