#include<iostream>
#include<atomic>
#include<thread>

using namespace std;
//definimos um vetor atomico para lidar com o contador.
atomic<int> contador(0);

//define um contador até 1000 
void incrementar(){
  for(int i=0;i<10000;i++){
    //poderiamos usar o fetch_add para incrementar de forma atomica caso n tivesse
    //definido o vetor como atomico 
    contador++;
  }
}

//usando thread para 
int main(){
  //define t1 como thread 1 e t2 como thread 2;
  thread t1(incrementar);
  thread t2(incrementar);
  t1.join();
  t2.join();
  cout<<"contador"<<contador<<endl;
  return 0;
}
  

