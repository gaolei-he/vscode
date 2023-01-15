    mystring(mystring && s):str(s.str){}
    mystring & operator =(mystring && s)
    {
        if(str != s.str)
        {
            delete []str;
            str = s.str;
            s.str = new char[1];
            s.str[0] = 0;
        }
        return *this;
    }