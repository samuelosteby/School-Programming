# Module logic
# Contains logic operators and a class for
# logical expressions
# Propositions are declared as: P = Prop('P')
# Predicates are declared as: P = Pred('P')
# Constants as: c = Const('c')
# Variables as: v = Var('v')
# A logical expression is:
#   - a proposition P
#   - a predicate atom P(t1,..,tn) where t1,...,tn are variables or constants
#   - t1 == t2  (equality)
#   - ~E  (not) where E is a logical expression
#   - E1 & E2  (and)
#   - E1 | E2  (or)
#   - E1 > E2  (implies)
#   - E1 <> E2  (equivalence)
#   - forall(v,E)  (universal)
#   - exists(v,E)  (existential)
#
#  An interpretation for predicate logic is created as:
#  Interpretation([P1(a1,..,an),...],[a1,..,an])
#  where the first argument is a list of predicate atoms that are true
#  in the interpretation, and
#  the second argument is a list of elements.
#
#  An interpretation for propositional logic is created as:
#  I = Interpretation([P,Q,...])
#  where P,Q,... are the predicates that are true
#
# You evaluate an expression E in a interpretation I by:
#  E.val(I)
# which returns True or False

class Expr:
    def __init__(self,str):
        self.name = str

    def __and__(self,arg):
        return AndExpr(self,arg)

    def __or__(self,arg):
        return OrExpr(self,arg)

    def __invert__(self):
        return NotExpr(self)

    def __gt__(self,arg):
        return ImpliesExpr(self,arg)

    def __eq__(self,arg):
        return EquivExpr(self,arg)

class AndExpr(Expr):
    def __init__(self,arg1,arg2):
        self.arg1 = arg1
        self.arg2 = arg2
    def val(self, inter, bind={}):
        return self.arg1.val(inter, bind) and self.arg2.val(inter, bind)
        
class OrExpr(Expr):
    def __init__(self,arg1,arg2):
        self.arg1 = arg1
        self.arg2 = arg2
    def val(self, inter, bind={}):
        return self.arg1.val(inter, bind) or self.arg2.val(inter, bind)

class NotExpr(Expr):
    def __init__(self,arg1):
        self.arg1 = arg1
    def val(self, inter, bind={}):
        return not self.arg1.val(inter, bind)

class ImpliesExpr(Expr):
    def __init__(self,arg1,arg2):
        self.arg1 = arg1
        self.arg2 = arg2
    def val(self, inter, bind={}):
        return not self.arg1.val(inter, bind) or self.arg2.val(inter, bind)

class EquivExpr(Expr):
    def __init__(self,arg1,arg2):
        self.arg1 = arg1
        self.arg2 = arg2
    def val(self, inter, bind={}):
        return (self.arg1.val(inter, bind) == self.arg2.val(inter, bind))
        
class Prop(Expr):
    def __init__(self,str):
        self.name = str
    def val(self, inter, bind={}):
        return self.name in inter.props
    
def Pred(symbol):
   return  (lambda *args: PredExpr(symbol,args))

class PredExpr(Expr):
    def __init__(self,symbol,args):
        self.symbol=symbol
        self.args=args
        self.name = "%s%s" % (self.symbol, tuple([a.name for a in self.args]))
    def val(self,inter, bind={}):
        form = "%s%s" % (self.symbol, tuple([a.tval(inter,bind).name for a in self.args]))
        return form in inter.props


class EqualExpr(Expr):
    def __init__(self,arg1,arg2):
        self.arg1 = arg1
        self.arg2 = arg2
    def val(self,inter, bind={}):    
        return (self.arg1.tval(inter, bind) is self.arg2.tval(inter, bind))

class NotEqualExpr(Expr):
    def __init__(self,arg1,arg2):
        self.arg1 = arg1
        self.arg2 = arg2
    def val(self,inter, bind={}):    
        return (self.arg1.tval(inter, bind) is not self.arg2.tval(inter, bind))
    
class forallExpr(Expr):
    def __init__(self,arg1,arg2):
        self.var = arg1
        self.body = arg2
    def val(self,inter, bind={}):
        bind2 = dict(bind)
        for e in inter.domain:
            bind2[self.var.name] = e
            if not self.body.val(inter,bind2):
                return False
        return True

class existsExpr(Expr):
    def __init__(self,arg1,arg2):
        self.var = arg1
        self.body = arg2
    def val(self,inter, bind={}):
        bind2 = dict(bind)
        for e in inter.domain:
            bind2[self.var.name] = e
            if self.body.val(inter,bind2):
                return True
        return False
    
def forall(v,b):
    return forallExpr(v,b)
def exists(v,b):
    return existsExpr(v,b)

class Term:
    def __init__(self,symbol):
        self.name = symbol
    def __eq__(self,arg):
        return EqualExpr(self,arg)
    def __ne__(self,arg):
        return NotEqualExpr(self,arg)

class Const(Term):
    def __init__(self,symbol):
        self.name = symbol
    def tval(self,inter,bind):
        return self

class Var(Term):
    def __init__(self,symbol):
        self.name = symbol
    def tval(self,inter,bind):
        return bind[self.name]

class Interpretation:
    def __init__(self,props,domain=[]):
        self.props = [ p.name for p in props ]
        self.domain = domain

def val(expr,props,domain=[]):
    return expr.val(Interpretation(props,domain))
    
for i in ['john','mary','bob','alice','fido','cleo','omalley','fluffy']:
    exec('%s = Const("%s")' % (i,i))

for i in 'xyzuv':
    exec('%s = Var("%s")' % (i,i))

for i in ['A','B','C','rainy','windy','wet','cold','sunny','snow','summer','winter','spring','autumn']:
    exec('%s = Prop("%s")' % (i,i))
 
for i in ['happy','sad','hungry','loves','hates','knows','human','dog','cat',\
          'owns','male','female','brother','sister','friend']:
    exec('%s = Pred("%s")' % (i,i))
 


