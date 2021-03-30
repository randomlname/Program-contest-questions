//Nwabunor Onwuanyi
// 348.cpp

#include <iostream>
#include <string>

using namespace std;
/*
A Slump is a character string that has the following properties:
1. Its first character is either a ’D’ or an ’E’.                                   Rule 1
2. The first character is followed by a string of one or more ’F’s.                 Rule 2
3. The string of one or more ’F’s is followed by either a Slump or a ’G’.           Rule 3
//The Slump or ’G’ that follows the F’s ends the Slump.
//For example DFFEFFFG is a Slump since it has a ’D’ for its
//first character, followed by a string of two F’s, and ended by the Slump ’EFFFG’.
4. Nothing else is a Slump.

A Slimp is a character string that has the following properties:
1. Its first character is an ’A’.                                                  Rule 4
2. If it is a two character Slimp then its second and last character is an ’H’.    Rule 5
3. If it is not a two character Slimp then it is in one of these two forms:        Rule 6
a) ’A’ followed by ’B’ followed by a Slimp followed by a ’C’.
b) ’A’ followed by a Slump (see above) followed by a ’C’.
4. Nothing else is a Slimp.

*/
bool isSlump(int);

string word;
int sizee;

int main () {
  int testcases;

  cin >> testcases;

  cout << "SLURPYS OUTPUT" << endl;

  while (testcases--) {

    cin >> word;

    sizee = word.size();

    if (word[0] != 'A' || word[sizee - 1] != 'G' ) {   // check Rule 4 and Rule 3
      cout << "NO" << endl;
      continue;
    }

    int temp = 0;
    for (temp = 0; temp < sizee; ++temp ) {
      if((word[temp] == 'D' || word[temp] == 'E' ) && isSlump(temp)) { // check Rule 1, Rule 2 and Rule 3
        break;
      }
    }

    word.erase(temp); // delete all character except the first temp so if temp = 2 and word = AHDFG this after the operation word will have AH left
    sizee = temp;  // store the size of new string

    bool flag = true;

    while (word.size()) {
      if (word == "AH") {  // check Rule 5    2 character Slimp
        break;
      }

      if (word[0] != 'A' || word[sizee - 1] != 'C' || sizee <= 3) { // check Rule 4 and Rule 6
        flag = false;
        break;
      }

      if (word[1] == 'B') {  // check Rule 6
        word.erase(sizee - 1);
        word.erase(0,2);
        sizee -= 3;
        continue;
      } else {
        word.erase(sizee - 1);
        word.erase(0,1);
        sizee -= 2;
        flag = isSlump(0);
        break;
      }
    }
    
    if (flag == true) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  cout << "END OF OUTPUT" << endl;
  return 0;
}

bool isSlump(int pos) {
  // check if the word fits a slump rules
  for( int i = pos + 1; i < sizee - 1; i += 2 ) {
    while( word[i] == 'F' ) {
      ++i;
    }
    if( i == sizee - 1 ) {
      return  true;
    }
    if((word[i] != 'D' && word[i] != 'E') || i == sizee - 2 ) {
      return  false;
    }
  }
  return  true;
}
