:- module(lexer, [
	white_space/2,
	comment/2,
	skip/2,
	in/3,
	out/3,
	operator/3,
	number/3,
	string/3,
	function_id/3,
	prolog_id/3,
	tokenize/2
]).

/*************
 * Utilities *
 *************/

sequence([]) --> [].
sequence([E | Es]) --> [E], sequence(Es).

starts_with([], _).
starts_with([Sub_First | Sub_Rest], [Sub_First | String_Rest]) :-
	starts_with(Sub_Rest, String_Rest), !.
starts_with(Sub, [_ | String_Rest]) :- starts_with(Sub, String_Rest), !.

substring(Sub, Str) :- starts_with(Sub, Str), !.
substring(Sub, [_, Str]) :- substring(Sub, Str), !.

str_type([], _).
str_type([First | Rest], Type) :-
	char_type(First, Type),
	str_type(Rest, Type).

/*********
 * Skips *
 *********/
 
white_space --> ([' '] | ['\t'] | ['\n']).

comment --> ['/', '*'], sequence(Comment_Content), ['*', '/'],
	{
		str_type(Comment_Content, ascii),
		\+ substring(['*', '/'], Comment_Content)
	}.

skip --> [].
skip --> (white_space | comment), skip.
skip_non_empty --> (white_space | comment), skip.

/**********
 * In/Out *
 **********/
 
in(in) --> ['#'].

out(out) --> ['$'].

/*************
 * Operators *
 *************/
 
operator(operator("(")) --> ['('].
operator(operator(")")) --> [')'].
operator(operator("->")) --> ['-'], ['>'].
operator(operator(":-")) --> [':'], ['-'].
operator(operator(".")) --> ['.'].
operator(operator(",")) --> [','].
operator(operator("=")) --> ['='].

/************
 * Literals *
 ************/
 
number(number(Number)) --> sequence(Chars),
	{
		string_chars(String, Chars),
		number_string(Number, String)
	}.

string(string(String)) --> ['"'], sequence(Chars), ['"'],
	{
		str_type(Chars, ascii),
		\+ substring(['"'], Chars),
		\+ substring(['\n'], Chars),
		string_chars(String, Chars)
	}.

/***************
 * Identifiers *
 ***************/
 
function_id(function_id(Identifier)) --> sequence(Chars),
	{
		Chars = [First | Rest],
		char_type(First, prolog_var_start),
		str_type(Rest, prolog_identifier_continue),
		string_chars(Identifier, Chars)
	}.

prolog_id(prolog_id(Identifier)) --> sequence(Chars),
	{
		Chars = [First | Rest],
		char_type(First, prolog_atom_start),
		str_type(Rest, prolog_identifier_continue),
		string_chars(Identifier, Chars)
	}.

/**********
 * Tokens *
 **********/
 
token_no_operator(Token) -->
	  in(Token)
	| out(Token)
	| number(Token)
	| string(Token)
	| function_id(Token)
	| prolog_id(Token).

tokens([]) --> skip.
tokens([Token | Tokens]) --> skip, operator(Token), tokens(Tokens).
tokens([Token]) --> skip, token_no_operator(Token).
tokens([Token | Tokens]) -->
	skip, token_no_operator(Token), skip_non_empty, tokens(Tokens).
tokens([Token1, Token2 | Tokens]) -->
	skip, token_no_operator(Token1), operator(Token2), tokens(Tokens).

tokenize(W, Tokens) :-
	string_chars(W, Chars),
	phrase(tokens(Tokens), Chars), !.
