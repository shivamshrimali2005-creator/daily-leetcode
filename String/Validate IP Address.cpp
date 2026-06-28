class Solution {
public:
    bool f1(string query){

        for(int i=0;i<query.size();i++){
            string temp = "";

            while(i < query.size() && query[i] != '.'){
                temp += query[i];
                i++;
            }

            if(temp == "") return false;
            if(temp.size() > 1 && temp[0] == '0') return false;

            for(char c : temp){
                if(!isdigit(c)) return false;
            }

            if(temp.size() > 3) return false;
            
            int num = stoi(temp);
            if(!(num >= 0 && num <= 255)) return false;
        }

        return true;
    }

    bool f2(string query){

        for(int i=0;i<query.size();i++){
            string temp = "";

            while(i < query.size() && query[i] != ':'){
                temp += query[i];
                i++;
            }

            if(temp == "") return false;
            if(temp.size() > 4) return false;

            for(auto x : temp){
                if(!isdigit(x) && !(x >= 'a' && x <= 'f') && !(x >= 'A' && x <= 'F')) return false;
            }
        }

        return true;
    }

    string validIPAddress(string queryIP) {

        if (queryIP.empty() || queryIP.back() == '.' || queryIP.back() == ':')
        return "Neither";
        
        if(count(queryIP.begin(),queryIP.end(),'.') == 3 && f1(queryIP)) return "IPv4";

        if(count(queryIP.begin(),queryIP.end(),':') == 7 && f2(queryIP)) return "IPv6";

        return "Neither";
    }
};
