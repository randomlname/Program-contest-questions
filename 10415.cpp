// Nwabunor Jeff Onwuanyi
// 10415

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int mapLowerCase[7][10] = {
	0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 0, 0, 1, 1, 1, 1,
	0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
	0, 1, 1, 1, 0, 0, 1, 1, 0, 0,
	0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
	0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};

int mapUpperCase[7][10] = {
	1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 1, 1, 1, 0,
	1, 1, 1, 1, 0, 0, 1, 1, 0, 0,
	1, 1, 1, 1, 0, 0, 1, 0, 0, 0,
	1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
};

int main()
{
	int a;
  int finger[10];
  int *p;
  int *lastP;
	char notes[200];

  cin >> a;
  cin.ignore();

	while (a != 0) {
    a--;
		cin >> (notes);

		for (int i = 0; i <= 9; ++ i) {
			finger[i] = 0;
		}

		for (int i = 0; notes[i]; ++ i) {
			if (notes[i] >= 'a' && notes[i] <= 'g') {
				p = mapLowerCase[notes[i]-'a'];
			} else {
				p = mapUpperCase[notes[i]-'A'];
			}

			for (int j = 0; j <= 9; ++ j) {
				if (p[j] == 1 && (i == 0 || lastP[j] == 0)) {
					finger[j] ++;
				}
			}
			lastP = p;
		}

    cout << endl;
		for (int i = 0; i < 9; ++i) {
			cout << finger[i];
      cout << " ";
		}
		cout << finger[9];
	}
	return 0;
}
