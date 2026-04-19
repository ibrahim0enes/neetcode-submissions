#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key olarak bu sefer string değil, karakter sayısını temsil eden bir yapı kullanacağız
        unordered_map<string, vector<string>> groups;

        for (const string& s : strs) {
            // 26 harf için bir frekans tablosu (a-z arası)
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

            // Bu sayıları bir "imza" stringine dönüştürerek key yapıyoruz
            // Örn: "1#0#1#0..." (1 tane a, 0 tane b, 1 tane c...)
            string key = "";
            for (int i : count) {
                key += "#" + to_string(i);
            }

            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        return result;
    }
};