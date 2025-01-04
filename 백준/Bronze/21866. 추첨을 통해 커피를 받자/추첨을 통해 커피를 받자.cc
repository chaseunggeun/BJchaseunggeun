#include<iostream>

using namespace std;

bool hacker = false;

void findhacker(int i, int score){
  if(score > (i/2 +1) * 100){
    hacker = true;
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

  int score, sum = 0;

  for(int i = 0; i < 9; i++){
    cin >> score;
    findhacker(i, score);

    sum += score;
  }

  if(hacker == true){
      cout << "hacker";
  }
  else{
    if(sum >= 100) cout << "draw";
    else cout << "none";
  }
}