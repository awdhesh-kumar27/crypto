#include<bits/stdc++.h>
using namespace std;



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




int multiplicative_inverse(vector<int>&divisor,vector<int>&dividend){
    vector<int>arr1 = divisor;
    vector<int>arr2 = dividend;
    unordered_map<int,vector<vector<int>>>mp;
     int k =0;
   int num = 0;
     vector<int>t1(16,0);
     vector<int>t2(16,0);
     t2[15]=1;
    auto it2 = std::find(arr1.begin(),arr1.end(),1);
    if(it2 == arr1.end()){
        return 0;
    }

    while(1){
         vector<int>arr3(16,0);
  
     while(1){
        auto it = std::find(arr1.begin(),arr1.end(),1);
        int ind1 = it - arr1.begin();
        ind1 = 15 -ind1;
        it = std::find(arr2.begin(),arr2.end(),1);
        int ind2 = it - arr2.begin();
        ind2 = 15-ind2;
        if(ind2-ind1 <0){
            break;
        }else{
            vector<int>temp(16,0);
            int diff = ind2 - ind1;
  
            int ind4 = 15-diff;
            arr3[ind4] = 1;
            for(int i = 0;i<arr1.size();i++){
                if(arr1[i] == 1){
                    int z = 15- i;
                    int ind3 =15- (z+diff);
                    arr2[ind3] = (arr2[ind3]+1)%2;
                }
        
            }
            
        }
     }
  
      vector<int>temp = arr2;
      arr2 = arr1;
      arr1 = temp;
   
    vector<int>t(16,0);
       for(int i = 0;i<16;i++){
         if(arr3[i] == 1){
            int x = 15 - i;
         for(int j = 0;j<16;j++){
            if(t2[j] == 1){
             int y = 15 - j;
             t[15 -(y+x)] += 1;
            }
          }
         }
       }

       for(int i = 0;i<16;i++){
           t[i] = (t[i] + t1[i])%2;
       }
       t1 = t2;
       t2 = t;
   
      auto it1 = std::find(arr1.begin(),arr1.end(),1);
      if(it1 == arr1.end()){
     
        for(int i = 15;i>= 0;i--){
            num += (t1[i]*pow(2,15-i));
        }
    
        break;
      }
        
    }
   
   return num;
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


 










int multiply_helper(int n){
   
vector<vector<int>>matrix = {
        {0,0,1,0,0,1,0,1},
        {1,0,0,1,0,0,1,0},
        {0,1,0,0,1,0,0,1},
        {1,0,1,0,0,1,0,0},
        {0,1,0,1,0,0,1,0},
        {0,0,1,0,1,0,0,1},
        {1,0,0,1,0,1,0,0},
        {0,1,0,0,1,0,1,0}
        
    };
    int m = n;
    vector<int>arr(8,0);
    int k  = 0;
    while(n>0){
        int rem = n%2;
        arr[k] = rem;
        k++;
        n/=2;
    }
    // cout<<"val : "<<m<<endl;
    // for(int i = 0;i<8;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    
    vector<int>constant = {1,0,1,0,0,0,0,0};
    vector<int>new_arr(8,0);
    for(int i = 0;i<matrix.size();i++){
        int val = 0;
        for(int j = 0;j<matrix[0].size();j++){
            val += (matrix[i][j] * arr[j]);
        }
        new_arr[i] = (val + constant[i])%2;
       // cout<<new_arr[i]<<" ";
    }
     int num = 0;
      k =0;
     for(int i =0;i<8;i++){
        num += (pow(2,k) * new_arr[i]);
        k++;
     }
    // cout<<endl;
     //cout<<num<<" ";

    return num;
}

void helper1(vector<vector<string>>&matrix){

    vector<vector<string>>final_matrix(4,vector<string>(4,""));
    for(int i =0;i<4;i++){
        for(int j = 0;j<4;j++){
           string str = matrix[i][j];
           int val = hex_to_num(str);
         //  cout<<val<<" ";
           int num = multiply_helper(val);
            // cout<<"num : "<<num<<" ";
           vector<int>divisor(16,0);
           dec_to_bin(num,divisor);
           vector<int>dividend(16,0);
           dec_to_bin(283,dividend);
           int inverse = multiplicative_inverse(divisor,dividend);
           string hex = num_to_hex(inverse);
           final_matrix[i][j] = hex;
           cout<<hex<<" ";
        }
        cout<<endl;
    }
}

int main(){
     vector<vector<string>>matrix = {
                {"00" ,"01" ,"65" ,"85"}, 
                {"83" ,"45" ,"5D" ,"96"}, 
                {"5C" ,"33" ,"98" ,"B0"},
                {"F0" ,"2D" ,"AD" ,"C5"}, 
     };
     helper1(matrix);
    // int num = 0;
            
    //        vector<int>divisor(16,0);
    //        dec_to_bin(num,divisor);
    //        vector<int>dividend(16,0);
    //        dec_to_bin(283,dividend);
    //        int inverse = multiplicative_inverse(divisor,dividend);
    //        cout<<inverse<<" ";
    return 0;
}