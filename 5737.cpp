//Nwabunor Onwuanyi
//5737.cpp pills
//https://github.com/huanghongxun/ACM/blob/master/UVaLive/p5737.cpp

/* explanation
for this program i will use pillInBottle = 2 to explain it
set pills all to 0  (memset)
pills[2][0] = 1
temp = 2 * 2 = 4  --- if we have 2 whole pills cutting both of them in half will result in 4 pills
take one of the half pills so now temp = 3 (while loop)

the condition(j * 2 + k == temp) works a first time when j = 1, k = 1 so 1 * 2 + 1 = 3
k is > 0 so
so we have pills[1][1] = 0, pills[1][1 + 1] = 0, pills[1 + 1][1 - 1] = 1
pills[1][1] = pills[1][1 + 1] + pills[1 + 1][1 - 1]
pills[1][1] = 1

the condition(j * 2 + k == temp) works a second time when j = 0, k = 2 so 0 * 2 + 2 = 2 (temp changed because of the while loop)
k is > 0 so
so we have pills[0][2] = 0, pills[0][2 + 1] = 0, pills[0 + 1][2 - 1] = 1
pills[0][2] = pills[0][2 + 1] + pills[0 + 1][2 - 1]
pills[0][2] = 1

the condition(j * 2 + k == temp) works a third time when j = 1, k = 0 so 1 * 2 + 0 = 2 (temp stays the same)
k is < 0 so
so we have pills[1][0] = 0, pills[1][0 + 1] = 1
pills[1][0] = pills[1][0 + 1];
pills[1][0] = 1

the condition(j * 2 + k == temp) works a fourth time when j = 0, k = 1 so 0 * 2 + 1 = 1 (temp changed because of the while loop)
k is > 0 so
so we have pills[0][1] = 1, pills[0][1 + 1] = 0, pills[0 + 1][1 - 1] = 1
pills[0][1] = pills[0][1 + 1] + pills[0 + 1][1 - 1]
pills[0][1] = 2

the condition(j * 2 + k == temp) works a fifth time when j = 0, k = 0 so 0 * 2 + 0 = 0 (temp changed because of the while loop)
k is < 0 so
so we have pills[0][0] = 0, pills[0][0 + 1] = 2
pills[0][0] = pills[1][0 + 1];
pills[0][0] = 2

then the while loop ends and we output pills[0][0]

this is a dynamic Programming approach 
it basically stores the solutions to the previous problems so that they do not have to be re-compute them when needed later
*/
#include <iostream>
using namespace std;
const int MAX = 30; // max amount of pills in a bottle

int main() {
  long int pills[MAX][MAX];
  int pillInBottle;
  int temp;

  Start:
  cin >> pillInBottle; // get the number of pills in the bottle
  if (pillInBottle == 0) { // if pillsInBottle = 0 quit the program
    return 0;
  }
  //fill(&pills[0][0], &pills[0][0] + sizeof(pills),0);
  memset(pills, 0, sizeof(pills)); // set pills all to 0
  pills[pillInBottle][0] = 1;
  temp = pillInBottle * 2; // how many pills we can have in total when they have all been cut in half


  //________________dynamic Programming approach________________________________
  while(temp--) { // take a pill (a half pill)__while loop start________________
    for (int j = 0; j <= pillInBottle; j++) { // j days taking 1 pill a day for whole pills
      for (int k = 0; k <= pillInBottle; k++) { // k pills  < pillInBottle
        if (j * 2 + k == temp) { // if (j(number days) * 2(to create all possible days)) + k(number of pills) = temp(which is the total number of pills but all are half pills)
          if (k > 0) {
            pills[j][k] = pills[j][k + 1] + pills[j + 1][k - 1];   // calculate and store
          } else {
            pills[j][k] = pills[j][k + 1];  // calculate and store

          }
        }
      }
    }
  }//______________________while loop end_______________________________________
  //____________________________________________________________________________

  //_________________Output_____________________________________________________
  cout << pills[0][0] << endl;
  goto Start; // return to start to see if there is more cases to do
  //____________________________________________________________________________
}
