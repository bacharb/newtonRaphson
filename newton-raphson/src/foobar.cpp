#include<iostream>
#include<vector>
#include<algorithm>
#include <tuple>

using namespace std;
using Real=float;
using point_2 = tuple<Real,Real> ;

int main(){
  vector <point_2> v;
  for (int i=0; i<10; i++){
    v.push_back(point_2(i*2, i*2+1) );
  }

  for(auto t: v){
    cout << get<0>(t) << ' ';
    cout << get<1>(t) << ' ';
  };
}
