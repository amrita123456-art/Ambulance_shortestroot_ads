//write a c++ program to implement linear queue using static 1d array to stimulate a document print spooler. IMPLEMENT enqueue (addjob id) dequeue (process job ) front / rear inspection  and display operation.
#include iostream 
using namespace stdint main(){
    int q[5],front==-1,rear==-1,x;
    for (int i=0 i<3,i++){
    cin>>x;

if(rear==-1)
cout<<"underflow";
else if(front==-1)
    {front=0;
        q[++front]=x;

    }
//dequeue
if(front=-1 || front>rear)
{cout>>"overflow";
    else cout<<"dequeued"<<q[front--];
} return 0;
}
}...