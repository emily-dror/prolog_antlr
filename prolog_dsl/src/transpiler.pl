:- module(transpiler, [
	transpile_to_prolog/2
]).
:- use_module(parser).

/*************
 * Utilities *
 *************/

join([], _, "").
join([String], _, String).
join([String | Strings], Delimiter, Out) :-
	string_concat(String, Delimiter, Out1),
	join(Strings, Delimiter, Out2),
	string_concat(Out1, Out2, Out).

function_name(Function_Id, Out) :-
	string_concat("fun_", Function_Id, Out).

temp_name(Temp_Number, Temp_Name) :-
	number_string(Temp_Number, Temp_Number_String),
	string_concat("TEMP", Temp_Number_String, Temp_Name).

/***********
 * Program *
 ***********/

transpile_program(program(Definitions), Out) :-
	transpile_definitions(Definitions, Definitions_Out),
	join(Definitions_Out, "\n", Out).

transpile_to_prolog(W, Out) :-
	parse(W, AST),
	transpile_program(AST, Out),
	!.

/***************
 * Definitions *
 ***************/

transpile_definitions([], []).
transpile_definitions([D | Ds], [Out1 | Out2]) :-
	transpile_definition(D, Out1),
	transpile_definitions(Ds, Out2).

transpile_variable(in, "Var_in") :- !.
transpile_variable(out, "Var_out") :- !.
transpile_variable(function_id(I), I).

transpile_variables([V], Out) :-
	transpile_variable(V, Out).
transpile_variables([V | Vs], Out) :-
	transpile_variable(V, Out1),
	string_concat(Out1, ",", Out2),
	transpile_variables(Vs, Out3),
	string_concat(Out2, Out3, Out).

transpile_definition(definition(function_id(Name), Body), Out) :-
	function_name(Name, Function_Name),
	string_concat(Function_Name, "(Var_in,Var_out):-", Out1),
	transpile_body(Body, Out2),
	string_concat(Out1, Out2, Out).
transpile_definition(definition(function_id(Name), Inputs, Outputs, Body), Out) :-
	function_name(Name, Function_Name),
	string_concat(Function_Name, "(", Out1),
	transpile_variables(Inputs, Out2),
	string_concat(Out1, Out2, Out3),
	string_concat(Out3, ",(", Out4),
	transpile_variables(Outputs, Out5),
	string_concat(Out4, Out5, Out6),
	string_concat(Out6, ")):-", Out7),
	transpile_body(Body, Out8),
	string_concat(Out7, Out8, Out).

transpile_body(Statements, Out) :-
	transpile_statements(Statements, 1, Out1),
	join(Out1, ",", Out2),
	string_concat(Out2, ".", Out).

/**************
 * Statements *
 **************/

transpile_statements([], _, []).
transpile_statements([S | Ss], Temp_Counter, Out) :-
	transpile_statement(S, Temp_Counter, Out1, Temp_Counter1),
	transpile_statements(Ss, Temp_Counter1, Out2),
	append(Out1, Out2, Out).

transpile_statement(prolog_id(I), Temp_Counter, [I], Temp_Counter).
transpile_statement(assignment(Vs, X), Temp_Counter, Out, Temp_Counter_Out) :-
	transpile_variables(Vs, Out1),
	string_concat("(", Out1, Out2),
	string_concat(Out2, ")=", Out3),
	transpile_expression(X, Temp_Counter, Statements_Out, Expression_Out, Temp_Counter_Out),
	string_concat(Out3, Expression_Out, Out4),
	append(Statements_Out, [Out4], Out).
transpile_statement(invocation(prolog_id(I), Arguments), Temp_Counter, Out, Temp_Counter_Out) :-
	string_concat(I, "(", Out1),
	transpile_expressions(Arguments, Temp_Counter, Statements_Out, Arguments_Out, Temp_Counter_Out),
	join(Arguments_Out, ",", Out2),
	string_concat(Out1, Out2, Out3),
	string_concat(Out3, ")", Out4),
	append(Statements_Out, [Out4], Out).
transpile_statement(invocation(function_id(I), Arguments), Temp_Counter, Out, Temp_Counter_Out) :-
	function_name(I, Out1),
	string_concat(Out1, "(", Out2),
	transpile_expressions(Arguments, Temp_Counter, Statements_Out, Arguments_Out1, Temp_Counter_Out),
	string_concat(Arguments_Out1, "_", Arguments_Out),
	join(Arguments_Out, ",", Out3),
	string_concat(Out2, Out3, Out4),
	string_concat(Out4, ")", Out5),
	append(Statements_Out, [Out5], Out).

/***************
 * Expressions *
 ***************/

transpile_expressions([], Temp_Counter, [], [], Temp_Counter).
transpile_expressions([X | Xs], Temp_Counter, Statements_Out, [X_Out | Xs_Out], Temp_Counter_Out) :-
	transpile_expression(X, Temp_Counter, Statements_Out1, X_Out, Temp_Counter1),
	transpile_expressions(Xs, Temp_Counter1, Statements_Out2, Xs_Out, Temp_Counter_Out),
	append(Statements_Out1, Statements_Out2, Statements_Out).

/**********************
 * Atomic Expressions *
 **********************/

transpile_expression(number(N), Temp_Counter, [], N_String, Temp_Counter) :-
	number_string(N, N_String).
transpile_expression(string(S), Temp_Counter, [], Out, Temp_Counter) :-
	string_concat("\"", S, Out1),
	string_concat(Out1, "\"", Out).
transpile_expression(in, Temp_Counter, [], "Var_in", Temp_Counter).
transpile_expression(out, Temp_Counter, [], "Var_out", Temp_Counter).
transpile_expression(prolog_id(I), Temp_Counter, [], I, Temp_Counter).
transpile_expression(function_id(I), Temp_Counter, [], I, Temp_Counter).

/************************
 * Compound Expressions *
 ************************/

transpile_expression(parenthesized(X), Temp_Counter, Statements_Out, Out, Temp_Counter_Out) :-
	transpile_expression(X, Temp_Counter, Statements_Out, Out, Temp_Counter_Out).
transpile_expression(tuple(Xs), Temp_Counter, Statements_Out, Out, Temp_Counter_Out) :-
	transpile_expressions(Xs, Temp_Counter, Statements_Out, Xs_Out, Temp_Counter_Out),
	join(Xs_Out, ",", Out1),
	string_concat("(", Out1, Out2),
	string_concat(Out2, ")", Out).
transpile_expression(invocation(prolog_id(I), Xs), Temp_Counter, Statements_Out, Out, Temp_Counter_Out) :-
	transpile_expressions(Xs, Temp_Counter, Statements_Out, Xs_Out, Temp_Counter_Out),
	string_concat(I, "(", Out1),
	join(Xs_Out, ",", Out2),
	string_concat(Out1, Out2, Out3),
	string_concat(Out3, ")", Out).
transpile_expression(invocation(function_id(I), Xs), Temp_Counter, Statements_Out, Temp_Name, Temp_Counter_Out) :-
	transpile_expressions(Xs, Temp_Counter, Statements1, Xs_Out1, Temp_Counter1),
	temp_name(Temp_Counter1, Temp_Name),
	Temp_Counter_Out is Temp_Counter1 + 1,
	append(Xs_Out1, [Temp_Name], Xs_Out),
	function_name(I, Function_Name),
	string_concat(Function_Name, "(", Statement1),
	join(Xs_Out, ",", Statement2),
	string_concat(Statement1, Statement2, Statement3),
	string_concat(Statement3, ")", Statement),
	append(Statements1, [Statement], Statements_Out).
