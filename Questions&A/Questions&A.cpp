//宇宙总统
/*#include <iostream>
#include <cstring>
using namespace std;
int main() 
{
    int n, id; // id 记录当上总统的人的号数
    string max = ""; // 赋初值，这个 max 不可以作为全局变量（会重名）
    // 如果一定要把 string max 放到全局变量去，应去掉 using namespce std;
    string in;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in;
        int inSize = in.size();
        int maxSize = max.size();
        if (inSize > maxSize || (inSize >= maxSize && in > max)) {
            max = in;
            id = i;
        }
    }
    cout << id << endl << max << endl;
    return 0;
}*/
//本题解答巧妙运用了字符串来比较特别大的数字，还有可以用strcmp和strlenC语言风格解答

//明明的随机数
/*#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 去重：保留最后一个出现的元素
    vector<int> unique_arr;
    for (int i = 0; i < n; i++) {
        bool is_last = true;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                is_last = false;
                break;
            }
        }
        if (is_last) {
            unique_arr.push_back(arr[i]);
        }
    }

    // 排序并输出
    sort(unique_arr.begin(), unique_arr.end());
    for (int num : unique_arr) {
        cout << num << " ";
    }
    return 0;
}*/

//拼数
/*#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
bool cmp(const string& a, const string& b) {
    return (a + b > b + a);
}
int main()
{
    int n = 0;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) cout << s[i];
    cout << endl;

    return 0;
}*/

//字符串中 最长的不重复字符串个数
/*#include <string.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;  // 空字符串直接返回0

    int maxLen = 0;

    for (int i = 0; i < len; i++) {
        bool visited[128] = { false };  // 记录当前子串中的字符是否出现过
        int currentLen = 0;

        for (int j = i; j < len; j++) {
            char currentChar = s[j];
            if (visited[currentChar]) {  // 如果字符已经出现过，就停止
                break;
            }
            visited[currentChar] = true;  // 标记为已访问
            currentLen++;
        }

        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}*/

//链表两两交换节点
/*#include <stdlib.h>

struct ListNode* swapPairs(struct ListNode* head) {
    // 创建虚拟头节点，简化头节点交换
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;

    while (prev->next != NULL && prev->next->next != NULL) {
        // 待交换的两个节点
        struct ListNode* node1 = prev->next;
        struct ListNode* node2 = prev->next->next;

        // 交换节点
        prev->next = node2;       // 前驱节点指向 node2
        node1->next = node2->next; // node1 指向 node2 的下一个节点
        node2->next = node1;      // node2 指向 node1

        // 移动 prev 到下一对待交换节点的前驱位置
        prev = node1;
    }

    return dummy.next;
}*/

//最长回文子串
#include <string.h>
#include <stdlib.h>

// 辅助函数：从中心向两边扩展，返回回文串的长度
int expandAroundCenter(char* s, int left, int right) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;  // (right - left + 1) - 2
}

char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) < 1) return "";

    int start = 0, end = 0;  // 记录最长回文串的起始和结束位置
    for (int i = 0; i < strlen(s); i++) {
        int len1 = expandAroundCenter(s, i, i);      // 奇数长度回文（如 "aba"）
        int len2 = expandAroundCenter(s, i, i + 1);  // 偶数长度回文（如 "abba"）
        int maxLen = len1 > len2 ? len1 : len2;
        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }
    }

    // 提取最长回文子串
    char* result = (char*)malloc(sizeof(char) * (end - start + 2));
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0';
    return result;
}