jim_gets_the_money(Bank, Safe) :-
    jim_climbs_into(Bank),
    chooses(Safe),
    wait_for(Tools),
    opens(Safe, Tools),
    outputs(Safe, Bank).

dick_gets_the_money(Bank, Safe) :-
    wait(nonvar(Safe)),
    has(Tools, Safe),
    send(Tools).

chooses(wertheim).
chooses(milner).
chooses(chatwood).

has(tool_set_a, milner).
has(tool_set_b, chatwood).

jim_climbs_into(Bank) :-
    during(5).

opens(milner, Tools) :-
    during(40).

opens(chatwood, Tools) :-
    during(10).

outputs(Safe, Bank) :-
    systemtime(T),
    outstring("The bandits got "),
    outstring("the money from the "),
    output(Safe),
    outstring(" safe, "),
    outstring(" from the "),
    output(Bank),
    outstring(" bank "),
    outstring(" at time "),
    output(T).

fin.

problem :-
    new(dick_gets_the_money(prolog_savings, Safe), dick, 0, 25),
    new(jim_gets_the_money(prolog_savings, Safe), jim, 0, 25).