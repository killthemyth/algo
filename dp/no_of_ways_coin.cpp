#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int no_of_ways(int value, int no_of_coins, int coins[]) {
  int arr[no_of_coins][value + 1];

  for(int i = 0; i < no_of_coins; i++)
    arr[i][0] = 1;

  // Formula arr[i][j] = arr[i - 1][j] + arr[i][j - coins[i]]
  for(int i = 0; i < no_of_coins; i++)
    for(int j = 1; j < value + 1; j++) {
      int x = ((i - 1) >= 0) ? arr[i- 1][j] : 0;
      int y = ((j - coins[i]) >=0) ? arr[i][j - coins[i]] : 0;
      arr[i][j] = x + y;
    }

  return arr[no_of_coins - 1][value];
}

int space_optimized(int value, int no_of_coins, int coins[]) {
  int arr[value + 1];
  for(int i = 0; i < value + 1; i++) arr[i] = 0;

  arr[0] = 1;

  for(int i = 0; i < no_of_coins; i++)
    for(int j = coins[i]; j < value + 1; j++)
      arr[j] += arr[j - coins[i]];

  return arr[value];
}

int main() {
  int value, no_of_coins;
  cin >> value;
  cin >> no_of_coins;
  int coins[no_of_coins];
  for(int i = 0; i < no_of_coins; i++) {
    cin >> coins[i];
  }
  cout << "No of Ways: " << no_of_ways(value, no_of_coins, coins) << endl;
  cout << "Space Optimzed: " << space_optimized(value, no_of_coins, coins) << endl;
  return 0;
}
