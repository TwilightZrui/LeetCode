<!--
 * @Author: TwilightZrui 1193882630@qq.com
 * @Date: 2023-04-26 13:20:30
 * @LastEditors: TwilightZrui 1193882630@qq.com
 * @LastEditTime: 2023-04-26 13:26:26
 * @FilePath: /LeetCode/note/algorithm.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
## 在排序数组中查找一个target：二分查找

二分查找算法的基本思想是：

  将待查找区间的中间位置与目标值进行比较，进而缩小查找范围，直到找到目标值或确定不存在目标值为止。

二分查找的具体过程：

  1. 定义两个指针 left 和 right 分别指向数组的第一个元素和最后一个元素，定义一个变量 mid 表示中间位置。
  2. 如果目标值等于中间位置的值，则返回中间位置的下标。
  3. 如果目标值小于中间位置的值，则将 right 指针移动到 mid-1 的位置，即在左侧继续查找。
  4. 如果目标值大于中间位置的值，则将 left 指针移动到 mid+1 的位置，即在右侧继续查找。
  5. 重复上述步骤，直到找到目标值或者 left > right。

计算中间位置以便进行二分查找：

int mid = ((right - left) >> 1) + left;

```cpp

classSolution {
    public intsearchInsert(int[] nums, int target) {
      int left =0, right = nums.length -1; // 注意
      while(left <= right) { // 注意
          int mid = (left + right) /2; // 注意
          if(nums[mid] == target) { // 注意
                          // 相关逻辑
            } elseif(nums[mid] < target) {
                        // 相关逻辑
              left = mid +1; // 注意
              } else {
                right = mid -1; // 注意
                }
      }
              // 相关返回值
      return 0;
    }
}
```

## DP

写状态转移方程

注意一开始几种情况，要特别返回


## 递归

递去归来
