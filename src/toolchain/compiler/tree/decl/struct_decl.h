#ifndef STRUCTDECLNODE_H
#define STRUCTDECLNODE_H

#include "node.h"
#include "decl_seq.h"

struct StructDeclNode : public DeclNode{
	string ident;
	DeclSeqNode *fields;
	StructType *sem_type;
	StructDeclNode( const string &i,DeclSeqNode *f ):ident(i),fields(f){}
	~StructDeclNode(){ delete fields; }
	void proto( DeclSeq *d,Environ *e );
	void semant( Environ *e );
	void translate( Codegen *g );

	json toJSON( Environ *e );
};

#endif
