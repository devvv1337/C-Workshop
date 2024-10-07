#pragma once

#include <cassert>
#include <iostream>
#include <memory>
#include <string>

template <class T>
class Singleton
{
public:
    static T* instance()
    {
        static const std::unique_ptr<T> instance{ new T{} };
        return instance.get();
    }

protected:
    Singleton(){};
    virtual ~Singleton(){};
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

class Logger final : public Singleton<Logger>
{
    friend class Singleton<Logger>;

public:
    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

private:
    Logger(){};
    std::string file_;
};
