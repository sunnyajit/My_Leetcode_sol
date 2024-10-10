 class Solution {
public:
   // code written by sunny
   vector<int> relativeSortArray( vector<int>& arr1, vector<int>& arr2) {
   
     unordered_map<int, int> rank;
    for (int i = 0; i < arr2.size(); ++i) {
        rank[arr2[i]] = i;
    }

        auto compare = [&rank](int a, int b) {
       
        if (rank.find(a) != rank.end() && rank.find(b) != rank.end()) {
            return rank[a] < rank[b];
        }
      
        if (rank.find(a) != rank.end()) {
            return true;
        }
        if (rank.find(b) != rank.end()) {
            return false;
        }
    
        return a < b;
    };

 
    sort(arr1.begin(), arr1.end(), compare);

    return arr1;
}

int main() {
    // Example 1
    vector<int> arr1_1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2_1 = {2,1,4,3,9,6};
    vector<int> result1 = relativeSortArray(arr1_1, arr2_1);
    cout << "Output 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example 2
    vector<int> arr1_2 = {28,6,22,8,44,17};
    vector<int> arr2_2 = {22,28,8,6};
    vector<int> result2 = relativeSortArray(arr1_2, arr2_2);
    cout << "Output 2: ";
    for (int num : result2) {
       cout << num << " ";
    }
    cout << endl;

    return 0;
  }

};