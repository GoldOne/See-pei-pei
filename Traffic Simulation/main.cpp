/* 
 * File:   main.cpp
 * Author: Yi Jin
 * ID: 4370673
 * Created on 4 October 2014, 1:12 PM
 */
#include<cmath>
#include<vector>
#include<cstdlib>
#include<fstream>
#include<iostream>
using namespace std;
const float speed=25;//90km/h==25m/s

struct coordinate
{
    int x;
    int y;
};

struct roadmap
{
    float distance;
    int cars;//the number of cars on the road
};

struct cars
{
    int time;//entry time
    int sp;//start point
    int ep;//end point
    int lp;//last point
    float trip;//trip time in peak
    float travel;//travel time 
    float duration;//how long for traveling the roads
    bool complete;//whether the trip is finish or not
    vector<int> plan;//planned path 
};

bool complete(vector<cars>);

int main(int argc, char* argv[]) 
{
    if(argc!=4)
    {
        cout<<"Usage: trafficsim <roadsfile> <carsfile> <congestion factor>"<<endl;
        exit(1);
    }
    
    float cf=atof(argv[3]);//congestion factor
    
    ifstream fin;
    
    fin.open(argv[1]);
    
    int size;//map size
    
    fin>>size;
    
    coordinate* gps=new coordinate[size];
    
    int junk;
    
    for(int i=0;i<size;i++)
    {
        fin>>junk;   
        fin>>gps[i].x;
        fin>>gps[i].y;
    }
    
    roadmap** map=new roadmap*[size];//declare the network map
    for(int i=0;i<size;i++)
        map[i]=new roadmap[size];
    
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)//Initialization
        {
            map[i][j].distance=0;
            map[i][j].cars=0;
        }
    
    fin>>junk;
    
    for(int i=0;i<junk;i++)//build undirected graph
    {
        int junk2,x,y;
        float distance;
        fin>>junk2;
        fin>>x;
        fin>>y;
        fin>>distance;
        map[x][y].distance=distance;
        map[y][x].distance=distance;
    }
    
    fin.close();
   
    fin.open(argv[2]);
    
    vector<cars> vcar;
    vector<cars> rcar;//cars on roads
    string time;
    
    while(fin>>time)
    {
        cars acar;
        acar.lp=-1;//Initialization
	acar.complete=false;
        acar.trip=0;
        string temp,tmp;
        int start,end,min,sec;
        temp=time.substr(3,2);//cut the string
        tmp=time.substr(6,2);
        min=atoi(temp.c_str());//convert into the minutes and seconds
        sec=atoi(tmp.c_str());
        acar.time=min*60+sec;//calculate in seconds
        fin>>start;
        acar.sp=start;
        fin>>end;
        acar.ep=end;
        vcar.push_back(acar);//store into a vector
    }     
   
    fin.close();
    
    //Radio traffic report simulation
    
    int stime=0;//simulation time
    int totdur=0;//total duration time for all cars
    float totdis=0;//total distance traveled for all cars
    cars longtime;//record the longest cost time car
    longtime.trip=0;
    longtime.travel=0;
    
    for(int i=0;i<vcar.size();i++)//choose the best way for the cars enter the map at the beginning of the simulation 
    {
        if(stime==vcar[i].time)
        {
            int finalway;
            int psp=vcar[i].sp;;//planned start point
            float distance=9999;
            
            do
            {
                for(int j=0;j<size;j++)//find the best way to next intersection
                {     
                    if(map[psp][j].distance!=0)
                    {
                        float temp=sqrt(pow(abs(gps[vcar[i].ep].x-gps[j].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[j].y),2.0));

                        if(distance>temp)
                        {    
                            distance=temp;
                            finalway=j; 
                        }
                    }
                }
                
                vcar[i].plan.push_back(finalway);
                psp=finalway;
                
            }while(psp!=vcar[i].ep);
                      
            map[vcar[i].sp][vcar[i].plan[0]].cars++;//add cars to the roads
            map[vcar[i].plan[0]][vcar[i].sp].cars++;
            
            totdis+=map[vcar[i].sp][vcar[i].plan[0]].distance;
            
            cars newcar;
            newcar.time=vcar[i].time;
            newcar.plan=vcar[i].plan;
            newcar.ep=vcar[i].ep;
            newcar.duration=map[vcar[i].sp][vcar[i].plan[0]].distance/speed;
            newcar.trip+=newcar.duration*(1+cf*(map[vcar[i].sp][vcar[i].plan[0]].cars/map[vcar[i].sp][vcar[i].plan[0]].distance));
            newcar.travel+=newcar.duration;
            newcar.lp=vcar[i].sp;
            newcar.sp=vcar[i].plan[0];
            newcar.complete=false;
            rcar.push_back(newcar);
        }
    }
    
    do
    {
        stime++;//tick-tock
        
        for(int i=0;i<rcar.size();i++)//car runs 25m on the road
            if(!rcar[i].complete)
                rcar[i].duration--;
        
        for(int i=0;i<rcar.size();i++)//check the car arrive at the new intersection
        {
            if(rcar[i].duration==0&&rcar[i].complete==false)
            {
                if(rcar[i].sp==rcar[i].ep)//the car reach the end point
                {
                    rcar[i].complete=true;
                    if(longtime.trip<rcar[i].trip)
                    {
                        longtime=rcar[i];
                        longtime.sp=vcar[i].sp;
                    }
                    
                    map[rcar[i].lp][rcar[i].sp].cars--;//remove the cars on the road
                    map[rcar[i].sp][rcar[i].lp].cars--;   
                    
                    totdur+=stime-vcar[i].time;
                }
                else//the car reach the intersection and go to the next intersection as planned
                {
                    int finalway;
    
                    for(int j=0;j<rcar[i].plan.size();j++)
                        if(rcar[i].sp==rcar[i].plan[j])
                            finalway=rcar[i].plan[j+1];
         
                    totdis+=map[rcar[i].sp][finalway].distance;

                    map[rcar[i].lp][rcar[i].sp].cars--;//remove the cars on the road
                    map[rcar[i].sp][rcar[i].lp].cars--;
                    map[rcar[i].sp][finalway].cars++;//add cars to the roads
                    map[finalway][rcar[i].sp].cars++;

                    rcar[i].duration=map[rcar[i].sp][finalway].distance/speed;
                    rcar[i].trip+=rcar[i].duration*(1+cf*(map[rcar[i].sp][finalway].cars/map[rcar[i].sp][finalway].distance));
                    rcar[i].lp=rcar[i].sp;  
                    rcar[i].sp=finalway;
                }
            }
        }  
        
        for(int i=0;i<vcar.size();i++)//add new car to the network when time is on
        {
            if(stime==vcar[i].time)
            {
                int finalway;
                int psp=vcar[i].sp;;//planned start point
                
                do
                {
                    float distance=9999;//make sure the car go to the right direction
                    float estimate=9999;//estimate trip time
                    int candidate1=0;
                    int candidate2=0;
                    bool mark=false;
                    
                    for(int j=0;j<size;j++)//find the best way to next intersection based on the current network status
                    {
                        if(map[psp][j].distance!=0)
                        {   
                            if(j==vcar[i].ep)
                            {
                                finalway=j;
                                mark=true;
                                break;
                            }

                            float temp=sqrt(pow(abs(gps[vcar[i].ep].x-gps[j].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[j].y),2.0));
                            if(distance>temp)
                            {
                                distance=temp;
                                candidate1=j;
                            }

                            if(estimate>map[psp][j].distance/speed*(1+cf*(map[psp][j].cars/map[psp][j].distance)))
                            {
                                estimate=map[psp][j].distance/speed*(1+cf*(map[psp][j].cars/map[psp][j].distance));
                                candidate2=j;
                            } 
                        }
                    }

                    if(!mark)
                    {
                        if(candidate1!=candidate2)
                        {
                            if(sqrt(pow(abs(gps[vcar[i].ep].x-gps[candidate1].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[candidate1].y),2.0))<sqrt(pow(abs(gps[vcar[i].ep].x-gps[candidate2].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[candidate2].y),2.0)))
                                finalway=candidate1;
                            else
                                finalway=candidate2;
                        }
                        else
                            finalway=candidate1;
                    }

                    vcar[i].plan.push_back(finalway);
                    psp=finalway;

                }while(psp!=vcar[i].ep);

                map[vcar[i].sp][vcar[i].plan[0]].cars++;//add cars to the roads
                map[vcar[i].plan[0]][vcar[i].sp].cars++;

                totdis+=map[vcar[i].sp][vcar[i].plan[0]].distance;

                cars newcar;
                newcar.time=vcar[i].time;
                newcar.plan=vcar[i].plan;
                newcar.ep=vcar[i].ep;
                newcar.duration=map[vcar[i].sp][vcar[i].plan[0]].distance/speed;
                newcar.trip+=newcar.duration*(1+cf*(map[vcar[i].sp][vcar[i].plan[0]].cars/map[vcar[i].sp][vcar[i].plan[0]].distance));
                newcar.travel+=newcar.duration;
                newcar.lp=vcar[i].sp;
                newcar.sp=vcar[i].plan[0];
                newcar.complete=false;
                rcar.push_back(newcar);
            }
        }
        
    }while(rcar.size()!=vcar.size()||!complete(rcar));
    
    cout<<"Radio traffic report simulation report"<<endl;
    cout<<"Total simulation time "<<stime/3600<<" hours "<<(stime%3600)/60<<" minutes "<<stime%3600%60<<" seconds."<<endl;
    cout<<"Average speed "<<totdis/totdur<<"m/s."<<endl;
    cout<<"The trip with the longest time:"<<endl;
    cout<<"Entry time 09:";
    if(longtime.time/60<10)
        cout<<"0"<<longtime.time/60<<":";
    else
        cout<<longtime.time/60<<":";
    if(longtime.time%60<10)
        cout<<"0"<<longtime.time%60<<endl;
    else
        cout<<longtime.time%60<<endl;
    cout<<"Start intersection: "<<longtime.sp<<endl;
    cout<<"Destination intersection: "<<longtime.ep<<endl;
    int tmp=static_cast<int>(longtime.trip);
    int temp=static_cast<int>(longtime.travel);
    cout<<"Trip time in peak: "<<(temp%3600)/180<<" minutes "<<temp%3600%60<<" seconds."<<endl;
    cout<<"Trip time off peak: "<<(tmp%3600)/180<<" minutes "<<tmp%3600%60<<" seconds."<<endl;
    
    stime=0;//simulation time reset
    totdur=0;//total duration time for all cars reset
    totdis=0;//total distance traveled for all car reset
    for(int i=0;i<size;i++)//reset all cars on roads to 0
        for(int j=0;j<size;j++)
            map[i][j].cars=0;
    
    longtime.trip=0;
    longtime.travel=0;
    rcar.clear();//clear all running cars on roads
    //GPS enabled simulation
    
    for(int i=0;i<vcar.size();i++)//choose the best way for the cars enter the map at the beginning of the simulation 
    {
        if(stime==vcar[i].time)
        {
            int finalway;
            float distance=9999;
            
            for(int j=0;j<size;j++)//find the cheapest way to next intersection
            {     
                if(map[vcar[i].sp][j].distance!=0)
                {
                    float temp=sqrt(pow(abs(gps[vcar[i].ep].x-gps[j].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[j].y),2.0));
                    
                    if(distance>temp)
                    {    
                        distance=temp;
                        finalway=j; 
                    }
                }
            }
            
            map[vcar[i].sp][finalway].cars++;//add cars to the roads
            map[finalway][vcar[i].sp].cars++;
            
            totdis+=map[vcar[i].sp][finalway].distance;
            
            cars newcar;
            newcar.time=vcar[i].time;
            newcar.ep=vcar[i].ep;
            newcar.duration=map[vcar[i].sp][finalway].distance/speed;
            newcar.trip+=newcar.duration*(1+cf*(map[vcar[i].sp][finalway].cars/map[vcar[i].sp][finalway].distance));
            newcar.travel+=newcar.duration;
            newcar.lp=vcar[i].sp;
            newcar.sp=finalway;
            newcar.complete=false;
            rcar.push_back(newcar);
        }
    }
    
    do
    {
        stime++;//tick-tock
        
        for(int i=0;i<rcar.size();i++)//car runs 25m on the roads
            if(!rcar[i].complete)
                rcar[i].duration--;
        
        for(int i=0;i<rcar.size();i++)//check whether the car arrive at the new intersection
        {
            if(rcar[i].duration==0&&rcar[i].complete==false)
            {   
                if(rcar[i].sp==rcar[i].ep)//the car reach the end point
                {   
                    rcar[i].complete=true;
                    if(longtime.trip<rcar[i].trip)
                    {
                        longtime=rcar[i];
                        longtime.sp=vcar[i].sp;
                    }
                    
                    map[rcar[i].lp][rcar[i].sp].cars--;//remove the cars on the road
                    map[rcar[i].sp][rcar[i].lp].cars--;   
                    
                    totdur+=stime-vcar[i].time;
                }
                else//the car reach the intersection and decide the new way
                {
                    int finalway;
                    float estimate=9999;//estimate trip time
                    float distance=9999;//make sure the car go to the right direction
        
                    int candidate1=0;
                    int candidate2=0;
                    bool mark=false;

                    for(int j=0;j<size;j++)//find the cheapest way to next intersection based on the network status
                    {
                        if(map[rcar[i].sp][j].distance!=0&&j!=rcar[i].lp)
                        {   
                            if(j==rcar[i].ep)
                            {
                                finalway=j;
                                mark=true;
                                break;
                            }

                            float temp=sqrt(pow(abs(gps[rcar[i].ep].x-gps[j].x),2.0)+pow(abs(gps[rcar[i].ep].y-gps[j].y),2.0));
                            if(distance>temp)
                            {
                                distance=temp;
                                candidate1=j;
                            }

                            if(estimate>map[rcar[i].sp][j].distance/speed*(1+cf*(map[rcar[i].sp][j].cars/map[rcar[i].sp][j].distance)))
                            {
                                estimate=map[rcar[i].sp][j].distance/speed*(1+cf*(map[rcar[i].sp][j].cars/map[rcar[i].sp][j].distance));
                                candidate2=j;
                            } 
                        }
                    }

                    if(!mark)
                    {
                        if(candidate1!=candidate2)
                        {
                            if(sqrt(pow(abs(gps[rcar[i].ep].x-gps[candidate1].x),2.0)+pow(abs(gps[rcar[i].ep].y-gps[candidate1].y),2.0))<sqrt(pow(abs(gps[rcar[i].ep].x-gps[candidate2].x),2.0)+pow(abs(gps[rcar[i].ep].y-gps[candidate2].y),2.0)))
                                finalway=candidate1;
                            else
                                finalway=candidate2;
                        }
                        else
                            finalway=candidate1;
                    }

                    totdis+=map[rcar[i].sp][finalway].distance;

                    map[rcar[i].lp][rcar[i].sp].cars--;//remove the cars on the road
                    map[rcar[i].sp][rcar[i].lp].cars--;
                    map[rcar[i].sp][finalway].cars++;//add cars to the roads
                    map[finalway][rcar[i].sp].cars++;

                    rcar[i].duration=map[rcar[i].sp][finalway].distance/speed;
                    rcar[i].trip+=rcar[i].duration*(1+cf*(map[rcar[i].sp][finalway].cars/map[rcar[i].sp][finalway].distance));
                    rcar[i].travel+=rcar[i].duration;
                    rcar[i].lp=rcar[i].sp;  
                    rcar[i].sp=finalway;
                }
            }
        }  
        
        for(int i=0;i<vcar.size();i++)//add new cars to the map when time is up
        {
            if(stime==vcar[i].time)
            {
                int finalway;
                float estimate=9999;//estimate trip time
                float distance=9999;//make sure the car go to the right direction
                bool mark=false;
                
                int candidate1=0;
                int candidate2=0;

                for(int j=0;j<size;j++)//find the cheapest way to next intersection based on the network status
                {
                    if(map[vcar[i].sp][j].distance!=0)
                    {   
                        if(j==vcar[i].ep)
                        {
                            finalway=j;
                            mark=true;
                            break;
                        }

                        float temp=sqrt(pow(abs(gps[vcar[i].ep].x-gps[j].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[j].y),2.0));
                        if(distance>temp)
                        {
                            distance=temp;
                            candidate1=j;
                        }

                        if(estimate>map[vcar[i].sp][j].distance/speed*(1+cf*(map[vcar[i].sp][j].cars/map[vcar[i].sp][j].distance)))
                        {
                            estimate=map[vcar[i].sp][j].distance/speed*(1+cf*(map[vcar[i].sp][j].cars/map[vcar[i].sp][j].distance));
                            candidate2=j;
                        } 
                    }
                }

                if(!mark)
                {
                    if(candidate1!=candidate2)
                    {
                        if(sqrt(pow(abs(gps[vcar[i].ep].x-gps[candidate1].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[candidate1].y),2.0))<sqrt(pow(abs(gps[vcar[i].ep].x-gps[candidate2].x),2.0)+pow(abs(gps[vcar[i].ep].y-gps[candidate2].y),2.0)))
                            finalway=candidate1;
                        else
                            finalway=candidate2;
                    }
                    else
                        finalway=candidate1;
                }
          
                totdis+=map[vcar[i].sp][finalway].distance;

                map[vcar[i].sp][finalway].cars++;//add cars to the roads
                map[finalway][vcar[i].sp].cars++;

                cars newcar;
                newcar.time=vcar[i].time;
                newcar.ep=vcar[i].ep;
                newcar.duration=map[vcar[i].sp][finalway].distance/speed;
                newcar.trip+=newcar.duration*(1+cf*(map[vcar[i].sp][finalway].cars/map[vcar[i].sp][finalway].distance));
                newcar.travel+=newcar.duration;
                newcar.lp=vcar[i].sp;
                newcar.sp=finalway;
                newcar.complete=false;
                rcar.push_back(newcar);     
            }
        }
        
    }while(rcar.size()!=vcar.size()||!complete(rcar));
    
    cout<<endl;
    cout<<"GPS enabled simulation report"<<endl;
    cout<<"Total simulation time "<<stime/3600<<" hours "<<(stime%3600)/60<<" minutes "<<stime%3600%60<<" seconds."<<endl;
    cout<<"Average speed "<<totdis/totdur<<"m/s."<<endl;
    cout<<"The trip with the longest time:"<<endl;
    cout<<"Entry time 09:";
    if(longtime.time/60<10)
        cout<<"0"<<longtime.time/60<<":";
    else
        cout<<longtime.time/60<<":";
    if(longtime.time%60<10)
        cout<<"0"<<longtime.time%60<<endl;
    else
        cout<<longtime.time%60<<endl;
    cout<<"Start intersection: "<<longtime.sp<<endl;
    cout<<"Destination intersection: "<<longtime.ep<<endl;
    temp=static_cast<int>(longtime.travel);
    cout<<"Trip time in peak: "<<(temp%3600)/180<<" minutes "<<temp%3600%60<<" seconds."<<endl;
    cout<<"Trip time off peak: "<<(tmp%3600)/180<<" minutes "<<tmp%3600%60<<" seconds."<<endl;
     
    for(int i=0;i<size;i++)
        delete [] map[i];
    delete [] map;
    delete [] gps;
    
    return 0;
}

bool complete(vector<cars> cars)
{
    for(int i=0;i<cars.size();i++)
        if(!cars[i].complete)
            return false;
    return true;
}
