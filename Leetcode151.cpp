#include <vector>
#include <string>

using namespace std;

/*
ԭ�ط�ת��
1������ȥ������ո�
2����ÿ������ԭ�ط�ת��Ȼ�������ַ�����ת

*/
class Solution {
public:
    void reverse(string& s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        //˫ָ��ȥ������ո�
        //ʹ��˫ָ������ĸ��������ȥ��β�ո������𵥴ʽ���
        //i�ҵ�һ����Ϊ�ո����ĸʱ���ҵ���һ�����ʵĿ�ͷ�����������ǰ����ӿո�
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (j != 0) s[j++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[j++] = s[i++];
                }
            }
        }
        s.resize(j);//������1������Ϊȥ���ո���ַ����ĳ��ȡ�
        reverse(s, 0, s.size() - 1);
        int start = 0; //ȥ������ո��֤��һ�����ʵĿ�ʼ�±�һ����0��
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { //����ո���ߴ�β��˵��һ�����ʽ��������з�ת��
                reverse(s, start, i - 1); //��ת��ע��������ұ� []�ķ�ת��
                start = i + 1; //������һ�����ʵĿ�ʼ�±�start
            }
        }
        return s;
    }
};