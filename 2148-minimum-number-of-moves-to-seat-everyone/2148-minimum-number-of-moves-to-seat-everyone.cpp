 class Solution {
public:  // code written by sunny
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
    
       int totalMoves = 0;
       for (int i = 0; i < seats.size(); ++i) {
          totalMoves += abs(seats[i] - students[i]);
        }
    
        return totalMoves;
    }

    int main() {
    vector<int> seats1 = {3, 1, 5};
    vector<int> students1 = {2, 7, 4};
    cout << "Example 1 Output: " << minMovesToSeat(seats1, students1) << endl;

    vector<int> seats2 = {4, 1, 5, 9};
    vector<int> students2 = {1, 3, 2, 6};
    cout << "Example 2 Output: " << minMovesToSeat(seats2, students2) << endl;

    vector<int> seats3 = {2, 2, 6, 6};
    vector<int> students3 = {1, 3, 2, 6};
    cout << "Example 3 Output: " << minMovesToSeat(seats3, students3) << endl;

    return 0;
}


};