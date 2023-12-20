/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.78%)
 * Likes:    6907
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 *
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */

// @lc code=start

// 时间复杂度限定为 O(log(m+n))，一眼 二分查找的思想

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
    {
        // 保证 nums1 是较短的数组
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int x = nums1Size;
    int y = nums2Size;
    int low = 0;
    int high = x;

    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX)
        {
            if ((x + y) % 2 == 0)
            {
                // 如果总长度为偶数，返回中间两个数的平均值
                return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
            }
            else
            {
                // 如果总长度为奇数，返回较大的中间数
                return max(maxX, maxY);
            }
        }
        else if (maxX > minY)
        {
            high = partitionX - 1;
        }
        else
        {
            low = partitionX + 1;
        }
    }

    // 如果程序执行到这里，说明输入数组不是按照升序排列的，这是一个非预期的情况
    // 在实际应用中，可能需要根据具体情况处理这种情况
    return 0.0;
}

// 时间复杂度太高了

// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//     int totalSize = nums1Size + nums2Size;
//     int merged[totalSize];

//     // 合并两个有序数组
//     int i = 0, j = 0, k = 0;
//     while (i < nums1Size && j < nums2Size) {
//         if (nums1[i] < nums2[j]) {
//             merged[k++] = nums1[i++];
//         } else {
//             merged[k++] = nums2[j++];
//         }
//     }

//     // 将剩余的元素加入合并后的数组
//     while (i < nums1Size) {
//         merged[k++] = nums1[i++];
//     }
//     while (j < nums2Size) {
//         merged[k++] = nums2[j++];
//     }

//     // 计算中位数
//     if (totalSize % 2 == 0) {
//         // 如果数组长度为偶数，返回中间两个数的平均值
//         int mid = totalSize / 2;
//         return (merged[mid - 1] + merged[mid]) / 2.0;
//     } else {
//         // 如果数组长度为奇数，返回中间的数
//         return merged[totalSize / 2];
//     }
// }

// @lc code=end
