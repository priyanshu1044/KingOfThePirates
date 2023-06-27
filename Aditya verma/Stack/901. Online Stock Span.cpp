* code is very similar to the nearest greater to left problem code is also simillar but in this case it is given as constructor and next function so we have to use stack as a data member of the class and we have to use it in the next function.we have use stack of pair because we have to store the element , index both.starting with i=0;and at the end find nearest greater to left indices and subtract it from the current index.we get our consequtive smaller or equal elements.
class StockSpanner {
public:
stack<pair<int,int>>st; 
int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        int ans;
        if(st.size()==0)
        {
            ans=-1;
        }
        else if(st.size()>0 && st.top().first>price)
        {
            ans=st.top().second;
        }
        else if(st.size()>0 && st.top().first<=price)
        {
            while(st.size()>0 && st.top().first<=price)
            {
                st.pop();
            }
            if(st.size()==0)
            {
                ans=-1;
            }
            else{
                ans=st.top().second;
            }
        }

        st.push({price,i});
        ans=i-ans;
        i++;
        return ans;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */