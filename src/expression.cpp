#include "expression.h"

/**
 * @brief check the validation of input expression
 * 
 * @return validation 
 */
bool Expression::iExpStrValidate(const std::string& midfixExpStr)
{
    std::string str = "";

    // ignore blank
    for (auto s: midfixExpStr)
        if (s!=' ') str.append(1, s);
    
    if(str.empty() || !isdigit(str.at(0)) || !isdigit(str.at(str.length()-1)))
        return false;
    
    int i=0;
    for (; i<str.length(); i++)
    {
        // to the first no digit
        if(i==str.length()-1) return true;
        if(!isdigit(str.at(i))) break;
    }

    while(i < str.length())
    {
        // operant operator operant ... operant
        if(str.at(i)=='+' || str.at(i)=='-' || str.at(i)=='*' || str.at(i)=='/'){
            if(++i<str.length() && isdigit(str.at(i))){
                while(i<str.length() && isdigit(str.at(i)))
                    i++;
                if(i==str.length()) return true;
            }
            else break;
        }
        else break;
    }
    return false;
}

/**
 * @brief transfer a midfix expression to postfix expression by using stack
 * 
 * @param midfixExpStr 
 * @return std::string 
 */
std::string Expression::midfixToPostfix(const std::string& midfixExpStr)
{
    std::string  postfixExpStr;
    //TODO:
    return postfixExpStr;
}

/**
 * @brief caculate the postfix expression by using stack
 * 
 * @param postfixExpStr 
 * @return int 
 */
int Expression::caculatePostfix(const std::string& postfixExpStr)
{
    int caculateResult;
    //TODO:
    return caculateResult;
}