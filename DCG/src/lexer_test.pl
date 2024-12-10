:- begin_tests(lexer).
:- use_module(lexer).

test(white_space) :-
	phrase(white_space, [' ']),
	phrase(white_space, ['\t']),
	phrase(white_space, ['\n']),
	\+ phrase(white_space, ['\t', '\t']),
	\+ phrase(white_space, ['a']),
	\+ phrase(white_space, ['@']),
	!.

test(comment) :-
	phrase(comment, ['/', '*', '*', '/']),
	phrase(comment, ['/', '*', ' ', '*', '/']),
	phrase(comment, ['/', '*', ' ', 'a', 'a', 'a', ' ', '*', '/']),
	phrase(comment, ['/', '*', 'a', '*', '/']),
	\+ phrase(comment, ['a', '/', '*', '*', '/']),
	\+ phrase(comment, ['/', '*', '/', '*', '*', '/', '*', '/']),
	\+ phrase(comment, ['/', '*', '*', '/', '/', '*', '*', '/']),
	!.

test(skip) :-
	phrase(skip, [' ', ' ']),
	phrase(skip, [' ', ' ', '/', '*', '*', '/', ' ', '\n', '\t', ' ', '/', '*', 'a', 'a', 'a', '*', '/']),
	\+ phrase(skip, [' ', ' ', '/', '*', '*', '/', ' ', 'a', ' ', '/', '*', '*', '/']),
	\+ phrase(skip, [' ', ' ', '/', '*', '*', '/', ' ', '/', '*', '/', '*', '*', '/', '*', '/']),
	!.

test(in) :-
	phrase(in(in), ['#']),
	\+ phrase(in(_), ['#', ' ']),
	!.

test(out) :-
	phrase(out(out), ['$']),
	\+ phrase(out(_), ['$', ' ']),
	!.

test(operator) :-
	phrase(operator(operator("(")), ['(']),
	phrase(operator(operator(")")), [')']),
	phrase(operator(operator(":-")), [':', '-']),
	phrase(operator(operator("->")), ['-', '>']),
	phrase(operator(operator(",")), [',']),
	phrase(operator(operator(".")), ['.']),
	\+ phrase(operator(_), ['(', ')']),
	\+ phrase(operator(_), ['.', '.', '.']),
	!.

test(number) :-
	phrase(number(number(0)),['0']),
	phrase(number(number(100)),['1', '0', '0']),
	phrase(number(number(0.1)),['0', '.', '1']),
	phrase(number(number(1e10)),['1', 'e', '1', '0']),
	\+ phrase(number(_),['1', 'e']),
	\+ phrase(number(_),['e', '1']),
	\+ phrase(number(_),['1', '+', '2']),
	!.

test(string) :-
	phrase(string(string("")), ['"', '"']),
	phrase(string(string("abc")), ['"', 'a', 'b', 'c', '"']),
	phrase(string(string("abc + 'abc'")), ['"', 'a', 'b', 'c', ' ', '+', ' ', '\'', 'a', 'b', 'c', '\'', '"']),
	\+ phrase(string(_), ['"', '"', '"']),
	\+ phrase(string(_), ['"', '\n', '"']),
	!.

test(function_id) :-
	phrase(function_id(function_id("_")), ['_']),
	phrase(function_id(function_id("_Foo")), ['_', 'F', 'o', 'o']),
	phrase(function_id(function_id("Foo")), ['F', 'o', 'o']),
	phrase(function_id(function_id("Foo_Bar1")), ['F', 'o', 'o', '_', 'B', 'a', 'r', '1']),
	\+ phrase(function_id(_), ['f', 'o', 'o']),
	\+ phrase(function_id(_), ['F', 'o', 'o', ' ', 'B', 'a', 'r']),
	\+ phrase(function_id(_), ['f', '@']),
	!.

test(prolog_id) :-
	phrase(prolog_id(prolog_id("foo")), ['f', 'o', 'o']),
	phrase(prolog_id(prolog_id("foo_Bar1")), ['f', 'o', 'o', '_', 'B', 'a', 'r', '1']),
	\+ phrase(prolog_id(_), ['f', 'o', 'o', ' ', 'b', 'a', 'r']),
	\+ phrase(prolog_id(_), ['F', '@']),
	!.

test(tokenize) :-
	tokenize("/* nothing here */", []),
	tokenize("Foo", [function_id("Foo")]),
	tokenize("Foo bar\n(1", [function_id("Foo"), prolog_id("bar"), operator("("), number(1)]),
	tokenize("f o(o", [prolog_id("f"), prolog_id("o"), operator("("), prolog_id("o")]),
	\+ tokenize("foo", [prolog_id("f"), prolog_id("o"), prolog_id("o")]).

:- end_tests(lexer).
