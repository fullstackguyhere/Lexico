# Lexico
Lexical analyzer & grammar analyzer for custom language

Features:-

1.  Lexical part: infix RG -> postfix RG -> NFA -> DFA -> ODFA -> scan analysis
    Grammatical part: grammar -> LR (1) Predictive Analysis Table -> resolve ambiguous conflict -> scan reduction
    // This third-party JSON library for rapidjson is used only on the result's input and output
    
2. Support lexical and grammatical rules in any language
  A. Support lexical rules in any language by defining several regular expressions in the lexical configuration file
  B. Support *. | () These five kinds of meta symbols
  C. Grammar rules that support any language by defining several productions in the syntax configuration file
  D. There is no hard code in the program
  
3. Can handle conflict
    Lexical Part: Conflicts resolved by prioritizing RGs
    Grammar part: By defining precedence and binding rules for grammar terminators, solving the "move - reduction clash"
    
4. error function
    A. The result and error logs are all recorded in JSON format
    B. Lexical analysis, you can skip the current error, continue to analyze, to a one-time scan all errors
