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
  vector<pair<int,int>> Entries;
  string input;
  
  while(getline(cin, input)) {
    auto tokens = StringSplitter::split(input, " ");
    pair<int,int> Entry = { stoi(tokens[0]), stoi(tokens[1]) };
    Entries.push_back(Entry);
  }

  for(auto& e:Entries) {
    if(e.first == e.second)
      continue;
    if(e.first > e.second)
      cout << "More\n";
    else {
      cout << "Less\n";
    }
  }
 
  return 0;
}
