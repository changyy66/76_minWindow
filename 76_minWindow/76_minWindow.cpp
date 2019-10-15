// 76_minWindow.cpp : 定义控制台应用程序的入口点。
//

/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
			//属于匹配字符
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

