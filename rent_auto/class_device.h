#ifndef IDISPLAYABLE_H
#define IDISPLAYABLE_H

#include <iostream>

// Пункт 8: Інтерфейс за допомогою чисто віртуальних функцій
class IDisplayable {
public:
    virtual void display() const = 0; // Чисто віртуальна функція
    virtual ~IDisplayable() {}        // Віртуальний деструктор для інтерфейсу
};

#endif