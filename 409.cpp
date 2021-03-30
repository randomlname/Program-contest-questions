#include <iostream>
#include <cstring>
#include <vector>
#include <locale>
#include <stdio.h>

using namespace std;

string convertToLower(string);
int sortAndFind(string,string);
const int SIZE = 21;

int main(int argc, const char * argv[]) {
  string keyword[SIZE];
  string excuse[SIZE];
  string keyExcuse[SIZE];
  int count[SIZE];

  int a,b;
  int excuseNum = 1;

  while (cin >> a >> b) {
    memset(count,0,sizeof(count));
    string temp;
    getline(cin,temp); // get rid of white space


    // get keywords
    for (int i = 0; i < a; i++) {
      getline(cin,keyword[i]);
    }

    // get excuses and convert them to small letters
    for (int i = 0; i < b; i++) {
      getline(cin,excuse[i]);
      keyExcuse[i] = convertToLower(excuse[i]);
    }

    // sort and find the worst excuse
    for (int i = 0; i < b; i++) {
      for (int j = 0; j < a; j++) {
        count[i] += sortAndFind(excuse[i],keyword[j]);
      }
    }

    vector<int> ans;
    int max = 1;
    for (int i = 0; i < b; i++) {
      if (max < count[i]) {
        ans.clear();
        ans.push_back(i);
        max = count[i];
      } else if (max == count[i]) {
        ans.push_back(i);
      }
    }

    for(int i = 0; i < ans.size()-1; i++) {
      if (count[i] <= count[i+1]){
        ans.erase(ans.begin()+i);
      }
    }

    // print the output
    //cout << endl;
    cout << "Excuse Set #" << excuseNum << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
      cout << excuse[ans[i]] << endl;
    }
    excuseNum++;
  }
return 0;
}

int sortAndFind(string excuse, string keyword) {
  int size = excuse.length();
  string temp = "";
  int count = 0;


  for (int i = 0; i < size; i++) {
    if (!isalpha(excuse[i])) {
      if (temp == keyword) {
        count++;
      }
      temp = "";
    } else {
      temp = temp + excuse[i];
    }
  }

  if (temp == keyword) {
    count++;
  }

  return count;
}


string convertToLower(string a) {
  string b,c;
  std::locale loc;
  std::string::size_type i;
  for(i = 0; i < a.length(); i++){
  b = std::tolower(a[i],loc);
  c.append(b);
  }
  return c;
}
