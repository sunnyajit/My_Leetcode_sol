 class Solution {
public:  // code written by sunny
 string toBinaryString(int number) {
   string binaryStr = std::bitset<32>(number).to_string();  
    binaryStr.erase(0, binaryStr.find_first_not_of('0'));
    return binaryStr.empty() ? "0" : binaryStr;
}
    string convertDateToBinary(string date) {
         std::string yearStr = date.substr(0, 4);
     string monthStr = date.substr(5, 2);
     string dayStr = date.substr(8, 2);
    int year = std::stoi(yearStr);
    int month = std::stoi(monthStr);
    int day = std::stoi(dayStr);
     string yearBinary = toBinaryString(year);
     string monthBinary = toBinaryString(month);
     string dayBinary = toBinaryString(day);
     ostringstream result;
    result << yearBinary << '-' << monthBinary << '-' << dayBinary;
    return result.str();
    }
};