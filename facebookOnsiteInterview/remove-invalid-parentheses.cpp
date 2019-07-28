    vector<string> removeInvalidParentheses(string s) {
        queue<tuple<string,int,int,char>> q;
        q.push(make_tuple(s,0,0,'('));
        vector<string> res;
        while(!q.empty()) {
            auto t=q.front();
            q.pop();
            string str=get<0>(t);
            int start =get<1>(t), lastRm=get<2>(t), count = 0;
            char l = get<3>(t), r = l=='('?')':'(';
            for(int i=start; i<str.size();i++) {
                if(str[i] == l) count++;
                else if(str[i]==r) count--;
                if(count>=0) continue;
                for(int j=lastRm;j<=i;j++)
                    if(str[j]==r && (j==lastRm || str[j-1]!=r))
                        q.push(make_tuple(str.substr(0,j)+str.substr(j+1),i,j,l));
                break;
            }
            if(count < 0) continue;
            reverse(str.begin(),str.end());
            if(l=='(') q.push(make_tuple(str,0,0,')'));
            else res.push_back(str);
        }
        return res;
    }
