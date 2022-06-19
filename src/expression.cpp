#include "expression.h"

Expression::Expression(QObject* parent) : QObject(parent) {}


bool Expression::expresionValidation(std::string exp_str)
{
    return generatePaticle(exp_str);
}

/**
 * @brief Expression::caculateExpressionResult
 */
void Expression::caculateExpressionResult()
{
    std::vector<ope_rant_rator> postfix_vec = midfixToPostfix(_exp_paticle);
    std::stack<int> tmp_stack;
    for(const auto &v : postfix_vec){
        if(v.type == OPER_TYPE::TYPE_OPERANT){
            tmp_stack.push(atoi(v.content.c_str()));
        }
        else{
            int n = tmp_stack.top();
            tmp_stack.pop();
            int m = tmp_stack.top();
            tmp_stack.pop();
            switch (v.prior) {
            case PRIORITY_PLUS:
                tmp_stack.push(m+n);
                break;
            case PRIORITY_MINUS:
                tmp_stack.push(m-n);
                break;
            case PRIORITY_MUL:
                tmp_stack.push(m*n);
                break;
            case PRIORITY_DIV:
                tmp_stack.push(m/n);
                break;
            default:
                break;
            }
        }
    }

    _caculate_result = tmp_stack.top();
}

/**
 * @brief transfer from midfix To Postfix
 * @param midfix_vec
 * @return postfix_vec
 */
std::vector<ope_rant_rator> Expression::midfixToPostfix(std::vector<ope_rant_rator> midfix_vec)
{
    std::stack<ope_rant_rator> tmp_stack;
    std::vector<ope_rant_rator> postfix_vec;
    for(const auto &v : midfix_vec){
        if(v.type == OPER_TYPE::TYPE_OPERANT){
            postfix_vec.push_back(v);
        }
        else{
            while(!tmp_stack.empty() && v.prior <= tmp_stack.top().prior){
                postfix_vec.push_back(tmp_stack.top());
                tmp_stack.pop();
            }
            tmp_stack.push(v);
        }
    }
    while(!tmp_stack.empty()){
        postfix_vec.push_back(tmp_stack.top());
        tmp_stack.pop();
    }

    return postfix_vec;
}

int Expression::getExpressionResult()
{
    return _caculate_result;
}

/**
 * @brief generate operators and operants from a expression
 * @param str
 * @return
 */
bool Expression::generatePaticle(std::string exp_str)
{
    std::string tmp="";
    std::vector<std::string> vec;
    std::map<char, std::string> priority_map = {{'+',"+"}, {'-',"-"}, {'*',"*"}, {'/',"/"}};
    // split string by operator:+-*/
    for(auto s: exp_str){
        auto itr = priority_map.find(s);
        if(itr != priority_map.end()){
            if(!tmp.empty()){
                vec.push_back(tmp);
                tmp="";
            }
            vec.push_back(itr->second);
        }
        else{
            tmp.append(1, s);
            continue;
        }
    }
    if(!tmp.empty()) vec.push_back(tmp);

    for(const auto &v: vec){
        // check oparant validation: only INT surported
        if(!(v == "+" || v == "-" || v == "*" || v == "/")){
            for(auto i: v){
                if(!isdigit(i)) return false;
            }
        }
    }

    // right now vec includes only operator and operant
    // transfer into struct type and kept in a tmp vector
    std::vector<ope_rant_rator> exp_paticle;
    ope_rant_rator ope_struct;
    std::map<std::string, OPER_PRIORITY> operator_map = {
                            {"+",PRIORITY_PLUS}, {"-",PRIORITY_MINUS},
                            {"*",PRIORITY_MUL},  {"/",PRIORITY_DIV}};

    for(const auto &s: vec){
        auto itr = operator_map.find(s);
        if(itr != operator_map.end()){
            ope_struct.type = TYPE_OPERATOR;
            ope_struct.prior = itr->second;
        }
        else{
            ope_struct.type = TYPE_OPERANT;
            ope_struct.prior = PRIORITY_NO;
        }
        ope_struct.content = s;
        exp_paticle.push_back(ope_struct);
    }

    // check order validation: operant operator operant ...
    if(exp_paticle.front().type != TYPE_OPERANT ||
       exp_paticle.back().type != TYPE_OPERANT) return false;

    for(auto i = 0; i < exp_paticle.size(); i+=2){
        if(exp_paticle.at(i).type != TYPE_OPERANT) return false;
    }
    for(auto i = 1; i < exp_paticle.size(); i+=2){
        if(exp_paticle.at(i).type != TYPE_OPERATOR) return false;
    }

    // illegal divided by zero
    for(auto i = 0; i < exp_paticle.size()-1; i+=1){
        if(exp_paticle.at(i).content == "/" &&
           exp_paticle.at(i+1).content == "0") return false;
    }

    // save to obj after checking successfully
    _exp_paticle = exp_paticle;

    return true;
}
