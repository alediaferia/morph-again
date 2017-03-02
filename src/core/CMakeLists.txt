project(core)

set(sources
  parser.cpp
element.cpp
token.cpp
word.cpp
num.cpp
lexer.cpp
color.cpp
type.cpp
array.cpp
node.cpp
expr.cpp
id.cpp
op.cpp
arith.cpp
scope.cpp
assign.cpp
constant.cpp
stmt.cpp
strlit.cpp
)

add_library(morphcore STATIC ${sources})
