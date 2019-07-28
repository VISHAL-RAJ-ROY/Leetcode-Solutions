#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


// recursive solution
class Solution1 {
public:    
    
        void doIT( ListNode* head, int index, stack<int> & s, vector <int>&ans  )
        {
            if( head == NULL )
            {
                if( index == 0 ) return;
                ans.assign(index,0);
                return;
            }
            doIT(head->next,index+1,s,ans);
            while( !s.empty() && s.top() <= head->val ) s.pop();
            ans[index] = s.empty() ? 0 : s.top();
            s.push(head->val);
        }
        
       vector<int> nextLargerNodes(ListNode* head) {
            stack<int> s;
           int index = 0;
            vector <int> ans;
           doIT(head,index,s,ans);
            return ans;
       }
};

// iterative solution

class Solution2 {
	public:
		 vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        int idx = 0;
        
        while(head != NULL){
            while(!s.empty() && ans[s.top()] < head->val){
                ans[s.top()] = head->val;
                s.pop();
            }
            
            s.push(idx++);
            ans.push_back(head->val);
            head = head->next;
        }
        
        while(!s.empty()){
            ans[s.top()] = 0;
            s.pop();
        }
        
        return ans;
    }
};
