#include <atomic>
#include <thread>

std::atomic<int> v;
std::atomic<bool> v_ready{false};

void threadA() {
  // Escreve o valor e define a flag de pronto
  v.store(42, std::memory_order_release);
  v_ready.store(true, std::memory_order_release);
}

void threadB() {
  // Aguarda uma mudança de valor e lê
  while (!v_ready.load(std::memory_order_acquire)) {
    // espera
  }
  const int my_v = v.load(std::memory_order_acquire);
  // Faz algo com my_v...
}

 
