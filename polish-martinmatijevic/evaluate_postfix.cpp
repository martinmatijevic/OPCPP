// Ovdje dolazi vaš kod za IPExpression klasu dolazi ovdje.
#include "evaluate_postfix.h"
#include <sstream>
#include <iterator>
#include <iostream>
#include <string>
#include <math.h>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

using namespace std;

string IPExpression::ParseNext(){
  ltrim(mText);
  string c;
  if(mText.empty()) c = "";
  if(!isdigit(mText[0])){
    c = mText.substr(0, 1);
    mText=mText.substr(1, mText.size());
  }
  else if(isdigit(mText[0])){
    int i = 0;
    while(i<=mText.size() && isdigit(mText[i])) ++i;
    c = mText.substr(0, i);
    if(i==mText.size()) mText="";
    else mText=mText.substr(i, mText.size());
  }
  return c;
}

IPExpression::Token::Token(std::string str) {
  if(str.compare("+") == 0 || str.compare("-") == 0 || str.compare("*") == 0 || str.compare("/") == 0 || str.compare("^") == 0) {
    mtype = binaryOp;
    msymbol = str[0];
  }
  else if (str.compare("~") == 0) {
    mtype = unaryOp;
    msymbol = str[0];
  }
  else {
    istringstream convert(str);
    if (!(convert >> mval)) mval = 0;
    mtype = operand;
  }
}

IPExpression::Token IPExpression::getToken() {
  rtrim(mText);
  return Token(ParseNext());
}

IPExpression::Value IPExpression::evaluate(){
  try {
  if(mText.empty()) {
    throw invalid_argument("Wrong input!");
  }
  while(!mText.empty()){
    IPExpression::Token t = getToken();
    switch(t.type()){
      case operand:
        ValueStack.push(t.value());
        break;
      case unaryOp:{
        int op1 = ValueStack.top();
        ValueStack.pop();
        ValueStack.push(-op1);
        break;
      }
      case binaryOp:{
        int op1 = ValueStack.top();
        ValueStack.pop();
        int op2 = ValueStack.top();
        ValueStack.pop();
        switch(t.symbol()){
          case '+':
            ValueStack.push(op1+op2);
            break;
          case '-':
            ValueStack.push(op2-op1);
            break;
          case '*':
            ValueStack.push(op1*op2);
            break;
          case '/':
            ValueStack.push(op2/op1);
            break;
          default:
            ValueStack.push(pow(op2, op1));
            break;
        }
      }
    }
  }
  if(ValueStack.size()!=1){
    throw std::runtime_error("Final stack size does not equal 1");
  }
  else return ValueStack.top();
  }
  catch (...) {
    throw std::invalid_argument("Bad expression!");
  }
}

// trim from start
std::string & IPExpression::ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

// trim from end
std::string &IPExpression::rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

// trim from both ends
std::string &IPExpression::trim(std::string &s) {
  return ltrim(rtrim(s));
}
