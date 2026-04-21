class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map: Key olarak karakter frekans tablosunu kullanacağız
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strs) {
            // Her kelime için 26 karakterlik frekans dizisi (a-z)
            string key = string(26, 0); 
            for (char c : s) {
                key[c - 'a']++;
            }
            // Sıralama yapmadan doğrudan map'e ekliyoruz
            groups[key].push_back(s);
        }

        vector<vector<string>> result;
        result.reserve(groups.size()); // Performans için bellek ayırma
        for (auto& entry : groups) {
            result.push_back(std::move(entry.second)); // move ile kopyalamadan kaçınma
        }
        return result;
    }
};