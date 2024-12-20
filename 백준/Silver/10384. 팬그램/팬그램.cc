#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int main(){
    int t;
    cin >> t;
    
    string str;
    int first = 1;
    while(getline(cin,str)){

        int index[26] = {0, };
        for(int i = 0;i<str.size();i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                 str[i] = toupper(str[i]);   
            }
            if(str[i] >= 'A' && str[i] <= 'Z'){
                index[str[i]-'A']++;
            }
        }
        
        int value = index[0];
        for(int i = 0;i<26;i++){

            value = min(value,index[i]);
        }

        if(first != 1){
              if(value == 0){
            cout << "Case" << ' ' << first-1 << ':' << ' ' << "Not a pangram" << '\n';
        }
        else if(value == 1){
             cout << "Case" << ' ' << first-1 << ':' << ' ' << "Pangram!" << '\n';
        }
        else if(value == 2){
            cout << "Case" << ' ' << first-1 << ':' << ' ' << "Double pangram!!" << '\n';
        }
        else{
            cout << "Case" << ' ' << first-1 << ':' << ' ' << "Triple pangram!!!" << '\n';
        }
        }
      
        
      first++;
         
    
    }
}