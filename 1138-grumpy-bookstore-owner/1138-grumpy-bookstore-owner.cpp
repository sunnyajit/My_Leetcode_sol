 class Solution {
public: /// code written by sunny......
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int initialSatisfied = 0;

     for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            initialSatisfied += customers[i];
        }
    }
    int maxExtraSatisfied = 0;
    int currentExtraSatisfied = 0;
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            currentExtraSatisfied += customers[i];
        }
    }
       maxExtraSatisfied = currentExtraSatisfied;
      for (int i = minutes; i < n; ++i) {
          if (grumpy[i] == 1) {
            currentExtraSatisfied += customers[i];
          }
         if (grumpy[i - minutes] == 1) {
            currentExtraSatisfied -= customers[i - minutes];
        }
           maxExtraSatisfied = std::max(maxExtraSatisfied, currentExtraSatisfied);
      }

      return initialSatisfied + maxExtraSatisfied;
}
int main() {
    std::vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
    std::vector<int> grumpy = {0, 1, 0, 1, 0, 1, 0, 1};
    int minutes = 3;
    int result = maxSatisfied(customers, grumpy, minutes);
    std::cout << "Maximum number of satisfied customers: " << result << std::endl;
    return 0;
  }
};