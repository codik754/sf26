//Файл array.h
#pragma once

#include <memory>
#include <cstddef>

//Класс для работы с массивом
class Array{
   std::shared_ptr<int[]> array_;//сам массив
   size_t n_;//количество элементов
   size_t m_;//на сколько участков делить
public:
   //Конструктор по умолчанию
   Array() : array_(nullptr), n_(0), m_(0) {}

   //Конструктор с параметрами
   Array(size_t n, size_t m);

   //Показать массив
   void show() const;
   
   //Подсчитать сумму всего массива
   long long calculateAllSum() const;

   //Подсчитать сумму
   long long calculateSum(size_t start, size_t end) const;
   
   //Получить массив
   std::shared_ptr<int[]> getArray() const;

   //Получить n
   size_t getN() const;

   //Получить m
   size_t getM() const;
};

