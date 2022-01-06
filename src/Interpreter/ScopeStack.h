#ifndef TKOM_SCOPESTACK_H
#define TKOM_SCOPESTACK_H

#include "Scope.h"
#include "CallContext.h"
#include "../Program/LanguageElements/Variables/Assignable.h"
#include "../Program/LanguageElements/Variables/String.h"
#include "../Program/LanguageElements/Variables/ListOfVariantValues.h"
#include "../Program/LanguageElements/Variables/Bool.h"
#include "../Program/LanguageElements/Variables/Number.h"
#include <variant>
#include <optional>
#include <stack>

class ScopeStack {
    std::stack<CallContext> call_stack;
    std::map<std::string, std::unique_ptr<FunctionDefinition>> func_map;

    mutable std::unique_ptr<VariantValue> last_result;
    std::optional<std::variant<Number, Bool, String, ListOfVariantValues>> last_result_variant;
public:
    const std::optional<std::variant<Number, Bool, String, ListOfVariantValues>> &getLastResultVariant() const;

    void setLastResultVariant(
            const std::optional<std::variant<Number, Bool, String, ListOfVariantValues>> &lastResultVariant);

public:
    ScopeStack(): last_result{ nullptr }, call_stack(), func_map() {}


    void init_global(std::map<std::string, std::unique_ptr<FunctionDefinition>> func_defs_);
    void make_call();
    void make_call(std::map<std::string, std::unique_ptr<VariantValue>> args);
    void return_call();
    void make_var(const std::string &name, std::unique_ptr<VariantValue> value_);
    void make_func(const std::string &name, std::unique_ptr<FunctionDefinition> func_def);
    const std::unique_ptr<FunctionDefinition> & get_function(const std::string & name);
    std::unique_ptr<VariantValue> & get_var(const std::string& name);
    void set_var(const std::string& name, std::unique_ptr<VariantValue> &value);

    bool is_symbol_defined(std::string name);

    std::unique_ptr<VariantValue> & get_last_result() const;

    void set_last_result(std::unique_ptr<VariantValue> lastResult);
};


#endif //TKOM_SCOPESTACK_H