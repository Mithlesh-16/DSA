#include <iostream>
#include <string>
using namespace std;

class Solution {
    private:
        bool check_Equal(int *a,int* b){
            for (int  i = 0; i<26; i++){
                if(a[i] != b[i]){
                    return false;
                }
            }
            return true;
        }

    public:
        bool checkInclusion(string s1, string s2) {
            int s1_map[26] = {0};
            for (int i = 0; i < s1.size(); i++)
            {
                int index = s1[i] - 'a';
                s1_map[index] += 1;
            }

            //First window
            int temp_map[26] = {0},i = 0;
            for (; i<s1.size() && i<s2.size(); i++){
                int index = s2[i] - 'a';
                temp_map[index] ++;
            }

            if(check_Equal(s1_map,temp_map)){
                return true;
            }

            // All Next windows
            while(i<s2.size()){
                int index = s2[i]- 'a';
                temp_map[index]++;

                int old_index = s2[i-s1.size()] - 'a';
                temp_map[old_index]--;

                if(check_Equal(s1_map,temp_map)) return 1;
                i++;
            }
            
                return 0;
                
            }
    };

int main()
{
    string s1; // chhota str
    getline(cin, s1);
    string s2; // bda str
    getline(cin, s2);

    int s1_map[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        // cout<<"for Loop 1"<<endl;
        int index = s1[i] - 'a';
        s1_map[index] += 1;
    }


    for (int i = 0; i < s2.size(); i++)
    {
        // cout<<"For Loop 2"<<endl;
        int temp_map[26] = {0};
        if (i + s1.size() > s2.size())
        {
            break;
        }
        int j = i;
        while (j <= i + s1.size())
        {
            int new_idx = s2[j] - 'a';
            temp_map[new_idx] += 1;
            j++;
        }
        int flag = 1;
        for (int j = 0; j < 26; j++)
        {
            cout << "j = " << j << " ";
            if (s1_map[j] != temp_map[j])
            {
                flag = 0;
                cout << "j = " << j << " ";
                cout << "s1_map = " << s1_map[j] << " ";
                cout << "temp_map = " << temp_map[j] << " ";
                break;
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
            return true;
        }
    }
    cout << "No" << endl;
    return 0;
}