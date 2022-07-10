#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

/*
    Given string, find longest substring w/o repeating chars
    Ex. s = "abcabcbb" -> 3 "abc", s = "bbbbb" -> 1 "b"
    Sliding window, expand if unique, contract if duplicate
    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;
        
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (j < s.size()) {
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                result = max(result, j - i + 1);
                j++;
            } else {
                letters.erase(s[i]);
                i++;
            }
        }
        
        return result;
    }
}; 

int main(){

    Solution s;
    string str = "abcabcbb";
    int len = s.lengthOfLongestSubstring(str);
    cout<<"longest substring length: "<<len;
    return 0;
}