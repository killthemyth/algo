#include<iostream>
using namespace std;

int min_no_of_ways(int coins[], int l, int value) {
  int A[value + 1], B[value + 1];

  for(int i = 0; i < value + 1; i++) {
    A[i] = 10000;
    B[i] = -1;
  }

  A[0] = 0;

  //Formula, A[j] = min(A[j], 1 + A[j] - coins[i]])
  for(int i = 0; i < l; i++)
    for(int j = coins[i]; j < value + 1; j++) {
      if(A[j] > 1 + A[j - coins[i]]) {
        A[j] = A[j - coins[i]] + 1;
        B[j] = i;
      }
    }
  cout << "Combination: ";
  int x = value;
  while(x > 0) {
    cout << coins[B[x]] << " ";
    x = x - coins[B[x]];
  }
  cout << endl;
  return A[value];
}

int main() {
  int value, no_of_coins; cin >> value >> no_of_coins;
  int coins[no_of_coins];
  for(int i = 0; i < no_of_coins; i++) cin >> coins[i];

  cout << "Min number of ways: " << min_no_of_ways(coins, no_of_coins, value) << endl;
}
