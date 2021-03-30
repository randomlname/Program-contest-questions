//Nwabunor Jeff Onwuanyi
//116.cpp

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main () {

  int row, col;
  int arr[10][100];
  int arr2[10][100];

  //---------------------read the table-----------------------------------------
  while(cin >> row >> col) {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        cin >> arr[i][j];
      }
    }
    //-------------------------end of read--------------------------------------

    //------------------copy last row-------------------------------------------
    for (int i = 0; i < row; i++) {
      arr2[i][col-1] = arr[i][col-1];
    }
    //--------------------------------------------------------------------------

    //------------------find the cost of each spot in the table-----------------
    for (int k = col-2; k >= 0; k--) {
      for (int q = 0; q < row; q++) {
        long a = arr2[(q + row - 1) % row][k + 1];
        long b = arr2[(q)][k + 1];
        long c = arr2[(q + row + 1) % row][k + 1];
        arr2[q][k] = arr[q][k] + min(a,min(b,c));
      }
    }
    //--------------------------------------------------------------------------

    //----------------minimal path cost calculation-----------------------------
    int min = arr2[0][0];
    int bestIndex = 0;
    for (int j = 0; j < row; j++) {
      if (arr2[j][0] < min) {
        min = arr2[j][0];
        bestIndex = j;
      }
    }
    int bestCost = min;
    //---------------end of find minimal path cost------------------------------

    //--------------------find the lexicographical path-------------------------
    vector<int> path;
    path.push_back(bestIndex+1);
    for (int j = 0; j < col - 1; j++) {

        //--------find the three elements from the last best cost---------------
        long a = arr2[(bestIndex + row - 1) % row][j + 1];
        long b = arr2[bestIndex][j + 1];
        long c = arr2[(bestIndex + row + 1) % row][j + 1];
        //----------------------------------------------------------------------

        //-----put the three elements in a vector and find the smallest one-----
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        int sml = *std::min_element(temp.begin(),temp.end());
        //----------------------------------------------------------------------

        //---find the index of the new picked best cost and put it in the path--
        temp.clear();
        if (sml == a) {
            temp.push_back((bestIndex + row - 1) % row);
        }
        if (sml == b) {
            temp.push_back(bestIndex);
        }
        if (sml == c) {
            temp.push_back((bestIndex + row + 1) % row);
        }
        bestIndex = *std::min_element(temp.begin(), temp.end());
        path.push_back(bestIndex+1);
        //-------------end of find & replace index------------------------------
      }
      //------------end of lexicographical path find----------------------------

      // print the output-------------------------------------------------------
      for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
      }
      cout << endl;
      cout << bestCost << " ";
      cout << endl;
      //-----------end of print-------------------------------------------------
  }
  //------------------------end of while loop-----------------------------------
  return 0;
}
