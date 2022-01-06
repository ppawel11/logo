#ifndef TKOM_CALLCONTEXT_H
#define TKOM_CALLCONTEXT_H

#include <list>
#include "Scope.h"

class CallContext {
    std::list<Scope> scope_list;
public:
    CallContext();

    explicit CallContext(std::map<std::string, std::unique_ptr<VariantValue>> args);

    void pop_block_scope();
    void add_block_scope();
    void add_block_scope(std::map<std::string, std::unique_ptr<VariantValue>> args);

    bool is_symbol_declared(const std::string& name);
    void set_variable(const std::string& name, std::unique_ptr<VariantValue> &value);
    const std::unique_ptr<VariantValue> & get_variable(const std::string& name);


};


#endif //TKOM_CALLCONTEXT_H