 class Solution {
public: // code written by sunny..
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrinks = numBottles;
    int emptyBottles = numBottles;

    while (emptyBottles >= numExchange) {
        int newBottles = emptyBottles / numExchange;
        totalDrinks += newBottles;
        emptyBottles = emptyBottles % numExchange + newBottles;
    }

    return totalDrinks;
}

int main() {
    int numBottles, numExchange;
    
    // Example 1
    numBottles = 9;
    numExchange = 3;
    std::cout << "Example 1: " << numWaterBottles(numBottles, numExchange) << std::endl;  // Output: 13

    // Example 2
    numBottles = 15;
    numExchange = 4;
    std::cout << "Example 2: " << numWaterBottles(numBottles, numExchange) << std::endl;  // Output: 19

    return 0;
    }
};