//Nwabunor Jeff Onwuanyi
//497.cpp

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main () {
  int Numcases;
  char missle[100];

  cin >> Numcases;
  cin.ignore();
  cin.ignore();

  //------------------------read numbers of testcases---------------------------
  while (Numcases--) {
    vector<int> missles;

    //----------read missle numbers and put them in a vector--------------------
    while (gets(missle)) {
      if (missle[0] == '\0') {
        break;
      }
      missles.push_back(atoi(missle));
    }
    //------------------------------end of missle read--------------------------

    //-----calculate best possible outcome and put it in a vector---------------
    int *temp1 = new int[missles.size()];
    int *temp2 = new int[missles.size()];
    int index = 0;
    int max = 1;
    vector<int> ans;

    fill(temp1,temp1 + missles.size(), 1);
    fill(temp2,temp2 + missles.size(), -1);

    for (int i = 0; i < missles.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (missles[i] > missles[j]) {
          if (temp1[j] + 1 > temp1[i]) {
            temp1[i] = temp1[j] + 1;
            if (max < temp1[i]) {
              max = temp1[i];
              index = i;
            }
            temp2[i] = j;
          }
        }
      }
    }

    ans.push_back(index);
    for (int i = 1; i < max; i++) {
      index = temp2[index];
      ans.push_back(index);
    }
    //---------------------------end of calculation-----------------------------

    //---------------------------print the output-------------------------------
    cout << "Max hits: " << max << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
      cout << missles[ans[i]] << endl;
    }
    //---------------------------end of output----------------------------------
  }
  //---------------------------end of while loop--------------------------------
  return 0;
}
