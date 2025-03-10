class Solution {
 public: /// code written by sunny
  long long countOfSubstrings(string word, int maxConsonants) {
    return countSubstringsWithAtMost(word, maxConsonants) - countSubstringsWithAtMost(word, maxConsonants - 1);
  }

 private:
  long countSubstringsWithAtMost(const string& word, int maxConsonants) {
    if (maxConsonants == -1)
      return 0;

    long substringCount = 0;
    int vowelCount = 0;
    int distinctVowelCount = 0;
    unordered_map<char, int> lastVowelIndex;

    for (int left = 0, right = 0; right < word.length(); ++right) {
      if (isVowel(word[right])) {
        ++vowelCount;
        if (lastVowelIndex.find(word[right]) == lastVowelIndex.end() || lastVowelIndex[word[right]] < left)
          ++distinctVowelCount;
        lastVowelIndex[word[right]] = right;
      }
      while (right - left + 1 - vowelCount > maxConsonants) {
        if (isVowel(word[left])) {
          --vowelCount;
          if (lastVowelIndex[word[left]] == left)
            --distinctVowelCount;
        }
        ++left;
      }
      if (distinctVowelCount == 5)
        substringCount += min({lastVowelIndex['a'], lastVowelIndex['e'], lastVowelIndex['i'],
                               lastVowelIndex['o'], lastVowelIndex['u']}) -
                          left + 1;
    }

    return substringCount;
  }

  bool isVowel(char ch) {
    static constexpr string_view vowels = "aeiou";
    return vowels.find(ch) != string_view::npos;
  }
};