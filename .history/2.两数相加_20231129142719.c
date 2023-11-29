/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (42.95%)
 * Likes:    10227
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 4.5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 *
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 *
 *
 * 示例 2：
 *
 *
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 *
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0
 * 题目数据保证列表表示的数字不含前导零
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    // 虚拟头节点 DummyHeadNode
    struct ListNode *dummyHeadNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = dummyHeadNode;
    int carry = 0;

    // 只有两个链表有任何一个不为空，则继续进行
    while (l1 != NULL || l2 != NULL)
    {
        int l1Value = (l1 != NULL) ? l1->val : 0;
        int l2Value = (l2 != NULL) ? l2->val : 0;
        int sum = l1Value + l2Value + carry;

        curry = sum / 10;

        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;

        // 两个链表往下循环
        if (l1 != NULL)
        {
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            l2 = l2->next;
        }
    }

    if (carry > 0)
    {
        current->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = carry;
        current->next = NULL;
    }

    struct ListNode *result = dummyHeadNode->next;
    free(dummyHeadNode);
    return result;
}
// @lc code=end
