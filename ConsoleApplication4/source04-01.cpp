 Complex& operator=(char s[])
 {
     int i;
     int len=sizeof(s)/sizeof(s[0]);
     for(i=0;i<len;i++)
     {
         char* c=new char[len+1];
         while(s[i]!='+'&&s[i]!='i'&&s[i]!='\0'&&s[i]!='-')
         {
             c[i]=s[i];
             i++;
         }
         if(s[i]=='\0')
         {
             r=atof(c);
             this->i=0;
         }
         else if(s[i]=='i')
         {
             this->i=atof(c);
             this->r=0;
              break;
         }
         else if(s[i]=='+'||s[i]=='-')
         {
             r=atof(c);
             strcpy(c,s+i+1);
             if(s[i]=='-')
             this->i=-atof(c);
             else this->i=atof(c);
         }
         
         delete []c;
         return *this;
     }
 }