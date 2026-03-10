#include <bits/stdc++.h>

using namespace std;

class CustomComparator {
  
  public:
    CustomComparator() {}

    bool operator()(string a, string b) const {
      // Use customParam in your comparison logic : return a < b
      transform(a.begin(), a.end(), a.begin(), ::toupper);
      transform(b.begin(), b.end(), b.begin(), ::toupper);
      
      return  a < b; 
    }
};

void display_by_col(vector<string> m) {
  size_t cols = m[0].size();
  for(size_t j = 0; j < cols; j++) {
    for(size_t i = 0; i < m.size(); i++) {
      cout << m[i][j];
    }
    cout << "\n";
  }
} 

int main (int argc, char *argv[]) {
  vector<string> d = { "tOOth", "brother", "Anime", "animal" };
  CustomComparator comp;
  sort(d.begin(), d.end(), comp);
  
  size_t r,c;
  cin >> r >> c;
  cin.ignore();
   
  while(r != 0 && c != 0) {
    vector<string> columns;
    
    // Initialize the columns vector
    for(size_t i = 0; i < c; i++) {
      columns.push_back("");
    }
    
    for(size_t i = 0; i < r; i++) {
      string input;
      getline(cin, input);

      for(size_t j = 0; j < input.size(); j++) {
        columns[j] += input[j];
      }
    }

    sort(columns.begin(), columns.end(), comp);
    display_by_col(columns);
    cout << "\n";

    cin >> r >> c;
    cin.ignore();
  }
  
  return 0;
}

