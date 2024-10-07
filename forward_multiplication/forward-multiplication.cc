#include "forward-multiplication.hh"

#include <functional>

lambda_type create_lambda()
{
    auto outer_lambda = [](int x) {
        auto inner_lambda = [x](int y) { return x * y; };
        return inner_lambda;
    };

    return outer_lambda;
}