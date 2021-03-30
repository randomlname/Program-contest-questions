//Nwabunor Onwuanyi
//5420.cpp biorhythms

#include <iostream>

const int PHY = 23;
const int EMO = 28;
const int INTEL = 33;

using namespace std;
/*
cycles         length
physical        23
emotional       28
intellectual    33

perforems at best in corresponding field when at peak
there is one peak in each cycles
want to find when  all three happen on the same day
three integers phy, emo, intel will be the dates at which the peak cycle happens
The value date is the given start date and may be smaller than any of p, e, or i

we find the date at which one of the cycles occurs so to
find the peak date for the phy cycle we can go
  ((date - phy) % 23(PHY) != 0) { date++; } if this equal 0 we konw that would be the peak phy cycle
  then we can do the same for our emo and intel
  after the find the peak date for one of our cycles we find the peak date for one of our other
  cycles and add out the cycle length of the first to is
  ((emotional cycle calc)  || (intellectual cycle calc)) { date += 23(PHY); }
*/
int main() {
  int phy;
  int emo;
  int intel;
  int date;

  int caseNum = 1;
  Start:
  cin >> phy >> emo >> intel >> date; // take in the fields
  if (phy == -1 && emo == -1 && intel == -1 && date == -1) { // if all the fields equal -1 we stop the program
    return 0;
  }

  int temp;
  temp = date; // store the original date
  date++; // increment the current date by one (next day)

  // while loop start___________________________________________________________
  while ((date - emo) % EMO != 0) { // if this is not equal 0 we havent found the cycles peak date
    date++; // increment the current date by one (next day)
  }// while loop end____________________________________________________________

  // while loop start___________________________________________________________
  while ((date - phy) % PHY != 0 || (date - intel) % INTEL != 0) { // line (54) find the next cycle to reach it peak day
    // increment the date by that of the first calc(emotional one) so if intellectual or
    // physical is = 0 we know that cycle which ever (phy or intel) occurs on the same date as the emo cycle
    date += EMO;
  }// while loop end____________________________________________________________

  //_________________________________Output Start_______________________________
  // subtract the original date(which is now in temp) from the new date(date += EMO in this case) because
  // the question states "you will be given the number of days from the beginning of the current year at
  // which one of its peaks (not necessarily the first) occurs." so we know a peak has occured before hand
  // thats why in line (54) we only need to find one of the peaks instead of both
  cout << "Case " << caseNum++ << ": the next triple peak occurs in " << date - temp << " days." << endl;
  goto Start; // go back to Start and see if there are any other cases to do
  //_________________________________Output end_________________________________

  return 0;
}
