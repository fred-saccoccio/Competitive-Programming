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

typedef map<string,vector<string>> report;
typedef vector<vector<string>> entry;

void order(report& r) {
  for(auto& mapItem: r) {
    sort(mapItem.second.begin(), mapItem.second.end());
  } 
}

void print(report& r) {
  for(auto mapItem: r) {
    auto& key = mapItem.first;
    auto& value = mapItem.second;
    cout << key << " ";
    for(size_t index = 0; index < value.size(); index++) {
      cout << value[index];
      if(index != (value.size()-1) ) {
        cout << " ";
      } else {
        cout << "\n";
      }
    }
  }
  
  cout << "\n";
}

int main (int argc, char *argv[]) {
  vector<entry> entries;

  size_t entry_size;
  cin >> entry_size;
  cin.ignore();

  // Read and store input data
  while(entry_size != 0) {
    entry e;
    
    for(size_t index = 0; index < entry_size; index++) {
      string input;
      getline(cin, input);
      auto tokens = StringSplitter::split(input, " ");
      e.push_back(tokens);
    }

    entries.push_back(e);

    cin >> entry_size;
    cin.ignore();
  }


  // Process input data
  for(auto& e:entries) {
    report r;
    for(auto& item:e) {
      //
      for(size_t index = 1; index < item.size(); index++) {
        r[item[index]].push_back(item[0]);
      }
    }

    order(r);
    print(r);
  }
  
  return 0;
}

