 class Solution {
public:
std::string toBinaryString(int number) {
    std::string binaryStr = std::bitset<32>(number).to_string(); // 32 bits max for our needs
    // Remove leading zeros
    binaryStr.erase(0, binaryStr.find_first_not_of('0'));
    return binaryStr.empty() ? "0" : binaryStr;
}
    string convertDateToBinary(string date) {
         std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    // Convert strings to integers
    int year = std::stoi(yearStr);
    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);

    // Convert integers to binary strings
    std::string yearBinary = toBinaryString(year);
    std::string monthBinary = toBinaryString(month);
    std::string dayBinary = toBinaryString(day);

    // Combine the binary representations into the final format
    std::ostringstream result;
    result << yearBinary << '-' << monthBinary << '-' << dayBinary;
    return result.str();
    }
};