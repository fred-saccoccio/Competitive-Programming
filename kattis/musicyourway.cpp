#include <bits/stdc++>
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

typedef pair<vector<string>,size_t> Entry;

namespace ref {
  int index = 0;
}

int main (int argc, char *argv[]) {
  vector<Entry> Entries;
  vector<string> Queries;
  unordered_map<string,size_t> fields;
  string input;
  getline(cin, input);
  auto tokens = StringSplitter::split(input, " ");
  size_t index = 0;
 
  // Read the fields' names
  for(auto& field:tokens) {
    fields.insert({field, index});
    index++
  }

  cin.ignore();

  size_t nbEntries;
  cin >> nbEntries;

  for(size_t index = 0; index < nbEntries; index++) {
    getline(cin, input);
    auto tokens = StringSplitter::split(input, " ");
    Entry e;
    e.first = tokens;
    e.second = index;
    Entries.push_back(e);
  }

  // Process queries
  cin.ignore();
  cin >> nbEntries;
  for(size_t index = 0; index < nbEntries; index++) {
    getline(cin, input);
    // Queries.push_back()
  }

  return 0;
}
