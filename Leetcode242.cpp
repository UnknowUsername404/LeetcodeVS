#include <iostream>
#include <vector>
using namespace std;

/*
��1�������ⷨ:
����ֻ����Сд��ĸ������ʹ����������Ϊ��ϣ��
ʹ��������ϣ���ֱ��¼s��t�ַ����и��ַ����ֵĴ�����Ȼ��Աȣ����������һ����Ϊ��λ��

�Ż���
���ȱȽ�s��t�ĳ��ȣ����Ȳ�һ����϶���Ϊ��λ�ʡ�
ʹ��һ����ϣ��s��t��������ϣ���е����ֶ�Ϊ0���ʾs��tΪ��λ�ʡ�


��2������--����unicode�ַ�
*/



class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> num_s(26, 0);
        vector<int> num_t(26, 0);

        for (char it : s) {
            num_s[it - 'a']++;
        }

        for (char it : t) {
            num_t[it - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (num_s[i] != num_t[i]) return false;
        }
        return true;
    }
};