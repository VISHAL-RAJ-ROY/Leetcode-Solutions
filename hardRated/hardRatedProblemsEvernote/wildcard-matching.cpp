        bool isMatch(string s, string p) {
            auto n = s.size(), m = p.size();
            int j = 0;
            for(int i = 0, lastp = -1, lasts = -1; i != n;){
                if ((s[i] == p[j]) || (p[j] == '?')){
                    i++; j++;
                }else if (p[j] == '*'){
                    j++;
                    lastp = j;
                    lasts = i;
                }else if (lastp != -1){
                    j = lastp;
                    i = ++lasts;
                }else
                    return false;
            }
            for (; (j < m) && (p[j] == '*'); j++);
            return (j == m);
        }
