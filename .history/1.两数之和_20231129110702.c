/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 *
 * https://leetcode.cn/problems/two-sum/description/
 *
 * algorithms
 * Easy (53.06%)
 * Likes:    18016
 * Dislikes: 0
 * Total Accepted:    5M
 * Total Submissions: 9.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,7,11,15], target = 9
 * 输出：[0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,4], target = 6
 * 输出：[1,2]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [3,3], target = 6
 * 输出：[0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * 只会存在一个有效答案
 * 
 * 
 * 
 * 
 * 进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？
 * 
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * @date 2023-11-29
 * 
 * @author zhangzijian
 * 
 * 1.判断数组长度是否合法
 * 2.判断数组中元素的大小是否合法
 * 3.两个For循环嵌套
*/
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_NUMBER_MAX 10000    //  
#define ARRAY_NUMBER_MIN 2
#define NUM_MAX 1000000000
#define NUM_MIN -1000000000
#define FALSE 0
#define TRUE 1

//判断数组长度是否合法  2 <= nums.length <= 10^4
const int Isvalid_len_array (int array[])
{
    if (array == NULL) {
        printf ("The array is null.\n");
        return FALSE;
    }
    int len_array = sizeof(array)/sizeof(array[0]);
    if (ARRAY_NUMBER_MIN<=len_array && len_array<=ARRAY_NUMBER_MAX) {
        return TRUE;
    } else {
        printf ("The array is oversize.\n");
        return FALSE;
    }
}

//判断数组中元素的大小是否合法
//-10^9 <= nums[i] <= 10^9 
//-10^9 <= target <= 10^9  
const int Isvalid_num (int NUM)
{
    if(NUM >= NUM_MIN && NUM <= NUM_MAX) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Isvalid_len_array (nums);
    Isvalid_num (target);

    for (int i=0; i < numsSize; ++i){
        for(int j = i + 1 ; j<numsSize; ++j){
            if(nums[i] + nums[j] == target){
                int* ret = malloc(sizeof(int) * 2);
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    *returnSize = 0;
    return 0;
}
// @lc code=end

