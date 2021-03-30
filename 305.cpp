// Nwabunor Jeff Onwuanyi
// 305

#include <iostream>

using namespace std;

int killCircle(int,int);

int main(int argc, const char * argv[]) {
    int arr[15];

    for(int i = 1; i <= 15; i++){
        for(int j = 1;; j++){
            if(killCircle(i,j) == i) {
                arr[i] = j;
                break;
            }
        }
    }
    int a = 0;
    while(cin >> a and a != 0) {
      cout << arr[a] << endl;
    }
    return 0;
}



int killCircle(int player, int killpostion){
    int playerSize = 0;
    int index = 0;
    int ajustedTotal = 0;
    int i = 0;

    playerSize = player * 2;
    ajustedTotal = playerSize;

    index = (killpostion - 1) % (ajustedTotal);

    for (i = 0; i < playerSize; i++){
        if (index < player) {
            break;
        }
        ajustedTotal--;
        index = (index + killpostion - 1) % (ajustedTotal);
    }
    return i;
}
