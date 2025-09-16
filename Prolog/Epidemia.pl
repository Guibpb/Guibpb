:- dynamic estado/2.

contato(p1, p2).
contato(p2, p3).
contato(p3, p4).
contato(p4, p5).

conecta(A,B) :- contato(A,B).
conecta(A,B) :- contato(B,A).

% Pessoas isoladas (não infectam)
isolado(p5).  % p2 infectado mas isolado (não transmite)

% Taxas da simulação
taxa_infeccao(0.5).     % 50% de chance de infectar
taxa_recuperacao(0.3).  % 30% de chance de se recuperar

% Inicializa o estado da população
iniciar :-
    retractall(estado(_, _)),  % limpa estados anteriores (necessário)
    assertz(estado(p1, suscetivel)),
    assertz(estado(p2, infectado)),
    assertz(estado(p3, suscetivel)),
    assertz(estado(p4, suscetivel)),
    assertz(estado(p5, infectado)),
    writeln("População inicializada."),
    listar_estados.

% Uma rodada completa (infecção + recuperação)
rodada :-
    writeln("rodada iniciada"),
    ignore(rodada_infeccao),
    ignore(rodada_recuperacao),
    nl, listar_estados, nl.

% Etapa de infecção
rodada_infeccao :-
    writeln("Infecção iniciada"),
    findall(P, estado(P, infectado), Infectados), format("Infectados: ~w~n", [Infectados]),
    forall(member(P, Infectados), tentar_infectar_contatos(P)).

tentar_infectar_contatos(Pessoa) :-
    writeln("Tentar infectar contatos iniciado."),
    \+ isolado(Pessoa),
    findall(Outro, conecta(Pessoa, Outro), Contatos),
    forall(member(C, Contatos), tentar_infectar(Pessoa, C)).

tentar_infectar(_, Para) :-
    estado(Para, suscetivel),
    taxa_infeccao(T),
    random(R),
    writeln("Tentar infectar"),
    R =< T,
    retract(estado(Para, suscetivel)),
    assertz(estado(Para, infectado)),
    format("~w foi infectado.~n", [Para]).
tentar_infectar(_, _).  % fallback

% Etapa de recuperação
rodada_recuperacao :-
    writeln("Recuperação iniciada"),
    findall(P, estado(P, infectado), Infectados),
    forall(member(P, Infectados), tentar_recuperar(P)).

tentar_recuperar(Pessoa) :-
    writeln("Tentar recuperar iniciado."),
    taxa_recuperacao(T),
    random(R),
    R =< T,
    retract(estado(Pessoa, infectado)),
    assertz(estado(Pessoa, recuperado)),
    format("~w se recuperou.~n", [Pessoa]),
    !.
tentar_recuperar(_).

% Exibir os estados atuais
listar_estados :-
    findall((P, E), estado(P, E), Lista),
    format("Estado atual: ~w~n", [Lista]).