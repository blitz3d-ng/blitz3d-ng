
#ifndef STMTNODE_H
#define STMTNODE_H

#include "node.h"

struct StmtNode : public Node{
	int pos;	//offset in source stream
	StmtNode():pos(-1){}
	void debug( int pos,Codegen *g );

	virtual void semant( Environ *e ){}
	virtual void translate( Codegen *g ){}
};

struct StmtSeqNode : public Node{
	string file;
	vector<StmtNode*> stmts;
	StmtSeqNode( const string &f ):file(f){}
	~StmtSeqNode(){ for( ;stmts.size();stmts.pop_back() ) delete stmts.back(); }
	void semant( Environ *e );
	void translate( Codegen *g );
	void push_back( StmtNode *s ){ stmts.push_back( s ); }
	int  size(){ return stmts.size(); }

	static void reset( const string &file,const string &lab );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="StmtSeqNode";
		tree["file"]=file;
		tree["stmts"]=json::array();
		for( int k=0;k<stmts.size();++k ){
			tree["stmts"].push_back( stmts[k]->toJSON( e ) );
		}
		return tree;
	}
};

#include "exprnode.h"
#include "declnode.h"

struct IncludeNode : public StmtNode{
	string file,label;
	StmtSeqNode *stmts;
	IncludeNode( const string &t,StmtSeqNode *ss ):file(t),stmts(ss){}
	~IncludeNode(){ delete stmts; }

	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="IncludeNode";
		tree["pos"]=pos;
		tree["file"]=file;
		tree["label"]=label;
		tree["stmts"]=stmts->toJSON( e );
		return tree;
	}
};

struct DeclStmtNode : public StmtNode{
	DeclNode *decl;
	DeclStmtNode( DeclNode *d ):decl(d){ pos=d->pos; }
	~DeclStmtNode(){ delete decl; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="DeclStmtNode";
		tree["pos"]=pos;
		tree["decl"]=decl->toJSON( e );
		return tree;
	}
};

struct DimNode : public StmtNode{
	string ident,tag;
	ExprSeqNode *exprs;
	ArrayType *sem_type;
	Decl *sem_decl;
	DimNode( const string &i,const string &t,ExprSeqNode *e ):ident(i),tag(t),exprs(e){}
	~DimNode(){ delete exprs; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="DimNode";
		tree["pos"]=pos;
		tree["ident"]=ident;
		tree["tag"]=tag;
		tree["exprs"]=exprs->toJSON( e );
		tree["sem_type"]=sem_type->toJSON();
		tree["sem_decl"]=sem_decl->toJSON();
		return tree;
	}
};

struct AssNode : public StmtNode{
	VarNode *var;
	ExprNode *expr;
	AssNode( VarNode *var,ExprNode *expr ):var(var),expr(expr){}
	~AssNode(){ delete var;delete expr; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="AssNode";
		tree["pos"]=pos;
		tree["var"]=var->toJSON( e );
		tree["expr"]=expr->toJSON( e );
		return tree;
	}
};

struct ExprStmtNode : public StmtNode{
	ExprNode *expr;
	ExprStmtNode( ExprNode *e ):expr(e){}
	~ExprStmtNode(){ delete expr; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ExprStmtNode";
		tree["pos"]=pos;
		tree["expr"]=expr->toJSON( e );
		return tree;
	}
};

struct LabelNode : public StmtNode{
	string ident;
	int data_sz;
	LabelNode( const string &s,int sz ):ident(s),data_sz(sz){}
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="LabelNode";
		tree["pos"]=pos;
		tree["ident"]=ident;
		tree["data_sz"]=data_sz;
		return tree;
	}
};

struct GotoNode : public StmtNode{
	string ident;
	GotoNode( const string &s ):ident(s){}
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="GotoNode";
		tree["pos"]=pos;
		tree["ident"]=ident;
		return tree;
	}
};

struct GosubNode : public StmtNode{
	string ident;
	GosubNode( const string &s ):ident(s){}
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="GosubNode";
		tree["pos"]=pos;
		tree["ident"]=ident;
		return tree;
	}
};

struct IfNode : public StmtNode{
	ExprNode *expr;
	StmtSeqNode *stmts,*elseOpt;
	IfNode( ExprNode *e,StmtSeqNode *s,StmtSeqNode *o ):expr(e),stmts(s),elseOpt(o){}
	~IfNode(){ delete expr;delete stmts;delete elseOpt; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="IfNode";
		tree["pos"]=pos;
		tree["expr"]=expr->toJSON( e );
		tree["stmts"]=stmts->toJSON( e );
		if( elseOpt ) tree["elseOpt"]=elseOpt->toJSON( e );
		return tree;
	}
};

struct ExitNode : public StmtNode{
	string sem_brk;
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ExitNode";
		tree["pos"]=pos;
		tree["sem_brk"]=sem_brk;
		return tree;
	}
};

struct WhileNode : public StmtNode{
	int wendPos;
	ExprNode *expr;
	StmtSeqNode *stmts;
	string sem_brk;
	WhileNode( ExprNode *e,StmtSeqNode *s,int wp ):expr(e),stmts(s),wendPos(wp){}
	~WhileNode(){ delete expr;delete stmts; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="WhileNode";
		tree["pos"]=pos;
		tree["wendPos"]=wendPos;
		tree["expr"]=expr->toJSON( e );
		tree["stmts"]=stmts->toJSON( e );
		tree["sem_brk"]=sem_brk;
		return tree;
	}
};

struct ForNode : public StmtNode{
	int nextPos;
	VarNode *var;
	ExprNode *fromExpr,*toExpr,*stepExpr;
	StmtSeqNode *stmts;
	string sem_brk;
	ForNode( VarNode *v,ExprNode *f,ExprNode *t,ExprNode *s,StmtSeqNode *ss,int np );
	~ForNode();
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ForNode";
		tree["pos"]=pos;
		tree["nextPos"]=nextPos;
		tree["var"]=var->toJSON( e );
		tree["fromExpr"]=fromExpr->toJSON( e );
		tree["toExpr"]=toExpr->toJSON( e );
		tree["stepExpr"]=stepExpr->toJSON( e );
		tree["stmts"]=stmts->toJSON( e );
		tree["sem_brk"]=sem_brk;
		return tree;
	}
};

struct ForEachNode : public StmtNode{
	int nextPos;
	VarNode *var;
	string typeIdent;
	StmtSeqNode *stmts;
	string sem_brk;
	ForEachNode( VarNode *v,const string &t,StmtSeqNode *s,int np):var(v),typeIdent(t),stmts(s),nextPos(np){}
	~ForEachNode(){ delete var;delete stmts; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ForEachNode";
		tree["pos"]=pos;
		tree["nextPos"]=nextPos;
		tree["var"]=var->toJSON( e );
		tree["typeIdent"]=typeIdent;
		tree["stmts"]=stmts->toJSON( e );
		tree["sem_brk"]=sem_brk;
		return tree;
	}
};

struct ReturnNode : public StmtNode{
	ExprNode *expr;
	string returnLabel;
	ReturnNode( ExprNode *e ):expr( e ){}
	~ReturnNode(){ delete expr; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ReturnNode";
		tree["pos"]=pos;
		if( expr ) tree["expr"]=expr->toJSON( e );
		tree["returnLabel"]=returnLabel;
		return tree;
	}
};

struct DeleteNode : public StmtNode{
	ExprNode *expr;
	DeleteNode( ExprNode *e ):expr(e){}
	~DeleteNode(){ delete expr; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="DeleteNode";
		tree["pos"]=pos;
		tree["expr"]=expr->toJSON( e );
		return tree;
	}
};

struct DeleteEachNode : public StmtNode{
	string typeIdent;
	DeleteEachNode( const string &t ):typeIdent(t){}
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="DeleteEachNode";
		tree["pos"]=pos;
		tree["typeIdent"]=typeIdent;
		return tree;
	}
};

struct InsertNode : public StmtNode{
	ExprNode *expr1,*expr2;
	bool before;
	InsertNode( ExprNode *e1,ExprNode *e2,bool b ):expr1(e1),expr2(e2),before(b){}
	~InsertNode(){ delete expr1;delete expr2; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="InsertNode";
		tree["pos"]=pos;
		tree["expr1"]=expr1->toJSON( e );
		tree["expr2"]=expr2->toJSON( e );
		tree["before"]=before;
		return tree;
	}
};

struct CaseNode : public Node{
	ExprSeqNode *exprs;
	StmtSeqNode *stmts;
	CaseNode( ExprSeqNode *e,StmtSeqNode *s ):exprs(e),stmts(s){}
	~CaseNode(){ delete exprs;delete stmts; }

	json toJSON( Environ *e ){
		json tree;tree["@class"]="CaseNode";
		tree["exprs"]=exprs->toJSON( e );
		tree["stmts"]=stmts->toJSON( e );
		return tree;
	}
};

struct SelectNode : public StmtNode{
	ExprNode *expr;
	StmtSeqNode *defStmts;
	vector<CaseNode*> cases;
	VarNode *sem_temp;
	SelectNode( ExprNode *e ):expr(e),defStmts(0),sem_temp(0){}
	~SelectNode(){ delete expr;delete defStmts;delete sem_temp;for( ;cases.size();cases.pop_back() ) delete cases.back(); }
	void push_back( CaseNode *c ){ cases.push_back( c ); }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="SelectNode";
		tree["pos"]=pos;
		tree["expr"]=expr->toJSON( e );
		tree["cases"]=json::array();
		for( int i=0;i<cases.size();i++ ){
			tree["cases"].push_back( cases[i]->toJSON( e ) );
		}
		if( defStmts ) tree["defStmts"]=defStmts->toJSON( e );
		tree["sem_temp"]=sem_temp->toJSON( e );
		return tree;
	}
};

struct RepeatNode : public StmtNode{
	int untilPos;
	StmtSeqNode *stmts;
	ExprNode *expr;
	string sem_brk;
	RepeatNode( StmtSeqNode *s,ExprNode *e,int up ):stmts(s),expr(e),untilPos(up){}
	~RepeatNode(){ delete stmts;delete expr; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="RepeatNode";
		tree["pos"]=pos;
		tree["untilPos"]=untilPos;
		tree["stmts"]=stmts->toJSON( e );
		if( expr ) tree["expr"]=expr->toJSON( e );
		tree["sem_brk"]=sem_brk;
		return tree;
	}
};

struct ReadNode : public StmtNode{
	VarNode *var;
	ReadNode( VarNode *v ):var(v){}
	~ReadNode(){ delete var; }
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ReadNode";
		tree["pos"]=pos;
		tree["var"]=var->toJSON( e );
		return tree;
	}
};

struct RestoreNode : public StmtNode{
	string ident;
	Label *sem_label;
	RestoreNode( const string &i ):ident(i){}
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="RestoreNode";
		tree["pos"]=pos;
		tree["ident"]=ident;
		tree["sem_label"]=sem_label->toJSON();
		return tree;
	}
};

#endif
