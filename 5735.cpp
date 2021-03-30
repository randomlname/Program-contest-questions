//Nwabunor Onwuanyi
//5735.cpp stock prices

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1000000; // max number of days we can do
int smallest();
int largest();
vector<int> vec(MAX);
vector<int> vec1;
vector<int> vec2;
vector<int> vec3;

int main() {
  int days;
  int lowestPrices;
  int highestPrices;
  int Casenum = 1;

  Start:
  vec1.clear(); // clear the vectors for new info
  vec2.clear(); // clear the vectors for new info
  vec3.clear(); // clear the vectors for new info
  cin >> days >> lowestPrices >> highestPrices; // take in the n k1 k2
  if (days == 0 && lowestPrices == 0 && highestPrices == 0) { // if n k1 and k2 all equal 0 end the program
    return 0;
  }
  //____________________________________________________________________________

  //__________while the number is less than days take in the prices_____________
  int prices;
  for (int i = 0; i < days; i++) {
    cin >> prices;
    vec.at(i) = prices;  // put the prices in a vector
  }
  //____________________________________________________________________________

  //______copy vec(with the prices to vec1) makes 2 vectors for same things_____
  for (int i = 0; i < days; i++) {
    vec1.push_back(vec.at(i));
  }
  //____________________________________________________________________________

  //________________find the smallest price in the list_________________________
  for (int i = 0; i < lowestPrices; i++) {
    int small = smallest();
    vec2.push_back(small); //while less that lowestPrices find the next smallest and put in a vector
  }
  //____________________________________________________________________________

  //______________reinitialize vec after taking the smallest ones_______________
  for (int i = 0; i < days; i++) {
    vec.at(i) = vec1.at(i);
  }
  //____________________________________________________________________________

  //_______________________find the highest price in the list___________________
  for (int i = 0; i < highestPrices; i++) {
    int large = largest(); //while less that highestPrices find the next largest and put in a vector
    vec3.push_back(large);
  }
  //____________________________________________________________________________

  //_________________________Sort_______________________________________________
  sort(vec2.begin(),vec2.end()); // sort in accending order
  sort(vec3.begin(), vec3.end(), greater<int>()); // sort in decending order
  //____________________________________________________________________________

  //_________________________Output_____________________________________________
  cout << "Case " << Casenum++ << endl;
  for (int i = 0; i < lowestPrices; i++) {
    cout << vec2[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < highestPrices; i++) {
    cout << vec3[i] << " ";
  }
  cout << endl;
  //_________________________Output end ________________________________________
  goto Start; // return to start to check if there are other cases
  return 0;
}

// find the smallest element and return it
int smallest() {
  int temp;
  int temp1;
  temp = *min_element(vec.begin(),vec.end()); // get the index of the smallest element
  temp1 = vec.at(temp); // get what the smallest element is
  vec.erase(vec.begin()+temp); // erase the element that was fetched
  return temp1;
}
// find the largest element and return it
int largest() {
  int temp;
  int temp1;
  temp = *max_element(vec.begin(),vec.end())-2; // get the index of the largest element
  temp1 = vec.at(temp); // get what the largest element is
  vec.erase(vec.begin()+temp); // erase the element that was fetched
  return temp1;
}
