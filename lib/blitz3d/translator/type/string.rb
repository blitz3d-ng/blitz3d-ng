module Blitz3D
  module AST
    class StringType < Type
      def initialize(json)
      end

      def to_c
        'BBStr*'
      end

      def ptr
        '&_bbStrType'
      end

      def default_value
        0
      end

      def kind
        'BBTYPE_STR'
      end
    end
  end
end
