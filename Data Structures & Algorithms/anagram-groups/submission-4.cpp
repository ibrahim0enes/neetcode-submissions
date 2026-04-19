#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// I/O Optimizasyonu: C++ akışlarını hızlandırır.
static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // PERFORMANS 1: Bellek yönetimini hızlandırmak için map yerine rehash maliyeti düşük bir yapı.
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        // PERFORMANS 2: Her döngüde 'new' yapmamak için key'i dışarıda tanımlıyoruz. (Allocation Avoidance)
        string key(26, 0);

        for (string& s : strs) {
            // Key'i sıfırla (Burası memset kadar hızlıdır)
            fill(key.begin(), key.end(), 0);
            
            // Karakter sayımı (Cache-friendly loop)
            for (char c : s) {
                key[c - 'a']++;
            }
            
            // PERFORMANS 3: move(s) kullanarak string içeriğini kopyalamadan 'taşıyoruz'.
            groups[key].push_back(move(s));
        }

        vector<vector<string>> result;
        result.reserve(groups.size());
        
        for (auto& entry : groups) {
            // PERFORMANS 4: entry.second bir vector<string>, onu kopyalamadan sonuç listesine taşıyoruz.
            result.push_back(move(entry.second));
        }

        return result;
    }
};