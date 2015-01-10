/* 
 * File:   main.cpp
 * Author: Yi Jin
 * ID: 4370673
 * Created on October 22, 2014, 10:53 PM
 */

#include"myheap.h"
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;  
  
class JacketFlow;  
class MiniHeapNode  
{  
    friend class JacketFlow;  
    public:  
        operator int() const {return bb;}  
    private:      
        void Init(int);  
        void NewNode(MiniHeapNode,int,int,int,int,int);  
        int arranged,          //arranged jobs 
            f1,         //finish time for machine a 
            f2,         //finish time for machine b
            f3,         //finish time for machine c
            sf2,        //current finish time for machine b
            sf3,        //current finish time for machine c
            bb,         //low bound  
            *x;         //current job schedule  
};  
  
class JacketFlow  
{  
    friend int main(int argc,char* argv[]);  
    public:  
        int BBFlow();  
    private:  
        int Bound(MiniHeapNode E,int &f1,int &f2,int &f3,bool **y);  
        void Sort();  
        int n,          //the number of jobs 
            **M,       //time for each jobs
            **sorted,        //time for each jobs sorted 
            **match,        //M and b match  
            *bestx,     //best sequence 
            bestc,      //finish time  
            count;      //search node
        bool **work;       //work array  
};  
  
template <class Type>  
inline void Swap(Type &a, Type &b);  

void report(int **,int *,int);

int main(int argc,char* argv[])  
{  
    int n=0;
    
    JacketFlow flow;  
    
    if(argc!=2)
    {
        cout<<"Usage: ./pfs <inputfile> "<<endl;
        exit(1);
    }
    
    ifstream fin;
    
    fin.open(argv[1]);
   
    fin>>n;
    
    int **M=new int*[n];  
    int **sorted=new int*[n];  
    int **match=new int*[n];  
    bool **work=new bool*[n];  
    int *bestx=new int[n];    
  
    for(int i=0;i<n;i++)  
    {  
        M[i]=new int[3];  
        sorted[i]=new int[3];  
        match[i]=new int[3];  
        work[i]=new bool[3];  
    }  
  
    for(int i=0;i<3;i++)    
        for(int j=0;j<n;j++)   
            fin>>M[j][i];  
    
    fin.close();
     
    flow.n=n;  
    flow.M=M;  
    flow.sorted=sorted;  
    flow.match=match;  
    flow.work=work;  
    flow.bestx=bestx;  
    flow.bestc=1000;
    flow.count=0;//initial number  
  
    flow.BBFlow();  
    cout<<"Optimal sequence ";  
    for(int i=0;i<n;i++)   
        cout<<(flow.bestx[i]+1)<<" ";    
    cout<<endl;  
    
    report(M,flow.bestx,flow.n);
    
    cout<<"Search nodes "<<flow.count<<endl;
    
    for(int i=0;i<n;i++)  
    {  
        delete[] M[i];  
        delete[] sorted[i];  
        delete[] match[i];  
        delete[] work[i];        
    }  
    return 0;  
   
}  

void MiniHeapNode::Init(int n)//initialization  
{  
    x=new int[n];  
    for(int i=0;i<n;i++)   
        x[i]=i;   
    arranged=0;  
    f1=0;  
    f2=0;  
    f3=0;
    sf2=0;
    sf3=0;
    bb=0;  
}  
  
void MiniHeapNode::NewNode(MiniHeapNode E,int Ef1,int Ef2,int Ef3,int Ebb,int n)  
{  
    x=new int[n];  
    for(int i=0;i<n;i++)   
        x[i]=E.x[i];   
    f1=Ef1;  
    f2=Ef2;  
    f3=Ef3;
    sf2=E.sf2+f2;
    sf3=E.sf3+f3;
    bb=Ebb;  
    arranged=E.arranged+1;  
}  
   
void JacketFlow::Sort()  
{ 
    int *c=new int[n];  
    for(int j=0;j<3;j++)  
    {  
        for(int i=0;i<n;i++)  
        {  
            sorted[i][j]=M[i][j];  
            c[i]=i;  
        }  
  
        for(int i=0;i<n-1;i++)  
        {  
            for(int k=n-1;k>i;k--)  
            {  
                if(sorted[k][j]<sorted[k-1][j])  
                {  
                    Swap(sorted[k][j],sorted[k-1][j]);  
                    Swap(c[k],c[k-1]);  
                }  
            }  
        }     
  
        for(int i=0;i<n;i++)    
            match[c[i]][j]=i;  
    }  
  
    delete []c;  
}  
   
int JacketFlow::Bound(MiniHeapNode E,int &f1,int &f2,int &f3,bool **work)//calculate the lower bound
{  
    for(int k=0;k<n;k++)    
        for(int j=0;j<3;j++)     
            work[k][j]=false;  
 
    for(int k=0;k<=E.arranged;k++)   
        for(int j=0;j<3;j++)  
            work[match[E.x[k]][j]][j]=true;  
         
    f1=E.f1+M[E.x[E.arranged]][0];  
    f2=(f1>E.f2?f1:E.f2)+M[E.x[E.arranged]][1];
    f3=(f2>E.f3?f2:E.f3)+(f1>E.f2?f1:E.f2)+M[E.x[E.arranged]][2];
    int sf2=E.sf2+f2;  
    int sf3=E.sf3+f2;
    int s1=0,s2=0,s3=0,k1=n-E.arranged,k2=n-E.arranged,k3=n-E.arranged,f4=f2;  
  
    //calculate the machine a 
    for(int j=0;j<n;j++)  
    { 
        if(!work[j][0])  
        {  
            k1--;  
            if(k1==n-E.arranged-1)   
                f4=(f2>f1+sorted[j][0])?f2:f1+sorted[j][0];    
            s1+=f1+k1*sorted[j][0];  
        }  
    }  
  
    //calculate the machine b
    for(int j=0;j<n;j++)  
    {     
        if(!work[j][1])  
        {  
            k2--;  
            s1+=sorted[j][1];  
            s2+=f4+k2*sorted[j][1];  
        }  
    } 
    
    //calculate the machine c
    for(int j=0;j<n;j++)  
    {     
        if(!work[j][2])  
        {  
            k3--;  
            s1+=sorted[j][2];  
            s2+=f4+k3*sorted[j][2];  
            s3+=f4+k3*sorted[j][2];
        }  
    }
   
    return sf3+(s3>s2?s2:s3)+(s1>s2?s1:s2);  
}  
   
int JacketFlow::BBFlow(void)//branch and bound
{  
    Sort(); 
    MiniHeap<MiniHeapNode> H(1000);  
    MiniHeapNode E;  
    E.Init(n);  

    while(E.arranged<=n)  
    {   
        if(E.arranged==n)  
        {  
            if(E.sf3<bestc)  
            {  
                bestc=E.sf3;  
                
                for(int i=0;i<n;i++)    
                    bestx[i]=E.x[i];    
            }  
            delete []E.x;  
        }  
        else//build siblings 
        {  
            for(int i=E.arranged;i<n;i++)  
            {  
                Swap(E.x[E.arranged],E.x[i]);  
                int f1,f2,f3; 
                int bb=Bound(E,f1,f2,f3,work);
                count++;
                if(bb<bestc)  
                {  
                    //child may have the best order
                    //insert into heap 
                    MiniHeapNode N;  
                    N.NewNode(E,f1,f2,f3,bb,n);  
                    H.Insert(N);  
                }  
                Swap(E.x[E.arranged],E.x[i]);  
            }  
            delete []E.x; 
        }  
        if(H.Size()==0)  
            break;  
  
        H.DeleteMin(E);//go to next child  
    }  
    
    int tmp=bestx[0];
    bestx[0]=bestx[1];
    bestx[1]=tmp;
    tmp=bestx[1];
    bestx[1]=bestx[3];
    bestx[3]=tmp;
    
    return bestc;  
}  
  
template <class Type>  
inline void Swap(Type &a, Type &b)  
{   
    Type temp=a;   
    a=b;   
    b=temp;  
}  

void report(int **M,int *order,int n)
{
    int machine=3;
    int **result=new int*[machine*2];
    for(int i=0;i<machine*2;i++)
        result[i]=new int[n];
      
    int** temp=new int*[3];
    for(int i=0;i<3;i++)
        temp[i]=new int[n];    
        
    for(int i=0;i<3;i++)
        for(int j=0;j<4;j++)
            temp[i][j]=M[j][i];
    
    for(int i=0;i<3;i++)
    {
        int tmp=temp[i][0];
        temp[i][0]=temp[i][1];
        temp[i][1]=tmp;
        tmp=temp[i][1];
        temp[i][1]=temp[i][2];
        temp[i][2]=tmp;
    }

    result[0][0]=0;
    result[1][0]=result[0][1]=result[2][0]=temp[0][0];
    result[0][2]=result[0][1]+temp[0][1];
    result[3][0]=result[4][0]=result[1][0]+temp[1][0];
    result[0][3]=result[0][2]+temp[0][2];
    result[5][0]=result[3][0]+temp[2][0];
     
    for(int i=1;i<machine*2;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(i==1&&i%2!=0)
                result[i][j]=result[i-1][j]+temp[i-1][j];
            else
                result[i][j]=result[i-1][j]+temp[i/2][j];
            
            if(i%2==0)
                result[i][j]=(result[i][j-1]+temp[i/2][j-1])>result[i-1][j]?result[i][j-1]+temp[i/2][j-1]:result[i-1][j];
        }
    }
    
    cout<<endl;
    cout<<"     j(i)         1     2     3     4"<<endl;
    for(int i=0;i<machine*2;i++)
    {
        if(i%2==0)
        {
            switch(i)
            {
                case 0:
                        cout<<"start[A,j(i)] ";
                        break;
                case 2:
                        cout<<"start[B,j(i)] ";
                        break;
                case 4: 
                        cout<<"start[C,j(i)] ";
                        break;
            }        
        }
        else
        {
            switch(i)
            {
                case 1:
                        cout<<"finish[A,j(i)]";
                        break;
                case 3:
                        cout<<"finish[B,j(i)]";
                        break;
                case 5: 
                        cout<<"finish[C,j(i)]";
                        break;
            }   
        }
       
        for(int j=0;j<n;j++)
            cout<<setw(5)<<result[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    
    for(int i=0;i<3;i++)
        delete [] temp[i];
        
    for(int i=0;i<machine*2;i++)
        delete [] result[i];
    
    delete [] result;
    delete [] temp;
}
