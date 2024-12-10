:- begin_tests(transpiler).
:- use_module(transpiler).

compile_prolog(Prolog_Program) :-
	tmp_file_stream(text, File, Stream),
	write(Stream, Prolog_Program),
	close(Stream),
	consult(File).

test(simple_program) :-
	transpile_to_prolog("Id :- $ = #.", Prolog_Program),
	compile_prolog(Prolog_Program),
	fun_Id(1, 1),
	\+ fun_Id(1, 2).

test(peano) :-
	transpile_to_prolog("Inc :- $ = s(#). Plus N1, N2 -> N3 :- N1 = 0, N3 = N2. Plus N1, N2 -> N3 :- N1 = s(N), N3 = Plus(N, s(N2)).", Prolog_Program),
	compile_prolog(Prolog_Program),
	N0 = 0,
	fun_Inc(N0, N1),
	fun_Plus(N1, N1, N2),
	fun_Plus(N2, N2, s(s(s(s(0))))).

:- end_tests(transpiler).
