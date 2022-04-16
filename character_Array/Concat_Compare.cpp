#include<bits/stdc++.h>
using namespace std;

bool compare_(char a[], char b[])
{
    int i = 0;
    int j = 0;
    int lena = strlen(a),lenb = strlen(b);
    while(i < lena && j < lenb)
    {
        if(a[i] != b[j])
        {
            return false;
        }
    }
    if(a[i] == '\0' && b[j] == '\0')
    {
        return true;
    }else 
    {
        return false;
    }



}

void concat(char a[],char b[])
{
    int i = strlen(a);
    for(int j = 0;j<=strlen(b);j++)
    {
        a[i] = b[j];
        i++;
    }
}


int main()
{
    char a[1000];
    char b[1000];
    cin.getline(a,1000);
    cin.getline(b,1000);

/*
    cout<<"Array a before:"<<a<<endl;
    cout<<"Array b before:"<<b<<endl;

    concat(a,b);

    //there is a inbuilt function strcat(); which works the same as our concat is doing

    cout<<"Array a after:"<<a<<endl;
    cout<<"Array b after:"<<b<<endl;
*/

// if(compare_(a,b)==true)
// {
//     cout<<"match"<<endl;
// }else{
//     cout<<"not match"<<endl;
// }


if(strcmp(a,b)==0)
{
    cout<<"match"<<endl;
}else{
    cout<<"not match"<<endl;
}




    return 0;

}