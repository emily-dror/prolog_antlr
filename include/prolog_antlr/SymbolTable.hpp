#pragma once

#include "ParserRuleContext.h"
#include "prologParser.h"
#include <cstdint>
#include <fstream>
#include <optional>

namespace PrologCompiler {

struct Sym {
    prologParser::VariableContext* varContext;
    std::size_t count = 0;
};


class SymTable {
public:
    SymTable() = default;


    /**
     * @brief Returns the symbol if it exists in the symbol table, otherwise returns empty
     * option (std::nullopt).
     * @param text: name of the symbol.
     */
    std::optional<Sym> getSym(const std::string& text) const;
    /**
     * @brief Returns the Sym->count.
     *
     * @param text: name of the symbol.
     */
    std::optional<std::size_t> getCount(const std::string& text) const;


private:
    std::map<std::string, Sym> m_table; // m_table : Name -> <Symbol, count>
};

} // namespace PrologCompiler
