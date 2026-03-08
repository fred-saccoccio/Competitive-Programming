#include <bits/stdc++.h>

using namespace std;

class StringSplitter {
  public:
    static std::vector<std::string> split(const std::string& str,
        const std::string& delimiters,
        bool keepEmpty = false) {
      std::vector<std::string> tokens;
      std::string::size_type pos = 0;
      std::string::size_type prev = 0;
      
      while ((pos = str.find_first_of(delimiters, prev)) != std::string::npos) {
        if (keepEmpty || pos > prev) {
          tokens.push_back(str.substr(prev, pos - prev));
        }
        prev = pos + 1;
      }
      
      if (prev < str.length()) {
        tokens.push_back(str.substr(prev));
      } else if (keepEmpty && prev == str.length()) {
        tokens.push_back("");
      } 
      
      return tokens;
    }
};

int main (int argc, char *argv[]) {
  string input;
  unordered_map<string,char> access_log;
  size_t movementsNumber = 0;

  cin >> movementsNumber;
  cin.ignore();

  for(size_t i = 0; i < movementsNumber; i++) {
    getline(cin, input);
    auto tokens = StringSplitter::split(input, " ");
    auto findIt = access_log.find(tokens[1]);
    cout << tokens[1] << " ";
    if(tokens[0] == "entry") {
      cout << "entered";
      if(findIt != access_log.end()) {
        cout << " (ANOMALY)";
      } else {
        access_log.insert({tokens[1],'#'});
      }
    } else if(tokens[0] == "exit") {
      cout << "exited";
      if(findIt == access_log.end()) {
        cout << " (ANOMALY)";
      } else {
        access_log.erase(tokens[1]);
      }
    }
    cout << "\n";
  }
}

