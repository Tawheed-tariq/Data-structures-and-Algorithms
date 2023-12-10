#include<iostream>
using namespace std;
int makeBeautiful(string);
int main(){
    string str = "01010010101";
    cout << makeBeautiful(str);
}
int makeBeautiful(string str) {
    int count = 0, count2 = 0, size = str.length();
	for(int i = 0; i < size; i++){
       if(i%2 == 0){
            if(str[i] == '1')
                count++;
            else
                count2++;
       }
       else{
           if(str[i] == '1')
                count2++;
            else
                count++;
       }
    }
    return min(count, count2);
}