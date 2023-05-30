#include <vector>
#include <iostream>
#include <stack>
using namespace std;

std::vector<std::string> convertToInfixArray(std::string str) {
    std::vector<std::string> res;
    std::string tmp;
    
    for (size_t i = 0; i < str.size(); ) {
        tmp = "";
        
        if (isdigit(str[i])) {
            while(isdigit(str[i])) {
                tmp.push_back(str[i++]);
            }
            res.push_back(tmp);
        }
        
        else if (str[i] == '-') {
            tmp.push_back(str[i++]);
            
            if (i == 1 || (str[i-2] != ')' && !isdigit(str[i-2]))) {
                while(isdigit(str[i])) {
                    tmp.push_back(str[i++]);
                }
            }
            
            res.push_back(tmp);
        }

        
        else if (str[i] == ' ') ++i;
        
        else {
            tmp = str[i++];
            res.push_back(tmp);
        }
        
    }
    
    return res;
} 

bool isOperator(std::string op) {
    if (op == "+" || op == "-" || op == "*" || op == "/") return true;
    return false;
}

int getPrecedence(std::string op) {
    if (op == "*" || op == "/") return 2;
    else if (op == "+" || op == "-") return 1;
    return 0;
}



std::vector<std::string> convertToPostfix(std::vector<std::string> Q) {
    std::stack<string> S;
    std::vector<string> P;
    
    for (size_t i = 0; i < Q.size(); ++i) {
        if (isdigit(Q[i][0]) || Q[i][0] == '-') {
            P.push_back(Q[i]);
        }
        
        if (Q[i] == "(") {
            S.push(Q[i]);
        }
        
        if (Q[i] == ")") {
            while(!S.empty() && S.top() != "(") {
              P.push_back(S.top());
              S.pop();
            }
            S.pop();
        }
        
        if (isOperator(Q[i])) {
            if (S.empty() || S.top() == "(") {
            	S.push(Q[i]);
            }
            
            else {
            	while(!S.empty() && S.top() != "(" && getPrecedence(Q[i]) <= getPrecedence(S.top())) {
            	    P.push_back(S.top());
            	    S.pop();
            	}
            }
        }
    }
    
    while(!S.empty()) {
        P.push_back(S.top());
        S.pop();
    }
    
    return P;
}

int main()
{
    std::string text = "-5*6 + 2 - 12 / 4";
    std::vector<std::string> infixArray = convertToInfixArray(text);
    // std::vector<std::string> infixArray = {"5", "*", "(", "6", "-", "2", ")", "-", "12", "/", "-4"};
    std::vector<std::string> postfixArray = convertToPostfix(infixArray);

    // Print the postfix array
    for (const auto& token : postfixArray) {
        std::cout << token << std::endl;
    }
}
