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
char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    if (namesSize != heightsSize)
    {
        return false;
    }
    char** sortArray = (char**)malloc(namesSize * sizeof(char**));

    if (sortArray == NULL) {
        return NULL; // 内存分配失败
    }


    free(free(myArray););
}
// @lc code=end

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义一个结构体来存储名字和身高
typedef struct {
    char *name;  //字符串（类似于一个一维数组）
    int height;
} Person;

// 比较函数，用于 qsort
int comparePersons(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return personB->height - personA->height; // 降序排序
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    if (namesSize != heightsSize) {
        return NULL;
    }

    // 创建一个结构体数组
    Person *people = (Person *)malloc(namesSize * sizeof(Person));
    if (people == NULL) {
        return NULL; // 内存分配失败
    }

    // 填充结构体数组
    for (int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    // 对结构体数组进行排序
    qsort(people, namesSize, sizeof(Person), comparePersons);

    // 创建返回的字符串数组
    char **sortedNames = (char **)malloc(namesSize * sizeof(char*));
    if (sortedNames == NULL) {
        free(people); // 释放之前分配的内存
        return NULL; // 内存分配失败
    }

    // 填充返回的字符串数组
    for (int i = 0; i < namesSize; i++) {
        sortedNames[i] = people[i].name;
    }

    // 设置返回大小
    *returnSize = namesSize;

    // 释放结构体数组
    free(people);

    return sortedNames;
}

// 测试函数
int main() {
    char *names[] = {"Mary", "John", "Emma"};
    int heights[] = {180, 165, 170};
    int returnSize;
    char **sortedNames = sortPeople(names, 3, heights, 3, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", sortedNames[i]);
    }

    // 释放返回的字符串数组
    free(sortedNames);

    return 0;
}
