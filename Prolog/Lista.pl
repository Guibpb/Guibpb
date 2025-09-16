soma(0,[]).

soma(S, [Cabeca|Cauda]) :-
    soma(SomaCauda, Cauda),
    S is Cabeca + SomaCauda.