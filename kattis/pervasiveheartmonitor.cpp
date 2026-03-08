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
  vector<pair<double,string>> ans;

  while(getline(cin, input)) {
    vector<string> vID;
    vector<double> beats;
    auto tokens = StringSplitter::split(input, " ");
    
    for(auto& token:tokens) {
      if(isalpha(token[0])) {
        vID.push_back(token);
      } else {
        beats.push_back(stod(token));
      }
    }
    
    double agv = 0.0;
    
    for(auto& a:beats) {
      agv += a;
    }
    
    agv /= (double)beats.size();
    string ID;
    
    for(size_t index = 0; index < vID.size(); index++) {
      ID += vID[index];
      if(index != vID.size()-1)
        ID += " ";
    }

    pair<double,string> entry = {agv, ID};
    ans.push_back(entry);
  }

  for(auto& resp:ans) {
    cout << resp.first << " " << resp.second << "\n";
  }

  return 0;
}

