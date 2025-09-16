% estrutura principal: estado(horizontal, vertical, caixa, temBanana?)
% relação move: 

%estado(H,V,C,T).
%move(Estado1, Movimento, Estado2).

% movimento pegar a banana : 

move(estado(no_centro, cima_caixa, no_centro, não_tem), pegar_banana, estado(no_centro, cima_caixa, no_centro, tem)).

%movimento de um ponto P1 para P2 (macaco):

move(estado(P1, no_chão, Caixa, Banana), caminhar(P1,P2), estado(P2, no_chão, Caixa, Banana)).

%movimento de empurrar a caixa:

move(estado(P1, no_chão, P1, Banana), empurrar(P1,P2), estado(P2, no_chão, P2, Banana)).

%movimento de subir na caixa:

move(estado(P, no_chão, P, Banana), subir, estado(P, cima_caixa, P, Banana)).

%macaco consegue a banana

consegue(estado(_,_,_,tem),[]).

consegue(Estado1,[Movimento|Resto]) :- 
    move(Estado1, Movimento, Estado2),
    consegue(Estado2, Resto).