#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "tabela.h"
#include <unordered_map>
#include <string>
#include <optional>
#include <iostream>

class SymbolTable {
private:
    std::unordered_map<std::string, Symbol> table;

public:
    // Insere um símbolo na tabela
    bool insert(const Symbol& symbol) {
        // Evita sobrescrever se já existe
        if (table.find(symbol.name) != table.end()) {
            return false;
        }
        table[symbol.name] = symbol;
        return true;
    }

    // Procura um símbolo na tabela
    std::optional<Symbol> lookup(const std::string& name) const {
        // 'auto' faz com que deduza automaticamente da estrutura ao lado, nesse caso, "table"
        auto symbol_type = table.find(name);
        if (symbol_type != table.end()) {
            // retorna o valor da chave, logo, por isso retorna "second"
            return symbol_type->second;
        }
        return std::nullopt;
    }

    // Percorre toda a tabela
    void dump() const {
        for (const auto& [key, symbol] : table) {
            std::cout << "Nome: " << symbol.name 
                      << ", Tipo: " << symbol.type 
                      << ", Escopo: " << symbol.scopeLevel << '\n';
        }
    }

    // Limpa a tabela da memória
    void clear() {
        table.clear();
    }
};

#endif