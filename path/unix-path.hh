#pragma once

#include "path.hh"

class UnixPath : public Path
{
public:
    UnixPath() = default;
    ~UnixPath() override = default;

    std::string to_string() const override;

    UnixPath& join(const std::string& tail, bool is_file = false) override;
};