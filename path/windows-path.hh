#pragma once

#include "path.hh"

class WindowsPath : public Path
{
public:
    WindowsPath(char drive);
    ~WindowsPath() override = default;

    std::string to_string() const override;

    WindowsPath& join(const std::string& tail, bool is_file = false) override;

private:
    char drive_;
};