  class Solution {
public: // code written by sunny
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> queue;
        for (int card : deck) {
            if (!queue.empty()) {
                queue.push_front(queue.back());
                queue.pop_back();
            }
            queue.push_front(card);
        }
        return vector<int>(queue.begin(), queue.end());
    }
};