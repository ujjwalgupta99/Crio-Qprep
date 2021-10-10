int myCompare(string X, string Y)
{
    string XY = X.append(Y);
 
    string YX = Y.append(X);
 
    return XY.compare(YX) > 0 ? 1 : 0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> temp;
    for(int i=0;i<A.size();i++){
        temp.push_back(to_string(A[i]));
    }
    sort(temp.begin(),temp.end(),myCompare);
    string s= temp[0];
    int flag=0;
    for(int i=1;i<temp.size();i++){
        s+=temp[i];
        //if(stoi(temp[i])>0)flag=1;
    }
    //cout<<s;
    for(int i=0;i<s.length();i++){
        if(s[i]>'0')flag=1;
    }
    if(flag==0) return "0";
    return s;
}