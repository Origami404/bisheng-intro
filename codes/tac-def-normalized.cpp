#include <string>
#include <vector>

struct Value {};
struct Literal : Value {};
struct Variable : Value {};

enum class OpKind {};
struct Operation {
    OpKind kind;
    Variable *result;
    std::vector<Value*> args;
};