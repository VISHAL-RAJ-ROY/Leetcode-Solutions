struct node
{
    node* n[26];
    bool isWord;
    node(bool _isWord) : isWord(_isWord) 
    {
       memset(n, 0, sizeof(n));
    }
};
class StreamChecker {
private:
    node* root = new node(false);
    vector<int> mem;
public:
    StreamChecker(vector<string>& words) {
        for(string& s : words)
        {
            node* nd = root;
            for(int j = (int)s.size()-1; j >= 0; j--)
            {
                int i = s[j]-'a';
                if(nd->n[i] == NULL)
                    nd->n[i] = new node(false);
                nd = nd->n[i];
            }
            if(!s.empty())
                nd->isWord = true;
        }
    }
    
    bool query(char letter) {
        mem.push_back(letter-'a');
        node* nd = root;
        for(int i = (int)mem.size()-1; i >= 0; i--)
            if(nd->n[mem[i]] != NULL)
            {
                nd = nd->n[mem[i]];
                if(nd->isWord)
                    return true;
            }
            else
                return false;
        return false;
    }
};
