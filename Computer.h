#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
using namespace std;

enum ProcessorType
{
    x86 = 86,  // Тип процессора x86 с значением 86
    x64 = 64   // Тип процессора x64 с значением 64
};

class IProcessor
{
public:
    // Установка параметров процессора
    virtual void SetProcessor(std::string version, ProcessorType type, double speed) = 0;

    // Получение информации о процессоре
    virtual void GetInfo() = 0;

    // Виртуальный деструктор для правильного освобождения памяти
    virtual ~IProcessor() {}
};

// Реализация процессора Intel
class IntelProcessor : public IProcessor
{
protected:
    std::string Version;       // Версия процессора
    ProcessorType Type;        // Тип процессора
    double Speed;              // Скорость процессора

public:
    IntelProcessor() {}

    // Установка параметров процессора Intel
    void SetProcessor(std::string version, ProcessorType type, double speed)
    {
        Version = version;
        Type = type;
        Speed = speed;
    }

    // Получение информации о процессоре Intel
    void GetInfo()
    {
        std::cout << "Processor for " << Version << " Speed: " << Speed << " Type: x" << Type << "\n";
    }

    // Деструктор процессора Intel
    ~IntelProcessor() {
        std::cout << "Intel destructor\n";
    }
};

// Реализация процессора AMD
class AMDProcessor : public IProcessor
{
protected:
    std::string Version;       // Версия процессора
    ProcessorType Type;        // Тип процессора
    double Speed;              // Скорость процессора

public:
    AMDProcessor() {}

    // Установка параметров процессора AMD
    void SetProcessor(std::string version, ProcessorType type, double speed)
    {
        Version = version;
        Type = type;
        Speed = speed;
    }

    // Получение информации о процессоре AMD
    void GetInfo()
    {
        std::cout << "Processor for " << Version << " Speed: " << Speed << " Type: x" << Type << "\n";
    }

    // Деструктор процессора AMD
    ~AMDProcessor() {
        std::cout << "AMD destructor\n";
    }
};

// Класс Computer
class Computer
{
    // Приватное поле класса, которое является указателем на объект
    // процессора. Оно используется для хранения экземпляра процессора, который будет установлен
    // для данного компьютера.
    IProcessor* Processor;

public:
    // конструктор класса Computer. Принимает указатель на объект процессора в качестве аргумента
    // и инициализирует поле Processor этим указателем.
    Computer(IProcessor* processor) : Processor(processor) {}

    // метод, позволяющий установить процессор для компьютера. Принимает указатель на объект
    // процессора в качестве аргумента и присваивает его полю Processor.
    void SetProc(IProcessor* processor)
    {
        Processor = processor;
    }

    // Получение информации о процессоре
    void Info()
    {
        Processor->GetInfo();
    }
};

#endif // COMPUTER_H
