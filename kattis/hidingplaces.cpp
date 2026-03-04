#include <bits/stdc++.h>

using namespace std;

class Chessboard {
  
  public:
    Chessboard();
    void Display();
    void SetCell(int rank, int file, char val);
    pair<int,int> Translate(string cell);
    string Normalize(int rank, int file);
    vector<string> HidingPlaces(string cell); 
  
  private:
    vector<pair<int,int>> KnightWalk(int rank, int file, int step);
    char board[8][8];
    const vector<int> deltasRank = {2, 1, -1, -2, -2, -1,  1,  2};
    const vector<int> deltasFile = {1, 2,  2,  1, -1, -2, -2, -1};
    void ResetBoard();
};

Chessboard::Chessboard() {
  ResetBoard();
}

void Chessboard::ResetBoard() {
  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
      board[i][j] = 0;
}

void Chessboard::SetCell(int rank, int file, char val) {
  board[rank][file] = val;
}

void Chessboard::Display() {
  cout << " +------------------------+\n";
  int count = 0;
  for(int rank = 7; rank >= 0; rank--) {
    cout << (rank+1) << "|";
    for(int file = 0; file < 8; file++) {
      
      if(count%2 == 0)
        printf("\033[47m\033[31m");
      else
        printf("\033[31m");
      
      printf(" %2x\033[0m", (unsigned char)board[rank][file]);
      count++;
    }
    count++;
    cout << "|\n";
  }

  cout << "-+------------------------+\n";
  cout << "  ";

  for(int i = 0; i < 8; i++)
    cout << " " << (char)('a'+i) << " ";

  cout << "\n";
}

pair<int,int> Chessboard::Translate(string cell) {
  pair<int,int> retVal;
  int rank = cell[1] - '1';
  int file = cell[0] - 'a';
  retVal.first = rank;
  retVal.second = file;
  return retVal;
}

string Chessboard::Normalize(int rank, int file) {
  char cRank = rank + '1';
  char cFile = file + 'a';
  string retVal;
  retVal += cFile;
  retVal += cRank;
  return retVal;
}

vector<string> Chessboard::HidingPlaces(string cell) {
  vector<string> retVal;
  pair<int,int> rankFile = Translate(cell);

  ResetBoard();

  SetCell(rankFile.first, rankFile.second, -1);
  int step = 0;
  set<pair<int,int>> cells;
  cells.insert({rankFile.first, rankFile.second});
  do {
    set<pair<int,int>> loopCells;
    for(auto& cell:cells) {
      vector<pair<int,int>> vCells = KnightWalk(cell.first, cell.second, step);
      for(auto& c:vCells) {
          loopCells.insert(c);
      }
    }
    cells = loopCells;
    
    step++;

    Display();

  } while(cells.size() != 0);

  cout << "max jumps = " << (step-1) << "\n";
  int max = step-1;
  vector<pair<int,int>> vAns;
  for (int i = 7; i >= 0; i--) {
    for(int j = 0; j < 8; j++) {
      if(board[i][j] == max) {
        vAns.push_back({i,j});
      }
    }
  }

  cout << "ANSWER = ";
  for(auto& c:vAns) {
    cout << Normalize(c.first, c.second) << " " ;
  }
  cout << "\n";

  return retVal;
}

vector<pair<int,int>>Chessboard::KnightWalk(int rank, int file, int step) {
  printf("KnightWalk(%d,%d,%d)\n", rank, file, step);
  
  vector<pair<int,int>> impactedCells;
  
  for(size_t index = 0; index < deltasFile.size(); index++) {
    int r = rank + deltasRank[index];
    int f = file + deltasFile[index];
    if(0 <= f && f < 8 && 0 <= r && r < 8) {
      if(board[r][f] == 0) {
        board[r][f] = (step + 1);
        impactedCells.push_back({r,f});
      }
    }
  }

  return impactedCells;
}

int main (int argc, char *argv[]) {
  Chessboard cb;
  cb.HidingPlaces("d5");

  cout << "################################################################################\n";

  cb.HidingPlaces("a1");

  return 0;
}
