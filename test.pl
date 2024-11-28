
fib ( 0 , 1 ) . 
fib ( 1 , 1 ) . 
fib ( X , Res ) :- X >= 2 , Y is X - 1 , Z is X - 2 , fib ( Y , Fib1 ) , fib ( Z , Fib2 ) , Res is Fib1 + Fib2 . 
