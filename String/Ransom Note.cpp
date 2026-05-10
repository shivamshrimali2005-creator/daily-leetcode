// Problem Number: 383
// Problem Name: Ransom Note

// Approach
// Count frequency of every character in magazine.
// Traverse ransomNote and decrease frequency.
// If frequency becomes negative, return false.
// Otherwise return true.

// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int n1 = ransomNote.size();
        int n2 = magazine.size();

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for(auto x : magazine){
            freq1[x-'a']++;
        }

        for(auto x : ransomNote){
            freq2[x-'a']++;
        }

        for(int i=0;i<26;i++){
            if(freq1[i] < freq2[i]){
                return false;
            }
        }

        return true;
    }
};
