 #include <iostream>
 usingnamespace std;

 class Queue{
 int arr[5]; //smallsizefordemo
 int front,rear;
 public:
 Queue(){
 front=-1;
 rear =-1;
 }
 void enqueue(intx){
 if (rear==4){
 cout<<"QueueOverflow\n";
 return;
 }
 if (front==-1)front=0;
 arr[++rear]=x;
 cout <<x<<"Enqueued\n";
 }
 void dequeue(){
 if (front==-1||front> rear){
 cout<<"QueueUnderflow\n";
 return;
 }
 cout <<arr[front++]<<"Dequeued\n";
 if (front>rear){
 front=rear=-1; //queuebecomesempty
 }
 }
 void display(){
 if (front==-1||front> rear){
 cout<<"QueueisEmpty\n";
 return;
 }
 cout <<"Queue:";

for (int i = front; i <= rear; i++)

cout << arr[i] << " ";
cout << "\n";
}

 };
 int main() {

Queue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.display();
// display queue
q.dequeue();
q.display();
return 0;
}

