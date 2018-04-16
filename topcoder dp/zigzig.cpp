

vector < int > frequency(string s) {
    int num[26]={0};
    int i=0;
    while(i<s.length())
    {
        
            if(s[i]==')' || s[i-1]==')')
            {
                i++;
                continue;
            }
            if(s[i]=='(')
            {
                if(s[i-1]!='#')
                {
                    num[s[i-1]-'0']+=s[i+1]-'0';
                    
                }
                else if(s[i-1]=='#')
                {
                    num[(s[i-3]-'0')*10+(s[i-2]-'0')]+=s[i+1]-'0';
                }
                i++;
                continue;
            }
            else if(s[i]=='#')
            {
                if(i+1<s.length() and s[i+1]!='(')
                {
                   num[(s[i-2]-'0')*10+(s[i-1]-'0')]++;
                    i++;
                }
            }
           else 
           {
               if(i+1<s.length() and s[i+1]!='(')
               {
                  int val1=s[i]-'0';
                   if(val1>=0 and val1<=9)
                   {
                       if(i+2<s.length() and s[i+2]!='#')
                           num[val1]++;
                       i++;
                       
                   }
               }
           }
        
                
            
           
        
    }
     vector<int > v;
    for(int i=0;i<26;i++)
    {
        cout<<num[i]<<" ";
       v.push_back(num[i]);   
    }   
       