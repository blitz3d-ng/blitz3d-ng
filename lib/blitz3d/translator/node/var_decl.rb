module Blitz3D
  module AST
    class VarDeclNode < DeclNode
      attr_accessor :ident, :tag, :kind, :constant, :expr, :sem_var

      def initialize(json)
        super
        @ident = json['ident']
        @tag = json['tag']
        @kind = json['kind']
        @constant = json['constant']
        @expr = Node.load(json['expr']) if json['expr']
        @sem_var = Node.load(json['sem_var']) if json['sem_var']
      end

      def to_h
        type = sem_var.try(:sem_decl).try(:type) || IntType.new
        "#{type.to_c} _v#{ident}"
      end

      def to_c
        expr = self.expr || IntConstNode.new('value' => 0)
        "_v#{ident}=#{expr.to_c}"
      end
    end
  end
end
