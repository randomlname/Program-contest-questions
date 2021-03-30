//Nwabunor Onwuanyi
//5733.cpp iterated difference

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
const int MAX = 20;
bool equall(vector<int>);

int main() {
  int numOfEle;
  int iterated = -1; // -1 to represent no iteration possible also handle the case of it iterating to 0 0 0 0 for some reason
  int CaseNum = 1;

  Start:
  // while loop start___________________________________________________________
  while(cin >> numOfEle) {
    if (numOfEle == 0) { // if number of element in the list is 0 exit
      return 0;
    }

    vector<int> vec(MAX);
    vector<int> vec2(MAX);

    for(int i = 0; i < numOfEle; i++) {
      int temp; // temp to use of the elements in the list
      cin >> temp; // while not equal to the number of elemets in the list take in the next element
      vec[i] = temp; // put the next element in the vector
    }

    Loop:
    for (int i = 0; i < numOfEle; i++) {
      int temp2;
      int first = vec[0];  //keep track of the first element in the list
      if (i == numOfEle - 1) { // if we hit the end of the list subtract it with the first element in the list
        temp2 = abs(vec[i] - first); // subtration with the first element of the list
        vec2[i] = temp2;  // put result in vector
      } else { // else we subtract the current element with the next element in the list
        temp2 = abs(vec[i] - vec[i+1]);
        vec2[i] = temp2; // put result in vector
      }
    }

    iterated++; // increment the iteration
    if (iterated >= 1000) { // if the iteration is above 1000 we go to no solution
      goto NoSolution;
    }
    for (int k = 0; k < numOfEle; k++) {  // put the new list in the original vector
      vec[k] = vec2[k];
    }

    if (equall(vec)) { // check if the vector contains all the same elements
      goto Solution; // go to solution and output the number of iteration
    } else {
      goto Loop;// go back to the loop and do another iteration if its not equal
    }
  }// while loop end____________________________________________________________

  //_________________________________Output Start_______________________________
  Solution: // if there is a solution print out the number of iterations
  cout << "Case " << CaseNum << ": " << iterated << " iterations" << endl;
  iterated = -1; // reset iteratons to -1
  CaseNum++; // increment case number
  goto Start; // return to start to check if theres more cases to do
  NoSolution: //No solution if the iterated is above 1000
  cout << "Case " << CaseNum << ": not attained" << endl;
  iterated = -1; // reset iteratons to -1
  CaseNum++;  // increment case number
  goto Start; // return to start to check if theres more cases to do
  //_________________________________Output end_________________________________
  return 0;
}

// check if the vector has all the same elements in it
bool equall(vector<int> v){
  if (equal(v.begin() + 1, v.end(), v.begin()) ) {
    return true;
  }
  return false;
}
