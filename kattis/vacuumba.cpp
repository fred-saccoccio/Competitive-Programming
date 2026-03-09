#include <bits/stdc++.h>

using namespace std;

typedef pair<double,double> segment;
typedef vector<segment> test_case;

int main (int argc, char *argv[]) {
  size_t tests_number = 0;
  vector<test_case> test_cases;
  cin >> tests_number;
  cin.ignore();

  // Read and store input data
  for(size_t i = 0; i < tests_number; i++) {
    size_t segments_number;
    cin >> segments_number;
    test_case tc;
    for(size_t s = 0; s < segments_number; s++) {
      double angle;
      double distance;
      cin >> angle >> distance;
      tc.push_back({angle,distance});
    }
    test_cases.push_back(tc);
  }

  // Process data
  for(auto& c:test_cases) {
    double X = 0.0;
    double Y = 0.0;
    double alpha = 90.0;
    
    // Iterate through each segment
    for(auto& s:c) {
      alpha += s.first;
      X += s.second * cos(alpha / 180.0 * M_PI);
      Y += s.second * sin(alpha / 180.0 * M_PI);
    }

    cout << X << " " << Y << "\n";
  }

  return 0;
}
