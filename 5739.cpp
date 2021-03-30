//Nwabunor Onwuanyi
//5735.cpp user name
//https://github.com/huanghongxun/ACM/blob/master/UVaLive/p5739.cpp
#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>

using  namespace std;
const int MAX = 80;

int main(){
  char name[MAX];
  char userName[MAX];

  map<string,int> mapp;
  int caseNum = 1;
  int numOfNames;
  int maxlen;

  while(cin >> numOfNames >> maxlen) { // read in the numbers for names and max length
    if (numOfNames == 0 && maxlen == 0) { // if the number of names and max length = 0 end the program
      return 0;
    }

    mapp.clear(); // clear the map
    getchar(); // get character

    cout << "Case " << caseNum++ << endl; // print out the case number we doing

    while(numOfNames--) { // do the operations while number of names is not = 0
      int current;
      int length;
      int length1;

      gets(name); // get the a full name until a new line
      length = strlen(name); // get the length of the name
      userName[0] = tolower(name[0]); // make the first character of the name small and put it in the user name array
      current = length - 1; // lenth - 1 because we have taken the first letter out
      length1 = 1; // postion of userName array

      while(name[current] != ' ') { // if not equal to an empty space
        --current; // decrement current
      }

      for (int i = current+1; i < length && length1 < maxlen; ++i) {
        if (isalpha(name[i])){ // if name at i is a letter
          userName[length1++] = tolower(name[i]); // make it small add it to the
          //next spot in the username array and increment length1 or the next spot in userName array
        }
      }


      if (!mapp.count(userName)){ // if the user name is not in the map
        ++mapp[userName]; // add it to the map
        cout << userName << endl;  //output user name without serial number
        continue;
      }


      int serialNum = mapp[userName];
      int deleteLength;

      // determine how much of the length of the string we need to delete from the serial numbber
      if (serialNum >= 10) {
        deleteLength = 2;
      } else {
        deleteLength = 1;
      }

      if (maxlen - length1 >= deleteLength) { // if greater that deleteLength just print the regularly with serial number
        cout << userName << serialNum << endl; //output
        ++mapp[userName]; // add it to the map
        continue;
      }

      // otherwise delete the needed space (temp) from the current userName and print with serial number
      int temp;
      temp = deleteLength - maxlen + length1;
      ++mapp[userName]; // add it to the map
      userName[length1-temp] = 0;
      cout << userName << serialNum << endl;//output
    }
  }
  return 0;
}
