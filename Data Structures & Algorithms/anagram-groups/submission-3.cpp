#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Hız aşırtma (I/O Optimization) - C++ giriş çıkışını hızlandırır
static const int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // PERFORMANS: Tıpkı UE5'teki TMap gibi, rehash maliyetini önlemek için baştan yer ayırıyoruz.
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        for (string& s : strs) {
            // PERFORMANS: sort() yerine 26 karakterlik sayıcı. O(K)
            // char kullanarak belleği ve key oluşturma süresini minimize ediyoruz.
            string key = string(26, 0); 
            for (char c : s) {
                key[c - 'a']++;
            }
            
            // PERFORMANS: move(s) ile string'i kopyalamıyoruz, doğrudan map'e taşıyoruz.
            groups[key].push_back(move(s));
        }

        vector<vector<string>> result;
        result.reserve(groups.size());
        
        for (auto& it : groups) {
            // PERFORMANS: Yine move kullanarak vektörü sonuç listesine taşıyoruz.
            result.push_back(move(it.second));
        }

        return result;
    }
};