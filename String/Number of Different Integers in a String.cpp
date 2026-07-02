class Solution {
public:
    int numDifferentIntegers(string word) {

        set<string> st;
        string temp = "";

        for(auto x : word){
            if(x >= '0' && x <= '9'){
                temp += x;
            }
            else{
                if(temp != ""){
                    int i = 0;
                    while(i < temp.size() && temp[i] == '0') i++;

                    if(i == temp.size())
                        st.insert("0");
                    else
                        st.insert(temp.substr(i));

                    temp = "";
                }
            }
        }

        if(temp != ""){
            int i = 0;
            while(i < temp.size() && temp[i] == '0') i++;

            if(i == temp.size())
                st.insert("0");
            else
                st.insert(temp.substr(i));

                temp = "";
        }

        return st.size();
    }
};
