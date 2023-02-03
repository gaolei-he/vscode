#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    getchar();
    while(n--)
    {
        
        char str[1009];
        cin.getline(str, 1008);
        cout << str << endl;
        int length1 = strlen(str);
        for(int i=0;str[i]==' ';i++) str[i] = '\0';
        for(int i=length1-1;str[i]==' ';i--) str[i] = '\0';
        for(int i=0;i<length1;i++)
        {
            if(str[i]=='?') str[i] = '!';
            if(str[i]==' '&&str[i+1]==' ') str[i] = '\0';
            if(str[i]==' '&&(str[i+1]==','||str[i+1]=='?'||str[i+1]=='!'||str[i+1]=='\'')) str[i] = '\0';
            if(str[i]>='A'&&str[i]<='Z'&&str[i]!='I') str[i] += 32; 
        }
        char *p = NULL;
        char str1[1009];
        int k = 0;
        for(int i=0;i<length1;i++)
            if(str[i]!='\0') str1[k++] = str[i];
        str1[k] = '\0';
        while(p=strstr(str1, "can you"))
        {
            *p = 'I', *(p+1) = ' ';
            *(p+2) = 'c', *(p+3) = 'a', *(p+4) = 'n';
            *(p+5) = '&', *(p+6) = '&';
        }
        char str2[1009];
        k = 0;
        length1 = strlen(str1);
        for(int i=0;i<length1;i++)
            if(str1[i]!='&') str2[k++] = str1[i];
        str2[k] = '\0';
        while(p=strstr(str2, "could you"))
        {
            *p = 'I', *(p+1) = ' ';
            *(p+2) = 'c', *(p+3) = 'o', *(p+4) = 'u', *(p+5) = 'l', *(p+6) = 'd';
            *(p+7) = '&', *(p+8) = '&';
        }
        char str3[1009];
        k = 0;
        length1 = strlen(str2);
        for(int i=0;i<length1;i++)
            if(str2[i]!='&') str3[k++] = str2[i];
        str3[k] = '\0';

        while(p=strstr(str2, "could you"))
        {
            *p = 'I', *(p+1) = ' ';
            *(p+2) = 'c', *(p+3) = 'o', *(p+4) = 'u', *(p+5) = 'l', *(p+6) = 'd';
            *(p+7) = '&', *(p+8) = '&';
        }



        cout << "AI: " << str3 << endl;
    }
    return 0;
}