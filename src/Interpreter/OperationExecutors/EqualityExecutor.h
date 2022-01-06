#ifndef TKOM_EQUALITYEXECUTOR_H
#define TKOM_EQUALITYEXECUTOR_H

#include <variant>
#include <system_error>
#include "../../Program/LanguageElements/Variables/Number.h"
#include "../../Program/LanguageElements/Variables/Bool.h"
#include "../../Program/LanguageElements/Variables/ListOfVariantValues.h"
#include "../../Program/LanguageElements/Variables/String.h"

class DivisionExecutor {
public:

    template<typename U, typename V>
    std::variant<Number, String, ListOfVariantValues, Bool> operator()(const U& lhs, const V &rhs)
    {
        throw std::runtime_error("");
    }
};

#endif //TKOM_EQUALITYEXECUTOR_H
