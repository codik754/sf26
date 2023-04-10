//Файл array.cpp
#include "array.h"
#include <ctime>
#include <iostream>

//Конструктор с параметрами
Array::Array(size_t n, size_t m) : n_(n), m_(m){
   //Создаем массив
   array_ = std::shared_ptr<int[]>(new int[n_], std::default_delete<int[]>());
   
   //Заполняем значениями
   //Устанавливаем точку, с которой начинается генерация
   srand(time(NULL));
   //Проходим по всему массиву и заполняем значениями
   for(size_t i = 0; i < n_;  ++i){
      array_[i] = rand() % 9 + 1;
   }
}

//Показать массив
void Array::show() const{
   std::cout << "array: ";
   for(size_t i = 0; i < n_; ++i){
      std::cout << array_[i] << " ";
   }
   std::cout << std::endl;
}

//Подсчитать сумму всего массива
long long Array::calculateAllSum() const{
   long long sum = 0;

   for(size_t i = 0; i < n_; ++i){
      sum += static_cast<long long>(array_[i]);
   }

   return sum;
}

//Подсчитать сумму элементов в определенном участке
long long Array::calculateSum(size_t start, size_t end) const{
   long long sum = 0;

   for(size_t i = start; i < end; ++i){
      sum += static_cast<long long>(array_[i]);
   }

   return sum;
}

//Получить массив
std::shared_ptr<int[]> Array::getArray() const{
   return array_;
}

//Получить n
size_t Array::getN() const{
   return n_;
}

//Получить m
size_t Array::getM() const{
   return m_;
}
