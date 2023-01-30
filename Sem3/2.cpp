#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void printvector(vector<int> v){
    unsigned int i;
    for(i = 0; i < v.size() - 1; i++) {
        cout << v.at(i) << ' ';
    }
    cout << v.at(i);
}

vector<int> getClosest(int val1, int val2, int target){
  vector<int> v;
  if(abs(target - val1 == val2 - target)){
    v.push_back(val1);
    v.push_back(val2);
  }
  else if (target - val1 >= val2 - target){
    v.push_back(val2);
  }
  else{
    v.push_back(val1);
  }
  return v;
}

vector<int> bSearch(int somas[], int l, int r, int p){
  vector<int> v;
  if (p <= somas[l]){
    v.push_back(somas[l]);
    return v;
  }

  if (p >= somas[r - 1]){
    v.push_back(somas[r-1]);
    return v;
  }

  int m;

  while(l < r){
      m =  (l + r) / 2;

      if(somas[m] == p){
        v.push_back(somas[m]);
        return v;
      }

      if(somas[m] > p){
        if (m > 0 && p > somas[m - 1])
            return getClosest(somas[m - 1], somas[m], p);
        r = m;
      }

      else {
          if (m < l - 1 && p < somas[m + 1])
              return getClosest(somas[m], somas[m + 1], p);
          l = m + 1;
      }
  }
  v.push_back(somas[m]);
  return v;
 }


int main() {
    int n, q, p;

    cin >> n;
    int s[n];

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    int nsums = 0;

    for(int i = 0; i<n; i++){
        nsums += i;
    }

    int somas[nsums];

    int k = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(i != j){
            somas[k] = s[i] + s[j];
            k++;
            }
        }
    }

    sort(somas, somas+k);


    cin >> q;

    for(int i = 0; i < q; i++){
        cin >> p;
        vector<int> r;
        r = bSearch(somas, 0, k, p);
        printvector(r);
        cout << endl;
    }

    return 0;
}