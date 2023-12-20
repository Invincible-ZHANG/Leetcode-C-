/*
 * @lc app=leetcode.cn id=2418 lang=c
 *
 * [2418] 按身高排序
 *
 * https://leetcode.cn/problems/sort-the-people/description/
 *
 * algorithms
 * Easy (78.71%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    40.2K
 * Total Submissions: 51.1K
 * Testcase Example:  '["Mary","John","Emma"]\n[180,165,170]'
 *
 * 给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。
 * 
 * 对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。
 * 
 * 请按身高 降序 顺序返回对应的名字数组 names 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：names = ["Mary","John","Emma"], heights = [180,165,170]
 * 输出：["Mary","Emma","John"]
 * 解释：Mary 最高，接着是 Emma 和 John 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：names = ["Alice","Bob","Bob"], heights = [155,185,150]
 * 输出：["Bob","Alice","Bob"]
 * 解释：第一个 Bob 最高，然后是 Alice 和第二个 Bob 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == names.length == heights.length
 * 1 <= n <= 10^3
 * 1 <= names[i].length <= 20
 * 1 <= heights[i] <= 10^5
 * names[i] 由大小写英文字母组成
 * heights 中的所有值互不相同
 * 
 * 
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


//冒泡排序
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    if (namesSize != heightsSize) {
        return NULL;
    }

    char** sortedNames = (char**)malloc(namesSize * sizeof(char*));
    if (sortedNames == NULL) {
        return NULL; // 内存分配失败
    }

    // 复制名字数组
    for (int i = 0; i < namesSize; i++) {
        sortedNames[i] = names[i];
    }

    for (int i = 0; i < namesSize-1; i++)   //冒泡不排最后一个
    {
        for (int j = 0; j < heightsSize -1 -i; j++)
        {
            if (heights[j] < heights[j+1])
            {
                //swap height
                int tempHeight = heights[j];
                heights[j] = heights[j+1];
                heights[j+1] = tempHeight;

                //swap name

                char* tempName = sortedNames[j];
                sortedNames[j] = sortedNames[j+1];
                sortedNames[j+1] = tempName;
            }   
        }
    }
    
    *returnSize = namesSize;
    return sortedNames;

}

// @lc code=end