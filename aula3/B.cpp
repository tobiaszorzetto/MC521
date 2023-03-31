#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int t,n,l,r,i;
    vector<int> a;
    long long ans;

    cin >> t;

    while (t--)
    {
        cin>> n >> l >> r;
        a.resize(n);

        for(i = 0; i< n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        ans = 0;

        for(i = 0; i< n; i++){
            ans+= upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
            ans-= lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();

            if(l<= 2*a[i] && 2*a[i] <= r){
                ans--;
            }
        }
        cout << ans/2 << endl;
    }
    
    return 0;
}