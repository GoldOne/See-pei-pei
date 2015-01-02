/* 
 * File:   pager.cpp
 * Author: yj742
 * ID: 4370673
 * CSCI330 Ass3
 * Created on 20 September 2014, 1:12 PM
 */
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
using namespace std;
const string type[4]={"FIFO","LRU","LFU","OPT"};

int main(int argc, char* argv[]) 
{
    int size;//frame size
    int number;//number of strings
    string alg;//algorithm type
    char RS[1000];//reference string
    ifstream fin;
    
    if(argc>1)
    {
        fin.open(argv[1]);
        
        if(!fin.good())
	{
            cout<<"File no exist or Reading error!!!"<<endl;
            exit(1);
	}
        
        fin>>alg;
        bool check=true;
        for(int i=0;i<4;i++)
        {
            if(alg==type[i])
            {
                check=false;
                break;
            }
        }
        if(check)
        {
            cout<<"Wrong type of paging algorithm!!!"<<endl;
            exit(1);
        }
        fin>>size;
        if(size<0||size>9)
        {
            cout<<"Out of scale of frame size!!!"<<endl;
            exit(1);
        }
        fin>>RS;
        number=strlen(RS);
        for(int i=0;i<size;i++)
        {
            if(isalpha(RS[i]))
            {
                check=false;
                cout<<"The reference string should be a sequence of integers (digits 0..9)!!!"<<endl;
                exit(1);
            }
        } 
        fin.close();
        
    }
    else
    {
        bool check=true;
        do
        {
            cout<<"Enter page replacement algorithm: ";
            cin>>alg;
            cout<<alg<<endl;
            for(int i=0;i<4;i++)
            {
                if(alg==type[i])
                { 
                    check=false;
                    break;
                }
            }
            if(check)
                cout<<"Wrong type of paging algorithm!!!"<<endl;

        }while(check);
        
        do
        {
            cout<<"Enter page frame size: ";
            cin>>size;
            if(size<0||size>9)
                cout<<"Out of scale of frame size!!!"<<endl;
        }while(size<0||size>9);
        
        do
        {  
            int size;
            cout<<"Enter reference string: ";
            cin>>RS;
            size=strlen(RS);
            for(int i=0;i<size;i++)
            {
                if(isalpha(RS[i]))
                {
                    check=false;
                    cout<<"The reference string should be a sequence of integers (digits 0..9)!!!"<<endl;
                    break;
                }
            }   
        }while(check);
        
        number=strlen(RS);
        cout<<endl;
    }
    
    if(size!=0)
    {
        char** frame=new char*[size];//Initialization
        for(int i=0;i<size;i++)
            frame[i]=new char[number];

        char* fault=new char[number];
        for(int i=0;i<number;i++)
            fault[i]='-';
        int minor=0;//minor fault
        int major=0;//major fault
        for(int i=0;i<size;i++)
            for(int j=0;j<number;j++)
                frame[i][j]='-';
        int* counts=new int[size];//the number of each reference string
        for(int i=0;i<size;i++)
            counts[i]=-1;
        int* oldest=new int[size];//the number for old reference string
        for(int i=0;i<size;i++)
            oldest[i]=0;

        cout<<alg<<": String / Frames / Faults"<<endl;
        cout<<"Str: ";
        for(int i=0;i<number;i++)
            cout<<RS[i]<<" ";
        cout<<endl;

        for(int i=0,j=0;i<number;i++,j++)
        {   
            int static capacity=0;

            if(capacity<size)
            {
                if(i>0)
                    for(int k=0;k<size;k++)//copy the frame from previous loop
                    {    
                        frame[k][i]=frame[k][i-1];
                        oldest[k]++;
                    }

                for(int k=0;k<size;k++)
                {
                    if(frame[k][i]==RS[i])
                    {
                        counts[k]++;
                        break;
                    }
                    if(frame[k][i]=='-')
                    {
                        frame[k][j]=RS[i];
                        fault[i]='m';
                        minor++;
                        capacity++;
                        counts[k]=1;
                        oldest[k]++;
                        break;
                    }
                }
            }
            else
            {
                bool find=false;

                for(int k=0;k<size;k++)//look for the same reference string
                {
                    if(RS[i]==frame[k][j-1])
                    {
                        find=true;
                        counts[k]++;
                        oldest[k]=1;
                        break;
                    }
                }
                if(find)//copy the frame from previous loop
                {
                    for(int k=0;k<size;k++)
                    {
                        frame[k][j]=frame[k][j-1];
                        oldest[k]++;
                    }
                }
                else//make the paging replace
                {
                    if(alg=="FIFO")
                    {
                        for(int k=0;k<size;k++)//copy the frame from previous loop
                            frame[k][j]=frame[k][j-1];
                        for(int k=0;k<size-1;k++)
                            frame[k][j]=frame[k+1][j];
                        frame[size-1][j]=RS[i];
                        major++;
                        fault[i]='M';
                    }

                    if(alg=="LFU")
                    {
                        int min=0;
                        for(int k=0;k<size;k++)//copy the frame from previous loop
                            frame[k][j]=frame[k][j-1];
                        for(int k=0;k<size;k++)//find the least frequent reference page
                            if(counts[min]>counts[k])
                                min=k;

                        frame[min][j]=RS[i];
                        major++;
                        fault[i]='M';
                        counts[min]=1;
                    }
                    if(alg=="OPT")
                    {
                        int victim;

                        bool find=false;

                        for(int k=0;k<size;k++)//copy the frame from previous loop
                            frame[k][j]=frame[k][j-1];

                        int* distance=new int[size];
                        for(int k=0;k<size;k++)
                        {
                            find=false;

                            for(int l=j+1;l<number;l++)//find the distance for each of current page who will be used in the future
                            {
                                if(frame[k][j]==RS[l])
                                {
                                    find=true;
                                    distance[k]=l;
                                    break;
                                }
                            }

                            if(!find)//if not find then replace it directly
                            {
                                victim=k;
                                break;
                            }
                        }

                        if(find)
                        {
                            int max=0;
                            for(int k=0;k<size;k++)
                                if(distance[max]<distance[k])
                                    max=k;
                            frame[max][j]=RS[i];
                            major++;
                            fault[i]='M';
                        }
                        else
                        {
                            frame[victim][j]=RS[i];
                            major++;
                            fault[i]='M';
                        }

                        delete [] distance;
                    }
                    if(alg=="LRU")
                    {
                        int max=0;
                        for(int k=0;k<size;k++)//copy the frame from previous loop
                        {
                            frame[k][j]=frame[k][j-1];
                            oldest[k]++;
                        }

                        for(int k=0;k<size;k++)//find the oldest one and replace it.
                            if(oldest[max]<oldest[k])
                                max=k;

                        frame[max][j]=RS[i];
                        major++;
                        fault[i]='M';
                        oldest[max]=1;
                    }
                }
            }
        }

        for(int i=0;i<size;i++)
        {
            cout<<"Fr"<<i+1<<": ";
            for(int j=0;j<number;j++)
                cout<<frame[i][j]<<" ";
            cout<<endl;
        }
        cout<<"Flt: ";
        for(int i=0;i<number;i++)
            cout<<fault[i]<<" ";
        cout<<endl;
        cout<<alg<<": "<<minor<<" Minor Faults "<<major<<" Major Faults."<<endl;
        
        for(int i=0;i<size;i++)
            delete [] frame[i];
        delete [] frame; 
        delete [] fault;
        delete [] counts;
        delete [] oldest;
    }
    else
    {
        cout<<alg<<": ";
        for(int i=0;i<number;i++)
            cout<<RS[i];
        cout<<endl;
        cout<<endl;
        
        int eachfault[9]={0};//each fault for each frames
        
        for(int size=1;size<10;size++)
        {
            char** frame=new char*[size];//Initialization
            for(int i=0;i<size;i++)
                frame[i]=new char[number];

            char* fault=new char[number];
            for(int i=0;i<number;i++)
                fault[i]='-';
            int minor=0;//minor fault
            int major=0;//major fault
            for(int i=0;i<size;i++)
                for(int j=0;j<number;j++)
                    frame[i][j]='-';
            int* counts=new int[size];//the number of each reference string
            for(int i=0;i<size;i++)
                counts[i]=-1;
            int* oldest=new int[size];//the number for old reference string
            for(int i=0;i<size;i++)
                oldest[i]=0;
            
            int capacity=0;
            
            for(int i=0,j=0;i<number;i++,j++)
            {   
                if(capacity<size)
                {
                    if(i>0)
                        for(int k=0;k<size;k++)//copy the frame from previous loop
                        {    
                            frame[k][i]=frame[k][i-1];
                            oldest[k]++;
                        }

                    for(int k=0;k<size;k++)
                    {
                        if(frame[k][i]==RS[i])
                        {
                            counts[k]++;
                            break;
                        }
                        if(frame[k][i]=='-')
                        {
                            frame[k][j]=RS[i];
                            fault[i]='m';
                            minor++;
                            capacity++;
                            counts[k]=1;
                            oldest[k]++;
                            break;
                        }
                    }
                }
                else
                {
                    bool find=false;

                    for(int k=0;k<size;k++)//look for the same reference string
                    {
                        if(RS[i]==frame[k][j-1])
                        {
                            find=true;
                            counts[k]++;
                            oldest[k]=1;
                            break;
                        }
                    }
                    if(find)//copy the frame from previous loop
                    {
                        for(int k=0;k<size;k++)
                        {
                            frame[k][j]=frame[k][j-1];
                            oldest[k]++;
                        }
                    }
                    else//make the paging replace
                    {
                        if(alg=="FIFO")
                        {
                            for(int k=0;k<size;k++)//copy the frame from previous loop
                                frame[k][j]=frame[k][j-1];
                            for(int k=0;k<size-1;k++)
                                frame[k][j]=frame[k+1][j];
                            frame[size-1][j]=RS[i];
                            major++;
                            fault[i]='M';
                        }

                        if(alg=="LFU")
                        {
                            int min=0;
                            for(int k=0;k<size;k++)//copy the frame from previous loop
                                frame[k][j]=frame[k][j-1];
                            for(int k=0;k<size;k++)//find the least frequent reference page
                                if(counts[min]>counts[k])
                                    min=k;

                            frame[min][j]=RS[i];
                            major++;
                            fault[i]='M';
                            counts[min]=1;
                        }
                        if(alg=="OPT")
                        {
                            int victim;

                            bool find=false;

                            for(int k=0;k<size;k++)//copy the frame from previous loop
                                frame[k][j]=frame[k][j-1];

                            int* distance=new int[size];
                            for(int k=0;k<size;k++)
                            {
                                find=false;

                                for(int l=j+1;l<number;l++)//find the distance for each of current page who will be used in the future
                                {
                                    if(frame[k][j]==RS[l])
                                    {
                                        find=true;
                                        distance[k]=l;
                                        break;
                                    }
                                }

                                if(!find)//if not find then replace it directly
                                {
                                    victim=k;
                                    break;
                                }
                            }

                            if(find)
                            {
                                int max=0;
                                for(int k=0;k<size;k++)
                                    if(distance[max]<distance[k])
                                        max=k;
                                frame[max][j]=RS[i];
                                major++;
                                fault[i]='M';
                            }
                            else
                            {
                                frame[victim][j]=RS[i];
                                major++;
                                fault[i]='M';
                            }

                            delete [] distance;
                        }
                        if(alg=="LRU")
                        {
                            int max=0;
                            for(int k=0;k<size;k++)//copy the frame from previous loop
                            {
                                frame[k][j]=frame[k][j-1];
                                oldest[k]++;
                            }

                            for(int k=0;k<size;k++)//find the oldest one and replace it.
                                if(oldest[max]<oldest[k])
                                    max=k;

                            frame[max][j]=RS[i];
                            major++;
                            fault[i]='M';
                            oldest[max]=1;
                        }
                    }
                } 
            }
            
            eachfault[size-1]=major;
            
            for(int i=0;i<size;i++)
                delete [] frame[i];
            delete [] frame; 
            delete [] fault;
            delete [] counts;
            delete [] oldest;
        }
        
        int maxfault=0;
        
        for(int i=0;i<9;i++)//find the max fault of array
            if(maxfault<eachfault[i])
                maxfault=eachfault[i];  
        
        for(int i=maxfault;i>=0;i--)
        {
            bool warp=true;
            if(i==maxfault)
                cout<<"\t"<<i<<"\t";
            else if(i==maxfault/2+1)
                cout<<"Page\t"<<i;
            else if(i==maxfault/2)
                cout<<"Faults  "<<i;
            else
                cout<<"\t"<<i;
            
            for(int j=0;j<9;j++)
                if(i==eachfault[j])
                {
                    if(warp)
                    {
                        for(int k=0;k<j;k++)
                        {
                            cout<<"\t";
                            warp=false;
                        }
                    }
                    if(warp)
                        cout<<"X";
                    else
                        cout<<"\tX";
                }       
          
            cout<<endl;
        }
        
        cout<<"\t\t";
        for(int i=0;i<9;i++)
            cout<<i+1<<"\t";
        cout<<endl;
        cout<<"\t\t\t\t\tFrames"<<endl;
    }
 
    return 0;
}
