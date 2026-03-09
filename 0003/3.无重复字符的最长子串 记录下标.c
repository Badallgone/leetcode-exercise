/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int res = 0;
    int map[128] = {0};
    for (int i = 0, j = 0; j < len; j++) {
        if(map[s[j]])
            i = fmax(i, map[s[j]]);
        map[s[j]] = j + 1; // 存储字符上次出现的索引位置 + 1，避免与默认值 0 冲突
        res = fmax(res, j - i + 1);
    }
    return res;
}
// @lc code=end

/*
 *Accepted
 *988/988 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 13.89 % of c submissions (10.4 MB)
*/

/*核心逻辑：毛毛虫爬行你可以把 i 和 j 想象成一只毛毛虫的尾巴和头。
这只毛毛虫在字符串 s 上爬行，目标是找一段最长的身体，且身体覆盖的字符里没有重复的。
1. 角色分工
    j (右边界/头)：负责向右探索，不断把新字符纳入窗口。
    i (左边界/尾)：负责收缩。当发现重复字符时，尾巴必须向前挪，把旧字符踢出窗口。
    map (记事本)：记录当前窗口里已经有哪些字符了（整数表示上次出现的索引位置）。

2. 执行步骤分解向右扩张：
    j 指针不断向右移动。遇到冲突：如果 map[s[j]] 为 true，说明新进来的字符 s[j] 已经在窗口里了。
    
    断尾求生 (While 循环)：只要冲突还在（即 s[j] 还没被踢出去），尾巴 i 就要不断向前走。
    走一步，就把 s[i] 从 map 里抹掉 (false)。直到把那个和 s[j] 重复的旧字符踢出窗口，循环才停止。
    
    标记占位：把新字符 s[j] 标记为已存在 (true)。更新战果：j - i + 1 就是当前“无重复子串”的长度，用 fmax 取最大值。
    
为什么这种算法高效？
时间复杂度：O(n)。虽然代码里有个 while 嵌套在 for 里，但观察 i 和 j 指针：它们都只会从左向右走一遍，绝不回头。每个字符最多被“进入”窗口一次，被“踢出”窗口一次。
空间复杂度：O(1)（或者 O(k)，取决于字符集大小）。这里用了一个大小为 128 的数组（假设是 ASCII 字符），是常数级别的空间。

还可以优化吗？
这段代码虽然是 O(n)，但在极端情况下（比如字符串是 abcdefga），当 j 指向最后的 a 时，i 需要一个一个跳，直到跳过第一个 a。

进阶优化思路：
    我们可以不存 bool，而是存每个字符上次出现的索引位置。
    如果发现 s[j] 重复了，i 不用一个一个挪，而是直接瞬移到 last_index + 1。这样 i 的移动就从 while 循环变成了单次赋值。
*/