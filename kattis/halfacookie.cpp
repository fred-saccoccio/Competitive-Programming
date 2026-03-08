#include <bits/stdc++.h>

using namespace std;

typedef struct {
  double r;
  double x;
  double y;
} Entry;

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

const double epsilon = 0.001;

int main (int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  vector<Entry> Entries;
  string input;
  while(getline(cin, input)) {
    auto tokens = StringSplitter::split(input, " ");
    Entry e;
    e.r = stod(tokens[0]);
    e.x = stod(tokens[1]);
    e.y = stod(tokens[2]);
    Entries.push_back(e);
  }

  for(auto& e:Entries) {
    double d = sqrt(e.x*e.x + e.y * e.y);
    if( (e.r - d) < epsilon ) {
      // (x,y) is considered outside the circle with radius r
      cout << "miss\n";
      continue;
    }
    double theta = 2*acos(d/e.r);
    double area_segment = 0.5*(e.r * e.r *(theta - sin(theta)));
    double area_remainder = M_PI*e.r*e.r - area_segment;
    cout << max(area_segment, area_remainder) << " " << min(area_segment, area_remainder) << "\n";
  }

  return 0;
}
