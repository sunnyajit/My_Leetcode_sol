class Solution {
 public: // code written by sunny
  string nearestPalindromic(string numStr) {
    const auto& [prevPal, nextPal] = findPalindromes(numStr);
    return abs(prevPal - stol(numStr)) <= abs(nextPal - stol(numStr))
               ? to_string(prevPal)
               : to_string(nextPal);
  }

 private:
  pair<long, long> findPalindromes(const string& numStr) {
    const long num = stol(numStr);
    const int len = numStr.length();
    pair<long, long> pals;
    const string firstHalf = numStr.substr(0, (len + 1) / 2);
    const string revHalf = reverseStr(firstHalf.substr(0, len / 2));
    const long candidate = stol(firstHalf + revHalf);

    if (candidate < num)
      pals.first = candidate;
    else {
      const string prevHalf = to_string(stol(firstHalf) - 1);
      const string revPrevHalf = reverseStr(prevHalf.substr(0, len / 2));
      if (len % 2 == 0 && stol(prevHalf) == 0)
        pals.first = 9;
      else if (len % 2 == 0 && prevHalf == "9")
        pals.first = stol(prevHalf + '9' + revPrevHalf);
      else
        pals.first = stol(prevHalf + revPrevHalf);
    }

    if (candidate > num)
      pals.second = candidate;
    else {
      const string& nextHalf = to_string(stol(firstHalf) + 1);
      const string& revNextHalf = reverseStr(nextHalf.substr(0, len / 2));
      pals.second = stol(nextHalf + revNextHalf);
    }

    return pals;
  }

  string reverseStr(const string& s) {
    return {s.rbegin(), s.rend()};
  }
};