// object inside object - tree like structure (employee hierarchy, calculator, movies list)

#include <bits/stdc++.h>
using namespace std;

// Abstract Component
class Expression {
public:
    virtual double evaluate() const = 0;
    virtual void add(shared_ptr<Expression> expr) {
        throw runtime_error("Cannot add to a leaf.");
    }
    virtual ~Expression() {}
};

// Leaf for Values
class Value : public Expression {
private:
    double value;
public:
    Value(double v) : value(v) {}
    double evaluate() const override {
        return value;
    }
};

// Composite for Binary Operations
class Operation : public Expression {
private:
    vector<shared_ptr<Expression>> children;
    string op;
public:
    Operation(const string& operation) : op(operation) {}

    void add(shared_ptr<Expression> expr) override {
        children.push_back(expr);
    }

    double evaluate() const override {
        if (children.size() != 2) {
            throw runtime_error("Operation must have exactly two operands.");
        }
        double left = children[0]->evaluate();
        double right = children[1]->evaluate();

        if (op == "+") return left + right;
        if (op == "-") return left - right;
        if (op == "*") return left * right;
        if (op == "/") return left / right;

        throw runtime_error("Unknown operation.");
    }
};

// Client Code
int main() {
    // Create leaf nodes (values)
    shared_ptr<Expression> five = make_shared<Value>(5);
    shared_ptr<Expression> three = make_shared<Value>(3);

    // Create composite nodes (operations)
    shared_ptr<Expression> add = make_shared<Operation>("+");
    add->add(five);
    add->add(three);

    shared_ptr<Expression> seven = make_shared<Value>(7);
    shared_ptr<Expression> multiply = make_shared<Operation>("*");
    multiply->add(add);
    multiply->add(seven);

    // Evaluate the expression: (5 + 3) * 7
    cout << "Result: " << multiply->evaluate() << endl; // Output: 56

    return 0;
}
