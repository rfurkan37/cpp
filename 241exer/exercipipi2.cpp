#include <iostream>
#include <cctype>
#include <cstdlib>
using std::istream;
using std::ostream;
using std::cout;
using std::cin;

 

class A{
    public:
        A():c('n') { cout << c << "no param const\n";        }
        A(const A & b): c('c') { cout << c << "copy const\n";        }
        ~A(){ cout << c << "dest\n";         }
        A operator=(const A & a) {cout << c << " assgn\n";        }
                
        char c;

 

};

 

A f(A  a){ A b; return b;}

 

A g; 

 

int main(){
    cout << "start\n";
    {
        g.c = 'g';

 

        A a, b;
        a.c = 'a';
        b.c = 'b';

 

        a = b;
        
        a = f(b);
        
        A c = a;
        c.c = 'c';
    
        
        A * ap = & a;
    }
    cout << "end\n";
}