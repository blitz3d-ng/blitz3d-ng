#ifndef OBJECT_CAST_NODE_H
#define OBJECT_CAST_NODE_H

#include "node.h"

struct ObjectCastNode : public ExprNode{
	ExprNode *expr;
	string type_ident;
	ObjectCastNode( ExprNode *e,const string &t ):expr(e),type_ident(t){}
	~ObjectCastNode(){ delete expr; }
	ExprNode *semant( Environ *e );
	TNode *translate( Codegen *g );

	json toJSON( Environ *e ){
		json tree;tree["@class"]="ObjectCastNode";
		tree["sem_type"]=sem_type->toJSON();
		tree["expr"]=expr->toJSON( e );
		tree["type_ident"]=type_ident;
		return tree;
	}
};

#endif
