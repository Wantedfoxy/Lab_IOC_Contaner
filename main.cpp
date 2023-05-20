#include <QCoreApplication>
#include "IOCContainer.h"
#include "Computer.h"

// Инициализируем ненулевым числом, иначе будет ошибка при компиляции "неразрешенный внешний символ"
int IOCContainer::s_nextTypeId = 1;

int main(int argc, char *argv[])
{
    // Создаем объект приложения QCoreApplication
    QCoreApplication a(argc, argv);

    // Создаем экземпляр контейнера для управления зависимостями (IOC)
    IOCContainer injector;

    // Регистрируем класс AMDProcessor как реализацию интерфейса IProcessor
    injector.RegisterInstance<IProcessor, AMDProcessor>();

    // Первый тест
    // Регистрируем класс IntelProcessor как реализацию интерфейса IProcessor
    injector.RegisterInstance<IProcessor, IntelProcessor>();

    // Получаем объект процессора через IOC-контейнер и устанавливаем его параметры
    // В данном случае, используется реализация IntelProcessor с версией "Intel",
    // типом процессора x86 и скоростью 4800
    injector.GetObject<IProcessor>()->SetProcessor("Intel", ProcessorType::x86, 4800);

    // Создаем компьютер PK1 с помощью полученного объекта процессора
    Computer PK1(injector.GetObject<IProcessor>().get());

    // Выводим информацию о процессоре, используемом в компьютере PK1
    PK1.Info();

    // Второй тест
    // Получаем объект процессора через IOC-контейнер и устанавливаем его параметры
    // В данном случае, используется реализация AMDProcessor с версией "AMD",
    // типом процессора x64 и скоростью 5200
    injector.GetObject<IProcessor>()->SetProcessor("AMD", ProcessorType::x64, 5200);

    // Создаем компьютер PK2 с помощью полученного объекта процессора
    Computer PK2(injector.GetObject<IProcessor>().get());

    // Выводим информацию о процессоре, используемом в компьютере PK2
    PK2.Info();

    // Запускаем цикл обработки событий приложения и возвращаем его код завершения
    return a.exec();
}
