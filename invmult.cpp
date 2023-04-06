#include<bits/stdc++.h>
using namespace std;

vector<string>round_arr = {"01","02","04","08","10","20","40","80","1B","36"};

char remainder_helper(int num){
    if(num<10){
        char ch = char(48+num);
        return ch;
    }else if(num == 10){
        return 'A';
    }else if(num == 11){
        return 'B';
    }else if(num == 12){
        return 'C';
    }else if(num == 13){
        return 'D';
    }else if(num == 14){
        return 'E';
    }else if(num == 15){
        return 'F';
    }
    return 0;
}

int num_helper(char ch){
    int val = ch;
    if(val>= 48 && val <= 58){
        return (val - 48);
    }else if(ch == 'A'){
        return 10;
    }else if(ch == 'B'){
        return 11;
    }else if(ch == 'C'){
        return 12;
    }else if(ch == 'D'){
        return 13;
    }else if(ch == 'E'){
        return 14;
    }else if(ch == 'F'){
        return 15;
    }
    return 0;
}

int hex_to_num(string hex){

    int len = hex.length();
    int ans = 0;
    for(int i =len-1;i>=0 ;i--){
        int val = num_helper(hex[i]) * pow(16,len-1-i);
        ans+=val;
    }

    return ans;

}

string num_to_hex(int val){
    string hex = "";
    while(val>0){
            int rem = val%16;
            char ch = remainder_helper(rem);
            hex = ch + hex;
            val/= 16;
       }
       while(hex.length()<2){
           hex = '0' + hex;
       }
       return hex;
}



void dec_to_bin(int val,vector<int>&arr){
    int n = val;
    string str = "";
    while(n>0){
        int rem = n%2;
         char ch = rem+48;
         str += ch;
        n /= 2;
    }
    int j = 0;
    for(int i = 15;i>=0;i--){
        arr[i] = str[j]-48;
        j++;
        if(j>= str.length()){
            break;
        }
        
    }
  
}


unordered_map<char,string> binary_to_hex(string str){
     int len = str.length();
     unordered_map<char,string>mp;
     for(int i =0;i<len;i++){
         int val = int(str[i]);
          string hex = num_to_hex(val);
          
          mp[str[i]] = hex;
        //   cout<<str[i]<<" "<<hex<<endl;
     }
     return mp;
}


int multiplication_helper(vector<int>&arr1,vector<int>&arr2){
       vector<int>arr3(16,0);
       for(int i =0;i<16;i++){
        if(arr1[i] == 1){
            int ind1 = 15 - i;
          for(int j = 0;j<16;j++){
             if(arr2[j] == 1){
                int ind2 = 15- j;
                 arr3[15-(ind1+ind2)] += 1;
             }
          }
        }
    }

    for(int i =0;i<16;i++){
         arr3[i] = arr3[i]%2;
    }
    vector<int>temp = {0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1};
    while(1){
        auto it = std::find(arr3.begin(),arr3.end(),1);
        int ind = it - arr3.begin();
        int x = 15-ind;
        if(x<8){
            break;
        }
        arr3[ind] = 0;
        for(int i =0;i<16;i++){
            arr3[i] = (arr3[i]+temp[i])%2;
        }
    }
    
    int num =0;
     for(int i = 15;i>= 0;i--){
            num += (arr3[i]*pow(2,15-i));
        }
    return num;
}

vector<vector<string>> mix_columns(vector<vector<string>>&constant_matrix,vector<vector<string>>&shift_matrix){
  vector<vector<string>>mix_matrix(4,vector<string>(4,""));

  cout<<"Mix columns: "<<endl;
  for(int i = 0;i<4;i++){
    for(int j = 0;j<4;j++){
        int ans = 0;
        vector<int>arr3(16,0);
        for(int k = 0;k<4;k++){
         //  string val3 = num_to_hex(constant_matrix[i][k]);
           int val1 = hex_to_num(constant_matrix[i][k]);
           int val2 = hex_to_num(shift_matrix[k][j]);
           vector<int>arr1(16,0);
           vector<int>arr2(16,0);
           dec_to_bin(val1,arr1);
           dec_to_bin(val2,arr2);  
           int val  = multiplication_helper(arr1,arr2);
           ans = ans ^ val;
        }
        // cout<<ans<<" ";
       
        mix_matrix[i][j] = num_to_hex(ans);
        cout<<mix_matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl<<endl;
     return mix_matrix;
}


int main(){
    // string plaintext = "0123456789ABCDEFFEDCBA9876543210";
    // string key = "0F1571C947D9E8590CB7ADD6AF7F6798";

  vector<vector<string>>constant_matrix = {{"0E","0B","0D","09"},{"09","0E","0B","0D"},{"0D","09","0E","0B"},{"0B","0D","09","0E"}};
   vector<vector<string>>matrix = {
                {"00" ,"01" ,"65" ,"85"}, 
                {"83" ,"45" ,"5D" ,"96"}, 
                {"5C" ,"33" ,"98" ,"B0"},
                {"F0" ,"2D" ,"AD" ,"C5"}, 
     };
  vector<vector<string>>mix_matrix(4,vector<string>(4,""));
  mix_matrix =  mix_columns(constant_matrix,matrix);  
    return 0;
}