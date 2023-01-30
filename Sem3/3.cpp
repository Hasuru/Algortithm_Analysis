#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool works(int percurso[], int d, int max, int size){
  int sum = 0;
  int i = 0;
  while(d > 0){
    if(sum + percurso[i] > max){
      d--;
      sum = 0;
    }
    else{
      sum += percurso[i];
      i++;
    }
  }
  if(i < size) return false;
  else return true;
}


int parte(int percurso[], int low, int size, int total, int d){
  int high = total;
  int best = total;
  while(low < high){
    int mid = (low + high) / 2;

    if(works(percurso, d, mid, size) == true){
      if(mid <= best){
        best = mid;
      }
      high = mid;
    }
    else{
      low = mid + 1;
    }
  }
  return best;
}

int main(){
  int n, q;
  int total = 0;

  cin >> n;

  int percurso[n];

  for(int i = 0; i < n; i++)
  {
    cin >> percurso[i];
    total += percurso[i];
  }

  cin >> q;

  for(int i = 0; i < q;i++){
    int d, best;
    cin >> d;

    best = parte(percurso, 0, n, total, d);
    cout << best << endl;
  }

  return 0;
}