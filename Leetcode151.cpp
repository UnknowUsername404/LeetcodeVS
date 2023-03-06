#include <vector>
#include <string>

using namespace std;

/*
原地反转：
1、首先去除多余空格
2、将每个单词原地反转，然后将整个字符串反转

*/
class Solution {
public:
    void reverse(string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        //双指针去除多余空格
        //使用双指针逐字母处理不容易去除尾空格，这里逐单词进行
        //i找到一个不为空格的字母时即找到了一个单词的开头，在这个单词前面添加空格
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (j != 0) s[j++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[j++] = s[i++];
                }
            }
        }
        s.resize(j);//最后加了1，所以为去除空格后字符串的长度。
        reverse(s, 0, s.size() - 1);
        int start = 0; //去除多余空格后保证第一个单词的开始下标一定是0。
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。
                start = i + 1; //更新下一个单词的开始下标start
            }
        }
        return s;
    }
};