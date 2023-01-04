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

    Operation(
        OpKind const& kind, 
        Variable * const& result, 
        std::vector<Value*> const& args
    ) : kind(kind), result(result), args(args) {}

    virtual ~Operation() = 0;
};

// 装饰一下
struct BinExpOp : Operation {
    BinExpOp(
        OpKind const& binOpKind, 
        Variable * const& result, 
        Value * const& lhs, 
        Value * const& rhs
    ) : Operation(binOpKind, result, {lhs, rhs}) {
        // check binOpKind here
    }

    Value *getLHS() const { return args[0]; }
    Value *getRHS() const { return args[1]; }
    void replaceLHS(Value * const& newLHS) { args[0] = newLHS; }
    void replaceRHS(Value * const& newRHS) { args[1] = newRHS; }
};