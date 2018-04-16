#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n,i,j,mark1=0,mark2=0,count=0;
     cin>>n;
     char s[2][n];

     for(i=0;i<2;i++)
     {
         for(j=0;j<n;j++)
         {
            cin>>s[i][j];
            if(i==0 && s[0][j]=='*') mark1=1;
            if(i==1 && s[1][j]=='*') mark2=1;  
         }
     }
     if(mark1==mark2 && mark1) count++;
     //cout<<"oth count "<<count<<endl;
     int marker1=0,marker2=0,index=0; // tere liye maker1=top and marker 2=bottom
   
	    for(j=0;j<n;j++) 
	     {
	     	if(s[0][j]=='*' && s[1][j]=='*')
	     	{
                marker1=1;
                marker2=1;
                index=j;
                break;
            }
            else if(s[0][j]=='*')
            {
                marker1=1;
                index=j;
                break;
            }
            else if(s[1][j]=='*')
            {
                marker2=1;
                index=j;
                break;
            }
	     }

	     for(j=index+1;j<n;j++)
	     {
	     	if(s[0][j]=='*'&&s[1][j]=='*')
	     	{
	     		if(marker1==1||marker2==1)
	     		{
	     			//cout<<j<<'\n';	
	     				count++;
	     				marker1=1;
	     				marker2=1;
	     		}
	     	}
            else if(s[0][j]=='*')
	     	{
               // marker1=1;
	     		if(marker1)
	     		{
                	count++;
                	//cout<<j<<'\n';	
                	marker2=0;
            	}
            	marker1=1;
          
            }
            else if(s[1][j]=='*')
            {
                if(marker2)
                {
                	count++;
                	//cout<<j<<'\n';	
                	marker1=0;
            	}
                marker2=1;
              
            }
	     }
	  cout<<count<<endl;
  }

return 0;
}

