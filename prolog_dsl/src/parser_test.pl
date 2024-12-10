:- begin_tests(parser).
:- use_module(lexer).
:- use_module(parser).

parse_atomic_expression(W, AST) :-
	tokenize(W, Tokens),
	phrase(atomic_expression(AST), Tokens).
test(atomic_expression) :-
	parse_atomic_expression("0", number(0)),
	parse_atomic_expression("0.1", number(0.1)),
	parse_atomic_expression("\"a\"", string("a")),
	parse_atomic_expression("a", prolog_id("a")),
	parse_atomic_expression("A", function_id("A")),
	parse_atomic_expression("_", function_id("_")),
	!.

parse_compound_expression(W, AST) :-
	tokenize(W, Tokens),
	phrase(compound_expression(AST), Tokens).
test(compound_expression) :-
	parse_compound_expression("Foo(bar, 0)",
		invocation(function_id("Foo"), [prolog_id("bar"), number(0)])),
	parse_compound_expression("foo(bar, 0)",
		invocation(prolog_id("foo"), [prolog_id("bar"), number(0)])),
	parse_compound_expression("Foo(bar, 0, Foo(bar, 0))",
		invocation(function_id("Foo"), [prolog_id("bar"), number(0),
			invocation(function_id("Foo"), [prolog_id("bar"), number(0)])])),
	parse_compound_expression("(bar, 0)",
		tuple([prolog_id("bar"), number(0)])),
	parse_compound_expression("(((bar, 0)))",
		tuple([prolog_id("bar"), number(0)])),
	\+ parse_compound_expression("Foo", _),
	\+ parse_compound_expression("Foo()", _),
	\+ parse_compound_expression("()", _),
	\+ parse_compound_expression("(X = Y)", _),
	!.

parse_statement(W, AST) :-
	tokenize(W, Tokens),
	phrase(statement(AST), Tokens).
test(statement) :-
	parse_statement("X = Y", assignment([function_id("X")], function_id("Y"))),
	parse_statement("(X) = Y", assignment([function_id("X")], function_id("Y"))),
	parse_statement("(X1, X2, X3) = Y", assignment([function_id("X1"), function_id("X2"), function_id("X3")], function_id("Y"))),
	!.

parse_definition(W, AST) :-
	tokenize(W, Tokens),
	phrase(definition(AST), Tokens).
test(definition) :-
	parse_definition("Bar :- baz(#, $).",
		definition(function_id("Bar"), [invocation(prolog_id("baz"), [in, out])])),
	parse_definition("Foo X1 -> X2 :-\n\tZ = Bar(Baz(X1), 13),\n\tfaz(X2, Z).",
		definition(function_id("Foo"), [function_id("X1")], [function_id("X2")],
			[assignment([function_id("Z")], _), invocation(prolog_id("faz"), _)])),
	parse_definition("Id :- $ = #.",
		definition(function_id("Id"), [assignment([out], in)])),
	parse_definition("Plus N1, N2 -> N3 :- N1 = s(N), N3 = Plus(N, N2).",
		definition(function_id("Plus"), [function_id("N1"), function_id("N2")], [function_id("N3")],
			[assignment(_, _), assignment(_, _)]
		)),
	!.

test(program) :-
	parse("Id :- $ = #. Id :- $ = #.", program([definition(_, _), definition(_, _)])),
	!.

:- end_tests(parser).
