#include<atomic>
#include<thread>
#include<iostream>

using namespace std;

atomic<int>atomico_contador(0);
int não_atomico_contador = 0;

void contador_atomico(){
  for(int a=0;a<40000000;a++){
    atomico_contador.fetch_add(1);
  }
}

void contador_n_atomico(){
  for(int b=0;b<40000000;b++){
    não_atomico_contador++;
  }
}

int main(){

  thread t1(contador_atomico);
  thread t2(contador_atomico);
  thread t3(contador_n_atomico);
  thread t4(contador_n_atomico);

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  cout<<"contador atomico"<<atomico_contador<<endl;
  cout<<"contador não atomico"<<não_atomico_contador<<endl;

  return 0;

}
