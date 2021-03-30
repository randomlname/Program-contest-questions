// Nwabunor Jeff Onwuanyi
//  10420

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
  int a = 0;
  string con,rest;
  map<string, int> total;

  cin >> a;
  cin.ignore();


  while (a--) {
    cin >> con;
    getline(cin, rest);
    total[con] += 1;
  }
  for (map<string, int>::const_iterator it = total.begin(); it != total.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
    return 0;
}
