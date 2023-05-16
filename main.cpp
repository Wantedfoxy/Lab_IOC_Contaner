#include <iostream>
#include "IOCContainer.h"
#include "Computer.h"

int main()
{
    // Создаем контейнер IOC
    IOCContainer injector;

    // Регистрируем фабрику для создания объекта AMDProcessor
    injector.RegisterFactory<IProcessor, AMDProcessor, double, ProcessorType, std::string>();

    // Регистрируем фабрику для создания объекта IntelProcessor
    injector.RegisterFactory<IProcessor, IntelProcessor, double, ProcessorType, std::string>();

    // Создаем объекты компьютеров
    Computer computer1;
    Computer computer2;

    // Внедряем объект AMDProcessor в компьютер1
    std::shared_ptr<IProcessor> AMDProcessor = injector.GetObject<IProcessor>();
    computer1.SetProcessor(AMDProcessor);

    // Внедряем объект IntelProcessor в компьютер2
    std::shared_ptr<IProcessor> intelProcessor = injector.GetObject<IProcessor>();
    computer2.SetProcessor(intelProcessor);

    // Проверяем информацию о процессорах в компьютерах
    std::cout << "Computer 1 Processor Info: " << computer1.GetProcessorInfo() << std::endl;
    std::cout << "Computer 2 Processor Info: " << computer2.GetProcessorInfo() << std::endl;

    return 0;
}
