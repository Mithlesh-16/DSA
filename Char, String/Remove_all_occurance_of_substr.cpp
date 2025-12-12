#include <iostream>
using namespace std;

class Solution {
    public:
        bool str_present(string s,string part){
            for (int i = 0; i<s.size(); i++){
                if (s[i] == part[0] && s.substr(i,part.size()) ==   part)
                {
                    return 1;
                }
            }
            return 0;
        }
        
        string removeOccurrences(string s, string part) {
        
        // size = s.size();
    
        while(str_present(s,part))
        {
            for (int i = 0; i<s.size(); i++){
                if (s[i] == part[0] && s.substr(i,part.size()) ==   part)
                {
                    s.replace(i, part.size(), "");
                    break;
                }
            }
        }
        cout << s << endl;
        return s;
        }
    };
    
    class Solution_2 {
        public:
            string removeOccurrences(string s, string part) {
            while(s.size()!=0 && s.find(part)<s.size()){
                s.erase(s.find(part),part.size());
            }
            cout << s << endl;
            return s;
            }
        };

int main()
{

    string given_str;
    getline(cin, given_str);
    string sub_str;
    getline(cin, sub_str);
    string new_str="";

    for (int i = 0; i < given_str.size(); i++)
    {
        if (given_str[i] == sub_str[0] && given_str.substr(i,sub_str.size()) == sub_str)
        {
            // given_str.replace(i, sub_str.size(), ".");
            i += sub_str.size() -1;
            // cout << given_str << endl;
        }
        else{
            new_str += given_str[i];
        }
    }
    cout << new_str << endl;

    return 0;
}