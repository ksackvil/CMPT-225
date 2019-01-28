
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>
using namespace std;

Token calc(Token x, Token y, Token op);

int main () 
{
    Scanner S(cin);
    Token t, result;
    bool calculate = false;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    
    t = S.getnext();
    while (t.tt != eof || !opstack.isEmpty()) 
    {
        // reset calc flag
        calculate = false; 
        cout << t.tt << endl;

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
            // operator stack is not empty, top is 1
            if(!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                calculate = true;   
            }
            else
            {
                // push t to the operator stack
                opstack.push(t);
                // cout << "pushed to operator stack\n";
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
                // cout << "pushed to operator stack\n";
            }
        }
        else 
        {
            calculate = true;
        }

        // ----- CALCULATE OR GET NEXT CHAR ---- //

        if(calculate)
        {
            // pop the top two numbers and the top opperator and preform opperation
            result = calc(numstack.pop(), numstack.pop(), opstack.pop());

            // store this result in numstack
            numstack.push(result);   
            cout << result.val;
        }
        else 
        {
            t = S.getnext();
        }
    }

    cout << endl;

    return 0;
}

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

