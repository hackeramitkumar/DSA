#include<bits/stdc++.h>
using namespace std;

int main(){

   //creation and  initialization of the vector
   vector<int> a;
   vector<int> b(5,10);//fivr int with values 10 - for init with zero(5,0)
   vector<int> c(b.begin(),b.end());
   vector<int> d{1,2,3,4,5};

//    traversing
for(int i = 0;i<c.size();i++){
    cout<<c[i]<<" ";
}
putchar('\n');

// by using itertor
for(auto it = b.begin(); it!=b.end();it++)   //here auto can be replace by vector<int>::iterator
{
    cout<<*it<<" ";
}
putchar('\n');

//using for each loop
for(auto x: c)
{
    cout<<x<<" ";
}
putchar('\n');

//DISCUSSION ON SOME MORE FUNCTION
vector<int> v;
int n;
cin>>n;
for(int i = 0;i<n;i++)
{
    int no;
    cin>>no;
    v.push_back(no);      //push back function is used to add elemnt at the back position this function will do doubling of the memory 
}                         //doubling of memory is a costly process because suppose there is not the space in the memory just ahead of the
                          // vector so there is not any possibility of increing thte size of vector so now we have to make another vector 
                          //and copy these element in that
for(auto x: v)
{
    cout<<x<<" ";
}
putchar('\n');



//understand at memory level what are the diffrences between two vector v and d

cout<<v.size()<<endl;//
cout<<v.capacity()<<endl;//gives the size of underlying array
cout<<v.max_size()<<endl; // maximum n0 of elements a vector can hold in the worst case acc to available memory in


cout<<d.size()<<endl;
cout<<d.capacity()<<endl;
cout<<d.max_size()<<endl;







}