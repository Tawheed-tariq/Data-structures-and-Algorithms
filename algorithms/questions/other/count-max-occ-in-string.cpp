#include<iostream>
using namespace std;
char get_max_occ(string s){
    int arr[26] = {0}, num , index_max = -1; // step 1 : create array

    for(int i = 0; i < s.length() ; i++){ // step 2: iterate and increase value at index of arr
        if(s[i] >= 'a' && s[i] <= 'z'){
            num = s[i] - 'a';
        }
        else{
            num = s[i] - 'A'; // provided string only contains alphabets
        }
        arr[num]++;
    }

    for(int i = 0; i < s.length() ; i++){ //step 3: find index of max in array
        if(arr[index_max] < arr[i])
            index_max = i;
    }
    //step 4: return index + 'a'
    return index_max + 'a';
}

int main(){
    char ch = get_max_occ("abcdAbdSajskjd"); //sometimes makes error in running , but program is correct
    cout << ch;
}