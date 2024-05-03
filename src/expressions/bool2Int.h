#pragma once

#include "../expression.h"

// An expression that simply converts an int type to a bool type.
class ASTExpressionBool2Int : public ASTExpression
{
    // Operand to work on.
    std::unique_ptr<ASTExpression> operand;

public:
    // Create a new integer to bool conversion.
    // operand: Expression to convert to a bool. Make sure it is an int type, or else this will fail.
    explicit ASTExpressionBool2Int(std::unique_ptr<ASTExpression> operand) : operand(std::move(operand)) {}

    // Create a new integer to bool conversion.
    // operand: Expression to convert to a bool. Make sure it is an int type, or else this will fail.
    static auto Create(std::unique_ptr<ASTExpression> operand)
    {
        return std::make_unique<ASTExpressionBool2Int>(std::move(operand));
    }

    void MyOptznPass(std::unique_ptr<ASTExpression> &parentPtr, ASTFunction &func) override;

    // Virtual functions. See base class for details.
    std::unique_ptr<VarType> ReturnType(ASTFunction &func) override;
    bool IsLValue(ASTFunction &func) override;
    llvm::Value *Compile(llvm::IRBuilder<> &builder, ASTFunction &func) override;
    std::string ToString(const std::string &prefix) override;
};