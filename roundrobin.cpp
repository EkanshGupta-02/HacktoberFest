// ROUND ROBIN

#include<bits/stdc++.h>
using namespace std;

struct round_robin
{
  int processId;
  int at,bt,ct,wt,tat,initial_time;
  int bt_rem;
}process[100];//array of structure to store the info of each process

bool arrangeAT(struct round_robin p,struct round_robin q)
{
   int a =p.at;
   int b =q.at;
   return a < b;

}

bool arrangePID(struct round_robin p,struct round_robin q)
{
   int a =p.processId;
   int b =q.processId;
   return a < b;
}

int main()
{
    
    int n,idx;
    queue<int> readyq;//works on FIFO manner
    bool checkFirst_Prcs=true;
    //presentTime->keep track of the time 
    int presentTime = 0,completed = 0,tq;
    bool visited[100]={false};//array to check if the process is in the queue or not
    cout<<"Enter number of processes: ";
    cin>>n;    
    float sumTat=0,sumWt=0;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter Arrival time of process "<<i<<" : ";
        cin >> process[i].at;
        process[i].processId=i;

        cout<<"Enter Burst time of process "<<i<<" : ";
        cin >> process[i].bt;
        process[i].bt_rem= process[i].bt;//storing all these burst time inside a new array ,this is outside from the structure
    }
    
    cout<<"\nEnter time quanta: ";
    cin>>tq;
     //sort structure on the basis of Arrival time in increasing order
    sort(process,process+n,arrangeAT);
    
    readyq.push(0);  //push the first process from the sorted list into queue
    visited[0] = true;
   
    while(completed != n) 
    {
      idx = readyq.front();      
      readyq.pop();
      
      if(process[idx].bt_rem == process[idx].bt)//a process is picked for the first time
      {
            process[idx].initial_time = max(presentTime,process[idx].at);
            presentTime =  process[idx].initial_time;//initial time will tell that at what particular point of time a particular process has been started to execute on the cpu 
            checkFirst_Prcs = false;
             
      }

     if(process[idx].bt_rem-tq > 0)
      {    
            process[idx].bt_rem -= tq;
            presentTime += tq;
      }
      else 
      {
            presentTime += process[idx].bt_rem;
            process[idx].bt_rem = 0;
            completed++;

            process[idx].ct = presentTime;
            process[idx].tat = process[idx].ct - process[idx].at;
            process[idx].wt = process[idx].tat - process[idx].bt;

            sumTat += process[idx].tat;
            sumWt += process[idx].wt;
      }

      //check which new Processes needs to be pushed to Ready Queue from Input list
      for(int i = 1; i < n; i++) 
      {
          if(process[i].bt_rem > 0 && process[i].at <= presentTime && visited[i] == false)
          {
            readyq.push(i);
            visited[i] = true;
          }
      }
      //check if Process on CPU needs to be pushed to Ready Queue
      if( process[idx].bt_rem> 0) 
          readyq.push(idx);
       //if queue is empty, just add one process from list, whose remaining burst time > 0     
      if(readyq.empty())//if there is no process in queue
      {
          for(int i = 1; i < n; i++)
          {
            if(process[i].bt_rem > 0)
            {
              //add process index in queue
              readyq.push(i);
              visited[i] = true;
              break;
            }
          }
      }
   }
  //sort so that process ID in output comes in Original order   
  sort(process, process+n , arrangePID);


  cout<<"\nProcess No.  Arrival Time  CPU Burst Time   Completion Time  Turn Around Time  Waiting Time\n";
  for(int i=0;i<n;i++)
    cout<<i<<"               "<<process[i].at<<"              "<<process[i].bt<<"        "
	<<"            "<<process[i].ct<<"               "<<process[i].tat<<"            "<<process[i].wt<<endl;
  cout<<endl;    


  cout<<"\nAverage Waiting Time= "<<(float)sumWt/n;  
  cout<<"\nAverage Turn Around time= "<< (float)sumTat/n;  
  return 0;
}
