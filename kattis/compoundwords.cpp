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
  vector<string> data;
  string input;
  while(getline(cin, input)) {
    auto tokens = StringSplitter::split(input, " ");
    for(auto& token:tokens) {
      data.push_back(token);
    }
  }
  map<string,char> ans;
  for(size_t i = 0; i < data.size()-1; i++){
    for(size_t j = i+1; j < data.size(); j++) {
        string s = data[i] + data[j];
        auto it = ans.find(s);
        if(ans.find(s) == ans.end())
          ans.insert({s,'#'});
        s = data[j] + data[i];
        it = ans.find(s);
        if(ans.find(s) == ans.end())
          ans.insert({s,'#'});
    }
  }
  for(auto& word:ans) {
    cout << word.first << "\n";
  }

  return 0;
}
