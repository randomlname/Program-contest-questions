//Nwabunor Onwuanyi
//5420.cpp 487-3279

#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;

char getChar(char);
string convertToNum(string);

int main() {
  map<string,int> set;
  map<string,int>::iterator it;
  int testCases;
  cin >> testCases;
  while (testCases--) {
    cin.ignore(); // ignore blank line

    int numOfTele;
    cin >> numOfTele;

    for (int i = 0; i < numOfTele; i++) {
      string numbers;
      string ans;
      cin >> numbers;

      ans = convertToNum(numbers);
      it = set.find(ans);

      if (it == set.end()) {
        set.insert(pair<string,int>(ans,1));
      } else {
        it -> second = it -> second + 1;
      }
    }

    bool found = false;
    for (it = set.begin(); it != set.end(); it++) {
      if (it -> second > 1) {
        found = true;
        cout << it -> first << " " << it -> second << endl;
      }
    }
    if (!found) {
      cout << "No duplicates." << endl;
    }
  }
  return 0;
}

string convertToNum(string str) {
  string temp; // for storing strings like 4873279 or 888-GlOP for the conversion
  char temp1; // storing a character from  temp
  int size = str.length(); // get the size of our string

  for (int i = 0; i < size; i++) { // for the size of the string
    if (str.at(i) != '-') {  // if out string at postion i is not -
      temp1 = getChar(str.at(i)); // we get the character in that postion
      temp = temp + temp1; // and add it to a new string (1)
    }
  }

  string temp2; // for storing the new converted string  (2)
  size = temp.length(); // size of our string from (1)

  for (int i = 0; i < size; i++){ // for the size of the string
    if (i == 3) { // if i is 3
      temp2 = temp2 + '-'; // we insert - to make it like the end result 487-3279
    } else { // otherwise
      temp2 = temp2 + temp.at(i); // we the character at i to a new string (2)
    }
  }
  return temp2; // return the new string (2)
}

// map the characters to number
char getChar(char charr) {
    switch(charr) {
    case 'A':
    case 'B':
    case 'C':
        return '2'; // 2 coresponds to  A B C
    case 'D':
    case 'E':
    case 'F':
        return '3'; // 3 coresponds to  D E F
    case 'G':
    case 'H':
    case 'I':
        return '4'; // 4 coresponds to  G H I
    case 'J':
    case 'K':
    case 'L':
        return '5'; // 5 coresponds to  J K L
    case 'M':
    case 'N':
    case 'O':
        return '6'; // 6 coresponds to  M N O
    case 'P':
    case 'R':
    case 'S':
        return '7'; // 7 coresponds to  P R S
    case 'T':
    case 'U':
    case 'V':
        return '8'; // 8 coresponds to  T U V
    case 'W':
    case 'X':
    case 'Y':
        return '9'; // 9 coresponds to  W X Y
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
       return charr;  // return the number if it already is one
    }
    return ' ';
}
