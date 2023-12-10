#include<iostream>
#include<array>
using namespace std;
//if input[] contains c1 , then replace it with c2
void replaceCharacter(char input[], char c1, char c2) {
    
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == c1)
            input[i] = c2;
    }
}
int main(){
    char name[20] = "etsunjknuste";
    replaceCharacter(name,'e','t');
    cout << name;
}