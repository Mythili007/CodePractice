#include<stdio.h>
int main(){
  int days;
  //7 days = 1 week
  //30 days - 1 month
  //365 days - 1 year
  printf("Enter days:");
  scanf("%d", &days);
  int year1 = days/365;
  int year2 = days%365;
  int month1 = days/30;
  int month2 = days%30;
  int week1 = days/7;
  int week2 = days%7;
  //i want to present the left days too. suppose there are 56 days user has given, for months 26 days more. So i wanna
  //show like 1 month 26 days

  printf("%d days is %d year(s) %d day(s)\n", days, year1, year2);
  printf("%d days is %d month(s) %d day(s)\n", days, month1, month2);
  printf("%d days is %d week(s) %d day(s)\n", days, week1, week2);
}
