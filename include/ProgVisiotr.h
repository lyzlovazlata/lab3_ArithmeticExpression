#pragma once
#include"PascalBaseVisitor.h"
#include "IMap.h"
#include <any>
#include<string>


class ProgVisitor : public PascalBaseVisitor {
    IMap<std::string, double>* memory;

public:
    ProgVisitor(IMap<std::string, double>* mem) : memory(mem) {}


	std::any visitExpression(PascalParser::ExpressionContext* ctx) override {
		double result = std::any_cast<double>(visit(ctx->term(0)));
	
		for (size_t i = 1; i < ctx->term().size(); ++i) {
			double rhs = std::any_cast<double>(visit(ctx->term(i)));
	
			if (ctx->PLUS(i - 1))
				result += rhs;
			else
				result -= rhs;
		}
	
		return result;
	}
	
	std::any visitTerm(PascalParser::TermContext* ctx) override {
		double result = std::any_cast<double>(visit(ctx->factor(0)));
	
		for (size_t i = 1; i < ctx->factor().size(); ++i) {
			double rhs = std::any_cast<double>(visit(ctx->factor(i)));
	
			if (ctx->MULTIPLY(i - 1))
				result *= rhs;
			else
				result /= rhs;
		}
	
		return result;
	}
	
	std::any visitFactor(PascalParser::FactorContext* ctx) override {
		if (ctx->INTEGER())
			return std::stod(ctx->INTEGER()->getText());
	
		if (ctx->DOUBLE())
			return std::stod(ctx->DOUBLE()->getText());
	
		if (ctx->VARIABLE()) {
			std::string name = ctx->VARIABLE()->getText();
	
			if (!memory->contains(name))
				throw std::runtime_error("Undefined variable: " + name);
	
			return (*memory)[name];
		}
	
		return visit(ctx->expression());
	}
	
	std::any visitAssignment(PascalParser::AssignmentContext* ctx) override {
		std::string name = ctx->VARIABLE()->getText();
		double value = std::any_cast<double>(visit(ctx->expression()));
	
		memory->insert(name, value);
	
		return value;
	
	}
	
	std::any visitWhileLoop(PascalParser::WhileLoopContext* ctx) override {
		while (std::any_cast<bool>(visit(ctx->condition()))) {
			for (auto stmt : ctx->statement()) {
				visit(stmt);
			}
		}
	}
	
	std::any visitCondition(PascalParser::ConditionContext* ctx) override {
		double left = std::any_cast<double>(visit(ctx->expression(0)));
	
		if (ctx->expression().size() == 1)
			return left != 0;
	
		double right = std::any_cast<double>(visit(ctx->expression(1)));
	
		if (ctx->LESS()) return left < right;
		if (ctx->GREATER()) return left > right;
		if (ctx->EQUALS()) return left == right;
		if (ctx->LESS_EQ()) return left <= right;
		if (ctx->GREATER_EQ()) return left >= right;
		if (ctx->NOT_EQ()) return left != right;
	
		return false;
	}
	
	std::any visitStatement(PascalParser::StatementContext* ctx) override {
		if (ctx->assignment()) return visit(ctx->assignment());
		if (ctx->whileLoop()) return visit(ctx->whileLoop());
		if (ctx->expression()) return visit(ctx->expression());

	}
	
	std::any visitProgram(PascalParser::ProgramContext* ctx) override {
		for (auto stmt : ctx->statement()) {
			visit(stmt);
		}
	}
};