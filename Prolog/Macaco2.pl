move(estado(no_centro,acima_caixa,no_centro,não_tem), % antes de mover
pegar_banana, % pega banana
estado(no_centro,acima_caixa,no_centro,tem) ). % depois de mover
move(estado(P,no_chão,P,Banana),
subir, % subir na caixa
estado(P,acima_caixa,P,Banana) ).
move(estado(P1,no_chão,P1,Banana),
empurrar(P1,P2), % empurrar caixa de P1 para P2
estado(P2,no_chão,P2,Banana) ).
move(estado(P1,no_chão,Caixa,Banana),
caminhar(P1,P2), % caminhar de P1 para P2
estado(P2,no_chão,Caixa,Banana) ).
consegue(estado(_,_,_,tem),[]). % macaco já tem banana
consegue(Estado1,[Movimento|Resto]) :- % movimentar e tentar conseguir
move(Estado1,Movimento,Estado2), % a banana
consegue(Estado2,Resto).