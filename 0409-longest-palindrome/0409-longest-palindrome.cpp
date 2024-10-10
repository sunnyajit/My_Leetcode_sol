 class Solution {
public: // code written by sunny
     int longestPalindrome(string s) {
    unordered_map<char, int> charCount;
    
    // Count the frequency of each character
    for (char c : s) {
        charCount[c]++;
    }
    
    int length = 0;
    bool oddFound = false;
    
    // Calculate the length of the longest palindrome
    for (auto& count : charCount) {
        if (count.second % 2 == 0) {
            length += count.second;
        } else {
            length += count.second - 1;  // Use the even part of the count
            oddFound = true;  // Mark that we have at least one odd count
        }
    }
    
    // If there's any odd count, we can place one character in the center
    if (oddFound) {
        length++;
    }
    
    return length;
}

int main() {
    string s = "abccccdd";
    cout << "The length of the longest palindrome that can be built is: " << longestPalindrome(s) << endl;
    
    s = "a";
    cout << "The length of the longest palindrome that can be built is: " << longestPalindrome(s) << endl;

    return 0;
}

};


 