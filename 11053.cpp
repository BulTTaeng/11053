#include <iostream>
#include <vector>

using namespace std;

vector<int> A;

int dp[1001];

int main() {
  int N , input;

  cin >> N;

  for(int i =0; i<N; i++){
    cin >> input;
    A.push_back(input);
  }
  dp[0] = 1;
  
  int ans = 0;
  int tmp_num, tmp_c;

  for(int i =1; i<N; i++){
    tmp_num = A[i];
    tmp_c = 0;

    for(int j = 0; j<i; j++){
      if(A[j] < tmp_num){
        if(tmp_c <= dp[j]){
          tmp_c = dp[j] +1;
        }
      }
    }
    if(tmp_c == 0){
      tmp_c = 1;
    }
    dp[i] = tmp_c;
  }

  for(int i =0; i<N; i++){
    //cout << dp[i][0] << " ";
    if(ans < dp[i]){
      ans = dp[i];
    }
  }

  cout << ans;
  return 0;


}
