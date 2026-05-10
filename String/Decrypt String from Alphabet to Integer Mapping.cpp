# 1309. Decrypt String from Alphabet to Integer Mapping

## Difficulty
Easy

---

## Approach
- Traverse the string from left to right.
- If the current character forms a two-digit number followed by `#`,
  convert it into the corresponding alphabet character.
- Otherwise, convert the single digit directly into a character.
- Append each decoded character to the result string.

---

## Time Complexity
- **O(N)** → Single traversal of the string.

## Space Complexity
- **O(N)** → Extra space used for storing the answer string.

---

## C++ Solution

```cpp
class Solution {
public:
    string freqAlphabets(string s) {
        
        int n = s.size();
        string ans;

        for(int i = 0; i < n; i++) {

            // Check for two-digit number followed by '#'
            if(i + 2 < n && s[i + 2] == '#') {

                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                ans += ('a' + num - 1);

                i = i + 2;
            }
            else {

                ans += ('a' + (s[i] - '0') - 1);
            }
        }

        return ans;
    }
};
