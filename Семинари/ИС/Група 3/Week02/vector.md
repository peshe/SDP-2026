# Вектори

## Задачи

### Задача 1
Напишете функция `erase` и `insert` за вектор, които изтриват и вмъкват елемент на дадена позиция.

### Задача 2
Довършете имплементацията на `vector_standart`. Добававете метод `emplace`, който добавя произволен брой елементи в края на вектора **in-place**. За целта използвайте `placement new`.

Материали за имплементацията:
- [Variadic Templates](https://en.cppreference.com/w/cpp/language/parameter_pack)

- [std::forward](https://en.cppreference.com/w/cpp/utility/forward)

- [Placement new](https://en.cppreference.com/w/cpp/language/new#Placement_new)

- [Perfect Forwarding](https://en.cppreference.com/w/cpp/utility/forward#Perfect_forwarding)

- [emplace_back](https://en.cppreference.com/w/cpp/container/vector/emplace)

### Задача 3
Имплементирайте методи, които намират сечението и обединението между два вектора. Имплементирайте метод, който намира обединението между три вектора.

## Материали

[Template constraints (Stroustrup)](https://www.stroustrup.com/bs_faq2.html#constraints)

[noexcept магии](https://stackoverflow.com/questions/9249781/are-move-constructors-required-to-be-noexcept)