//Файл main.cpp
#include <iostream>
#include <algorithm>
#include <thread>
#include <vector>
#include <chrono>
#include "array.h"

int main(){
   Array array(10000000, 10); 

   std::cout << "N = " << array.getN() << std::endl; 
   std::cout << "M = " << array.getM() << std::endl; 
   std::cout << "======================================" << std::endl;

   //Начало отсчета времени
   auto tstart = std::chrono::system_clock::now();
   std::cout << "Sum(without threads) = " << array.calculateAllSum() << std::endl;
   //Конец отсчета
   auto tend = std::chrono::system_clock::now();
   std::chrono::duration<double> diff = tend - tstart;
   std::cout << "Time: " << diff.count() << std::endl;
   std::cout << "======================================" << std::endl;

   //Теперь сделаем подсчет с помощью потоков
   //Начало отсчета времени
   tstart = std::chrono::system_clock::now();

   //Высчитываем количество элементов в участках
   size_t n = array.getN() / array.getM();
   
   //Объявляем вектор для потоков
   std::vector<std::thread> threads;

   long long sum = 0;//переменная для конечного результата суммы
   //Добавляем значения для расчетов в поток
   for(size_t i = 0; i < array.getM() - 1; ++i){
      threads.push_back(std::thread([i, n, &array, &sum](){
         //Начало интервала
         size_t start = n * i;
         //Конец интервала
         size_t end = n + n * i;
         
         sum += array.calculateSum(start, end);
      }));
   }
   
   //Добавляем последний участок в поток
   threads.push_back(std::thread([n, &array, &sum](){
      //Начало интервала
      size_t start = n * (array.getM() - 1);
      //Конец интервала
      size_t end = array.getN();
      sum += array.calculateSum(start, end);
   }));

   //std::cout << "Count: " << threads.size() << std::endl;
   
   //Ждем завершения работы потоков
   std::for_each(threads.begin(), threads.end(), [](std::thread &t){ t.join(); });
   
   std::cout << "Sum(with threads) = " << sum << std::endl;
   //Конец отсчета
   tend = std::chrono::system_clock::now();
   diff = tend - tstart;
   std::cout << "Time: " << diff.count() << std::endl;

   return 0;
}
