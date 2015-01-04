/* 
 * File:   disk.cpp
 * Author: Yi Jin
 * ID: 4370673
 * Created on October 18, 2014, 1:13 PM
 */
#include<cmath>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

struct addup
{
    string name;
    int data;
};

bool compare(addup a,addup b)
{
  return a.data<b.data;  
};

const char direction[4]={'L','l','G','g'};

int main() 
{
    addup cylinders[6];
    addup Maxwt[6];
    addup avewt[6];
    
    int cs;//Cylinder Start
    char hd;//Head Direction
    char temp[256];
    char tmp[256];
    vector<int> cq;//cylinder queue
    cout<<"Cylinder Start: ";
    cin>>cs;
    if(cs>199||cs<0)
    {
        cout<<"Out of cylinders scales!!!"<<endl;
        exit(1);
    }
    cout<<"Head Direction: ";
    cin>>hd;
    bool check=true;
    for(int i=0;i<4;i++)
    {
        if(hd==direction[i])
        {
            check=false;
            break;
        }
    }
    if(check)
    {
        cout<<"Wrong type of head direction!!!"<<endl;
        exit(1);
    }
    cout<<"Cylinder Queue: ";
    cin.ignore();
    cin.getline(temp,256,'\n');
    stringstream stemp(temp);
    do
    {
        stemp.getline(tmp,256,' ');
        cq.push_back(atoi(tmp));
    }while(strlen(tmp)!=0);
    cq.pop_back();//remove the excess space
    
    bool find=false;
    
    for(int i=0;i<cq.size();i++)
        if(cs==cq[i])
            find=true;
    
    if(find)
        cout<<endl;
    else
        cout<<" "<<endl;
    cout<<"FCFS Head Movement: ";
    if(!find)
        cout<<cs<<"=>";
    
    for(int i=0;i<cq.size();i++)
    {
        if(i!=cq.size()-1)
            cout<<cq[i]<<"=>";
        else
            cout<<cq[i]<<endl;
    }
    
    int totmove=0;//Initialization
    int maxwt=0;
    int minwt=9999;
    int totwt=0;
    int cc=cs;//current cylinder
    
    for(int i=0;i<cq.size();i++)
    {
        int static pw=0;//previous waiting time
        int curw=0;//current waiting time
        if(cc!=cq[i])
            curw=abs(cc-cq[i])*0.8+3+pw;
        else
            curw=0;
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cq[i]);
        cc=cq[i];
    }
    cout<<"FCFS Total Movement: "<<totmove<<" cylinders"<<endl;
    cout<<"FCFS Min Waiting Time: "<<minwt<<"ms"<<endl;
    cout<<"FCFS Max Waiting Time: "<<maxwt<<"ms"<<endl;
    cout<<"FCFS Ave Waiting Time: "<<totwt/cq.size()<<"ms"<<endl;
    cylinders[0].name="FCFS";
    cylinders[0].data=totmove;
    Maxwt[0].name="FCFS";
    Maxwt[0].data=maxwt;
    avewt[0].name="FCFS";
    avewt[0].data=totwt/cq.size();
    
    totmove=0;//reset
    maxwt=0;
    minwt=9999;
    totwt=0;
    cc=cs;
    int* distance=new int[cq.size()];
    for(int i=0;i<cq.size();i++)//calculate cylinder move for each request 
        distance[i]=abs(cs-cq[i]);
    for(int i=0;i<cq.size();i++)//sort
        for(int j=i+1;j<cq.size();j++)
            if(distance[i]>distance[j])
            {
                int temp=distance[i];
                distance[i]=distance[j];
                distance[j]=temp;
                temp=cq[i];
                cq[i]=cq[j];
                cq[j]=temp;
            }
    
    cout<<endl<<"SSTF Head Movement: ";
    if(!find)
        cout<<cs<<"=>";
    for(int i=0;i<cq.size();i++)
        if(i!=cq.size()-1)
            cout<<cq[i]<<"=>";
        else
            cout<<cq[i]<<endl;
    
    for(int i=0;i<cq.size();i++)
    {
        int static pw=0;//previous waiting time
        int curw=0;//current waiting time
        if(cc!=cq[i])
            curw=abs(cc-cq[i])*0.8+3+pw;
        else
            curw=0;
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cq[i]);
        cc=cq[i];
    }
    cout<<"SSTF Total Movement: "<<totmove<<" cylinders"<<endl;
    cout<<"SSTF Min Waiting Time: "<<minwt<<"ms"<<endl;
    cout<<"SSTF Max Waiting Time: "<<maxwt<<"ms"<<endl;
    cout<<"SSTF Ave Waiting Time: "<<totwt/cq.size()<<"ms"<<endl;
    cylinders[1].name="SSTF";
    cylinders[1].data=totmove;
    Maxwt[1].name="SSTF";
    Maxwt[1].data=maxwt;
    avewt[1].name="SSTF";
    avewt[1].data=totwt/cq.size();
    
    delete [] distance;
    cq.push_back(cs);
    sort(cq.begin(),cq.end());
    
    totmove=0;//reset
    maxwt=0;
    minwt=9999;
    totwt=0;
    cc=cs;
    int num=0;//the position for the cylinder start
    vector<int> result;
    vector<int> cqx(cq);//cylinder queue with boundary
    cqx.push_back(0);
    cqx.push_back(199);
    sort(cqx.begin(),cqx.end());
    for(int i=0;i<cqx.size();i++)
        if(cc==cqx[i])
        {
            num=i;
            break;
        }    
    
    if(hd=='g'||hd=='G')//go greater direction
    {
        int backpoint=num-1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        for(int i=num+1;i<cqx.size();i++)
        {       
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        }
        
        curw=abs(cc-cqx[backpoint])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cqx[backpoint]);
        cc=cqx[backpoint];
        result.push_back(cc);
        
        for(int i=backpoint-1;i>0;i--)
        {
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        }  
    }
    else
    {
        int backpoint;
        if(cqx[num]==cqx[num+1])
            backpoint=num+2;
        else
            backpoint=num+1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        
        for(int i=num-1;i>=0;i--)
        {
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        }  
        
        curw=abs(cc-cqx[backpoint])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cqx[backpoint]);
        cc=cqx[backpoint];
        result.push_back(cc);
        
        for(int i=backpoint+1;i<cqx.size()-1;i++)
        {
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        } 
    }
     
    if(!find)
    {
        cout<<" "<<endl<<"SCAN Head Movement: ";
        cout<<cs<<"=>";
    }
    else if(hd!='l'&&hd!='L')
        cout<<endl<<"SCAN Head Movement: ";
    else
    {
        cout<<" "<<endl<<"SCAN Head Movement: ";
        cout<<cs<<"=>";
    }
    for(int i=0;i<result.size();i++)
        if(i!=result.size()-1)
            cout<<result[i]<<"=>";
        else
            cout<<result[i]<<endl;
    cout<<"SCAN Total Movement: "<<totmove<<" cylinders"<<endl;
    cout<<"SCAN Min Waiting Time: "<<minwt<<"ms"<<endl;
    cout<<"SCAN Max Waiting Time: "<<maxwt<<"ms"<<endl;
    cout<<"SCAN Ave Waiting Time: "<<totwt/(cq.size()-1)<<"ms"<<endl;
    cylinders[2].name="SCAN";
    cylinders[2].data=totmove;
    Maxwt[2].name="SCAN";
    Maxwt[2].data=maxwt;
    avewt[2].name="SCAN";
    avewt[2].data=totwt/(cq.size()-1);
    
    totmove=0;//reset
    maxwt=0;
    minwt=9999;
    totwt=0;
    cc=cs;
    num=0;
    result.clear();
    
    for(int i=0;i<cqx.size();i++)
        if(cc==cqx[i])
        {
            num=i;
            break;
        }    
    
    if(hd=='g'||hd=='G')//go greater direction
    {
        int backpoint=num-1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        for(int i=num+1;i<cqx.size();i++)
        {       
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        }
        
        curw=abs(cc-cqx[0])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cqx[0]);
        cc=cqx[0];
        result.push_back(cc);
        
        for(int i=1;i<backpoint+1;i++)
        {
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        }  
    }
    else
    {
        int backpoint;
        if(cqx[num]==cqx[num+1])
            backpoint=num+2;
        else
            backpoint=num+1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        
        for(int i=num-1;i>=0;i--)
        {
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        }  
        
        curw=abs(cc-cqx[cqx.size()-1])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cqx[cqx.size()-1]);
        cc=cqx[cqx.size()-1];
        result.push_back(cc);
        
        for(int i=cqx.size()-2;i>num+1;i--)
        {
            if(cc!=cqx[i])
                curw=abs(cc-cqx[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cqx[i]);
            cc=cqx[i];
            result.push_back(cc);
        } 
    }
     
    if(!find)
    {
        cout<<" "<<endl<<"CSCAN Head Movement: ";
        cout<<cs<<"=>";
    }
    else if(hd!='l'&&hd!='L')
        cout<<" "<<endl<<"CSCAN Head Movement: ";
    else
    {
        cout<<" "<<endl<<"CSCAN Head Movement: ";
        cout<<cs<<"=>";
    }
    for(int i=0;i<result.size();i++)
        if(i!=result.size()-1)
            cout<<result[i]<<"=>";
        else
            cout<<result[i]<<endl;
    cout<<"CSCAN Total Movement: "<<totmove<<" cylinders"<<endl;
    cout<<"CSCAN Min Waiting Time: "<<minwt<<"ms"<<endl;
    cout<<"CSCAN Max Waiting Time: "<<maxwt<<"ms"<<endl;
    cout<<"CSCAN Ave Waiting Time: "<<totwt/(cq.size()-1)<<"ms"<<endl;
    cylinders[3].name="CSCAN";
    cylinders[3].data=totmove;
    Maxwt[3].name="CSCAN";
    Maxwt[3].data=maxwt;
    avewt[3].name="CSCAN";
    avewt[3].data=totwt/(cq.size()-1);
    
    totmove=0;//reset
    maxwt=0;
    minwt=9999;
    totwt=0;
    cc=cs;
    num=0;
    result.clear();
    for(int i=0;i<cq.size();i++)
        if(cc==cq[i])
        {
            num=i;
            break;
        }
    if(hd=='g'||hd=='G')//go greater direction
    {
        int backpoint=num-1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        for(int i=num+1;i<cq.size();i++)
        {       
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        }
        
        curw=abs(cc-cq[backpoint])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cq[backpoint]);
        cc=cq[backpoint];
        result.push_back(cc);
        
        for(int i=backpoint-1;i>=0;i--)
        {
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        }  
    }
    else
    {
        int backpoint;
        if(cq[num]==cq[num+1])
            backpoint=num+2;
        else
            backpoint=num+1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        
        for(int i=num-1;i>=0;i--)
        {
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        }  
        
        curw=abs(cc-cq[backpoint])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cq[backpoint]);
        cc=cq[backpoint];
        result.push_back(cc);
        
        for(int i=backpoint+1;i<cq.size();i++)
        {
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        } 
    }
    if(!find)
    {
        cout<<" "<<endl<<"LOOK Head Movement: ";
        cout<<cs<<"=>";
    }
    else if(hd!='l'&&hd!='L')
        cout<<endl<<"LOOK Head Movement: ";
    else
    {
        cout<<" "<<endl<<"LOOK Head Movement: ";
        cout<<cs<<"=>";
    }
    for(int i=0;i<result.size();i++)
        if(i!=result.size()-1)
            cout<<result[i]<<"=>";
        else
            cout<<result[i]<<endl;
    cout<<"LOOK Total Movement: "<<totmove<<" cylinders"<<endl;
    cout<<"LOOK Min Waiting Time: "<<minwt<<"ms"<<endl;
    cout<<"LOOK Max Waiting Time: "<<maxwt<<"ms"<<endl;
    cout<<"LOOK Ave Waiting Time: "<<totwt/(cq.size()-1)<<"ms"<<endl;
    cylinders[4].name="LOOK";
    cylinders[4].data=totmove;
    Maxwt[4].name="LOOK";
    Maxwt[4].data=maxwt;
    avewt[4].name="LOOK";
    avewt[4].data=totwt/(cq.size()-1);
    
    totmove=0;//reset
    maxwt=0;
    minwt=9999;
    totwt=0;
    cc=cs;
    num=0;
    result.clear();
    for(int i=0;i<cq.size();i++)
        if(cc==cq[i])
        {
            num=i;
            break;
        }
    if(hd=='g'||hd=='G')//go greater direction
    {
        int backpoint=num-1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        for(int i=num+1;i<cq.size();i++)
        {       
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        }
        
        curw=abs(cc-cq[0])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cq[0]);
        cc=cq[0];
        result.push_back(cc);
        
        for(int i=1;i<num;i++)
        {
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        }  
    }
    else
    {
        int backpoint;
        if(cq[num]==cq[num+1])
            backpoint=num+2;
        else
            backpoint=num+1;
        int pw=0;//previous waiting time
        int curw=0;//current waiting time
        
        for(int i=num-1;i>=0;i--)
        {
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        }  
        
        curw=abs(cc-cq[cq.size()-1])*0.8+3+pw;//go to the back point
        if(minwt>curw)
            minwt=curw;
        if(maxwt<curw)
            maxwt=curw;
        pw=curw;
        totwt+=curw;
        totmove+=abs(cc-cq[cq.size()-1]);
        cc=cq[cq.size()-1];
        result.push_back(cc);
        
        for(int i=cq.size()-2;i>num+1;i--)
        {
            if(cc!=cq[i])
                curw=abs(cc-cq[i])*0.8+3+pw;
            else
                curw=0;
            if(minwt>curw)
                minwt=curw;
            if(maxwt<curw)
                maxwt=curw;
            pw=curw;
            totwt+=curw;
            totmove+=abs(cc-cq[i]);
            cc=cq[i];
            result.push_back(cc);
        } 
    }
    if(!find)
    {
        cout<<" "<<endl<<"CLOOK Head Movement: ";
        cout<<cs<<"=>";
    }
    else if(hd!='l'&&hd!='L')
        cout<<endl<<"CLOOK Head Movement: ";
    else
    {
        cout<<" "<<endl<<"CLOOK Head Movement: ";
        cout<<cs<<"=>";
    }
    for(int i=0;i<result.size();i++)
        if(i!=result.size()-1)
            cout<<result[i]<<"=>";
        else
            cout<<result[i]<<endl;
    cout<<"CLOOK Total Movement: "<<totmove<<" cylinders"<<endl;
    cout<<"CLOOK Min Waiting Time: "<<minwt<<"ms"<<endl;
    cout<<"CLOOK Max Waiting Time: "<<maxwt<<"ms"<<endl;
    cout<<"CLOOK Ave Waiting Time: "<<totwt/(cq.size()-1)<<"ms"<<endl;
    cylinders[5].name="CLOOK";
    cylinders[5].data=totmove;
    Maxwt[5].name="CLOOK";
    Maxwt[5].data=maxwt;
    avewt[5].name="CLOOK";
    avewt[5].data=totwt/(cq.size()-1);
    cout<<endl<<"BEST TO WORST ALGORITHMS (min to max)"<<endl;
    sort(cylinders,cylinders+6,compare);
    sort(Maxwt,Maxwt+6,compare);
    sort(avewt,avewt+6,compare);
    cout<<"Total Cylinders: ";
    for(int i=0;i<6;i++)
        cout<<cylinders[i].name<<" ";
    cout<<endl;
    cout<<"Max Waiting time: ";
    for(int i=0;i<6;i++)
        cout<<Maxwt[i].name<<" ";
    cout<<endl;
    cout<<"Ave Waiting time: ";
    for(int i=0;i<6;i++)
        cout<<avewt[i].name<<" ";
    cout<<endl;
    
    return 0;
}

