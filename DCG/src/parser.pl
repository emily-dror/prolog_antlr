:- module(term, [
	atomic_expression/3,
	compound_expression/3,
	expression/3,
	statement/3,
	definition/3,
	program/3,
	parse/2
]).
:- use_module(lexer).

/*********************
 * Atomic Expressions *
 *********************/

literal(number(N)) --> [number(N)].
literal(string(N)) --> [string(N)].
literal(prolog_id(I)) --> [prolog_id(I)].

variable(in) --> [in].
variable(out) --> [out].
variable(function_id(I)) --> [function_id(I)].

atomic_expression(X) --> literal(X).
atomic_expression(X) --> variable(X).

/************************
 * Compound Expressions *
 ************************/

invocation(invocation(prolog_id(I), Xs)) -->
	[prolog_id(I)],
	[operator("(")],
	expressions(Xs),
	[operator(")")].
invocation(invocation(V, Xs)) -->
	variable(V),
	[operator("(")],
	expressions(Xs),
	[operator(")")].

parenthesized(X) -->
	[operator("(")],
	expression(X),
	[operator(")")].

tuple(tuple([X | Xs])) -->
	[operator("(")],
	expression(X),
	[operator(",")],
	expressions(Xs),
	[operator(")")].

variables([V]) --> variable(V).
variables([V | Vs]) -->
	variable(V),
	[operator(",")],
	variables(Vs).

compound_expression(X) --> invocation(X).
compound_expression(X) --> parenthesized(X).
compound_expression(X) --> tuple(X).

/***************
 * Expressions *
 ***************/

expression(X) --> atomic_expression(X).
expression(X) --> compound_expression(X).

expressions([X]) --> expression(X).
expressions([X | Xs]) -->
	expression(X),
	[operator(",")],
	expressions(Xs).

/***************
 * Definitions *
 ***************/

assignment(assignment([V], X)) -->
	variable(V),
	[operator("=")],
	expression(X).
assignment(assignment(Vs, X)) -->
	[operator("(")],
	variables(Vs),
	[operator(")")],
	[operator("=")],
	expression(X).

statement(prolog_id(I)) --> [prolog_id(I)].
statement(I) --> invocation(I).
statement(A) --> assignment(A).

statements([S]) --> statement(S).
statements([S | Ss]) -->
	statement(S),
	[operator(",")],
	statements(Ss).

implicit_definition(definition(Name, Body)) -->
	variable(Name),
	[operator(":-")],
	statements(Body),
	[operator(".")].

explicit_definition(definition(Name, Inputs, Outputs, Body)) -->
	variable(Name),
	variables(Inputs),
	[operator("->")],
	variables(Outputs),
	[operator(":-")],
	statements(Body),
	[operator(".")].

definition(D) --> implicit_definition(D).
definition(D) --> explicit_definition(D).

/***********
 * Program *
 ***********/

definitions([D]) --> definition(D).
definitions([D | Ds]) -->
	definition(D),
	definitions(Ds).

program(program(Ds)) --> definitions(Ds).

parse(W, AST) :-
	tokenize(W, Tokens),
	phrase(program(AST), Tokens), !.
