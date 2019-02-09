/* 
 * eval.cpp
 *
 * Description: 
 *      This utility will calculate the inputted infix expression and output
 *      the value. It is assumed that input is well formatted. Enter expression
 *      below on one line and hit enter to calculate (note that you may need to
 *      press enter more than once). Bracket expression in parentheses
 *      for best result.
 *
 * Author: Kai Sackville-Hii
 * Date: Feb 6, 2019
 */

#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>
#include <string>
using namespace std;

// Helper Function to do the opperations.
// Pre: given two token numbers (x,y) and an opperation to do on them (op)
// Post: Token with result will be returned.
Token calc(Token x, Token y, Token op);

int main () 
{
    Scanner S(cin);
    Token t, result;
    bool calculate = false; // do opperation if true
    bool end = false;       // end program if true

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token

    // User Output Message 
    cout << "CMPT-225 Assignment 2 - Q3 (Feb 6, 2019)" << endl
        << "(c) Infix Expression Calculator, Developed by Kai Sackville-Hii." << endl
        << endl
        << "This utility will calculate the inputted infix expression and output" << endl
        << "the value. It is assumed that input is well formatted. Enter expression" << endl
        << "below on one line and hit enter to calculate (note that you may need to" << endl
        << "press enter more than once). Bracket expression in parentheses" << endl
        << "for best result." << endl
        << endl;

    // get initial token
    t = S.getnext();

    // ----- MAIN LOOP ----- //
    while (t.tt != eof  || !opstack.isEmpty())
    {
        // reset calc flag
        calculate = false;

        // ----- PARSE INPUT ----- //

        if(t.tt == integer)
        {
            // push T to the number stack
            numstack.push(t);
        }
        else if(t.tt == lptok)
        {   
            opstack.push(t);
        }
        else if(t.tt == rptok)
        {
            // Top of opperator stack is left parenthesis
            if(opstack.peek().tt == lptok)
            {
                opstack.pop();
            }
            else
            {
                calculate = true;
            }
        }
        else if(t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            // operator stack is not empty, top is 1 of the tokens
            if(!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                calculate = true;   
            }
            else
            {
                // push t to the operator stack
                opstack.push(t);
            }
        }
        else if(t.tt == asttok || t.tt == slashtok)
        {
            if(!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                calculate = true;
            }   
            else
            {
                // push t to the operator stack
                opstack.push(t);
            }
        }

        // ----- CALCULATE OR GET NEXT CHAR ---- //

        // error case: if we have reached the end without t.tt = eof,
        // Do final calculation and return it.
        if(cin.peek() == '\n')
        {
            calculate = true;
            end = true;
        }

        if(calculate)
        {
            Token y = numstack.pop();
            Token x = numstack.pop();
            Token op = opstack.pop();

            // pop the top two numbers and the top opperator and preform opperation
            result = calc(x, y, op);

            // Final calculation print result 
            if (end)
            {
                cout << endl << "ans = " << result.val << endl;    
                cout << endl;
                break;
            }
            
            // store this result in numstack
            numstack.push(result);   

        }
        else 
        {
            // get next token
            t = S.getnext();
        }
    }   



    return 0;
}

// Helper Function to do the opperations.
// Pre: given two token numbers (x,y) and an opperation to do on them (op)
// Post: Token with result will be returned.
Token calc(Token x, Token y, Token op)
{
    Token returnTok;

    switch (op.tt)
    {
        case pltok:
            returnTok.val = (x.val + y.val);
            break;

        case mitok:
            returnTok.val = (x.val - y.val);
            break;
        
        case asttok:
            returnTok.val = (x.val * y.val);
            break;

        case slashtok:
            returnTok.val = (x.val / y.val);
            break;

        default:
            break;
    }

    return(returnTok);
}

