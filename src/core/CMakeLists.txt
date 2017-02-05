project(core)

set(sources
  parser.cpp
  attribute.cpp
  symbol_table.cpp
  element.cpp
  expression.cpp
  entity.cpp
  entity.h
  value.cpp token.cpp word.cpp word.h num.cpp num.h lexer.cpp lexer.h color.cpp color.h type.cpp type.h array.cpp array.h node.cpp node.h expr.cpp expr.h id.cpp id.h temp.cpp temp.h op.cpp op.h arith.cpp arith.h scope.cpp scope.h)

add_library(morphcore STATIC ${sources})
