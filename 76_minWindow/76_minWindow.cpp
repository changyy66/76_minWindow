// 76_minWindow.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
����һ���ַ��� S��һ���ַ��� T�������ַ��� S �����ҳ������� T ������ĸ����С�Ӵ���

ʾ����

����: S = "ADOBECODEBANC", T = "ABC"
���: "BANC"
˵����

��� S �в����������Ӵ����򷵻ؿ��ַ��� ""��
��� S �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ𰸡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/minimum-window-substring
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
#include "stdafx.h"
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size() == 0 || t.size() == 0||s.size()<t.size())return "";
// 		if (t.size() == 1)
// 		{
// 			if (s.find(t[0]) != string::npos)return t;
// 			return "";
// 		}
		int sLen = s.size();
		int tLen = t.size();
		map<char,int>tMap;
		map<char, int>posMap;
		queue<int> posSet;
		int matchLen = 0;
		int minLen = sLen + 1;
		string matchS = "";
		for (int i=0;i<tLen;i++)
		{
			if (tMap.count(t[i]) > 0)
				tMap[t[i]]++;
			else
				tMap[t[i]] = 1;
		}

		for (int i=0;i<sLen;i++)
		{
			//����ƥ���ַ�
			int num = tMap[s[i]];
			if (num>0)
			{
				posMap[s[i]]++;
				posSet.push(i);

				if (posMap[s[i]] <= num)
				{
					matchLen++;
				}
				while (matchLen==tLen)
				{
					int pos = posSet.front();
					if (posMap[s[pos]] == tMap[s[pos]])
					{
						if (minLen>(i-pos+1))
						{
							minLen = i - pos + 1;
							matchS = s.substr(pos, minLen);
						}
						matchLen--;
					}
					posSet.pop();
					posMap[s[pos]]--;
				}
			}
		}
		return matchS;
	}
};

int main()
{
	string S = "a", T = "a";
	Solution s0;
	cout << s0.minWindow(S, T);

    return 0;
}

