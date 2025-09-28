// Write a C++ program that implements the Ackermann function, which is a classic example of
// nested recursion. The function ackermann(int m, int n) is defined as:
// ● If m=0, return n+1.
// ● If m>0 and n=0, return ackermann(m-1, 1).
// ● If m>0 and n>0, return ackermann(m-1, ackermann(m, n-1)).
// This task requires you to trace the execution and understand how one recursive call is a
// parameter to another.

#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    if (m == 0)
        return n + 1; // Rule 1
    else if (m > 0 && n == 0)
        return ackermann(m - 1, 1); // Rule 2
    else
        return ackermann(m - 1, ackermann(m, n - 1)); // Rule 3
}

int main()
{
    int m = 2, n = 1;
    int result = ackermann(m, n);
    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;
}

/*
Example Trace for ackermann(2,1):

ackermann(2,1) m>1 && n>0, so Rule 3 applies:

= ackermann(1, ackermann(2,0))
                   |__________     m>0 && n==0, so Rule 2 applies:
= ackermann(1, ackermann(1,1))
                   |_____________   m>0 && n>0, so Rule 3 applies:
= ackermann(1, ackermann(0, ackermann(1,0)))
                                |_________________________  m>0 && n==0, so Rule 2 applies:

= ackermann(1, ackermann(0, ackermann(0,1)))
                                |_________________________  m==0, so Rule 1 applies: return n+1=2
=                                                                |_________________________ackermann(1, ackermann(0,2))
                                                                                                           |_________________________ m==0, so Rule 1 applies: return n+1=3
= ackermann(1,3)
           |_________________________ m>0 && n>0, so Rule 3 applies:
= ackermann(0, ackermann(1,2))
                   |_________________________ m>0 && n>0, so Rule 3 applies:
= ackermann(0, ackermann(0, ackermann(1,1)))
                                |_________________________ m>0 && n>0, so Rule 3 applies:
= ackermann(0, ackermann(0, ackermann(0, ackermann(1,0))))
                                             |_________________________ m>0 && n==0, so Rule 2 applies:
= ackermann(0, ackermann(0, ackermann(0,2)))
                                 |_________________________ m==0, so Rule 1 applies: return n+1=3
= ackermann(0,3)
           |_________________________ m==0, so Rule 1 applies: return n+1=4

= ackermann(0,4)
           |_________________________ m==0, so Rule 1 applies: return n+1=5

Final Answer: Ackermann(2,1) = 5
*/
