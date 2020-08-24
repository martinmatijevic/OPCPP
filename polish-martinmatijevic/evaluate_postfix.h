#ifndef EVALUATE_POSTFIX_H
#define EVALUATE_POSTFIX_H
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <stack>
#include <vector>
#include <istream>

/*  Klasa za izračunavanje aritmetičkog izraza danog u inverznoj poljskoj notaciji.
 *  Binarne operacije su +,-,*,/ i ^.
 *  Unarne operacije ~ (negacija). Koristimo ~ umjesto - kako bismo
 *  mogli razlikovati unarnu od binarne operacije prema simbolu.
 */

class IPExpression{
public:
  // tip izraza
  using Value = int;

  enum TokenType {operand, unaryOp, binaryOp};

  // pomoćna klasa koja predstavlja element izraza
  struct Token{
    public:
      TokenType type() const { return mtype; }
      char symbol() const { return msymbol; }
      Value value() const { return mval; }
      Token(std::string str);
    private:
      char msymbol;
      Value mval;
      TokenType mtype;
  };
  // Konstrukcija praznog izraza.
  IPExpression() : mText("") {}
  // Konstrukcija izraza iz stringa.
  // text mora sadržavati aritmetički izraz u poljskoj notaciji
  IPExpression(std::string text) : mText(text) {};
  // Izračunaj vrijednost izraza. Uništava izraz
  Value evaluate();

  std::string getText() {return mText;}

  std::string ParseNext();

  // trim from start
  static inline std::string &ltrim(std::string &s);
  // trim from end
  static inline std::string &rtrim(std::string &s);
  // trim from both ends
  static inline std::string &trim(std::string &s);
private:
  std::string mText;
  // Daje sljedeći token sadržan u izrazu
  Token getToken();
  std::stack<Value> ValueStack;
};

// NAPOMENA: Nije nužno koristiti unutarnju klasu  Expression::Token
//           ukoliko imate bolji način, no unutarnje klase su ovdje vrlo
//           prirodne.

#endif // EVALUATE_POSTFIX_H
