#include "hpp.hpp"
#define YYERR "\n\n"<<yylineno<<":"<<msg<<"["<<yytext<<"]\n\n"
void yyerror(string msg) { cout<<YYERR; cerr<<YYERR; exit(-1); }
int main() { return yyparse(); }

Sym::Sym(string T,string V) { tag=T; val=V; }
Sym::Sym(string V):Sym("sym",V){}

Sym* Sym::push(Sym*o) { nest.push_back(o); return this; }

string pad(int n) { string S="\n"; for (int i=0;i<n;i++) S+='\t'; return S; }
string Sym::head() { ostringstream os;
	os<<"<"<< tag <<":"<< val <<"> # "<<this; return os.str(); }
string Sym::dump(int depth) { string S = pad(depth)+head();
	for (auto j:nest) S += j->dump(depth+1);
	return S; } 

Vector::Vector():Sym("vector","[]"){}
string Vector::head() { return val; }

Op::Op(string V):Sym("op",V){}
