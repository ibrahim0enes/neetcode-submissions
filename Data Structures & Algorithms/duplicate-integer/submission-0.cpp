class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Modern for döngüsü kullanırken indeksi dışarıda tutabiliriz (C++20 öncesi)
        int i = 0;
        for (int sayi : nums) {
            int j = 0;
            for (int check : nums) {
                // Sadece farklı kutucuklardaki sayıları karşılaştır (i != j)
                if (i != j && sayi == check) {
                    return true; // Kopya bulduk
                }
                j++;
            }
            i++;
        }
        return false; // Hiç kopya bulunamadı
    }
};