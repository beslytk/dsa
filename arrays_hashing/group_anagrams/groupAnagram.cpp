/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Strategy:
    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            // get unique key for given string based on number of occurence of each char
            string key = getKey(strs[i]); 
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a'));
        }
        return key;
    }
};

int main(){

    Solution s;
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string> > outArrArr = s.groupAnagrams(strs);
    for(auto outArr: outArrArr){
        for(auto wrd: outArr){
            cout<<wrd<<" ";
        }
        cout<<"\n-----------"<<endl;
    }
    return 0;
}