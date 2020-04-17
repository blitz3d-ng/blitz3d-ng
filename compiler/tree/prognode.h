
#ifndef PROGNODE_H
#define PROGNODE_H

#include "node.h"
#include "../codegen.h"

extern vector<string> modules;

struct UserFunc{
	string ident,proc,lib;
	UserFunc( const UserFunc &t ):ident(t.ident),proc(t.proc),lib(t.lib){}
	UserFunc( const string &id,const string &pr,const string &lb ):ident(id),proc(pr),lib(lb){}
};

struct ProgNode : public Node{

	DeclSeqNode *consts;
	DeclSeqNode *structs;
	DeclSeqNode *funcs;
	DeclSeqNode *datas;
	StmtSeqNode *stmts;

	Environ *sem_env;

	bool debug;

	string file_lab;

	ProgNode( DeclSeqNode *c,DeclSeqNode *s,DeclSeqNode *f,DeclSeqNode *d,StmtSeqNode *ss ):consts(c),structs(s),funcs(f),datas(d),stmts(ss),debug(false){}
	~ProgNode(){
		delete consts;
		delete structs;
		delete funcs;
		delete datas;
		delete stmts;
	}

	Environ *semant( Environ *e );
	void translate( Codegen *g,const vector<UserFunc> &userfuncs );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ProgNode";
		tree["debug"]=debug;
		tree["modules"]=modules;
		tree["funcs"]=funcs->toJSON( e );
		tree["structs"]=structs->toJSON( e );

		tree["types"]=json::array();
		for( int k=0;k<e->types.size();++k ){
			tree["types"].push_back( e->types[k]->toFullJSON() );
		}

		tree["arrays"]=json::array();
		tree["globals"]=json::array();
		tree["locals"]=json::array();
		for( int k=0;k<e->decls->size();++k ){
			Decl *d=e->decls->decls[k];
			switch( d->kind ){
			case DECL_LOCAL:
				tree["locals"].push_back( d->toJSON() );
				break;
			case DECL_GLOBAL:
				tree["globals"].push_back( d->toJSON() );
				break;
			case DECL_ARRAY:
				tree["arrays"].push_back( d->toJSON() );
				break;
			}
		}

		tree["data"]=datas->toJSON( e );

		tree["stmts"]=stmts->toJSON( e );
		return tree;
	}

	json toJSON( bool dbg ){
		debug = dbg;
		return toJSON( sem_env );
	}
};

#endif
