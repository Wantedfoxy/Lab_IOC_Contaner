#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>
#include <string>
using namespace std;

enum ProcessorType
{ x86,
  x64
};

// Интерфейс IProcessor
class IProcessor
{
public:
    virtual ~IProcessor() {}
    virtual string GetProcessorInfo() = 0;
};

// Реализация IntelProcessor
class IntelProcessor : public IProcessor
{
private:
    std::string m_version;
    ProcessorType m_type;
    double m_speed;

public:
    IntelProcessor(double speed, ProcessorType type, std::string version)
        : m_version(version), m_type(type), m_speed(speed)
    {}

    std::string GetProcessorInfo() override
    {
        return "Intel Processor: " + m_version + ", Speed: " + std::to_string(m_speed) + ", Type: " + std::to_string(static_cast<int>(m_type));
    }
};

// Реализация AMDProcessor
class AMDProcessor : public IProcessor
{
private:
    std::string m_version;
    ProcessorType m_type;
    double m_speed;

public:
    AMDProcessor(double speed, ProcessorType type, std::string version)
        : m_version(version), m_type(type), m_speed(speed)
    {}

    std::string GetProcessorInfo() override
    {
        return "AMD Processor: " + m_version + ", Speed: " + std::to_string(m_speed) + ", Type: " + std::to_string(static_cast<int>(m_type));
    }
};

class Computer
{
private:
    std::shared_ptr<IProcessor> m_processor;

public:
    void SetProcessor(std::shared_ptr<IProcessor> processor)
    {
        m_processor = processor;
    }

    std::string GetProcessorInfo()
    {
        if (m_processor)
            return m_processor->GetProcessorInfo();
        else
            return "No processor set";
    }
};

#endif // COMPUTER_H
