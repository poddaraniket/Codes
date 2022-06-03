//O(1)

class Bitset {
public:
    
    int count1=0,count0;
    string zeros,ones;
    
    Bitset(int size) {
        ones.resize(size,'0');
        zeros.resize(size,'1');
        count0=size;
    }
    
    void fix(int idx) {
        if(zeros[idx]=='1'){
           zeros[idx]='0'; 
           count0--;
        }
        
        if(ones[idx]=='0'){
           ones[idx]='1'; 
           count1++;
        }
    }
    
    void unfix(int idx) {
       if(ones[idx]=='1'){
           ones[idx]='0'; 
           count1--;
        }
        
        if(zeros[idx]=='0'){
           zeros[idx]='1'; 
           count0++;
        }
    }
    
    void flip() {
        swap(zeros,ones);
        swap(count0,count1);
    }
    
    bool all() {
        if(count1==ones.size())
            return true;
        return false;
    }
    
    bool one() {
        return count1>0 ? true : false;
    }
    
    int count() {
       return count1; 
    }
    
    string toString() {
       return ones;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */