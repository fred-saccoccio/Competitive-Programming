#include <bits/stdc++.h>
using namespace std;

// Returns :
//   “arithmetic” if the sequence is an arithmetic sequence.
//   “permuted arithmetic” if the sequence can be reordered to make an arithmetic sequence. 
//   “non-arithmetic” otherwise
string check_sequence(vector<int>& s) {

  // 0, 1 or 2 numbers long sequence is de facto arithmetic
  if(s.size() <= 2)
    return string("arithmetic");

  int diff = s[0] - s[1];
  bool is_arith = true;
  for(size_t index = 1; index < s.size()-1; index++) {
    int delta = s[index] - s[index+1];
    if(delta != diff) {
      is_arith = false;
      break;
    }
  }

  // Arithmetic sequence match !
  if(is_arith) {
    return string("arithmetic");
  }

  sort(s.begin(), s.end());
  diff = s[0] - s[1];
  is_arith = true;
  for(size_t index = 1; index < s.size()-1; index++) {
    int delta = s[index] - s[index+1];
    if(delta != diff) {
      is_arith = false;
      break;
    }
  }

  if(is_arith) {
    return string("permuted arithmetic");
  } else {
    return string("non-arithmetic");
  }
}

int main (int argc, char *argv[]) {
  vector<string> results;
  size_t sequences_number = 0;
  cin >> sequences_number;

  for(size_t index = 0; index < sequences_number; index++) {
    size_t sequence_size = 0;
    vector<int> sequence;
    cin >> sequence_size;
    int current_number = 0;
    for(size_t i = 0; i < sequence_size; i++) {
      cin >> current_number;
      sequence.push_back(current_number);
    }

    results.push_back(check_sequence(sequence));
  }

  for(auto& result:results) {
    cout << result << "\n";
  }

  return 0;
}
