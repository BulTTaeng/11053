#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

int dp[1001][2];

int main() {
  int N , input;

  cin >> N;

  for(int i =0; i<N; i++){
    cin >> input;
    A.push_back(input);
  }
  dp[0][0] = 1;
  dp[0][1] = A[0];
  
  int ans = 0;
  int tmp_num, tmp_c;

  for(int i =1; i<N; i++){
    tmp_num = A[i];
    tmp_c = 0;

    for(int j = 0; j<i; j++){
      if(A[j] < tmp_num){
        if(tmp_c <= dp[j][0]){
          tmp_c = dp[j][0] +1;
        }
      }
    }
    if(tmp_c == 0){
      tmp_c = 1;
    }
    dp[i][0] = tmp_c;
  }

  for(int i =0; i<N; i++){
    //cout << dp[i][0] << " ";
    if(ans < dp[i][0]){
      ans = dp[i][0];
    }
  }

  cout << ans;
  return 0;


}