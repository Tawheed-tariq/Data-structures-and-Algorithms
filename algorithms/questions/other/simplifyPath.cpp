class Solution {
public:
    string simplifyPath(string str) {
        stack<string> st;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '/') continue;
            string temp;

            while(i < str.size() && str[i] != '/'){
                temp += str[i];
                i++;
            }

            if(temp == ".") continue;

            if(temp == ".."){
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(temp);
        }
        string res;
        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }

        if(res.size() == 0) return "/";
        return res;
    }
};