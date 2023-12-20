/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (39.34%)
 * Likes:    9815
 * Dislikes: 0
 * Total Accepted:    2.6M
 * Total Submissions: 6.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b)    ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char* s) {
    int lengthString = strlen(s);

    //假设ASCII字符，创建一个数组，用于存储每个字符最后一次出现的索引

    int *charASCIIarray = (int *)malloc(256 * sizeof(int));

    //初始化数组，所有字符的索引初始化为-1

    for(int i = 0; i < 256; i++)
    {
        charASCIIarray[i] = -1;
    }

    //初始化变量
    int maxLength = 0;
    int start = 0 ;

    //遍历数组进行判断是否存在重复字符
    for(int end = 0; end < lengthString; end++)
    {
        if(charASCIIarray[s[end]] != -1)
        {
            //更新start，即左滑窗的位置，保证代码健壮性，需要保证新的值大于原来的值
            //charASCIIarray[s[end]] +1 是指重复字符位置的有一个大小。不能直接使用end，此时end是最末尾。
            start = MAX(start , charASCIIarray[s[end]] +1);
        }

        //更新当前charASCIIarray状态
        charASCIIarray[s[end]] = end;
        
        //更新maxLength状态
        maxLength = MAX(maxLength,end - start + 1);
    }
}
// @lc code=end

