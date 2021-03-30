//Nwabunor Onwuanyi
// 719.cpp
//https://topic.alibabacloud.com/a/uva-719-suffix-automatamin-notation_8_8_10252500.html
#include <iostream>
#include <string>
/* Explanation
we are finding the smallest lexicographic order in a string and
using the smallest representation using minimal string notation

first we gonna take the word say helloworld in this case
length = strlen(word); we find the length of our word which is 10

next we declear i,k,j which well help with the checking the string
i = 0 k = 0 j = 1
we go temp = word[(0 + 0) % length] - word[(1 + 0) % length];
for our string helloworld  word[(0 + 0) % length]  = h word[(1 + 0) % length] = e
this will corespond to the ascii codes so we have
temp = 104(ascii code for h) - 101(ascii code for e) so temp = 3

next we check if temp is 0 if it is we increment k so we can check the next letters in the string
else if temp is greater that 0 we do i += k + 1 which is 0 += 0 + 1 which will now make i = 1

otherwise if temp is negative we go j += k + 1 which is 1 += 0 + 1 which will now make k = 2

if i is equal to j we increment j to move to the next letter

the program does this again while i,k,j < length if one is not we go to
if (++i < ++j) {
  cout << i << endl;
} else {
  cout << j << endl;
}
and check which is the smallest of the two and then return it
*/
using namespace std;
const int MAX = 10000;

char word[MAX];

int main() {
  int testcases;
  int length;
  int temp;

  cin >> testcases;

  while (testcases--) {
    cin >> word;

    length = strlen(word);
    int i = 0;
    int k = 0;
    int j = 1;
    while (i < length && k < length && j < length) {
      temp = word[(i + k) % length] - word[(j + k) % length];
      if (!temp) {
        k++;
      } else {
        if (temp > 0) {
          i += k + 1;
        } else {
          j += k + 1;
        }

        if (i == j) {
          j++;
        }
        k = 0;
      }
    }

    if (++i < ++j) {
      cout << i << endl;
    } else {
      cout << j << endl;
    }

  }
  return 0;
}
