#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> &a, int &cnt, string tmp, int index){

    if(index == 0){

        bool flag = 1;
            for(int j = 0; j < tmp.size(); j++){
                char tmp_char = tmp[j];
                int tmp_cnt = 0;
                for(int k = 0; k < tmp.size(); k++){
                    char curr_char = tmp[k];
                    if(curr_char == 'L' and j >= k) tmp_cnt++;
                    if(curr_char == 'R' and j <= k) tmp_cnt++;
                }
                if(tmp_cnt != a[j]) {
                    flag = 0;
                    break;
                }
            }
            if(flag)cnt =  (cnt) % 676767677;


        return ;
    }

    //left cape
    solution(a, cnt, tmp + 'L', index - 1);
    
    //right cape
    solution(a, cnt, tmp + 'R', index - 1);

}


int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        int cnt = 0;
        solution(a, cnt, "", n);

            

        cout<<cnt<<endl;
    }


    return 0;
}